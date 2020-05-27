CFLAGS=-L./lib
LIBS=-lui -ltictactoe

libtictactoe:
	${CC} -fPIC -shared tictactoe.c -o libtictactoe.so

tictactoe:
	${CC} tictactoe.c -o tictactoe ${CFLAGS} ${LIBS}
