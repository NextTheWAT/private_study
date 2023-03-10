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
	strcpy(lee.name,"이재은");
	lee.num=1971070;
	strcpy(lee.majer,"IT융합학부");
	
	printf("이름: %s\n학번: %d\n전공:%s\n",lee.name,lee.num,lee.majer); 
}
