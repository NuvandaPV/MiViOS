/*
 * linker.ld
 *
 * Created by Jean-Pierre Höhmann on 25.08.18.
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

/*
 * Instructions for linking the kernel targeting i386.
 */

/*
 * The bootloader will look at this image and start execution at the symbol
 * designated at the entry point.
 */
ENTRY(_start)

/*
 * Tell where the various sections of the object files will be put in the final
 * kernel image.
 */
SECTIONS
{
	/*
	 * Begin putting sections at 1 MiB, a conventional place for kernels to be
	 * loaded at by the bootloader.
	 */
	. = 1M;

	/*
	 * First put the multiboot header, as it is required to be put very early
	 * early in the image or the bootloader won't recognize the file format.
	 * Next we'll put the .text section.
	 */
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}

	/*
	 * Read-only data.
	 */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	/*
	 * Initialized read-write data.
	 */
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	/*
	 * Uninitialized read-write data and stack.
	 */
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}
}