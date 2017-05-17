/*
 * Scool.h
 *
 *  Created on: May 10, 2017
 *      Author: user hade
 */

#ifndef SCHOOL_H_
#define SCHOOL_H_

#include "avl.h"
#include "Student.h"
#include "library1.h"
#include <stdlib.h>

class School {
public:

	AVLTree<Student, int> students_by_id;
	AVLTree<int, Student, compareStudents> students;
	AVLTree<AVLTree<int, Student, compareStudents>, int> teams_id;

public:

	StatusType AddStudent(int id, int Grade, int Power) {
		if (id <= 0 || Power <= 0 || Grade < 0)
			return INVALID_INPUT;
		if (students_by_id.contains(id))
			return FAILURE;
		students.insert(Student(id, Grade, Power), 0);
		students_by_id.insert(id, Student(id, Grade, Power));
		return SUCCESS;
	}

	StatusType MoveStudentToTeam(int student_id, int team_id) {

		if (student_id <= 0 || team_id <= 0)
			return INVALID_INPUT;
		if (!students_by_id.contains(student_id) || !teams_id.contains(team_id))
			return FAILURE;
		Student &student = *(students_by_id.find(student_id));
		if (student.team_ptr != NULL) {
			(*(student.team_ptr)).remove(student);
		}
		student.team_ptr = teams_id.find(team_id);
		student.team_ptr->insert(student, 0);
		return SUCCESS;
	}

	class StoreStudentByPower {
		int i;
		int* id_S;
	public:
		StoreStudentByPower(int array_size, int* id_S) :
				i(array_size - 1), id_S(id_S) {
		}
		void operator ()(Student student) {
			*(id_S + i) = student.id;
			i--;
		}

	};

	StatusType GetAllStudentsByPower(int TeamID, int** Students_arr,
			int* numOfStudents) {
		if (Students_arr == NULL||numOfStudents==NULL || TeamID == 0)
			return INVALID_INPUT;

		if (TeamID > 0 && !teams_id.contains(TeamID))
			return FAILURE;

		AVLTree<int, Student, compareStudents>* target_tree_ptr;

		target_tree_ptr = teams_id.find(TeamID);

		if (target_tree_ptr == NULL) {
			target_tree_ptr = &students;
		}

		int num_of_students = (*target_tree_ptr).getSize();
		if (num_of_students == 0) {
			*numOfStudents = 0;
			*Students_arr = NULL;
			return SUCCESS;
		}
		int* id_array =(int*) malloc (sizeof(int)*num_of_students) ;
		StoreStudentByPower f(num_of_students, id_array);
		(*target_tree_ptr).InOrderByKey(f);
		*Students_arr = id_array;
		*numOfStudents = num_of_students;
		return SUCCESS;
	}

	StatusType GetMostPowerful(int TeamID, int* StudentID) {
		if (StudentID == NULL || TeamID == 0)
			return INVALID_INPUT;
		if (TeamID > 0 && !teams_id.contains(TeamID))
			return FAILURE;
		if (TeamID < 0) {
			*StudentID = students.most_powerful_student.id;
			return SUCCESS;
		}
		AVLTree<int, Student, compareStudents>* tree = teams_id.find(TeamID);
		*StudentID = tree->most_powerful_student.id;
		return SUCCESS;
	}
	StatusType RemoveStudent(int StudentID) {
		if (StudentID <= 0)
			return INVALID_INPUT;
		if (!students_by_id.contains(StudentID))
			return FAILURE;
		Student& student = *(students_by_id.find(StudentID));
		if (student.team_ptr == NULL) {
			students.remove(student);
			students_by_id.remove(StudentID);
		} else {
			AVLTree<int, Student, compareStudents>* tree = student.team_ptr;
			tree->remove(student);
			students.remove(student);
			students_by_id.remove(StudentID);
		}
		return SUCCESS;
	}

	StatusType AddTeam(int TeamID) {
		if (TeamID <= 0)
			return INVALID_INPUT;
		if (teams_id.contains(TeamID))
			return FAILURE;
		teams_id.insert(TeamID, AVLTree<int, Student, compareStudents>());
		return SUCCESS;
	}


	StatusType IncreaseLevel(int Grade, int PowerIncrease);
};











#endif /* SCHOOL_H_ */
