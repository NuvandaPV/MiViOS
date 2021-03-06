/*
 * libc.h
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

#ifndef LIBC_LIBC_H
#define LIBC_LIBC_H

#include <stddef.h>
#include <stdint.h>
#include <kernel/info.h>

void initialize_standard_library(
    size_t* argc_ptr,
    char*** argv_ptr,
    size_t* envc_ptr,
    char*** envp_ptr,
    uint32_t magic,
    union info* info);

void finalize_standard_library(int status);

#endif // ! LIBC_LIBC_H
