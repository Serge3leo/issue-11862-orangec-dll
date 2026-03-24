@if "x%VERBOSE%"=="x" echo off
rem vim:set sw=4 ts=8 et fileencoding=utf8:
rem SPDX-License-Identifier: BSD-2-Clause
rem SPDX-FileCopyrightText: 2025 Сергей Леонтьев (leo@sai.msu.ru)

occ -c -Dmnld_EXPORTS=1 dll-mnld.c
occ -o mnld.dll --out-implib mnld.l -shared dll-mnld.o

occ main-mnld.c mnld.l
echo Start main-mnld.exe
main-mnld.exe
