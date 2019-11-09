#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// constants used on getPosition variadic arg
#define CONVERT "!1"
#define NOCONVERT "!\0"

typedef enum {
    X=1,
    O=0,
    x=1,
    o=0,

    n=-1,
    N=-1
} Position;

typedef struct {
    Position position [3][3];
} Board;

// clear a board preenched
#define clearBoard(Board) initBoard(Board)

// set the with the player symbol a especific position
int setPosition( Board * board, int _i, int _j, Position _val );

/* get a especific position, the "..." is a unic arg that
   assume just "CONVERT" or "NOCONVERT" */
int getPosition( Board board, int _i, int _j, ...);

// returns if the player is the winner
int isWinner( Board board, Position _player);

// inicializate one board with "white spaces"
int initBoard(Board * nullBoard);

// print on command line the board representation
int printBoard(Board board);
