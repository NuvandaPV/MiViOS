/*
 * atexit.h
 *
 * Created by Jean-Pierre Höhmann on 2018-09-14.
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

#ifndef STDLIB_ATEXIT_H
#define STDLIB_ATEXIT_H

#define ATEXIT_HANDLER_COUNT_LIMIT 32

void run_atexit_handlers(void);

#endif // STDLIB_ATEXIT_H
