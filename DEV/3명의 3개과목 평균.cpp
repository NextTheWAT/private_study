#include <stdio.h>

void Sum(int x, int y, int z); 

int main(void)
{
    int a, b, c, i,j ;
    char name[100] ;

    for(i=0; i<=2; i++)
    {
    	printf("�̸�: ");
        scanf("%s", name);
        printf("����: ");
           scanf("%d", &a); 
           printf("����: ");
         scanf("%d", &b);
          printf("����: ");
          scanf("%d", &c);
          printf("�ջ�: %d \n", a+b+c);
                      int arg[i] ;
            arg[i]=(a+b+c)*1./3 ; 
          printf("���: %d \n", arg[i]);
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
