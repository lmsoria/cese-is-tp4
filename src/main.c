/************************************************************************************************
Copyright (c) 2023, Leandro Soria <leandromsoria@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file main.c
 ** @brief Declaracion de la función principal del programa
 **/

/* === Headers files inclusions =============================================================== */

#include <stdio.h>
#include <unistd.h>

#include "gpio.h"
#include "main.h"

/* === Macros definitions ====================================================================== */

#define LED_RED_PORT   1
#define LED_GREEN_PORT 2

#define LED_RED_PIN    28
#define LED_GREEN_PIN  12

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

static void delay(int ms);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

static void delay(int ms) {
    usleep(1000 * ms);
}

/* === Public function implementation ========================================================== */

int main(void) {

    GPIO_t led_red = gpio_create(LED_RED_PORT, LED_RED_PIN, true);
    GPIO_t led_green = gpio_create(LED_GREEN_PORT, LED_GREEN_PIN, true);

    if (!led_red || !led_green) {
        printf("No se pudo inicializar alguno de los LEDs. Saliendo...\n");
        return -1;
    }

    while (1) {
        gpio_set_state(led_red, true);
        delay(1000);
        gpio_set_state(led_red, false);
    }

    return 0;
}

/* === End of documentation ==================================================================== */
