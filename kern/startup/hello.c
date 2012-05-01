#include <types.h>
#include <kern/errno.h>
#include <kern/reboot.h>
#include <kern/unistd.h>
#include <limits.h>
#include <lib.h>
#include <uio.h>
#include <clock.h>
#include <thread.h>
#include <vfs.h>
#include <sfs.h>
#include <syscall.h>
#include <test.h>
#include "opt-synchprobs.h"
#include "opt-sfs.h"
#include "opt-net.h"

void hellomofos(){
	kprintf("hello mofos!\n");
};
void panic_beatch(){
	char * a;
	a = (char *)0;
	*a='H';
};
