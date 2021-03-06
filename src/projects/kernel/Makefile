#
# Makefile
#
# Created by Jean-Pierre Höhmann on 18-08-25.
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

#
# Make instructions for the kernel.
#

DEFAULT_HOST?=i686-elf
HOST?=$(DEFAULT_HOST)
HOSTARCH!=target-triplet-to-arch.sh $(HOST)

AR?=$(HOST)-ar
AS?=$(HOST)-as
CC?=$(HOST)-cc

CFLAGS_DEFAULT=-O2 -g
CFLAGS_EXTRA=-ffreestanding -Wall -Wextra
CPPFLAGS_DEFAULT=
CPPFLAGS_EXTRA=-Iinclude
LDFLAGS_DEFAULT=
LDFLAGS_EXTRA=
LIBS_DEFAULT=
LIBS_EXTRA=-nostdlib -lk -lgcc

KERNEL_CFLAGS_DEFAULT=
KERNEL_CFLAGS_EXTRA=
KERNEL_CPPFLAGS_DEFAULT=
KERNEL_CPPFLAGS_EXTRA=-D__is_kernel
KERNEL_LDFLAGS_DEFAULT=
KERNEL_LDFLAGS_EXTRA=
KERNEL_LIBS_DEFAULT=
KERNEL_LIBS_EXTRA=

DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
BOOTDIR?=$(EXEC_PREFIX)/boot
INCLUDEDIR?=$(PREFIX)/include

CFLAGS_DEFAULT:=$(CFLAGS_DEFAULT)
CPPFLAGS_DEFAULT:=$(CPPFLAGS_DEFAULT)
LDFLAGS_DEFAULT:=$(LDFLAGS_DEFAULT)
LIBS_DEFAULT:=$(LIBS_DEFAULT)

CFLAGS_EXTRA:=$(CFLAGS_EXTRA)
CPPFLAGS_EXTRA:=$(CPPFLAGS_EXTRA)
LDFLAGS_EXTRA:=$(LDFLAGS_EXTRA)
LIBS_EXTRA:=$(LIBS_EXTRA)

CFLAGS?=$(CFLAGS_DEFAULT)
CPPFLAGS?=$(CPPFLAGS_DEFAULT)
LDFLAGS?=$(LDFLAGS_DEFAULT)
LIBS?=$(LIBS_DEFAULT)

CFLAGS:=$(CFLAGS)
CPPFLAGS:=$(CPPFLAGS)
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS)

KERNEL_CFLAGS_DEFAULT:=$(CFLAGS) $(KERNEL_CFLAGS_DEFAULT)
KERNEL_CPPFLAGS_DEFAULT:=$(CPPFLAGS) $(KERNEL_CPPFLAGS_DEFAULT)
KERNEL_LDFLAGS_DEFAULT:=$(LDFLAGS) $(KERNEL_LDFLAGS_DEFAULT)
KERNEL_LIBS_DEFAULT:=$(LIBS) $(KERNEL_LIBS_DEFAULT)

KERNEL_CFLAGS_EXTRA:=$(CFLAGS_EXTRA) $(KERNEL_CFLAGS_EXTRA)
KERNEL_CPPFLAGS_EXTRA:=$(CPPFLAGS_EXTRA) $(KERNEL_CPPFLAGS_EXTRA)
KERNEL_LDFLAGS_EXTRA:=$(LDFLAGS_EXTRA) $(KERNEL_LDFLAGS_EXTRA)
KERNEL_LIBS_EXTRA:=$(LIBS_EXTRA) $(KERNEL_LIBS_EXTRA)

KERNEL_CFLAGS?=$(KERNEL_CFLAGS_DEFAULT)
KERNEL_CPPFLAGS?=$(KERNEL_CPPFLAGS_DEFAULT)
KERNEL_LDFLAGS?=$(KERNEL_LDFLAGS_DEFAULT)
KERNEL_LIBS?=$(KERNEL_LIBS_DEFAULT)

