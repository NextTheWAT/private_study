#include <stdio.h>

//3������ ��� (�����Լ����) 
double average(double kor, double eng, double math)
{
	int sum=0;
	double ave=0;
	ave = (kor +eng +math)/ 3;
    return ave;
}



int main()
{
	int kor=0, eng=0, math=0;
	int sum;
	double ave=0;
	printf("����, ���� , ���� ������ �Է����ּ���.: ");
	for(int i=0; i<3; i++)
	{
	    scanf("%d%d%d",&kor,&eng,&math);
	    ave = average(kor,eng,math);
	    printf("���:%.5lf\n",(double)ave);
	}
}
