all: calc03

calc03: calc.c
	gcc -Wall -lm calc.c -o calc03
