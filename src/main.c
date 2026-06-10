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

/** @file main.c
 ** @brief Plantilla para la creación de archivos de código fuente en lenguaje C
 **/

/* === Headers files inclusions ================================================================ */

#include "bsp.h"
#include "digital.h"
#include "screen.h"
#include <stdbool.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private function declarations =========================================================== */

/* === Private variable definitions ============================================================ */

static board_t board;

/* === Public variable definition  ============================================================= */

/* === Private function definitions ============================================================ */

/* === Public function implementation ========================================================== */

int main(void) {
    uint8_t entrada[4] = {7, 8, 9, 4};
    uint16_t frecuencia = 0;

    board = BoardCreate();
    DisplayWriteBCD(board->display, entrada, sizeof(entrada));
    while (true) {
        if (DigitalInputHasChanged(board->accept)){
            if (frecuencia == 0) {
                frecuencia = 100;
            } else if (frecuencia == 100){
                frecuencia =250;
            } else {
                frecuencia = 0;
            }
            DisplayFlashDigits(board->display, 0, 3, frecuencia);
        }

        if (DigitalInputHasActivated(board->cancel)){
            DisplayToggleDots(board->display, 0, 3);
        }

        if (DigitalInputHasActivated(board->f1)){
            entrada[3] = (entrada[3] + 1) % 10;
            DisplayWriteBCD(board->display, entrada, sizeof(entrada));
        }

        if (DigitalInputHasActivated(board->f2)){
            entrada[2] = (entrada[2] + 1) % 10;
            DisplayWriteBCD(board->display, entrada, sizeof(entrada));
        }

        if (DigitalInputHasActivated(board->f3)){
            entrada[1] = (entrada[1] + 1) % 10;
            DisplayWriteBCD(board->display, entrada, sizeof(entrada));
        }

        if (DigitalInputHasActivated(board->f4)){
            entrada[0] = (entrada[0] + 1) % 10;
            DisplayWriteBCD(board->display, entrada, sizeof(entrada));
        }

        for (int index = 0; index < 50; index++) {
            for (int delay = 0; delay < 10000; delay++){
                __asm("NOP");
            }
            DisplayRefresh(board->display);
        }
    }
}

/* === End of documentation ==================================================================== */
