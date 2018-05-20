/*
 * main.c
 *
 *  Created on: May 20, 2018
 *      Author: tiger
 */
#include "main.h"

St_company HossamCompany;
St_company AdelCompany;

int main ()
{

	companys_name(&HossamCompany);
	companys_name(&AdelCompany);

	HossamCompany.company_config(&HossamCompany);
	HossamCompany.company_config(&AdelCompany);

	for(;;)
	{
		HossamCompany.company_cond(&HossamCompany);

		HossamCompany.company_hire(&HossamCompany);

		HossamCompany.company_cond(&AdelCompany);

		HossamCompany.company_hire(&AdelCompany);

	}

	return 0;
}
