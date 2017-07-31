// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

int _tmain(int argc, _TCHAR* argv[])
{
	FILE * pFile; 
	fopen_s(&pFile,"tax_data.csv","w");
	fprintf(pFile,"Salary, Tax, Take Home Pay\n");
	double increment = 50.0, min = 0, max = 500000.0;
	int N = max / increment;
	std::vector<double> v_tax_brackets{0.0, 9325.0, 37950.0, 91900.0, 191650.0, 416700.0, 418400.0};
	std::vector<double> v_tax_rates{ 0.1, 0.15, 0.25, 0.28, 0.33, 0.35, 0.396 };
	std::vector<double>::iterator low;
	double x = 0.0;
	double tax;
	for (int i = 0; i < N; i++){
		x = (i+1)*increment;
	//while (1){
	//	std::cin >> x;
		tax = 0.0;
		low = std::lower_bound(v_tax_brackets.begin(),v_tax_brackets.end(),x);
		int lower_bound_val = low - v_tax_brackets.begin();
		for (int b = 0; b<(lower_bound_val-1); b++){
			tax += (v_tax_brackets.at(b + 1) - v_tax_brackets.at(b)) * v_tax_rates.at(b);
			//std::cout << "(" << v_tax_brackets.at(b + 1) << "-" << v_tax_brackets.at(b) << ")*" << v_tax_rates.at(b) << "+";
		}
		tax += (x - v_tax_brackets.at(low - v_tax_brackets.begin() - 1)) * v_tax_rates.at(low - v_tax_brackets.begin() - 1);
		//std::cout << "(x-" << v_tax_brackets.at(low - v_tax_brackets.begin() - 1) << ")" << "*" << v_tax_rates.at(low - v_tax_brackets.begin() - 1) << std::endl;
		fprintf(pFile, "%.02f, %.02f, %.02f \n", x, tax, x-tax);
		//std::cout << x << ", " << tax << ", " << x - tax << "\n";
	}
	fclose(pFile);
	return 0;
}

