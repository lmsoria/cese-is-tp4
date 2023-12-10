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

/** @file gpio.c
 ** @brief Capa de abstracción para gestionar puertos de E/S digitales (implementación)
 **/

/* === Headers files inclusions =============================================================== */

#include <stdlib.h>
#include <stdio.h>

#include "gpio.h"

/* === Macros definitions ====================================================================== */

#ifdef USE_STATIC_ALLOCATION
#ifndef MAX_GPIO_INSTANCES
#define MAX_GPIO_INSTANCES 16
#endif
#endif

/* === Private data type declarations ========================================================== */

/// @brief Estructura con los atributos de un puerto
struct GPIO {
    uint32_t port;  ///< Número de puerto GPIO.
    uint32_t pin;   ///< Pin del puerto GPIO.
    bool is_output; ///< El puerto está configurado como salida.
    bool state;     ///< Estado lógico del puerto
#ifdef USE_STATIC_ALLOCATION
    bool used; ///< El descriptor del puerto está ocupado.
#endif
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

#ifdef USE_STATIC_ALLOCATION
/// @brief Función para alocar estáticamente un puerto GPIO.
/// @return Puntero al objeto alocado si hay espacio, o NULL en caso contrario.
static GPIO_t gpio_allocate();
#endif

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

#ifdef USE_STATIC_ALLOCATION
static GPIO_t gpio_allocate() {
    static struct GPIO GPIO_INSTANCES[MAX_GPIO_INSTANCES] = {0};
    GPIO_t ret = NULL;

    for (size_t index = 0; index < MAX_GPIO_INSTANCES; index++) {
        if (!GPIO_INSTANCES[index].used) {
            ret = &GPIO_INSTANCES[index];
            ret->used = true;
            break;
        }
    }

    return ret;
}
#endif

/* === Public function implementation ========================================================== */

GPIO_t gpio_create(uint32_t port, uint32_t pin, bool is_output) {

    GPIO_t self;

#ifdef USE_STATIC_ALLOCATION
    self = gpio_allocate();
#else
    self = malloc(sizeof(struct GPIO));
#endif

    if (self) {
        self->pin = pin;
        self->port = port;
        self->is_output = is_output;
    }

    printf("[gpio] Alocado Puerto <%d,%d> como %s\n", self->port, self->pin,
           self->is_output ? "salida" : "entrada");
    return self;
}

void gpio_set_direction(GPIO_t gpio, bool output) {
    gpio->is_output = output;
}

bool gpio_get_direction(GPIO_t gpio) {
    return gpio->is_output;
}

void gpio_set_state(GPIO_t gpio, bool state) {
    if (gpio->is_output) {
        gpio->state = state;
        printf("[gpio] Puerto <%d,%d> = %d\n", gpio->port, gpio->pin, gpio->state);
    }
}

bool gpio_get_state(GPIO_t gpio) {
    return gpio->state;
}

/* === End of documentation ==================================================================== */
