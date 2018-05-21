
#include "main.h"
#include "Services.h"


void company_init(St_company *company , void (*config)(St_company *company) , void (*hire)(St_company *company) ,
		int (*cond)(St_company *company) , void (*log)(St_company *company))
{

	if(company)
	{
		company->company_config = config;
		company->company_hire = hire;
		company->company_cond = cond;
		company->company_log  = log;
	}
}

void Cmp_config(St_company *company)
{

	printf("\r\nPlease Enter Your First Name As Anew Manager  : ");

	read_scanf_name(company->manager.name,MAX_NAME_SIZE);

	printf("Hello mr. %s   " , company->manager.name);
	printf("\r\nThis app helps you to configure some information about your employees . \n");
	printf("------------------------------------------------------------------------\n");

	printf("Set Your Information about (Salary , Hours , Tasks , Overtime)\r\n");
	printf("1 - Max Salary per month : ");
	scanf("%d", &company->main.max_Salary);
	printf("2 - Min Salary per month : ");
	scanf("%d", &company->main.Min_Salary);
	printf("3 - Hours per week : ");
	scanf("%d", &company->main.Fixed_Hours);
	printf("4 - Num Of Tasks per day  : ");
	scanf("%d", &company->main.Num_Of_Tasks);
	printf("5 - Overtimer per day : ");
	scanf("%f", &company->main.overtimer_gain);

	printf("-------------------------------------------------------------------------\n");
	printf("Thanks Sir \n");
	printf("-------------------------------------------------------------------------\n");

}

void Cmp_hire(St_company *company)
{




	if(company->main.switchs == GOTO_HIRE  )
	{
		if(company->employee_counter == MAX_EMPLOYEE_NUM)
		{
			printf("Sorry Sir Your data base is full \n");
			company->main.switchs = GOTO_CANCEL;
			return;

		}
		printf("Mr.%s   " , company->manager.name);

		printf("\nYou can now hire nw employee to your company , Sir\n");
		printf("------------------------------------------------------------------------\r\n");
		printf("Mr.%s   " , company->manager.name);
		printf("Employee Name :");

		read_scanf_name(company->employee[company->employee_counter].name,MAX_NAME_SIZE);

		while(1)
		{
			printf("Mr.%s   " , company->manager.name);
			printf("Employee Salary :");
			scanf("%d", &company->employee[company->employee_counter].fixed_salary);
			if(company->employee[company->employee_counter].fixed_salary > company->main.max_Salary)
			{
				printf("Warning Sir, your max Salary is : %d \nPlease try again \n" , company->main.max_Salary );

			}
			else if (company->employee[company->employee_counter].fixed_salary < company->main.Min_Salary)
			{
				printf("Warning Sir, your Min Salary is : %d \nPlease try again \n" , company->main.Min_Salary );
			}
			else
			{
				break;
			}
		}

		while(1)
		{
			printf("Mr.%s   " , company->manager.name);
			printf("Employee ID :");
			scanf("%d", &company->employee[company->employee_counter].id);

			int flag = 0;
			for (int index = 0; index < MAX_EMPLOYEE_NUM ; index ++)
			{
				if (company->employee[company->employee_counter].id == company->employee[index].id)
				{
					flag ++;
				}

			}
			if(flag == 1) break;
			else
				printf("Warning Sir, this ID (%d) was token \nPlease try again \n" , company->employee[company->employee_counter].id );

		}

		printf("Mr.%s   " , company->manager.name);
		printf("Employee Working Hours :");
		scanf("%d", &company->employee[company->employee_counter].nume_of_houres);

		printf("Mr.%s   " , company->manager.name);
		printf("Employee Tasks number :");
		scanf("%d", &company->employee[company->employee_counter].task);

		printf("Employee Added\n");
		printf("Employee Name is : %s \n" , company->employee[company->employee_counter].name);
		printf("Employee Salary is : %d\n" , company->employee[company->employee_counter].fixed_salary);
		printf("Employee ID is : %d\n" , company->employee[company->employee_counter].id);
		printf("Employee Working Hours is : %d\n" , company->employee[company->employee_counter].nume_of_houres);
		printf("Employee Working Tasks is : %d\n" , company->employee[company->employee_counter].task);

		printf("-------------------------------------------------------------------------\r\n");
		company->main.switchs = GOTO_CANCEL;
		company->employee_counter++;


	}





}

int Cmp_cond(St_company *company)
{
	printf("------------------------------------------------------------------------\r\n");
	printf("Mr.%s   " , company->manager.name);
	printf("\rNow sir you can chose your next stage .. \r\n");
	printf("if you press.. \n (2)  employee logs .\n");
	printf(" (1)  hire new employee .\n");
	printf(" (0)  cancel .\n");
	scanf("%d", &company->main.switchs);
	printf("------------------------------------------------------------------------\r\n");

	return company->main.switchs;
}

void Cmp_log(St_company *company)
{

	if(company->main.switchs == GOTO_LOG)
	{
		printf("------------------------------------------------------------------------\r\n");
		printf("Hello Mr.%s  This is some information about your company Employee \n" , company->manager.name);
		printf("You have (%d) Employee , note your max employee (%d) \n" , company->employee_counter , MAX_EMPLOYEE_NUM);
		printf("------------------------------------------------------------------------\r\n");

		for(int index = 0; index < MAX_EMPLOYEE_NUM ; index++)
		{
			if(company->employee_counter == 0)
			{
				printf("You have no Employee\n");
				break;
			}
			if(index == company->employee_counter)
			{
				break;

			}
			printf("Employee Name : %s\n",company->employee[index].name);
			printf("Employee ID : %d\n",company->employee[index].id);
			printf("Employee Salary : %d\n",company->employee[index].fixed_salary);
			printf("Employee task : %d\n",company->employee[index].task);
			printf("Employee Hours : %d\n",company->employee[index].nume_of_houres);
			printf("------------------------------------------------------------------------\r\n");

		}
		company->main.switchs = GOTO_CANCEL;
	}

}

void companys_name(St_company *company)
{
	company_init(company , Cmp_config ,  Cmp_hire , Cmp_cond , Cmp_log);
}
