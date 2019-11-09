#include "gui/gui.c"

void doWin(Position winner){
    putchar(winner?'X':'O');
    puts(" é o vencedor!");
}

int main(int argc, char *argv[])
{

    int playRound = 0;
    ArgData args[3][3];

    TicTacToe ttt;
    Boxes * boxes = getBoxes(&ttt);
    Board * board =  getBoard(&ttt);
    board->whenWin = doWin;

    initBoard(board);
    initGUI();

    GtkWidget * container = createBoardGui(&ttt);
    GtkWidget * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    setButtonsSettings(args, boxes);

    endGUI(container, window);

    return 0;
}
