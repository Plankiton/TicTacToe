#include <gtk/gtk.h>
#include "gui.h"

GtkWidget * createBoardGui(TicTacToe * board){

    GtkWidget * layout =  gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    // Creating the widgets
    for (int c = 0; c<3; c++){
        board->boxes.container[c] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        gtk_box_pack_start(GTK_BOX(layout), board->boxes.container[c], TRUE, TRUE, 3);

        for (int b = 0; b<3; b++){
            board->boxes.button[c][b] = gtk_button_new_with_label(" ");
            gtk_box_pack_start(GTK_BOX(board->boxes.container[c]), board->boxes.button[c][b],
                    TRUE, TRUE, 3);
        }
    }

    return layout;
}

void setBoxButtonEvent(GtkWidget * widget, void (*call_function)(GtkWidget *,ArgData *), ...){
    va_list args;
    va_start(args, call_function);
    g_signal_connect(widget, "clicked", G_CALLBACK(call_function), va_arg(args, ArgData *));
    va_end(args);
}

Boxes * getBoxes (TicTacToe * board){
    return &board->boxes;
}

Board * getBoard (TicTacToe * board){
    return &board->board;
}

void play(GtkWidget * button, ArgData * a){
    printf("%i, %i\n", a->c, a->b);
}

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
    setButtonsSettings(args, play, boxes);

    endGUI(board, container, window);

    return 0;
}
