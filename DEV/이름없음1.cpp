#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>


/////////////////////////////////////////////////////
typedef struct list
{
    int data;
    struct list* link;
}LIST;
                          //queue�� ���� ����ü ����
typedef struct queue
{
    LIST* front;
    LIST* rear;
}QUEUE;
////////////////////////////////////////////////////


QUEUE* Create_queue();
void Enqueue(QUEUE* pQ);
void Print(QUEUE* pQ);   //�Լ����� ����
int Dequeue(QUEUE* pQ);
void Search(QUEUE* pQ);
int que();

///////////////////////////////////////////////////

int main(){
	
	que();
}

int Que()
{
    QUEUE* Q;
    int item, val;
    system("cls");
    while(1)
    {
    	printf("\n\n\n     ��������������������������������������������\n");
    	printf("     ��                    ��    \n"); 
        printf("     ��    *** MeNu ***    ��\n");
        printf("     ��   1) ��ȣǥ ����   ��\n");
        printf("     ��   2) ��ȣǥ �Է�   ��\n");
        printf("     ��   3) ��ȣǥ ����   ��\n");
        printf("     ��   4) ��⿭        ��\n");
        printf("     ��   5) Exit          ��\n");
        printf("     ��                    ��\n"); 
        printf("     ��                    ��    \n"); 
        printf("     ��������������������������������������������\n");
        printf("     SELECT : ");
        scanf("%d", &val);
        switch(val)
        {
        case 1 : Q = Create_queue(); break;
        case 2 :  Enqueue(Q); break;
        case 3 :  item = Dequeue(Q);
                  printf("\t �� �� ��ȣǥ�� �����Ǿ����ϴ�. %d\n", item);
                  break;
        case 4 : Print(Q); break;
        case 5 : exit(1);
        }
    }
}

/* ť�� �ʱ�ȭ �ϴ� �Լ�(front�� rear�� �����Ѵ�.) */
QUEUE* Create_queue()
{
	system("cls");
    QUEUE* Q;
    Q = (QUEUE*)malloc(sizeof(QUEUE));
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}

/* ť���� �����͸� �Է��ϴ� �Լ� */
void Enqueue(QUEUE* pQ)
{
	system("cls");
    LIST* newNode, *temp;
    int val;
    printf("\t ��ȣǥ�� �Է��� �ּ���. : ");
    scanf("%d", &val);

    newNode = (LIST*)malloc(sizeof(LIST));
    newNode->data = val;
    newNode->link = NULL;

    if(pQ->rear == NULL)
    {
        pQ->rear = newNode;
        pQ->front = newNode;
    }
    else
    {
        temp = pQ->rear;
        while(temp->link != NULL)
            temp = temp->link;
        temp->link = newNode;
    }
}

/* ť���� �����͸� �����ϴ� �Լ� */
int Dequeue(QUEUE* pQ)
{
	system("cls");
    LIST* temp;
    int item;
   
    if(pQ->front == NULL)
    {
        printf("\n\t ���� ��⿭�� �����ϴ�.\n");
        exit(1);
    }
    else
    {
        temp = pQ->front;//������ ������
        item = temp->data;
        pQ->front = pQ->front->link;//front�� ������ ������Ŵ
        if(pQ->front == NULL)//������ ��尡 �Ѱ��� ���
        {
            pQ->rear = NULL;
        }
        free(temp);
    }
    return item;
}

/* ť�� �ִ� �����͸� ����ϴ� �Լ� */
void Print(QUEUE* pQ)
{
	system("cls");
    LIST* temp;
    temp = pQ->front;
    printf("\n\t*** ��⿭ ***\n\t");
    while(temp != NULL)
    {
        printf("%d�� ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}


