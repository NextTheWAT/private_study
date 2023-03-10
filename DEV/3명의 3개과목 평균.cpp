#include <stdio.h>

void Sum(int x, int y, int z); 

int main(void)
{
    int a, b, c, i,j ;
    char name[100] ;

    for(i=0; i<=2; i++)
    {
    	printf("이름: ");
        scanf("%s", name);
        printf("국어: ");
           scanf("%d", &a); 
           printf("영어: ");
         scanf("%d", &b);
          printf("수학: ");
          scanf("%d", &c);
          printf("합산: %d \n", a+b+c);
                      int arg[i] ;
            arg[i]=(a+b+c)*1./3 ; 
          printf("평균: %d \n", arg[i]);
    }
    Sum(a, b, c);
    return 0;
}
void Sum(int x, int y, int z)
{
    int i,j;
    char name[100] ;
    for(i=0; i<=2; i++)
    {
            i++;
            scanf("%s", name);
            printf("\n");

    }
}
