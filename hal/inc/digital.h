/*********************************************************************************************************************
Copyright 2016-2026, Electronica IV
Facultad de Ciencias Exactas y Tecnologia
Universidad Nacional de Tucuman

Copyright 2016-2026, Chaile Diego Fernando <chailediegofernando@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef DIGITAL_H_
#define DIGITAL_H_

/** @file digital.h
 ** @brief Declaraciondes de la biblioteca digital para entradas y salidas
*/

/* === Headers files inclusions ================================================================ */

#include <stdint.h>
#include <stdbool.h>

/* === Macros definitions ====================================================================== */

#define ACTIVATE_EVENT 1
#define DEACTIVATE_EVENT 0

/* === Public data type declarations ========================================================== */

typedef struct digital_input_s * digital_input_t;

typedef struct digital_output_s * digital_output_t;

/* === Public function declarations =========================================================== */

digital_output_t DigitalOutputCreate(uint32_t gpio, uint8_t bit, bool inverted);

void DigitalOutputActivate(digital_output_t self);

void DigitalOutputDeactivate(digital_output_t self);

void DigitalOutputToggle(digital_output_t self);

bool DigitalOutputGetState(digital_output_t self);

digital_input_t DigitalInputCreate(uint8_t gpio, uint8_t bit, bool inverted);

bool DigitalInputGetState(digital_input_t self);

int DigitalInputHasChanged(digital_input_t self);

bool DigitalInputHasActivated(digital_input_t self);

bool DigitalInputHasDeactivated(digital_input_t self);

/* === Public variable definitions ============================================================ */

/* === Public variable definition  ============================================================= */

/* === Public function definitions ============================================================ */

/* === Public function implementation ========================================================== */

/* === End of documentation ==================================================================== */
#endif /* DIGITAL_H_ */