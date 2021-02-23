//
// Created by ou on 2021/2/10.
//

#ifndef BASE_UTILS_ANSI_CODES_H
#define BASE_UTILS_ANSI_CODES_H

//////////////////////////////////////////////////////////////////
/*
ANSI控制码格式：
            \e[显示方式;前景色;背景色 m "输出字符串" \033[0m  、
            也可进行连续设置如下划线蓝色\e[4m\e[34m

    显示：
            0 (关闭属性)、8(消隐)
            1(粗体高亮)、22(非粗体)、
            4(单条下划线)、24(无下划线)、
            5(闪烁)、25(无闪烁)、
            7(反显、翻转前景色和背景色)、27(无反显)、
    颜色：
            简单:
                颜色:0(黑)、1(红)、2(绿)、 3(黄)、4(蓝)、5(洋红)、6(青)、7(白)
                前景色:
                        暗色: 30+x —— "\e[31m"  暗红
                        亮色: 90+x —— "\e[91m"  亮红
                背景色:
                        暗色: 40+x —— "\e[41m"  暗红
                        亮色:100+x —— "\e[101m" 亮红

            255色:
                x:
                16-231：6 × 6 × 6 立方（216色）: 16 + 36 × r + 6 × g + b (0 ≤ r, g, b ≤ 5)
                232-255：从黑到白的24阶灰度色
                前景色: "\e[38;5;xm"
                背景色："\e[48;5;xm"

            rgb:
                前景色："\e[38;2;<r>;<g>;<b>m"
                后景色："\e[48;2;<r>;<g>;<b>m"

*/
//////////////////////////////////////////////////////////////////
/*                        颜色码-基本                           */
#define ANSI_PRIFIX_FG                                  3
#define ANSI_PRIFIX_FGH                                 9
#define ANSI_PRIFIX_BG                                  4
#define ANSI_PRIFIX_BGH                                 10
///////////////////////
#define ANSI_SUFFIX_BLACK                               0
#define ANSI_SUFFIX_RED                                 1
#define ANSI_SUFFIX_GREEN                               2
#define ANSI_SUFFIX_YELLOW                              3
#define ANSI_SUFFIX_BLUE                                4
#define ANSI_SUFFIX_PURPLE                              5
#define ANSI_SUFFIX_CYAN                                6
#define ANSI_SUFFIX_GRAY                                7
#define ANSI_SUFFIX_WHITE                               8
///////////////////////
#define ANSI_FG_BLACK                                   "\e[30m"
#define ANSI_FG_RED                                     "\e[31m"
#define ANSI_FG_GREEN                                   "\e[32m"
#define ANSI_FG_YELLOW                                  "\e[33m"
#define ANSI_FG_BLUE                                    "\e[34m"
#define ANSI_FG_PURPLE                                  "\e[35m"
#define ANSI_FG_CYAN                                    "\e[36m"
#define ANSI_FG_GRAY                                    "\e[37m"
#define ANSI_FG_WHITE                                   "\e[38m"

#define ANSI_FG_BLACK_H                                 "\e[90m"
#define ANSI_FG_RED_H                                   "\e[91m"
#define ANSI_FG_GREEN_H                                 "\e[92m"
#define ANSI_FG_YELLOW_H                                "\e[93m"
#define ANSI_FG_BLUE_H                                  "\e[94m"
#define ANSI_FG_PURPLE_H                                "\e[95m"
#define ANSI_FG_CYAN_H                                  "\e[96m"
#define ANSI_FG_GRAY_H                                  "\e[97m"
#define ANSI_FG_WHITE_H                                 "\e[98m"

#define ANSI_BG_BLACK                                   "\e[40m"
#define ANSI_BG_RED                                     "\e[41m"
#define ANSI_BG_GREEN                                   "\e[42m"
#define ANSI_BG_YELLOW                                  "\e[43m"
#define ANSI_BG_BLUE                                    "\e[44m"
#define ANSI_BG_PURPLE                                  "\e[45m"
#define ANSI_BG_CYAN                                    "\e[46m"
#define ANSI_BG_GRAY                                    "\e[47m"
#define ANSI_BG_WHITE                                   "\e[48m"

