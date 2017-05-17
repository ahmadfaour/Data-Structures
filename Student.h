#ifndef STUDENT_H_
#define STUDENT_H_
#include "avl.h"

class compareStudents;
class Student {

public:
	int id;
	int Grade;
	int Power;
	AVLTree<int, Student, compareStudents>* team_ptr;
	Student(int StudentID, int Grade, int Power) :
			id(StudentID), Grade(Grade), Power(Power), team_ptr(NULL) {
	}
	Student() :
			id(-1), Grade(0), Power(-1), team_ptr(NULL) {
	}
};
class compareStudents {
public:
	bool operator ()(Student s1, Student s2) {
		if (s1.Power < s2.Power>)
			return true;
		if (s1.Power > s2.Power)
			return false;
		if (s2.id < s1.id)
			return true;
		return false;
	}
};



#endif /* STUDENT_H_ */
