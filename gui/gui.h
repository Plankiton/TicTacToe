#include <gtk/gtk.h>
#include "../board/board.c"

typedef struct {
    GtkWidget * button[3][3];
    GtkWidget * container[3];
} Boxes;

typedef struct {
    Board board;
    Boxes boxes;
} TicTacToe;

typedef struct {
    int * playRound;
    Board * board;
    int c;
    int b;
} ArgData;

#define endGUI(container, window) \
    g_signal_connect(window, "delete_event",\
             G_CALLBACK(gtk_main_quit), NULL);\
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);\
    gtk_container_add(GTK_CONTAINER(window), container);\
    gtk_widget_show_all(window);\
    gtk_main()

#define initGUI() gtk_init(&argc, &argv);

#define setButtonsSettings(_args, _boxes, _board, playRound) \
    for (int c = 0; c < 3; c++) {\
        for (int b = 0; b < 3; b++) {\
            args[c][b].b = b;\
            args[c][b].c = c;\
            args[c][b].board = _board;\
            args[c][b].playRound = &playRound;\
            setBoxButtonEvent(_boxes->button[c][b], play, &_args[c][b]);\
        }\
    }


// The GUI functions
GtkWidget * createBoardGui(TicTacToe * board);
void setBoxButtonEvent(GtkWidget * widget, void (*call_function)(GtkWidget *,ArgData *), ...);

// The manipulator functions
Boxes * getBoxes (TicTacToe * board);
Board * getBoard (TicTacToe * board);
