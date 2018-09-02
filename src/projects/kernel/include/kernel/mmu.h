/*
 * mmu.h
 *
 * Created by Jean-Pierre Höhmann on 29.08.18.
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

#ifndef _KERNEL_MMU_H
#define _KERNEL_MMU_H 1

#include <stdint.h>

void memory_initialize(void);
void* pfalloc(uint32_t, uint32_t, uint16_t);

#endif // _KERNEL_MMU_H
