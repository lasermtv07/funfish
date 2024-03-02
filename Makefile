main:
	gcc src/main.c -o main

clean:
	rm -f main

recompile: clean main

.PHONY: clean recompile
