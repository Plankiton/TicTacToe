#include <ui.h>
#define __GUI_APP
#include <tictactoe.h>
#include <string.h>
#include "nothing.c"

uiInitOptions o;
Board board;
uiWindow *win;
uiAttributedString * text;


void onWin(GameType winner);
uiAreaHandler * creatArea(void);
void onClick(uiButton* button, void* data);
static int onClosing(uiWindow *w, void *data);
int main(void)
{
    const char *err;
    memset(&o, 0, sizeof (uiInitOptions));
    err = uiInit(&o);
    if (err != NULL) {
        fprintf(stderr, "error initializing ui: %s\n", err);
        uiFreeInitError(err);
        return 1;
    }

    board = board_create();
    Box ** boxes = board.boxes;

    win = uiNewWindow("Jogo da Velha", 400, 400, 1);
    uiWindowOnClosing(win, onClosing, NULL);
    uiControlShow(uiControl(win));

    uiBox* vbox = uiNewVerticalBox();
    uiWindowSetChild(win, uiControl(vbox));

    uiBox** hbox = (uiBox *[]){
        uiNewHorizontalBox(),
        uiNewHorizontalBox(),
        uiNewHorizontalBox()
    };

    for (int r = 0; r<3; r++){
        uiBoxAppend(vbox, uiControl(hbox[r]), 1);
        for (int c = 0; c<3; c++){
            uiBoxAppend(hbox[r], uiControl(boxes[r][c].button), 1);

            for (int i = 0; i < 6; i++)
                uiBoxAppend(hbox[r], uiControl(uiNewVerticalSeparator()), 0);


            uiButtonOnClicked(boxes[r][c].button, onClick, &boxes[r][c]);
        }
        for (int i = 0; i < 6; i++)
            uiBoxAppend(vbox, uiControl(uiNewHorizontalSeparator()), 0);
    }

    uiMain();
    return 0;
}

static int onClosing(uiWindow *w, void *data)
{
    uiControlDestroy(uiControl(win));
    uiQuit();
    return 0;
}

static void handlerDraw(uiAreaHandler *a, uiArea *area, uiAreaDrawParams *p)
{
    uiDrawTextLayout *textLayout;
    uiDrawTextLayoutParams params;

    params.String = text;
    params.DefaultFont = &(uiFontDescriptor){
        .Family = "Sans",
        .Size = 20,
        .Weight = 600,
        .Italic = 0,
        .Stretch = 1
    };
    params.Width = p->AreaWidth;
    params.Align = uiDrawTextAlignCenter;
    textLayout = uiDrawNewTextLayout(&params);
    uiDrawText(p->Context, textLayout, 0, 0);
    uiDrawFreeTextLayout(textLayout);
}

uiAreaHandler * creatArea(void)
{
    uiAreaHandler * area = malloc(sizeof (uiAreaHandler));

    area->Draw = handlerDraw;
    area->MouseEvent = handlerMouseEvent;
    area->MouseCrossed = handlerMouseCrossed;
    area->DragBroken = handlerDragBroken;
    area->KeyEvent = handlerKeyEvent;
    return area;
}

void onWin(GameType winner)
{
    uiBox * box = uiNewHorizontalBox();
    uiWindowSetChild(win, uiControl(box));
    //
    // N is the winner
    char raw_text [] = "N is the winner!!";
    raw_text[0] = (char)winner;
    text = uiNewAttributedString(raw_text);

    //uiLabel * label = uiNewLabel(text);
    uiArea * label = uiNewArea(creatArea());
    uiBoxAppend(box, uiControl(label), 1);
}

void onClick(uiButton* button, void* data)
{
    Box * box = data;
    GameType symbol = box_play(&board, box);
    if (symbol != N)
        uiButtonSetText(button, (char []){symbol, 0});
    GameType winner = board_check(board);
    if (winner != N)
        onWin(winner);
}

