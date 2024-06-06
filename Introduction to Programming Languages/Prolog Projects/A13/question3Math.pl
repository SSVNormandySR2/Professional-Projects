/*
Vincent Latona
Question 3 - Math
*/
/* Return for stopping condition 1 */
foo(X, Y, X) :-
	/* Stopping condition 1 */
	Y =< 0, !.
/* Return for stopping condition 2 */
foo(X, Y, Y) :-
	/* Stopping condition 2 */
	X =< 0, !.
/* Size-n problem */
foo(X, Y, Z) :-
	X >= Y,
	NewX is X - 2,
	/* Size-m problem */
	foo(NewX, Y, Result),
	/* Size-n solution from size-m solution */
	Z is X + Result.
/* Size-n problem */
foo(X, Y, Z) :-
	X < Y,
	NewY is Y - 3,
	/* Size-m problem */
	foo(X, NewY, Result),
	/* Size-n solution from size-m solution */
	Z is Y + Result.