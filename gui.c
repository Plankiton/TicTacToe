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

int main(int argc, char *argv[])
{

    gtk_init(&argc, &argv);
    GtkWidget * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    TicTacToe board;

    GtkWidget * layout = createBoardGui(&board);

    g_signal_connect(window, "delete_event",
             G_CALLBACK(gtk_main_quit), NULL);
    gtk_container_add(GTK_CONTAINER(window), layout);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
