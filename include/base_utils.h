//
// Created by ou on 2021/2/9.
//

#ifndef BASE_UTILS_UTILS_H
#define BASE_UTILS_UTILS_H

#include "ansi_code_ex.h"
#include <chrono>

#define __DEBUG__
///////////////////////////////////////
#define MARCO_BLOCK_HEAD do{
#define MARCO_BLOCK_END }while(0)
///////////////////////////////////////
using __timeType = std::chrono::steady_clock::time_point;
#define __TIME_GET_NOW                                  std::chrono::steady_clock::now()
#define __TIME_POINT(__TP__)                            __timeType __TP__
#define __STATIC_TIME_POINT(__TP__)                     static __TIME_POINT(__TP__)
///////////////////////////////////////
#define TIME_COST_MS(__T2__, __T1__)                    std::chrono::duration_cast<std::chrono::duration<double>> \
                                                        (__T2__ - __T1__).count()*1000.0f

#define RECORD_BLOCK_AVRG_TIME(__IDX)                   __TIME_DURATION_##__IDX/__TIME_TIMES_##__IDX/10.0f
///////////////////////////////////////
/*----------------------------------
 * RECORD_BLOCK_HEAD(1)
 * {
 *      //do something...
 * }
 * RECORD_BLOCK_END(1,0)
 * ---------------------------------
 * RECORD_BLOCK_HEAD(1)
 * {
 *      //do something...
 * }
 * RECORD_BLOCK_END(1,1)
 * ---------------------------------
 * RECORD_BLOCK_HEAD(1)
 * {
 *      //do something...
 * }
 * RECORD_BLOCK_END_F(1,(ANSI_C8(FG,RED,H),ANSI_UNDERLINE),"%s","this task take :")
*/
#ifdef __DEBUG__
#define RECORD_BLOCK_HEAD(IDX)                          __STATIC_TIME_POINT(__TIME_START_##IDX);                        \
                                                        __TIME_START_##IDX = __TIME_GET_NOW;                            \
                                                        static long __TIME_DURATION_##IDX = 0;                          \
                                                        static long __TIME_TIMES_##IDX = 0;                             \

#define RECORD_BLOCK_END(IDX, INFO,...)                 __STATIC_TIME_POINT(__TIME_END_##IDX);                          \
                                                        __TIME_END_##IDX = __TIME_GET_NOW;                              \
                                                        __TIME_DURATION_##IDX += TIME_COST_MS(__TIME_END_##IDX,         \
                                                                                              __TIME_START_##IDX)*10;   \
                                                        __TIME_TIMES_##IDX+=1;                                          \
                                                        printf(ANSI_CLEAR_LINE_BEHIND                                   \
                                                            "%s%10s(\e[38;2;%d;%d;%dm%06.1fms%s)%s" INFO,                    \
                                                            ANSI_C8(FG,WHITE) ,                                         \
                                                            #IDX,                                                       \
                                                            (int)(RECORD_BLOCK_AVRG_TIME(IDX)>122?                      \
                                                            255:RECORD_BLOCK_AVRG_TIME(IDX)*2),                         \
                                                            (int)(RECORD_BLOCK_AVRG_TIME(IDX)>255?                      \
                                                            0:255-RECORD_BLOCK_AVRG_TIME(IDX)),                         \
                                                            0,                                                          \
                                                            (float)RECORD_BLOCK_AVRG_TIME(IDX),                         \
                                                            ANSI_C8(FG,WHITE),                                          \
                                                            ANSI_NONE,##__VA_ARGS__);

#else
#define RECORD_BLOCK_HEAD(IDX)
#define RECORD_BLOCK_END(IDX,INFO)
#define RECORD_BLOCK_END_F(IDX, CFG, s, ...)
#endif

#endif //BASE_UTILS_UTILS_H
