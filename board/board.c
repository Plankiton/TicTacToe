#include "board.h"

int setPosition( Board * board, int _i, int _j, Position _val ){
    board->position[_i][_j] = _val;
    return 1;
}

int getPosition( Board board, int _i, int _j, ...){
    va_list arg;va_start( arg, _j );
    char *isToConvert = va_arg  ( arg, char *);
    va_end  ( arg     );

    if (isToConvert[0]!='!'){
        isToConvert[1] = 1;
    }

    return isToConvert[1]?(
                board.position[_i][_j]==N?' ':
                    (board.position[_i][_j]?'X':'O')
            ):board.position[_i][_j];
}

int isWinner( Board board, Position _player){

    int i, j, mainDiagonal = 0, secondDiagonal = 0;
    for (i = 0; i<3; i++){
        for (j = 0; j<3; j++){

            if (board.position[i][0] == _player && board.position[i][1] == _player && board.position[i][2] == _player )
                return 1;

            if (board.position[0][j] == _player && board.position[1][j] == _player && board.position[2][j] == _player )
                return 1;

            if (j==i && board.position[i][j] == _player)
                mainDiagonal ++;

            if (j==2-i && board.position[i][j] == _player)
                secondDiagonal ++;
        }
    }

    if (mainDiagonal == 3 || secondDiagonal == 3){
        return 1;
    }

    return 0;
}

int initBoard(Board * nullBoard){

    int i, j;
    for (i = 0; i<3; i++)
        for (j = 0; j<3; j++){
            nullBoard->position[i][j] = N;
        }

    return 1;
}

int printBoard(Board board){

    int i, j;
    for (i = 0; i<3; i++){
        for (j = 0; j<3; j++){

            putchar(' ');
            putchar(board.position[i][j]==N?' ':
                    (board.position[i][j]?'X':'O'));
            putchar(' ');
            if (j < 2) putchar('|');
            else putchar('\n');

        }
    }

    return 1;
}
