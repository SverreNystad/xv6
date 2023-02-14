#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// writes to standard output:
uint64
sys_hello(void)
{
  printf("Hello World this message comes from the syscall, I LOVE YOU MY MAKER");
  return 0;
}

// writes out all info about current process
uint64
sys_print_prosses_info(void)
{
  // int pid = sys_getpid();
  // printf("The PID: %d\n", pid);

  // int currentState = myproc()->state;
  // printf("The State: %d\n", currentState);

  // if (currentState == 4) {
  //   printf("Program is running");
  // }
  // printf();
  procmanagement();
  return 0;
}

// writes out the state of a prossess
uint64
sys_print_prosses_state(void)
{

  procdump();
  // printf("The State: %d\n", currentState);

  //   if (currentState == RUNNING) {
  //   printf("Program is running");
  // }
  return 0;
}



