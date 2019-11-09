#include <stdio.h>
#include "board.h"

int main(int argc, char *argv[])
{
    Board tabuleiro;initBoard(&tabuleiro);
    printBoard(tabuleiro);

    setPosition(&tabuleiro, 0, 2, X);

    putchar(getPosition(tabuleiro, 0, 2, CONVERT));
    puts("");
    clearBoard(&tabuleiro);
    return 0;
}
