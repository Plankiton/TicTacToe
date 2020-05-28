CFLAGS=-L./lib -I./include
LIBS=-lui -ltictactoe
CC=cc

libtictactoe:
	${CC} -fPIC -shared lib/tictactoe.c -o lib/libtictactoe.so ${CFLAGS}

tictactoe: libtictactoe
	${CC} tictactoe_gui.c -o tictactoe_gui ${CFLAGS} ${LIBS}
	${CC} tictactoe_cli.c -o tictactoe_cli ${CFLAGS} ${LIBS}
