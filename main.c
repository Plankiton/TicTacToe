#include "gui/gui.c"

void doWin(Position player){
    putchar(player?'X':'O');
    puts(" is the winner!!");

    char * winner = player?"X is the winner!!":"O is the winner!!";

    GtkWidget * win_popup = gtk_window_new(GTK_WINDOW_POPUP);

    GtkWidget * box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_size_request(box, 300, 100);

    GtkWidget * label = gtk_label_new(winner);
    GtkWidget * button = gtk_button_new_with_label("Quit");
    g_signal_connect(button, "clicked",
             G_CALLBACK(gtk_main_quit), NULL);

    gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);

    gtk_window_set_default_size(GTK_WINDOW(win_popup), 400, 200);
    gtk_container_add(GTK_CONTAINER(win_popup), box);
    gtk_window_set_position (GTK_WINDOW (win_popup),GTK_WIN_POS_CENTER);
    gtk_widget_show_all(win_popup);
    g_signal_connect(win_popup, "delete_event",
             G_CALLBACK(gtk_main_quit), NULL);
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
