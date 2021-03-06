/*
 * gdt.h
 *
 * Created by Jean-Pierre Höhmann on 18-08-26.
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

#ifndef ARCH_I386_GDT_H
#define ARCH_I386_GDT_H

// Stub.

#ifndef __assembler

#include <stdint.h>

struct gdt_entry {
    uint32_t base;
    uint32_t limit;
    uint8_t type;
};

extern uint64_t _gdt_start;
extern void _gdt_end;
extern void _gdt_set(uint64_t*, uint16_t);

#endif // ! __assembler

#endif // ! ARCH_I386_GDT_H
