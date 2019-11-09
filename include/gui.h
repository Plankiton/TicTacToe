#include <gtk/gtk.h>
#include "../board/board.c"

typedef struct {
    int id;
    GtkWidget * obj;
} Object;

typedef struct {
    Object button[3][3];
    Object container[3];
} Boxes;

typedef struct {
    Board board;
    Boxes boxes;
} TicTacToe;
