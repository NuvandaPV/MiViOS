/*
 * kernel.c
 *
 * Created by Jean-Pierre Höhmann on 18-08-25.
 *
 * Copyright 2018 Jean-Pierre Höhmann (@NuvandaPV) <jean-pierre@höhmann.info>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include <kernel/kernel.h>
#include <kernel/init.h>

static char* args;
static struct file env;

/*
 * Initialize the kernel.
 */
void kernel_initialize(struct kernel_info* info) {
    args    = info->args;
    env     = info->env;
}

/*
 * Finalize the kernel.
 */
void kernel_finalize() {
    ((void) 0);
}

/*
 * Print a debugging message.
 */
void kdebug(char* dbg) {
    // TODO Add an option to turn this off with an environment variable
    printf("kernel: debug: %s\n", dbg);
}

/*
 * Print an informational message.
 */
void kinfo(char* info) {
    printf("kernel: info:  %s\n", info);
}

/*
 * Print a warning.
 */
void kwarn(char* warn) {
    printf("kernel: warn:  %s\n", warn);
}

/*
 * Panic with an error.
 */
__attribute__((__noreturn__))
void kerror(char* err) {
    printf("kernel: error: %s\n", err);
    abort();
}

/*
 * MiViOS Kernel.
 *
 * This is called as soon as the libk is fully operational.
 */
int kernel_main(size_t argc, char* argv[], size_t envc, char* envp[]) {
    run_init(args, env);
}
