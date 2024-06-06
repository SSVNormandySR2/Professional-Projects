/*
Vincent Latona
Students
*/
/* 2.1-Student facts */
/* School facts */
school(jack, cidse).
school(sam, ssebe).
/* Subject facts */
subject(jack, computer_science).
subject(jack, software_engg).
subject(sam, construction_engg).
subject(sam, environmental_engg).
/* Course facts */
course(computer_science, cse240).
course(computer_science, cse446).
course(software_engg, ser321).
course(software_engg, ser322).
course(construction_engg, cne210).
course(construction_engg, cne213).
course(environmental_engg, eve214).
course(environmental_engg, eve261).
/* 2.2-Info */
/* Rule for finding relevant information of a student */
info(Student, Info) :-
	school(Student, School), 
	subject(Student, Subject1), subject(Student, Subject2),
	\==(Subject1, Subject2),
	Info = [School, Subject1, Subject2],!.
/* 2.3-Schedule */
/* Rule for finding a student's schedule */
schedule(Student, CourseList) :-
	subject(Student, Subject1), subject(Student, Subject2),
	\==(Subject1, Subject2),
	course(Subject1, Course1), course(Subject1, Course2),
	\==(Course1, Course2),
	course(Subject2, Course3), course(Subject2, Course4),
	\==(Course3, Course4),
	CourseList = [Course1, Course2, Course3, Course4],!.