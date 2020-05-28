#include <tictactoe.h>
#include <stdio.h>

int clear(void){
    return system(CLEAR_CMD);
}

Position player_get_input(char * message, ...){
    int line = 0, column = 0;
    char input[3];

    va_list vars;
    va_start(vars, message);

    vprintf(message, vars);
    gets(input);

    if (isalpha(input[0])){
        line = get_line_from_letter(tolower(input[0]));
        if (isdigit(input[1]))
            column = atoi((char []){input[1], 0})-1;
    } else {
        if (isdigit(input[0]))
            column = atoi((char []){input[0], 0})-1;
        line = get_line_from_letter(tolower(input[1]));
    }

    va_end(vars);
    return (Position) {
        .line = line,
        .column = column
    };
}

GameType box_play(Board * board, Box * box){
    if (box->value == N){
        GameType symbol = ( (int)++board->all_plays % 2 ? X : O );
        box->value = symbol;
        return symbol;
    }
    return N;
}

GameType board_play(Board * board, const Position location){
    int line = location.line;
    int column = location.column;

    if ((line >= 0 && line < 3) && (column >= 0 && column < 3))
        return box_play(board, &board->boxes[line][column]);
    return N;
}

GameType board_check(const Board board){
    GameType symbol[] = {O, X};
    for (int i = 0; i < 2; i++){
        GameType sym = symbol[i];

        int md_possible = 0, sd_possible = 0;

        for (int l = 0; l < 3; l ++){
            if (board.boxes[l][0].value == sym &&
                    board.boxes[l][1].value == sym &&
                    board.boxes[l][2].value == sym) return sym;

            for (int c = 0; c < 3; c ++){

                if (board.boxes[0][c].value == sym &&
                        board.boxes[1][c].value == sym &&
                        board.boxes[2][c].value == sym) return sym;

                if (l == c )            // Main diagonal
                    if (board.boxes[l][c].value == sym) md_possible++;
                if ( l+c == 2 )  // Secondary diagonal
                    if (board.boxes[l][c].value == sym) sd_possible++;
            }
        }

        if (md_possible == 3 || sd_possible == 3)
            return sym;
    }

    return N;
}

int get_line_from_letter(char letter){
    switch (letter){
        case 'a':
            return 0;
            break;
        case 'b':
            return 1;
            break;
        case 'c':
            return 2;
            break;
        default:
            return 4;
            break;
    }
}

void board_print(const Board tabuleiro){

    clear();
    printf("    1   2   3\n");
    char line = 'A';
    for (int l = 0; l < 3; l ++){
        printf("%c  ", line++);
        for (int c = 0; c < 3; c ++){
            char box = tabuleiro.boxes[l][c].value;

            if (c < 2)
                printf(" %c |", box);
            else
                printf(" %c\n", box);
        }

        if (l < 2)
            printf("   -----------\n");
    }
}
