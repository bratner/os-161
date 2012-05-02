/*
 * Copyright (c) 2001, 2002, 2009
 *	The President and Fellows of Harvard College.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE UNIVERSITY AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE UNIVERSITY OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * Driver code for bathroom problem
 */
#include <types.h>
#include <lib.h>
#include <thread.h>
#include <test.h>

#define NPEOPLE 20

static
void
shower()
{
	// The thread enjoys a refreshing shower!
        clocksleep(1);
}

static
void
boy(void *p, unsigned long which)
{
	(void)p;
	kprintf("boy #%ld starting\n", which);

	// Implement synchronization
	shower();
}

static
void
girl(void *p, unsigned long which)
{
	(void)p;
	kprintf("girl #%ld starting\n", which);

	// Implement synchronization
	shower();
}

// Change this function as necessary
int
bathroom(int nargs, char **args)
{

	int i, err=0;
	
	(void)nargs;
	(void)args;

	for (i = 0; i < NPEOPLE; i++) {
		switch(i % 2) {
			case 0:
			err = thread_fork("Boy Thread",NULL, i, boy, NULL);
			break;
			case 1:
			err = thread_fork("Girl Thread",NULL, i, girl, NULL);
			break;
		}
		if (err) {
			panic("bathroom: thread_fork failed: %s)\n",
				strerror(err));
		}
	}

	return 0;
}
