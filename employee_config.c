
#include "main.h"



void company_init(St_company *company , void (*config)(St_company *company) , void (*hire)(St_company *company) ,
		int (*cond)(St_company *company))
{

	if(company)
	{
		company->company_config = config;
		company->company_hire = hire;
		company->company_cond = cond;
	}
}

void Cmp_config(St_company *company)
{

	printf("\r\nPlease Enter Your First Name As Anew Manager  : ");

	for(int index = 0 ; index <MAX_NAME_SIZE-1 ; index ++)
	{
		scanf("%c", &company->manager.name[index]);

		if(company->manager.name[index] == END_NAME && index > 2 )
		{
			company->manager.name[index] = 0;
			break;
		}
		if(company->manager.name[0] == END_NAME && index < 1)
		{
			index=-1;
		}
	}

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



	if(company->main.switchs == GOTO_HIRE)
	{
		printf("Mr.%s   " , company->manager.name);

		printf("\nYou can now hire nw employee to your company , Sir\n");
		printf("------------------------------------------------------------------------\r\n");
		printf("Mr.%s   " , company->manager.name);
		printf("Employee Salary :");
		scanf("%d", &company->employee.fixed_salary);
		printf("Mr.%s   " , company->manager.name);

		printf("Employee ID :");
		scanf("%d", &company->employee.id);
		printf("Mr.%s   " , company->manager.name);

		printf("Employee Working Hours :");
		scanf("%d", &company->employee.nume_of_houres);
		printf("Mr.%s   " , company->manager.name);

		printf("Employee Tasks number :");
		scanf("%d", &company->employee.task);

		printf("Employee Added\n");
		printf("Employee Salary is : %d\n" , company->employee.fixed_salary);
		printf("Employee ID is : %d\n" , company->employee.id);
		printf("Employee Working Hours is : %d\n" , company->employee.nume_of_houres);
		printf("Employee Working Tasks is : %d\n" , company->employee.task);

		printf("-------------------------------------------------------------------------\r\n");
		company->main.switchs = 0;

	}


}

int Cmp_cond(St_company *company)
{
	printf("------------------------------------------------------------------------\r\n");
	printf("mr.%s   " , company->manager.name);
	printf("\rNow sir you can chose your next stage .. \r\n");
	printf("if you press.. \n (1)  hire new employee .\n");
	printf(" (0)  cancel .\n");
	scanf("%d", &company->main.switchs);


	return company->main.switchs;
}

void companys_name(St_company *company)
{
	company_init(company , Cmp_config ,  Cmp_hire , Cmp_cond);
}
