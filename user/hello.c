#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#include <stdarg.h>

// #include <stdio.h>

int main(int argc, char const *argv[])
{
		if(argc < 2) {
		printf("Hello World\n");
	}
	else {
		printf("Hello %s, nice to meet you!\n", argv[1]);
	}

	// printf("This is the output of the syscall hello(): ");
	// printf("%d\n", hello());
	
	// // SYSCALL(hello());

	return 0;
}
