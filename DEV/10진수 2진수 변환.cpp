#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//10������ 2�����κ�ȯ  
int Trantwo(int n,int count)
{
   int arr[100];
   int na;
  
   
     na = n%2;
     arr[count] = na;
     //1�������մϴ�.
   
    if(n<2) 
   {
       arr[count] = n;
       for(int i=count; i>=0; i--)
        printf("%d",arr[i]);
       return 0;
   }
   
  
   printf("%d %d count=%d\n",n,na,count);
   Trantwo(n/2,count+1); //2�� ���� ���� �����ش� 
}



int main()
{
   int ten,two,sixteen;
    printf("10������ �Է����ּ���!: ");
    scanf("%d",&ten);
    Trantwo(ten,0);
}
