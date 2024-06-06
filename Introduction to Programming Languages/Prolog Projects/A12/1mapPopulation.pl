/* 
Vincent Latona
Map and Populations 
*/
/* 1.1-Node facts */
/* AZ Connections */
edge(arizona, california).
edge(arizona, nevada).
edge(arizona, utah).
edge(arizona, colorado).
edge(arizona, newMexico).
/* CA Connections */
edge(california, nevada).
edge(california, oregon).
/* OR Connections */
edge(oregon, washington).
edge(oregon, nevada).
edge(oregon, idaho).
/* WA Connection */
edge(washington, idaho).
/* ID Connections */
edge(idaho, nevada).
edge(idaho, utah).
edge(idaho, montana).
edge(idaho, wyoming).
/* NV Connection */
edge(nevada, utah).
/* UT Connections */
edge(utah, wyoming).
edge(utah, colorado).
edge(utah, newMexico).
/* NM Connection*/
edge(newMexico, colorado).
/* CO Connections */
edge(colorado, wyoming).
edge(colorado, nebraska).
edge(colorado, kansas).
/* WY Connections */
edge(wyoming, montana).
edge(wyoming, southDakota).
edge(wyoming, nebraska).
/* MT Connections */
edge(montana, northDakota).
edge(montana, southDakota).
/* ND Connection */
edge(northDakota, southDakota).
/* SD Connection */
edge(southDakota, nebraska).
/* NB Connection */
edge(nebraska, kansas).
/* 1.2-Color facts */
/* Red States */
color(wyoming, red).
color(northDakota, red).
color(kansas, red).
color(newMexico, red).
color(nevada, red).
color(washington, red).
/* Blue States */
color(southDakota, blue).
color(colorado, blue).
color(idaho, blue).
color(california, blue).
/* Green States - UT and AZ will conflict */
color(montana, green).
color(nebraska, green).
color(oregon, green).
color(arizona, green).
color(utah, green).
/* 1.3-Population facts */
population(california, 40).
population(oregon, 4).
population(washington, 8).
population(arizona, 8).
population(nevada, 3).
population(utah, 3).
population(idaho, 2).
population(newMexico, 2).
population(colorado, 6).
population(wyoming, 1).
population(montana, 1).
population(kansas, 3).
population(nebraska, 2).
population(southDakota, 1).
population(northDakota, 1).
/* 1.4-Miscolor detector */
/* Rule for identifying neighboring states */
adjacent(S1, S2) :-
	edge(S1, S2); edge(S2, S1).
/* Rule for identifying color errors */
miscolor(S1, S2, Color) :-
	adjacent(S1, S2), color(S1, Color), color(S2, Color).
/* 1.5-Total population calculator */
/* Recursive rule for calculating the total population of a list of states */
/*Stopping condition */
totalpopulation([], 0) :- !.
totalpopulation([[_ | Pop] | Tail], Total) :-
	/* Recursive call */
	totalpopulation(Tail, RunningTotal), 
	/* Final calculation */
	Total is Pop + RunningTotal.
/* Test case */
q1 :- miscolor(S1, S2, Color), write(S1), write(' and '), write(S2), write(' have conflict color: '), write(Color), nl,
	totalpopulation([[california, 40], [oregon, 4], [washington, 8], [arizona, 8], [nevada, 3], 
	[utah, 3], [idaho, 2], [newMexico, 2], [colorado, 6], [wyoming, 1]], Total), 
	write('Total = '), write(Total), nl.