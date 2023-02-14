#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#include <stdarg.h>


int main(int argc, char const *argv[])
{
	/* code */
	// printf("Print all relevant stuff: \n");
	// print_prosses_info();
	
	// printf("Print id with XV6 systemcall getpid(): %d\n", getpid());
	// procdump();
	print_prosses_info();
	// sys_print_prosses_state();
	
	return 0;
}
