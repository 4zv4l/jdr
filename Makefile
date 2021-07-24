dep = f.c stats.c save.c
f = bin/

all: clean dir win lin

main: dir win
	@echo Building...
	cc -o bin/jdr.linux main.c $(dep)
	@echo Done!

dir:
	@mkdir $(f)
	@echo folder made

lin: dir
	gcc -o bin/jdr.linux main.c $(dep)

win: dir
	i686-w64-mingw32-gcc -o bin/jdr.exe main.c $(dep)

debug: dir obj
	@echo Building...
	cc -o bin/jdr.linux -g main.c obj/*
	@echo Done!

clean:
	rm -rf $(f) a.out
	@echo project cleaned
