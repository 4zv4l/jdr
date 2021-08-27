dep = f.c stats.c save.c
f = bin/

all: clean dir win lin

main: dir win
	@echo Building...
	cc -o bin/jdr.linux main.c $(dep)
	@echo Done!

dir:
	mkdir -p $(f)
	@echo folder made

lin: dir
	gcc -o bin/jdr.linux main.c $(dep)
	@echo "-> jdr.linux is ready! waiting for you in bin/jdr.linux"

win: dir
	i686-w64-mingw32-gcc -o bin/jdr.exe main.c $(dep)
	@echo "-> jdr.exe is ready! waiting for you in bin/jdr.exe"

debug: dir
	@echo Building...
	gcc -o bin/jdr.linux -g main.c $(dep)
	@echo Done!

clean:
	rm -rf $(f)
	@echo "-> project cleaned"
