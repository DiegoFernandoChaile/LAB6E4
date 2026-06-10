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

#ifndef BSP_H_
#define BSP_H_

/** @file bsp.h
 ** @brief Plantilla para la creacion de archivos de cabeceras en lenguaje C
 **/

/* === Headers files inclusions ==================================================================================== */

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */

typedef struct board_s {
    digital_output_t buzzer;   /**< Salida del zumbador */
    digital_input_t f1;        /**< Tecla de función F1 */
    digital_input_t f2;        /**< Tecla de función F2 */
    digital_input_t f3;        /**< Tecla de función F3 */
    digital_input_t f4;        /**< Tecla de función F4 */
    digital_input_t accept;    /**< Tecla Aceptar */
    digital_input_t cancel;    /**< Tecla Cancelar */
    display_t display;         /**< Pantalla multiplexada de siete segmentos */
} const * board_t;

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

/**
 * @brief Inicializa el hardware de la placa y crea el descriptor de recursos
 * @return Puntero al descriptor de la placa
 */
board_t BoardCreate(void);

/** @brief Inicializa el temporizador SysTick del nucleo
 ** @param ticks Número de ticks para la inicialización
 **/
void SisTick_Init(uint16_t ticks);

/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* BSP_H_ */