#define ANSI_BG_BLACK_H                                 "\e[100m"
#define ANSI_BG_RED_H                                   "\e[101m"
#define ANSI_BG_GREEN_H                                 "\e[102m"
#define ANSI_BG_YELLOW_H                                "\e[103m"
#define ANSI_BG_BLUE_H                                  "\e[104m"
#define ANSI_BG_PURPLE_H                                "\e[105m"
#define ANSI_BG_CYAN_H                                  "\e[106m"
#define ANSI_BG_GRAY_H                                  "\e[107m"
#define ANSI_BG_WHITE_H                                 "\e[108m"

/*                        颜色码-255                           */
#define ANSI_FG_255(color)                              "\e[38;5;"#color"m"
#define ANSI_BG_255(color)                              "\e[48;5;"#color"m"
/*                        颜色码-rgb                           */
#define ANSI_FG_RGB(r,g,b)                              "\e[38;2;"#r";"#g";"#b"m"
#define ANSI_BG_RGB(r,g,b)                              "\e[48;2;"#r";"#g";"#b"m"

//////////////////////////////////////////////////////////////////
/*                          控制码-字体
 */
#define ANSI_NONE                                       "\e[0m"     //取消所有设置
#define ANSI_BOLD                                       "\e[1m"     //粗体
#define ANSI_WEAK                                       "\e[2m"     //弱化亮度
#define ANSI_ITALIC                                     "\e[3m"     //斜体
#define ANSI_UNDERLINE                                  "\e[4m"     //下划线
#define ANSI_UNDERLINE_MID                              "\e[9m"     //中划线
#define ANSI_UNDERLINE_TOP                              "\e[53m"    //上划线
#define ANSI_BLINK                                      "\e[5m"     //闪烁
#define ANSI_BLINK_FAST                                 "\e[6m"     //快速闪烁(未广泛支持)
#define ANSI_REVERSE                                    "\e[7m"     //反显
#define ANSI_HIDE                                       "\e[8m"     //隐藏文字


#define ANSI_FONT_NOMAL                                 "\e[10m"    //正常字体(未广泛支持)
#define ANSI_FONT_SONG                                  "\e[11m"    //宋体(未广泛支持)
#define ANSI_FONT_BLACK                                 "\e[12m"    //黑体(未广泛支持)
#define ANSI_FONT_KAI                                   "\e[15m"    //楷体(未广泛支持)


/*                          控制码-删除
 */
#define ANSI_CLEAR_SCREEN                               "\e[2J"     //清屏且光标回到左上角
#define ANSI_CLEAR_SCREEN_BEHIND                        "\e[0J"     //清除光标到屏幕末尾
#define ANSI_CLEAR_SCREEN_AHEAD                         "\e[1J"     //清除光标到屏幕开头
#define ANSI_CLEAR_SCREEN_AND_BUFFER                    "\e[3J"     //清屏和回滚区

#define ANSI_CLEAR_LINE                                 "\r\e[K"    //清除整行光标回到开头
#define ANSI_CLEAR_LINE_WHOLD                           "\e[2K"     //清除整行,光标不变
#define ANSI_CLEAR_LINE_BEHIND                          "\e[0K"     //清除行中光标之后的,光标不变
#define ANSI_CLEAR_LINE_AHEAD                           "\e[1K"     //清除行中光标之前的,光标不变

/*                          控制码-光标
 */
#define ANSI_CURSOR_SAVE                                "\e[s"
#define ANSI_CURSOR_LOAD                                "\e[u"
#define ANSI_CURSOR_HIDE                                "\e[?25l"
#define ANSI_CURSOR_SHOW                                "\e[?25h"
#define ANSI_CURSOR_MOVE(_Y_, _X_)                      "\e[" #_Y_ ";" #_X_ "H"

#define ANSI_SCROLL_UP(N)                               "\e[NS"     //整页上滚N行，新行添加到尾部
#define ANSI_SCROLL_DOWN(N)                             "\e[NT"     //整页下滚N行，新行添加到顶部

#endif //BASE_UTILS_ANSI_CODES_H
