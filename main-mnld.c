// vim:set sw=4 ts=8 et fileencoding=utf8::Кодировка:UTF-8[АБЁЪЯабёъя]
// SPDX-License-Identifier: BSD-2-Clause
// SPDX-FileCopyrightText: 2026 Сергей Леонтьев (leo@sai.msu.ru)

#include <stdio.h>
#include <stdlib.h>

#include "mnld.h"

int main(void) {
    if (MNLD_CHECK != mnld()) {
        printf("FAIL: mnld() = %d\n", mnld());
        exit(EXIT_FAILURE);
    }
    printf("Ok\n");
}
