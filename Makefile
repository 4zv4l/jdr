dep = f.c stats.c save.c
ob = f.o stats.o save.o
f = obj/

all: obj main

main:
	@echo Building...
	cc main.c obj/*
	@echo Done!

obj:
	cc -c $(dep)
	mkdir $(f)
	mv *.o $(f)
	@echo object file ready!

debug: obj
	@echo Building...
	cc -g main.c obj/*
	@echo Done!

clean:
	rm -rf $(f) a.out
	@echo project cleaned
