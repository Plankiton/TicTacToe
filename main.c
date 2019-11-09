#include "gui/gui.c"

void doWin(Position winner){
    putchar(winner?'X':'O');
    puts(" é o vencedor!");
}

int main(int argc, char *argv[])
{

    int playRound = 0;
    ArgData args[3][3];

    TicTacToe tictactoe[3][3];
    Board * boards[3][3];
    Boxes * boxes[3][3];

    initGUI();

    GtkWidget * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget * container[3][3];
    GtkWidget * root_container;
    GtkWidget * hcontainer[3];

    root_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    for (int c = 0; c<3; c++){
        hcontainer[c] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
        gtk_box_pack_start(GTK_BOX(root_container), hcontainer[c], TRUE, TRUE, 0);
        for (int b = 0; b<3; b++){
            container[c][b] = createBoardGui(&tictactoe[c][b]);
            gtk_box_pack_start(GTK_BOX(hcontainer[c]), container[c][b], TRUE, TRUE, 10);

            boxes[c][b] = getBoxes(&tictactoe[c][b]);
            boards[c][b] = getBoard(&tictactoe[c][b]);
            setButtonsSettings(args, boxes[c][b], boards[c][b], playRound);
        }
    }

    endGUI(root_container, window);
    return 0;
}
