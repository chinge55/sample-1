
all:
		bison -d sample.y
		flex sample.l
		gcc sample.tab.c lex.yy.c samplefunc.c