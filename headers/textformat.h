#ifndef TEXTFORMAT_H
#define TEXTFORMAT_H

#ifdef __linux__
    //TEXT ATTRIBUTES
    #define TEXT_DEFAULT             "\x1b[0m"         //All attributes off(color at startup)
    #define TEXT_BOLD                "\x1b[1m"         //Bold on(enable foreground intensity)
    #define TEXT_UNDERLINE           "\x1b[4m"         //Underline on
    #define TEXT_BLINK               "\x1b[5m"         //Blink on(enable background intensity)
    #define TEXT_BOLD_OFF            "\x1b[21m"        //Bold off(disable foreground intensity)
    #define TEXT_UNDERLINE_OFF       "\x1b[24m"        //Underline off
    #define TEXT_BLINK_OFF           "\x1b[25m"        //Blink off(disable background intensity)
    //FOREGROUND COLOR
    #define TEXT_COLOR_FG_BLACK      "\x1b[30m" 	   //Black
    #define TEXT_COLOR_FG_RED        "\x1b[31m" 	   //Red
    #define TEXT_COLOR_FG_GREEN      "\x1b[32m" 	   //Green
    #define TEXT_COLOR_FG_YELLOW     "\x1b[33m" 	   //Yellow
    #define TEXT_COLOR_FG_BLUE       "\x1b[34m" 	   //Blue
    #define TEXT_COLOR_FG_MAGENTA    "\x1b[35m" 	   //Magenta
    #define TEXT_COLOR_FG_CYAN       "\x1b[36m" 	   //Cyan
    #define TEXT_COLOR_FG_WHITE      "\x1b[37m" 	   //White
    #define TEXT_COLOR_FG_DEFAULT    "\x1b[39m" 	   //Default(foreground color at startup)
    #define TEXT_COLOR_FG_LGRAY      "\x1b[90m" 	   //Light Gray
    #define TEXT_COLOR_FG_LRED       "\x1b[91m" 	   //Light Red
    #define TEXT_COLOR_FG_LGREEN     "\x1b[92m" 	   //Light Green
    #define TEXT_COLOR_FG_LYELLOW    "\x1b[93m" 	   //Light Yellow
    #define TEXT_COLOR_FG_LBLUE      "\x1b[94m" 	   //Light Blue
    #define TEXT_COLOR_FG_LMAGENTA   "\x1b[95m" 	   //Light Magenta
    #define TEXT_COLOR_FG_LCYAN      "\x1b[96m" 	   //Light Cyan
    #define TEXT_COLOR_FG_LWHITE     "\x1b[97m" 	   //Light White
    //BACKGROUND COLOR
    #define TEXT_COLOR_BG_BLACK      "\x1b[40m"        //Black
    #define TEXT_COLOR_BG_RED        "\x1b[41m"        //Red
    #define TEXT_COLOR_BG_GREEN      "\x1b[42m"        //Green
    #define TEXT_COLOR_BG_YELLOW     "\x1b[43m"        //Yellow
    #define TEXT_COLOR_BG_BLUE       "\x1b[44m"        //Blue
    #define TEXT_COLOR_BG_MAGENTA    "\x1b[45m"        //Magenta
    #define TEXT_COLOR_BG_CYAN       "\x1b[46m"        //Cyan
    #define TEXT_COLOR_BG_WHITE      "\x1b[47m"        //White
    #define TEXT_COLOR_BG_DEFAULT    "\x1b[49m"        //Default(background color at startup)
    #define TEXT_COLOR_BG_LGRAY      "\x1b[100m"       //Light Gray
    #define TEXT_COLOR_BG_LRED       "\x1b[101m"       //Light Red
    #define TEXT_COLOR_BG_LGREEN     "\x1b[102m"       //Light Green
    #define TEXT_COLOR_BG_LYELLOW    "\x1b[103m"       //Light Yellow
    #define TEXT_COLOR_BG_LBLUE      "\x1b[104m"       //Light Blue
    #define TEXT_COLOR_BG_LMAGENTA   "\x1b[105m"       //Light Magenta
    #define TEXT_COLOR_BG_LCYAN      "\x1b[106m"       //Light Cyan
    #define TEXT_COLOR_BG_LWHITE     "\x1b[107m"       //Light White

#elif _WIN32
     //TEXT ATTRIBUTES
    #define TEXT_DEFAULT             ""                //All attributes off(color at startup)
    #define TEXT_BOLD                ""                //Bold on(enable foreground intensity)
    #define TEXT_UNDERLINE           ""                //Underline on
    #define TEXT_BLINK               ""                //Blink on(enable background intensity)
    #define TEXT_BOLD_OFF            ""                //Bold off(disable foreground intensity)
    #define TEXT_UNDERLINE_OFF       ""                //Underline off
    #define TEXT_BLINK_OFF           ""                //Blink off(disable background intensity)
    //FOREGROUND COLOR
    #define TEXT_COLOR_FG_BLACK      ""          	   //Black
    #define TEXT_COLOR_FG_RED        ""          	   //Red
    #define TEXT_COLOR_FG_GREEN      ""          	   //Green
    #define TEXT_COLOR_FG_YELLOW     ""          	   //Yellow
    #define TEXT_COLOR_FG_BLUE       ""          	   //Blue
    #define TEXT_COLOR_FG_MAGENTA    ""          	   //Magenta
    #define TEXT_COLOR_FG_CYAN       ""          	   //Cyan
    #define TEXT_COLOR_FG_WHITE      ""          	   //White
    #define TEXT_COLOR_FG_DEFAULT    ""          	   //Default(foreground color at startup)
    #define TEXT_COLOR_FG_LGRAY      ""          	   //Light Gray
    #define TEXT_COLOR_FG_LRED       ""          	   //Light Red
    #define TEXT_COLOR_FG_LGREEN     ""          	   //Light Green
    #define TEXT_COLOR_FG_LYELLOW    ""          	   //Light Yellow
    #define TEXT_COLOR_FG_LBLUE      ""          	   //Light Blue
    #define TEXT_COLOR_FG_LMAGENTA   ""          	   //Light Magenta
    #define TEXT_COLOR_FG_LCYAN      ""          	   //Light Cyan
    #define TEXT_COLOR_FG_LWHITE     ""          	   //Light White
    //BACKGROUND COLOR
    #define TEXT_COLOR_BG_BLACK      ""                //Black
    #define TEXT_COLOR_BG_RED        ""                //Red
    #define TEXT_COLOR_BG_GREEN      ""                //Green
    #define TEXT_COLOR_BG_YELLOW     ""                //Yellow
    #define TEXT_COLOR_BG_BLUE       ""                //Blue
    #define TEXT_COLOR_BG_MAGENTA    ""                //Magenta
    #define TEXT_COLOR_BG_CYAN       ""                //Cyan
    #define TEXT_COLOR_BG_WHITE      ""                //White
    #define TEXT_COLOR_BG_DEFAULT    ""                //Default(background color at startup)
    #define TEXT_COLOR_BG_LGRAY      ""                //Light Gray
    #define TEXT_COLOR_BG_LRED       ""                //Light Red
    #define TEXT_COLOR_BG_LGREEN     ""                //Light Green
    #define TEXT_COLOR_BG_LYELLOW    ""                //Light Yellow
    #define TEXT_COLOR_BG_LBLUE      ""                //Light Blue
    #define TEXT_COLOR_BG_LMAGENTA   ""                //Light Magenta
    #define TEXT_COLOR_BG_LCYAN      ""                //Light Cyan
    #define TEXT_COLOR_BG_LWHITE     ""                //Light White
#endif

#endif /* TEXTFORMAT_H */