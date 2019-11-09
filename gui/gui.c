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
    Position local_played = getPosition(* a->board, a->c, a->b, NOCONVERT);

    Position player = *a->playRound%2?X:O;
    if (local_played == N){
        setPosition(a->board, a->c, a->b, player);
        printBoard(*a->board);
        g_print("\n");
        *a->playRound += 1;

        gtk_button_set_label(GTK_BUTTON(button), player?"X":"O");
        if (isWinner(*a->board, player))
            a->board->whenWin(player);
    }
}
