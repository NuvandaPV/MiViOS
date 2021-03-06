/*
 * initialize-kernel-library.h
 *
 * Created by Jean-Pierre Höhmann on 2018-09-16.
 *
 * Copyright 2018 Jean-Pierre Höhmann (@NuvandaPV) <jean-pierre@höhmann.info>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LIBC_INITIALIZE_KERNEL_LIBRARY
#define LIBC_INITIALIZE_KERNEL_LIBRARY

#include <stddef.h>

#include <kernel/cpu.h>
#include <kernel/init.h>
#include <kernel/kernel.h>
#include <kernel/ma.h>
#include <kernel/mm.h>
#include <kernel/mmu.h>
#include <kernel/pfa.h>
#include <kernel/tty.h>

struct libk_info {
    struct tty_info* tty;
    struct cpu_info* cpu;
    struct mmu_info* mmu;
    struct pfa_info* pfa;
    struct mm_info* mm;
    struct ma_info* ma;
    struct init_info* init;
    struct kernel_info* kernel;
};

void initialize_kernel_library(struct libk_info* info);

#endif // ! LIBC_INITIALIZE_KERNEL_LIBRARY
