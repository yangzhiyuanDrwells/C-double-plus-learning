#include <stdio.h>
int main (void)
{
	double firstNumber,secondNumber,temporaryVariable;
	
	printf("Enter firstNumber: ");
	scanf("%lf",&firstNumber);
	
	printf("Enter secondNumber�� "); 
	scanf("%lf",&secondNumber);
	
	temporaryVariable = firstNumber;
	
	firstNumber = secondNumber;
	
	secondNumber = temporaryVariable;
	
	printf("\n������firstNumber = %lf\n",firstNumber);
	printf("������secondNumber = %lf",secondNumber);
	
	return 0;
	
 } 
