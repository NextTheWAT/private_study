#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main(void)
{
	char arr[SIZE];
	char name;
	int count=1;
	
	printf("�̸��� �Է����ּ���!: ");
	scanf("%s",&arr); //�̸��� �Է¹��� 
	
	while(arr[count]!='\0') //���� ��������! 
	{
		count++;
	}
	
	for(int i=0; i<=count; i++)
	{ 
		arr[i] = (int)arr[i]-32;
		printf("%c",(char)arr[i]);
	}
	return 0;
}

int main(void)
{
	char arr[SIZE];
	char name;
	int count=1;
	
	printf("�̸��� �Է����ּ���!: ");
	scanf("%s",&arr); //�̸��� �Է¹��� 
	
	while(arr[count]!='\0') //���� ��������! 
	{
		count++;
	}
	
	for(int i=0; i<=count; i++)
	{ 
		arr[i] = (int)arr[i]+32;
		printf("%c",(char)arr[i]);
	}
	return 0;
}

