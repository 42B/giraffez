/*
 * Copyright 2016 Capital One Services, LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __GIRAFFEZ_UNPACK_H
#define __GIRAFFEZ_UNPACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <Python.h>
#if defined(WIN32) || defined(WIN64)
#include <pstdint.h>
#else
#include <stdint.h>
#endif

#include "columns.h"
#include "encoder.h"


uint32_t count_rows(unsigned char* data, const uint32_t length);

PyObject* unpack_rows(const TeradataEncoder *e, unsigned char **data, const uint32_t length);
PyObject* unpack_rows_raw(const TeradataEncoder *e, unsigned char **data, const uint32_t length);

PyObject* unpack_row_dict(const TeradataEncoder *e, unsigned char **data, const uint16_t length);
PyObject* unpack_row_str(const TeradataEncoder *e, unsigned char **data, const uint16_t length);
PyObject* unpack_row_list(const TeradataEncoder *e, unsigned char **data, const uint16_t length);
PyObject* unpack_row_raw(const TeradataEncoder *e, unsigned char **data, const uint16_t length);

PyObject* unpack_row_item_as_str(const TeradataEncoder *e, unsigned char **data, const GiraffeColumn *column);
PyObject* unpack_row_item_with_builtin_types(const TeradataEncoder *e, unsigned char **data, const GiraffeColumn *column);
PyObject* unpack_row_item_with_giraffe_types(const TeradataEncoder *e, unsigned char **data, const GiraffeColumn *column);

GiraffeColumns* unpack_stmt_info_to_columns(unsigned char **data, const uint32_t length);
void unpack_stmt_info(unsigned char **data, StatementInfo *s, const uint32_t length);
void unpack_stmt_info_ext(unsigned char **data, StatementInfoColumn *column, const uint16_t length);

#ifdef __cplusplus
}
#endif

#endif
