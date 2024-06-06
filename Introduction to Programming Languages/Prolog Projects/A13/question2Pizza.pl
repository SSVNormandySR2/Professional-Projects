/*
Vincent Latona
Question 2 - Pizza
*/
/* 2.1 - Pizza Topping Combinator */
pizza(P, S, B, O, M) :-
	/* Possible numbers of each topping */
	member(P, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]),
	member(S, [0, 1, 2, 3, 4]),
	member(B, [0, 1, 2, 3, 4, 5, 6]),
	member(O, [0, 1, 2, 3, 4, 5, 6, 7, 8]),
	member(M, [0, 1, 2, 3, 4, 5]),
	/* Weight check */
	W is 4 * P + 10 * S + 6 * B + 5 * O + 7 * M,
	W == 40.
/* 
2.2 Answers
M = 0
O = 6
S = 0 

M = 0
O = 4
S = 1 

M = 0
O = 2
S = 2 

M = 0
O = 0
S = 3 

2.3 Answers
B = 3
O = 3
P = 0
S = 0 

B = 3
O = 1
P = 0
S = 1 

B = 4
O = 1
P = 1
S = 0 

B = 0
O = 5
P = 2
S = 0 

B = 0
O = 3
P = 2
S = 1 

B = 0
O = 1
P = 2
S = 2 

B = 1
O = 3
P = 3
S = 0 

B = 1
O = 1
P = 3
S = 1 

B = 2
O = 1
P = 4
S = 0 

B = 0
O = 1
P = 7
S = 0 
*/