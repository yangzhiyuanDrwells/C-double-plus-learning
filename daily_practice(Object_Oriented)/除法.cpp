#include <stdio.h>
int main (void)
{
	int dividend,divisor,quotient,remainder;
	
	printf("Enter an dividend: ");
	scanf("%d",&dividend);
	
	printf("Enter an divisor: ");
	scanf("%d",&divisor);
	
	quotient = dividend / divisor;
	remainder = dividend % divisor;
	
	printf("�� = %d\n",quotient);
	printf("���� = %d",remainder);
	
	return 0; 
}
