#include <tictactoe.h>

int main(int argc, char *argv[])
{
    int i, interromp = 0;

    Board tabuleiro = board_create();
    GameType winner, player [] = {X, O};


    do {
        i = 0;
        do {
            board_print(tabuleiro);
            if (board_play(&tabuleiro,
                        player_get_input("É a vez do \"%c\": ",
                            player[i%2])))
                i ++;

            winner = board_check(tabuleiro);
            if (winner != N){
                interromp = 1;
            }

        } while(!interromp);
    } while (tabuleiro.all_plays<9 && !interromp);

    board_print(tabuleiro);
    printf("\nwinner: %c\n", winner);
    return 0;
}
