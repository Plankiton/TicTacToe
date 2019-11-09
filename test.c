#include "gui/gui.c"

int main(int argc, char *argv[])
{

    ArgData args[3][3];

    TicTacToe ttt;
    Boxes * boxes = getBoxes(&ttt);
    Board * board =  getBoard(&ttt);
    int playRound = 0;

    initGUI();

    GtkWidget * container = createBoardGui(&ttt);
    GtkWidget * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    setButtonsSettings(args, boxes, board, playRound);

    endGUI(container, window);

    return 0;
}
