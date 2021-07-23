dep = f.c stats.c save.c
f = bin/

all: clean dir win lin

main: dir win
	@echo Building...
	cc -o bin/jdr.linux main.c $(dep)
	@echo Done!

lin:
	gcc -o bin/jdr.linux main.c $(dep)

dir:
	@mkdir $(f)
	@echo folder made

debug: dir obj
	@echo Building...
	cc -o bin/jdr.linux -g main.c obj/*
	@echo Done!

win: dir
	i686-w64-mingw32-gcc -o bin/jdr.exe main.c $(dep)

clean:
	rm -rf $(f) a.out
	@echo project cleaned
