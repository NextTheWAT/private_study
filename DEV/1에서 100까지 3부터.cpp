#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>

int main(void)
{
int x, sum;
x =1;
sum = 0;
while(x<=100)
{
if(x%3==0)
{sum = sum +x;}
x++;
}
printf("1���� 100������ ��� 3�ǹ���� ���� %d�Դϴ�.\n", sum);
return 0;
}
