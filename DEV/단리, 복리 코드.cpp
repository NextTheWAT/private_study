#include<stdio.h>
#include<math.h>

int dan(int money,int pluspoint,int year);
int bok(int money,int pluspoint,int year);

int main(void){

	int i,money,pluspoint,year,arr[2];

	printf("������ �Է��ϼ���:");
	scanf("%d",&money);
	printf("�������� �Է��ϼ���:");
	scanf("%d",&pluspoint);
	printf("��ġ�Ⱓ�� �Է��ϼ���(��)):");
	scanf("%d",&year);
	
	printf("====================================\n");
	printf("��\t�ܸ�\t����\n");

	for(i=0; i<year; i++)
	{
		arr[0]=dan(money,pluspoint,i+1);
		arr[1]=bok(money,pluspoint,i+1);
		printf("%d\t%d\t%d\n",i+1,arr[0],arr[1]);
	}
}


int dan(int money,int pluspoint,int year){
	return money*(1+pluspoint/100.0*year);
}

int bok(int money,int pluspoint, int year){
	return money*pow(1+pluspoint/100.0,year);
}

