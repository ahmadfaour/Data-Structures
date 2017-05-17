/*
 * School.cpp
 *
 *  Created on: May 12, 2017
 *      Author: user hade
 */





#include "School.h"



class StoreStudentsByGrade {
	int grade;
	Student* same_grade;
	Student* other_grade;
	int i, j;
public:
	StoreStudentsByGrade(int grade, Student* same_grade, Student* other_grade) :
			grade(grade), same_grade(same_grade), other_grade(other_grade), i(
					0), j(0) {
	}
	void operator()(const Student& student) {
		if (student.Grade == grade) {
			same_grade[i++] = student;
		} else
			other_grade[j++] = student;
	}
};
void GetAllStudentsByPG(Student** Students_diffrent_g,
		Student** Students_same_g, int size, int grade,
		AVLTree<int, Student, compareStudents>& tree) {

	int num_of_students = size;
	Student* same_g_students = new Student[num_of_students];
	Student* diffrent_g_students = new Student[num_of_students];
	StoreStudentsByGrade g(grade, same_g_students, diffrent_g_students);
	(tree).InOrderByKey(g);
	*Students_diffrent_g = diffrent_g_students;
	*Students_same_g = same_g_students;
}
void increasePower(int PowerIncrease, Student* students_arr, int size) {
	int i = 0;
	while (i < size && (students_arr + i)->id > 0) {

		(students_arr + i)->Power += PowerIncrease;
		i++;
	}
}

Student* merge(Student* array1, Student* array2, int size) {
	int i = 0;
	int j = 0;
	int k = 0;
	Student* merged = new Student[size];
	while (k < size) {
		if ((array1 + i)->id < 0) {
			merged[k] = *(array2 + j);
			j++;
			k++;
			continue;
		}
		if ((array2 + j)->id < 0) {
			merged[k] = *(array1 + i);
			i++;
			k++;
			continue;
		}
		compareStudents c;
		if (c(*(array1 + i), *(array2 + j))) {
			merged[k] = *(array1 + i);
			i++;
			k++;
			continue;
		}
		merged[k] = *(array2 + j);
		j++;
		k++;
	}
	return merged;
}

class AddPower2Grade {
	int PowerIncrease;
	int Grade;
public:
	AddPower2Grade(int PowerIncrease, int Grade) :
			PowerIncrease(PowerIncrease), Grade(Grade) {
	}
	void operator()(Student &student) {
		if (student.Grade == Grade)
			student.Power += PowerIncrease;
	}
};
class FillKeys {
	int i;
	Student* id_S;
public:
	FillKeys(Student* id_S) :
			i(0), id_S(id_S) {
	}
	void operator ()(Student& student) {
		student = *(id_S + i);
		i++;
	}
};
void rebulidTree(int Grade, int PowerIncrease,
		AVLTree<int, Student, compareStudents>& tree) {

	Student* diffrent_grade_students;
	Student* same_grade_students;
	int arr_size = (tree).getSize();
	if (arr_size == 0)
		return;
	GetAllStudentsByPG(&diffrent_grade_students, &same_grade_students, arr_size,
			Grade, tree);
	if (same_grade_students->id < 0) {
		delete[] diffrent_grade_students;
		delete[] same_grade_students;
		return;
	}
	//Updating students by power tree
	increasePower(PowerIncrease, same_grade_students, arr_size);
	Student* merged_arr = merge(same_grade_students, diffrent_grade_students,
			arr_size);

	tree.clean();
	tree.createTreeOfSize(arr_size);
	FillKeys fill(merged_arr);
	tree.InOrderByKey(fill);
	tree.most_powerful_student = merged_arr [arr_size-1];
	delete[] diffrent_grade_students;
	delete[] same_grade_students;
	delete[] merged_arr;
}

class BuildTeamTree {
	int grade;
	int powerIncrease;
public:
	BuildTeamTree(int grade, int powerIncrease) :
			grade(grade), powerIncrease(powerIncrease) {
	}
	void operator ()(AVLTree<int, Student, compareStudents>& tree) {
		rebulidTree(grade, powerIncrease, tree);
	}
};

StatusType School::IncreaseLevel(int Grade, int PowerIncrease) {
	if (Grade < 0 || PowerIncrease <= 0)
		return INVALID_INPUT;
     if (students_by_id.getSize() == 0)
    	 return SUCCESS;
	//Updating students_by_id tree
	AddPower2Grade f(PowerIncrease, Grade);
	students_by_id.InOrder(f);

	//*********************
	rebulidTree(Grade, PowerIncrease, students);
	BuildTeamTree b(Grade, PowerIncrease);
	teams_id.InOrder(b);
	return SUCCESS;
}