KERNEL_CFLAGS:=$(KERNEL_CFLAGS)
KERNEL_CPPFLAGS:=$(KERNEL_CPPFLAGS)
KERNEL_LDFLAGS:=$(KERNEL_LDFLAGS)
KERNEL_LIBS:=$(KERNEL_LIBS)

CFLAGS:=$(CFLAGS) $(CFLAGS_EXTRA)
CPPFLAGS:=$(CPPFLAGS) $(CPPFLAGS_EXTRA)
LDFLAGS:=$(LDFLAGS) $(LDFLAGS_EXTRA)
LIBS:=$(LIBS) $(LIBS_EXTRA)

KERNEL_CFLAGS:=$(KERNEL_CFLAGS) $(KERNEL_CFLAGS_EXTRA)
KERNEL_CPPFLAGS:=$(KERNEL_CPPFLAGS) $(KERNEL_CPPFLAGS_EXTRA)
KERNEL_LDFLAGS:=$(KERNEL_LDFLAGS) $(KERNEL_LDFLAGS_EXTRA)
KERNEL_LIBS:=$(KERNEL_LIBS) $(KERNEL_LIBS_EXTRA)

ARCHDIR=arch/$(HOSTARCH)

include $(ARCHDIR)/$(HOSTARCH).make

CFLAGS:=$(CFLAGS) $(ARCH_CFLAGS)
CPPFLAGS:=$(CPPFLAGS) $(ARCH_CPPFLAGS)
LDFLAGS:=$(LDFLAGS) $(ARCH_LDFLAGS)
LIBS:=$(LIBS) $(ARCH_LIBS)

KERNEL_CFLAGS:=$(KERNEL_CFLAGS) $(KERNEL_ARCH_CFLAGS)
KERNEL_CPPFLAGS:=$(KERNEL_CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)
KERNEL_LDFLAGS:=$(KERNEL_LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
KERNEL_LIBS:=$(KERNEL_LIBS) $(KERNEL_ARCH_LIBS)

KERNEL_OBJS=\
$(KERNEL_ARCH_OBJS) \
kernel/kernel.o \
kernel/mm.o \
kernel/ma.o \

OBJS=\
$(ARCHDIR)/crti.o \
$(ARCHDIR)/crtbegin.o \
$(KERNEL_OBJS) \
$(ARCHDIR)/crtend.o \
$(ARCHDIR)/crtn.o \

LINK_LIST=\
$(KERNEL_LDFLAGS) \
$(ARCHDIR)/crti.o \
$(ARCHDIR)/crtbegin.o \
$(KERNEL_OBJS) \
$(KERNEL_LIBS) \
$(ARCHDIR)/crtend.o \
$(ARCHDIR)/crtn.o \

BINARIES=\
mivios.elf \
mivios.env \

.PHONY: all clean install install-headers install-kernel
.SUFFIXES: .o .c .S

all: $(BINARIES)

mivios.elf: $(OBJS) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(KERNEL_CFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot mivios.elf

mivios.env: kernel/kernel.env
	txt.pl $< > $@

$(ARCHDIR)/crtbegin.o $(ARCHDIR)/crtend.o:
	OBJ=`$(CC) $(KERNEL_CFLAGS) $(KERNEL_LDFLAGS) -print-file-name=$(@F)` && cp "$$OBJ" $@

.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(KERNEL_CFLAGS) $(KERNEL_CPPFLAGS)

.S.o:
	$(CC) -MD -c $< -o $@ $(KERNEL_CFLAGS) -D__assembler $(KERNEL_CPPFLAGS)

clean:
	rm -f $(BINARIES) $(OBJS) $(OBJS:.o=.d)

install: install-headers install-kernel

install-headers:
	mkdir -p $(DESTDIR)/$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)/$(INCLUDEDIR)/.

install-kernel: $(BINARIES)
	mkdir -p $(DESTDIR)/$(BOOTDIR)
	cp $(BINARIES) $(DESTDIR)/$(BOOTDIR)

-include $(OBJS:.o=.d)
