#
# gdt.S
#
# Created by Jean-Pierre Höhmann on 26.08.18.
#
# Copyright 2018 Jean-Pierre Höhmann (@NuvandaPV) <jean-pierre@höhmann.info>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

.section .data

# GDT with five entries. Mandatory null entry, supervisor code, supervisor data, user code, user data, in a flat setup.
.align 8
.global _gdt_start
.type _gdt_start, @object
_gdt_start:
.quad 0x0000000000000000
.quad 0x00CF9A000000FFFF
.quad 0x00CF92000000FFFF
.quad 0x00CFFA000000FFFF
.quad 0x00CFF2000000FFFF
.global _gdt_end
.type _gdt_end, @notype
_gdt_end:

.section .text

# Set the GDT frome a given pointer and size (on the stack in that order).
.global _setGDT
.type _setGDT, @function
_setGDT:
    push %ebp                                                           # Set up the stack.
    movl %esp, %ebp                                                     #
    movl 8(%esp), %eax                                                  # Put the GDT pointer on the stack.
    push %eax                                                           #
    movw 12(%esp), %ax                                                  # Put the size on the stack as a 16 bit value
    push %ax                                                            # directly below the GDT pointer.
    lgdt (%esp)                                                         # Load the GDT using the 6 bytes just written.
    call reloadSegments                                                 # Reload the segments.
    movl %ebp, %esp                                                     #
    pop %ebp                                                            # Restore the stack and return.
    ret                                                                 #

# Reload the segments. This is run after the GDT is loaded and will load the new supervisor code and data segments.
reloadSegments:
    ljmp $0x08, $reloadDS                                               # Long jump into the supervisor code segment
reloadDS:
    movw $0x10, %ax                                                     # Load the supervisor data segment, as data
    movw %ax, %ds                                                       # (d, e, f, and g) and stack (s) segments.
    movw %ax, %es                                                       #
    movw %ax, %fs                                                       # Kernel code: 0b 0000000000001 0 00
    movw %ax, %gs                                                       # (index 1, segmentation on, ring 0)
    movw %ax, %ss                                                       # Kernel data: 0b 0000000000010 0 00
    ret                                                                 # (index 2, segmentation on, ring 0)

.end