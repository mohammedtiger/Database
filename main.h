/*
 * main.h
 *
 *  Created on: May 20, 2018
 *      Author: tiger
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <string.h>
#include <termios.h>

#define END_NAME			 '\n'
#define MAX_NAME_SIZE 		 20

enum
{
	GOTO_HIRE = 1
};

typedef struct manager {
	char name[MAX_NAME_SIZE];
}St_manager;

typedef struct employe {
	char name[MAX_NAME_SIZE];
	unsigned int salary;
	unsigned int fixed_salary;
	int nume_of_houres;
	int task;
	int def;
	char id;
}St_employee;


typedef struct main_stepup
{
	 int max_Salary;
	 int Min_Salary;
	 int Fixed_Hours;
	 int Num_Of_Tasks;
	 int switchs;
	float overtimer_gain;
}St_main;

typedef struct company St_company ;
struct company
{
	St_employee employee;
	St_main 	main;
	St_manager  manager;
	void 		(*company_config)(St_company *company);
	void 		(*company_hire)(St_company *company);
	int 		(*company_cond)(St_company *company);

};


void companys_name(St_company *company);


#endif /* MAIN_H_ */
