/*
Vincent Latona
Question 1 - Sort
*/
/* Stopping condition and return */
qsort2([], []) :-
	!.
/* Special single case */
qsort2([Single], [Single]).
/* Size-n problem */
qsort2([First | [Pivot | Rest]], Sorted) :-
	split(Pivot, [First | Rest], L, R),
	/* Size-m problems */
	qsort2(L, SortedL),
	qsort2(R, SortedR),
	/* Size-n solution from size-m solutions */
	append(SortedL, [Pivot | SortedR], Sorted).
/* Stopping condition and return */
split(_, [], [], []).
/* Size-n problem and solution from size-m solution */
split(Pivot, [First | Rest], [First | L], R) :-
	First =< Pivot,
	/* Size-m problem */
	split(Pivot, Rest, L, R).
/* Size-n problem and solution from size-m solution */
split(Pivot, [First | Rest], L, [First | R]) :-
	First > Pivot,
	/* Size-m problem */
	split(Pivot, Rest, L, R).