#include <stdio.h>
#include <String.h>
#include <math.h>
struct Student
{
	char name[10];
	int num;
	char majer[10];
};


int main(void)
{
	struct Student lee;
	strcpy(lee.name,"������");
	lee.num=1971070;
	strcpy(lee.majer,"IT�����к�");
	
	printf("�̸�: %s\n�й�: %d\n����:%s\n",lee.name,lee.num,lee.majer); 
}
