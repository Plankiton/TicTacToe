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
