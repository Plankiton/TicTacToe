#include "gui/gui.c"

void doWin(Position winner){
    gtk_main_quit();
}

int main(int argc, char *argv[])
{

    ArgData args[3][3];

    TicTacToe ttt;
    Boxes * boxes = getBoxes(&ttt);
    Board * board =  getBoard(&ttt);
    board->whenWin = doWin;
    initBoard(board);

    int playRound = 0;

    initGUI();

    GtkWidget * container = createBoardGui(&ttt);
    GtkWidget * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    setButtonsSettings(args, boxes, board, playRound);

    endGUI(container, window);

    return 0;
}
