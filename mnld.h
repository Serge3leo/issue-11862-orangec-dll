// vim:set sw=4 ts=8 et fileencoding=utf8:
// SPDX-License-Identifier: BSD-2-Clause
// SPDX-FileCopyrightText: 2026 Сергей Леонтьев (leo@sai.msu.ru)

#ifndef MNLD_H_0784
#define MNLD_H_0784

#define MNLD_CHECK  (1945)

#ifdef mnld_EXPORTS
   __declspec(dllexport) int mnld(void);
#else
   __declspec(dllimport) int mnld(void);
#endif

#endif  // MNLD_H_0784
