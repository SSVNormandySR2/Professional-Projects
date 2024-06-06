/*
Vincent Latona
Recursion
*/
/* 3-Recursive function */
/* Rule for Recursive function foo */
/* Stopping conditions */
foo(X, Y, Z) :-
	/* First stopping condition and return */
	Y =< 0, 
	Z is X + 1,!.
foo(X, Y, Z) :-
	/* Second stopping condition and return */
	X =< 0,
	Z is Y + 1,!.
/* Recursive cases */
foo(X, Y, Z) :-
	X < Y,
	X2 is X - 2,
	/* Size-m problem and size-n solution from size-m solution */
	foo(X2, Y, RecZ),
	Z is X + 2 + RecZ.
foo(X, Y, Z) :-
	X >= Y,
	Y3 is Y - 3,
	/* Size-m problem and size-n solution from size-m solution */
	foo(X, Y3, RecZ),
	Z is Y + 3 + RecZ.