/*
 * main.cpp
 *
 *  Created on: May 14, 2017
 *      Author: Admin
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library1.h"
#include <iostream>
using namespace std;
int main() {
	int studentId;
	int* students = NULL;
	int size;
	void* DS = Init();
	AddTeam(DS, 2);
	GetAllStudentsByPower(DS, -1, &students, &size);
	free(students);
	students = NULL;
	AddStudent(DS, 337, -2, 0);
	GetAllStudentsByPower(DS, -2, &students, &size);
	free(students);
	students = NULL;
	MoveStudentToTeam(DS, 942, -3);
	MoveStudentToTeam(DS, 984, 1);
	MoveStudentToTeam(DS, 822, 1);
	IncreaseLevel(DS, 1, -3);
	RemoveStudent(DS, 834); // 10
	RemoveStudent(DS, 263);
	IncreaseLevel(DS, 1, 2);
	GetMostPowerful(DS, -3, &studentId);
	MoveStudentToTeam(DS, 626, 2);
	RemoveStudent(DS, 500);
	AddTeam(DS, 1);
	AddTeam(DS, -3);
	AddTeam(DS, -2);
	GetMostPowerful(DS, 1, &studentId);
	RemoveStudent(DS, 327); // 20
	GetMostPowerful(DS, -1, &studentId);
	AddStudent(DS, 122, -3, 2);
	MoveStudentToTeam(DS, 772, 2);
	MoveStudentToTeam(DS, 270, -3);
	MoveStudentToTeam(DS, 710, -1);
	RemoveStudent(DS, 643);
	MoveStudentToTeam(DS, 926, 3);
	IncreaseLevel(DS, -1, -1);
	AddStudent(DS, 483, 2, -2);
	GetMostPowerful(DS, -1, &studentId); // 30
	GetAllStudentsByPower(DS, 2, &students, &size);
	free(students);
	students = NULL;
	MoveStudentToTeam(DS, 863, -1);
	RemoveStudent(DS, 314);
	GetAllStudentsByPower(DS, 3, &students, &size);
	free(students);
	students = NULL;
	IncreaseLevel(DS, -2, 3);
	AddTeam(DS, 2);
	GetAllStudentsByPower(DS, 0, &students, &size);
	free(students);
	students = NULL;
	GetMostPowerful(DS, 1, &studentId);
	MoveStudentToTeam(DS, 924, -2);
	MoveStudentToTeam(DS, 996, 0); // 40
	IncreaseLevel(DS, 3, -3);
	GetAllStudentsByPower(DS, -1, &students, &size);
	free(students);
	students = NULL;
	GetAllStudentsByPower(DS, 3, &students, &size);
	free(students);
	students = NULL;
	GetMostPowerful(DS, 1, &studentId);
	AddStudent(DS, -8, 3, 1);
	GetAllStudentsByPower(DS, -3, &students, &size);
	free(students);
	students = NULL;
	IncreaseLevel(DS, 1, 3);
	AddStudent(DS, 683, 2, 1);
	RemoveStudent(DS, 440);
	GetAllStudentsByPower(DS, -2, &students, &size); // 50
	free(students);
	students = NULL;
	MoveStudentToTeam(DS, 984, 2);
	AddTeam(DS, 2);
	AddStudent(DS, 451, -3, 1);
	AddTeam(DS, -3);
	GetAllStudentsByPower(DS, 1, &students, &size);
	free(students);
	students = NULL;
	GetAllStudentsByPower(DS, -2, &students, &size);
	free(students);
	students = NULL;
	AddStudent(DS, 742, 2, -3);
	RemoveStudent(DS, 149);
	IncreaseLevel(DS, -2, -1);
	IncreaseLevel(DS, -3, -3); // 60
	GetAllStudentsByPower(DS, -1, &students, &size);
	free(students);
	students = NULL;
	IncreaseLevel(DS, 0, 0);
	MoveStudentToTeam(DS, 872, -1);
	AddStudent(DS, 761, 1, 1);
	GetAllStudentsByPower(DS, -2, &students, &size);
	free(students);
	students = NULL;
	IncreaseLevel(DS, -1, 0);
	GetMostPowerful(DS, 3, &studentId);
	AddTeam(DS, -3);
	AddStudent(DS, 431, -2, 1);
	GetAllStudentsByPower(DS, 2, &students, &size); // 70
	free(students);
	students = NULL;
	IncreaseLevel(DS, -3, 2);
	AddStudent(DS, 602, 1, -2);
	IncreaseLevel(DS, -1, 2);
	AddTeam(DS, -1);
	MoveStudentToTeam(DS, 310, -2);
	RemoveStudent(DS, 166);
	GetMostPowerful(DS, -2, &studentId);
	GetAllStudentsByPower(DS, -2, &students, &size);
	free(students);
	students = NULL;
	IncreaseLevel(DS, 0, -3);
	GetAllStudentsByPower(DS, 1, &students, &size); // 80
	free(students);
	students = NULL;
	RemoveStudent(DS, 649);
	GetAllStudentsByPower(DS, -2, &students, &size);
	free(students);
	students = NULL;
	MoveStudentToTeam(DS, 485, -1);
	AddStudent(DS, 26, -2, -2);
	IncreaseLevel(DS, -1, 3);
	IncreaseLevel(DS, 0, -1);
	AddTeam(DS, 0);
	AddTeam(DS, 2);
	AddTeam(DS, 1);
	MoveStudentToTeam(DS, 415, 0); // 90
	RemoveStudent(DS, 508);
	MoveStudentToTeam(DS, 904, -1);
	GetMostPowerful(DS, 1, &studentId);
	MoveStudentToTeam(DS, 434, 3);
	GetMostPowerful(DS, -3, &studentId);
	MoveStudentToTeam(DS, 701, -3);
	GetAllStudentsByPower(DS, 1, &students, &size);
	free(students);
	students = NULL;
	AddStudent(DS, 84, -2, -2);
	GetAllStudentsByPower(DS, 3, &students, &size);
	free(students);
	students = NULL;
	MoveStudentToTeam(DS, 97, -3); // 100
	GetMostPowerful(DS, 1, &studentId);
	MoveStudentToTeam(DS, 100, 1);
	GetMostPowerful(DS, -1, &studentId);
	AddStudent(DS, 658, 2, 0);
	GetAllStudentsByPower(DS, -2, &students, &size);
	free(students);
	students = NULL;
	AddStudent(DS, 961, 0, 3);
	IncreaseLevel(DS, -2, -1);
	AddStudent(DS, 467, -3, 0);
	GetAllStudentsByPower(DS, -1, &students, &size);
	free(students);
	students = NULL;
	GetAllStudentsByPower(DS, -2, &students, &size); // 110
	free(students);
	students = NULL;
	MoveStudentToTeam(DS, 861, -3);
	IncreaseLevel(DS, 0, 1);
	MoveStudentToTeam(DS, 375, 1);
	AddTeam(DS, -2);
	MoveStudentToTeam(DS, 753, -2);
	MoveStudentToTeam(DS, 426, -1);
	RemoveStudent(DS, 715);
	AddStudent(DS, 658, 3, 1);
	MoveStudentToTeam(DS, 461, 2);
	AddTeam(DS, 1); // 120
	AddStudent(DS, 896, 1, 2);
	IncreaseLevel(DS, -3, -2);
	AddStudent(DS, 463, -3, 2);
	AddStudent(DS, 35, -1, 2);
	MoveStudentToTeam(DS, 635, 0);
	GetMostPowerful(DS, 1, &studentId);
	GetMostPowerful(DS, 1, &studentId);
	RemoveStudent(DS, 120);
	IncreaseLevel(DS, 0, 2);
	AddStudent(DS, 648, -1, -1); // 130
	GetMostPowerful(DS, -3, &studentId);
	MoveStudentToTeam(DS, 847, -3);
	GetAllStudentsByPower(DS, 3, &students, &size);
	free(students);
	students = NULL;
	MoveStudentToTeam(DS, 676, 0);
	MoveStudentToTeam(DS, 617, -2);
	IncreaseLevel(DS, 3, 3);
	RemoveStudent(DS, 286);
	IncreaseLevel(DS, 0, 2);
	IncreaseLevel(DS, 1, 2);
	GetAllStudentsByPower(DS, 1, &students, &size); // 140
	free(students);
	students = NULL;
	RemoveStudent(DS, 993);
	RemoveStudent(DS, 889);
	AddStudent(DS, 606, -2, -1);
	AddTeam(DS, 3);
	IncreaseLevel(DS, -3, 1);
	AddStudent(DS, 299, 2, 1);
	IncreaseLevel(DS, 0, 2);
	IncreaseLevel(DS, 2, -2);
	GetMostPowerful(DS, 0, &studentId);
	MoveStudentToTeam(DS, 620, -2); // 150
	IncreaseLevel(DS, 2, 3);
	IncreaseLevel(DS, 0, -1);
	IncreaseLevel(DS, 0, 3);
	GetMostPowerful(DS, 3, &studentId);
	AddStudent(DS, 542, 1, 0);
	GetMostPowerful(DS, 3, &studentId);
	AddStudent(DS, 872, 2, 1);
	IncreaseLevel(DS, -1, 3);
	GetMostPowerful(DS, 1, &studentId);
	AddTeam(DS, 1); // 160
	IncreaseLevel(DS, 2, 1);
	GetAllStudentsByPower(DS, 1, &students, &size);
	free(students);
	students = NULL;
	MoveStudentToTeam(DS, 355, 0);
	GetAllStudentsByPower(DS, 0, &students, &size);
	free(students);
	students = NULL;
	IncreaseLevel(DS, -3, 2);
	AddStudent(DS, 459, 2, 3);
	IncreaseLevel(DS, 1, -3);
	IncreaseLevel(DS, 0, -2);
	IncreaseLevel(DS, -1, 3);
	IncreaseLevel(DS, -1, 2); // 170
	RemoveStudent(DS, 388);
	IncreaseLevel(DS, -2, 3);
	IncreaseLevel(DS, 3, 3);
	MoveStudentToTeam(DS, 552, 2);
	GetAllStudentsByPower(DS, -1, &students, &size);
	free(students);
	students = NULL;
	GetMostPowerful(DS, 0, &studentId);
	RemoveStudent(DS, 868);
	IncreaseLevel(DS, -1, -2);
	AddStudent(DS, 820, -1, -2);
	RemoveStudent(DS, 875); // 180
	IncreaseLevel(DS, 0, -1);
	IncreaseLevel(DS, 2, -3);
	GetMostPowerful(DS, 3, &studentId);
	RemoveStudent(DS, 621);
	GetMostPowerful(DS, 1, &studentId);
	MoveStudentToTeam(DS, 486, 2);
	IncreaseLevel(DS, -3, 2);
	AddTeam(DS, 1);
	AddStudent(DS, 863, 2, -2);
	AddStudent(DS, 239, 1, 1); // 190
	GetAllStudentsByPower(DS, -3, &students, &size);
	free(students);
	students = NULL;
	MoveStudentToTeam(DS, 572, 2);
	AddTeam(DS, 1);
	GetAllStudentsByPower(DS, -1, &students, &size);
	free(students);
	students = NULL;
	AddTeam(DS, 0);
	MoveStudentToTeam(DS, 877, 0);
	IncreaseLevel(DS, 0, 3);
	GetMostPowerful(DS, -1, &studentId);
	AddTeam(DS, 0);
	GetAllStudentsByPower(DS, 0, &students, &size); // 200
	free(students);
	students = NULL;
	IncreaseLevel(DS, -3, -2);
	GetMostPowerful(DS, -2, &studentId);
	AddTeam(DS, 0);
	AddStudent(DS, 483, 2, 3);
	AddStudent(DS, 319, 2, 1);
	AddStudent(DS, 465, 1, -2);
	MoveStudentToTeam(DS, 341, 1);
	RemoveStudent(DS, 553);
	AddStudent(DS, -5, 1, 0);
	IncreaseLevel(DS, -3, -2); // 210
	RemoveStudent(DS, 582);
	GetMostPowerful(DS, -1, &studentId);
	MoveStudentToTeam(DS, 730, 0);
	IncreaseLevel(DS, -1, 0);
	MoveStudentToTeam(DS, 484, 2);
	AddTeam(DS, 3);
	GetAllStudentsByPower(DS, -1, &students, &size);
	free(students);
	students = NULL;
	AddStudent(DS, 47, -2, -1);
	GetMostPowerful(DS, 2, &studentId);
	MoveStudentToTeam(DS, 598, -2); // 220
	IncreaseLevel(DS, -2, 0);
	IncreaseLevel(DS, 2, -2);
	GetMostPowerful(DS, 1, &studentId);
	IncreaseLevel(DS, 2, -3);
	AddStudent(DS, 361, 0, -3);
	AddTeam(DS, -1);
	GetAllStudentsByPower(DS, 3, &students, &size);
	free(students);
	students = NULL;
	RemoveStudent(DS, 74);
	GetAllStudentsByPower(DS, -2, &students, &size);
	free(students);
	students = NULL;
	GetMostPowerful(DS, -3, &studentId); // 230
	GetMostPowerful(DS, 1, &studentId);
	IncreaseLevel(DS, 1, 2);
	MoveStudentToTeam(DS, 748, -3);
	AddStudent(DS, 659, -3, 2);
	MoveStudentToTeam(DS, 193, 1);
	RemoveStudent(DS, 913);
	MoveStudentToTeam(DS, 286, -2);
	GetAllStudentsByPower(DS, -3, &students, &size);
	free(students);
	students = NULL;
	GetAllStudentsByPower(DS, -2, &students, &size);
	free(students);
	students = NULL;
	IncreaseLevel(DS, 0, -3); // 240
	AddTeam(DS, 3);
	GetMostPowerful(DS, 3, &studentId);
	AddTeam(DS, -2);
	RemoveStudent(DS, 723);
	RemoveStudent(DS, 537);
	GetMostPowerful(DS, -2, &studentId);
	GetMostPowerful(DS, -2, &studentId);
	GetAllStudentsByPower(DS, 2, &students, &size);
	free(students);
	students = NULL;
	AddStudent(DS, 929, -2, 0);
	MoveStudentToTeam(DS, 766, 0); // 250
	RemoveStudent(DS, 802);
	GetAllStudentsByPower(DS, 2, &students, &size);
	free(students);
	students = NULL;
	IncreaseLevel(DS, 0, 2);
	RemoveStudent(DS, 458);
	MoveStudentToTeam(DS, 470, 0);
	AddStudent(DS, 175, 1, 1);
	AddStudent(DS, 610, 0, -3);
	MoveStudentToTeam(DS, 944, -1);
	AddTeam(DS, 1);
	AddTeam(DS, -2); // 260
	RemoveStudent(DS, 12);
	GetMostPowerful(DS, 0, &studentId);
	GetAllStudentsByPower(DS, -2, &students, &size);
	free(students);
	students = NULL;
	GetMostPowerful(DS, -3, &studentId);
	GetAllStudentsByPower(DS, 2, &students, &size);
	free(students);
	students = NULL;
	AddStudent(DS, 386, -2, 3);
	GetMostPowerful(DS, 3, &studentId);
	AddStudent(DS, 564, 0, -1);
	IncreaseLevel(DS, -3, 1);
	AddStudent(DS, 46, -2, -2); // 270
	MoveStudentToTeam(DS, 273, -1);
	IncreaseLevel(DS, 1, 3);
	IncreaseLevel(DS, -3, -3);
	IncreaseLevel(DS, -1, -1);
	IncreaseLevel(DS, -2, 1);
	AddTeam(DS, -2);
	IncreaseLevel(DS, 0, -2);
	AddStudent(DS, 691, 1, 0);
	RemoveStudent(DS, 386);
	MoveStudentToTeam(DS, 391, -3); // 280
	MoveStudentToTeam(DS, 307, 2);
	GetMostPowerful(DS, 0, &studentId);
	AddTeam(DS, 2);
	RemoveStudent(DS, 622);
	MoveStudentToTeam(DS, 363, -2);
	GetMostPowerful(DS, 2, &studentId);
	IncreaseLevel(DS, 0, -1);
	GetAllStudentsByPower(DS, -1, &students, &size);
	free(students);
	students = NULL;
	MoveStudentToTeam(DS, 459, 1);
	RemoveStudent(DS, 607); // 290
	MoveStudentToTeam(DS, 791, 2);
	GetAllStudentsByPower(DS, 2, &students, &size);
	free(students);
	students = NULL;
	GetAllStudentsByPower(DS, -2, &students, &size);
	free(students);
	students = NULL;
	IncreaseLevel(DS, 0, -1);
	MoveStudentToTeam(DS, 769, -2);
	AddStudent(DS, 855, 0, 3);
	GetMostPowerful(DS, 1, &studentId);
	GetMostPowerful(DS, -1, &studentId);
	GetMostPowerful(DS, 2, &studentId);
	RemoveStudent(DS, 836); // 300
	MoveStudentToTeam(DS, 18, -2);
	RemoveStudent(DS, 797);
	RemoveStudent(DS, 674);
	RemoveStudent(DS, 707);
	AddStudent(DS, 920, 0, 1);
	AddStudent(DS, 166, -1, -2);
	GetAllStudentsByPower(DS, 1, &students, &size);
	free(students);
	students = NULL;
	GetAllStudentsByPower(DS, 2, &students, &size);
	free(students);
	students = NULL;
	GetMostPowerful(DS, 3, &studentId);
	MoveStudentToTeam(DS, 176, -2); // 310
	AddTeam(DS, -2);
	AddTeam(DS, 2);
	AddTeam(DS, 0);
	AddTeam(DS, 2);
	GetAllStudentsByPower(DS, 0, &students, &size);
	free(students);
	students = NULL;
	IncreaseLevel(DS, 0, -3);
	AddTeam(DS, -1);
	MoveStudentToTeam(DS, 996, 3);
	GetMostPowerful(DS, 2, &studentId);
	GetAllStudentsByPower(DS, 2, &students, &size); // 320
	free(students);
	students = NULL;
	AddStudent(DS, 448, 1, -1);
	RemoveStudent(DS, 192);
	IncreaseLevel(DS, -3, -1);
	AddTeam(DS, -2);
	GetMostPowerful(DS, -1, &studentId);
	IncreaseLevel(DS, 0, -2);
	MoveStudentToTeam(DS, 727, -2);
	GetAllStudentsByPower(DS, 2, &students, &size);
	free(students);
	students = NULL;
	AddStudent(DS, 624, 3, 3);
	RemoveStudent(DS, 487); // 330
	RemoveStudent(DS, 729);
	AddTeam(DS, -3);
	RemoveStudent(DS, 961);
	RemoveStudent(DS, 355);
	IncreaseLevel(DS, -2, -3);
	RemoveStudent(DS, 808);
	MoveStudentToTeam(DS, 289, -1);
	AddTeam(DS, 1);
	GetAllStudentsByPower(DS, -1, &students, &size);
	free(students);
	students = NULL;
	AddTeam(DS, 2); // 340
	GetAllStudentsByPower(DS, 2, &students, &size);
	free(students);
	students = NULL;
	GetMostPowerful(DS, 2, &studentId);
	AddTeam(DS, 1);
	MoveStudentToTeam(DS, 43, -3);
	AddStudent(DS, 874, 1, -2);
	GetMostPowerful(DS, 2, &studentId);
	AddStudent(DS, 455, 3, 0);
	IncreaseLevel(DS, -1, 0);
	GetMostPowerful(DS, 3, &studentId);
	AddTeam(DS, 0); // 350
	AddTeam(DS, -3);
	RemoveStudent(DS, 210);
	GetAllStudentsByPower(DS, 2, &students, &size);
	free(students);
	students = NULL;
	IncreaseLevel(DS, -3, 3);
	MoveStudentToTeam(DS, 841, 2);
	MoveStudentToTeam(DS, 93, 0);
	AddTeam(DS, 2);
	AddTeam(DS, 3);
	MoveStudentToTeam(DS, 298, -2);
	GetAllStudentsByPower(DS, -3, &students, &size); // 360
	for(int i=0;i<size;i++){
		cout << students[i] << endl;
	}
	free(students);
	students = NULL;
	AddStudent(DS, 216, -3, 1);
	AddTeam(DS, 3);
	IncreaseLevel(DS, -3, -3);
	AddTeam(DS, -2);
	GetMostPowerful(DS, 0, &studentId);
	AddTeam(DS, 0);
	AddStudent(DS, 902, 1, 3);
	MoveStudentToTeam(DS, 510, -1);
	GetMostPowerful(DS, -1, &studentId); //****
	cout << "most powerful: "<< studentId;
	MoveStudentToTeam(DS, 42, -2); // 370
	AddTeam(DS, -1);
	IncreaseLevel(DS, -2, -1);
	AddTeam(DS, -1);
	GetMostPowerful(DS, -3, &studentId);
	Quit(&DS);
}

