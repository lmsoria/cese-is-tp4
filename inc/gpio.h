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

#pragma once

/** @file gpio.h
 ** @brief Capa de abstracción para gestionar puertos de E/S digitales (definición)
 **/

/* === Headers files inclusions ================================================================ */

#include <stdbool.h>
#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

typedef struct GPIO * GPIO_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/// @brief Crea un puerto digital con los parámetros dados.
/// @param port Puerto de E/S.
/// @param pin Número de Pin.
/// @param is_output `true` si es salida, `false` si es entrada.
/// @return Puntero al objeto creado.
GPIO_t gpio_create(uint32_t port, uint32_t pin, bool is_output);

/// @brief Cambiar el estado del GPIO para que sea entrada o salida.
/// @param gpio GPIO a configurar.
/// @param output `true` si es salida, `false` si es entrada.
void gpio_set_direction(GPIO_t gpio, bool output);

/// @brief Consultar si el GPIO es entrada o salida
/// @param gpio GPIO a consultar.
/// @return `true` si es salida, `false` si es entrada.
bool gpio_get_direction(GPIO_t gpio);

/// @brief Configurar el estado lógico del GPIO (siempre y cuando sea de salida).
/// @param gpio GPIO a configurar.
/// @param state `true` para que esté en estado lógico alto, `false` de lo contrario.
void gpio_set_state(GPIO_t gpio, bool state);

/// @brief Consultar el estado lógico del GPIO.
/// @param gpio GPIO a consultar.
/// @return `true` si está en estado lógico alto, `false` de lo contrario.
bool gpio_get_state(GPIO_t gpio);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif
