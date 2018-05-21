/*
 * main.c
 *
 *  Created on: May 20, 2018
 *      Author: tiger
 */
#include "main.h"

St_company HossamCompany = {.employee_counter = 0};

int main ()
{

	companys_name(&HossamCompany);

	HossamCompany.company_config(&HossamCompany);

	for(;;)
	{
		HossamCompany.company_cond(&HossamCompany);

		HossamCompany.company_hire(&HossamCompany);

		HossamCompany.company_log(&HossamCompany);
	}

	return 0;
}
