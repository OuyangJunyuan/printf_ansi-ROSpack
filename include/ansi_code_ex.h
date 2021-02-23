//
// Created by ou on 2021/2/18.
//

#ifndef BASE_UTILS_ANSI_CODE_EX_H
#define BASE_UTILS_ANSI_CODE_EX_H

#include "ansi_codes.h"
#include <stdio.h>
//////////////////////////////////////////////////////////////////
/*                            辅助宏                            */
#define _MACRO(x) x
#define MACRO(x) _MACRO(x)
#define _STR(x) #x
#define STR(x) _STR(x)

//////////////////////////////////////////////////////////////////
/*                            颜色宏
 * eg:
 *      ANSI_C8(FG,YELLOW)->"\e[33m"
 *      ANSI_C8(BG,YELLOW)->"\e[43m"
 *      ANSI_C8(FG,YELLOW,H)->"\e[93m"
 *      ANSI_C8(BG,YELLOW,H)->"\e[103m"
 *
 *      ANSI_C255(FG,255)->"\e[38;5;255m"
 *      ANSI_C255(BG,255)->"\e[48;5;255m"
 *      ANSI_CRGB(FG,255,255,0)->"\e[38;2;255;255;0m"
 *      ANSI_CRGB(BG,255,255,0)->"\e[48;2;255;255;0m"
 */
#define ANSI_C8(FB, COLOR, ...)                         "\e["\
                                                        STR(ANSI_PRIFIX_ ##FB ##__VA_ARGS__)\
                                                        STR(ANSI_SUFFIX_ ##COLOR)\
                                                        "m"

#define ANSI_C255(FB, VALUE)                            "\e["\
                                                        STR(ANSI_PRIFIX_ ##FB)\
                                                        "8;5;"\
                                                        STR(VALUE)\
                                                        "m"

#define ANSI_CRGB(FB, R, G, B)                          "\e["\
                                                        STR(ANSI_PRIFIX_ ##FB)\
                                                        "8;2;"\
                                                        STR(R) ";" STR(G) ";" STR(B)\
                                                        "m"

#define ANSI_CBOOL(var, c1, c2)                         (var)?c1:c2

#define ANSI_BG_RGB_VAR(r, g, b)                        printf("\e[48;2;%d;%d;%dm",r%256,g%256,b%256);
//////////////////////////////////////////////////////////////////
/*                            控制宏                            */
#define CONSOLE_CLEAR_SCREEN                            printf(ANSI_CLEAR_SCREEN);
#define CONSOLE_CLEAR_SCREEN_BEHIND                     printf(ANSI_CLEAR_SCREEN_BEHIND);
#define CONSOLE_CLEAR_LINE                              printf(ANSI_CLEAR_LINE_WHOLD);
#define CONSOLE_CURSOR_MOVE(_Y_, _X_)                   printf(ANSI_CURSOR_MOVE(_Y_, _X_));
#define CONSOLE_CURSOR_HEAD                             printf(ANSI_CURSOR_MOVE(0,0));
#define CONSOLE_CURSOR_MOVE_VAR(inty, intx)             printf("\e[%d;%dH",(int)(inty),(int)(intx));
#define CONSOLE_CURSOR_HIDE                             printf(ANSI_CURSOR_HIDE);
#define CONSOLE_CURSOR_SHOW                             printf(ANSI_CURSOR_SHOW);
#define CONSOLE_LINE_NEXT                               printf("\n");
////////////////////////////////////////////////////////////////////
/*                            功能
 * printf_ansi(ANSI_FONT(FG,BLUE),ANSI_UNDERLINE,ANSI_BLINK)("printf %s ansi code","with");
 */
#define printf_ansi(...)                                do{ \
                                                            printf("%s",__printf_ansi_va_cfg("",##__VA_ARGS__,"")); \
                                                            printf( __printf_ansi
#define __printf_ansi(x, ...)                               x ANSI_NONE ,##__VA_ARGS__); \
                                                        }while(0)

//////////////////////////////////////////////////////////////////
/*                            功能                            */
#define CONSOLE_LOADING_BAR(X, Y, W, N, G, I, C)                __loading_bar(X, Y, W, N, G, I, C);


//////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C" {
#endif

const char *__printf_ansi_va_cfg(const char *format, ...);

void __loading_bar(int _x, int _y, unsigned int _width, unsigned int _n, int _grid_on, int _info, const char *_color);


#ifdef __cplusplus
}
#endif
#endif //BASE_UTILS_ANSI_CODE_EX_H
