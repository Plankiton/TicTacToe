#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

#if defined(_WIN32)||defined(WIN32)
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif

#if !defined(__GUI_APP)
#define board_create() (Board){ \
    .all_plays = (int)0,\
    .boxes = (Box *[]){\
        (Box []){\
            (Box){NULL, N},\
            (Box){NULL, N},\
            (Box){NULL, N}\
        },\
        (Box []){\
            (Box){NULL, N},\
            (Box){NULL, N},\
            (Box){NULL, N}\
        },\
        (Box []){\
            (Box){NULL, N},\
            (Box){NULL, N},\
            (Box){NULL, N}\
        }\
    }\
}
#else
#define board_create() (Board){ \
    .all_plays = 0,\
    .boxes = (Box *[]){\
        (Box []){\
            (Box){uiNewButton(""), N},\
            (Box){uiNewButton(""), N},\
            (Box){uiNewButton(""), N}\
        },\
        (Box []){\
            (Box){uiNewButton(""), N},\
            (Box){uiNewButton(""), N},\
            (Box){uiNewButton(""), N}\
        },\
        (Box []){\
            (Box){uiNewButton(""), N},\
            (Box){uiNewButton(""), N},\
            (Box){uiNewButton(""), N}\
        }\
    }\
}
#endif

typedef enum {
    X = 'X',
    O = 'O',
    N = ' '
} GameType;

typedef struct {
    int line;
    int column;
} Position;

typedef struct uiButton uiButton;
typedef struct {
    uiButton * button;
    GameType value;
} Box;

typedef struct {
    Box **boxes;
    int all_plays;
} Board;

typedef struct {
    GameType symbol;
    int plays;
} Player;

// Generic functions
int get_line_from_letter(char letter);

// Board functions
void board_print(const Board tabuleiro);
GameType board_play(Board * board, const Position location);
GameType box_play(Board * board, Box * box);
GameType board_check(const Board board);

// Player functions
Position player_get_input(char * message, ...);
