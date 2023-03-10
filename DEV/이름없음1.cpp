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
                          //queue를 위한 구조체 선언
typedef struct queue
{
    LIST* front;
    LIST* rear;
}QUEUE;
////////////////////////////////////////////////////


QUEUE* Create_queue();
void Enqueue(QUEUE* pQ);
void Print(QUEUE* pQ);   //함수원형 선언
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
    	printf("\n\n\n     ┏━━━━━━━━━━━━━━━━━━━━┓\n");
    	printf("     ┃                    ┃    \n"); 
        printf("     ┃    *** MeNu ***    ┃\n");
        printf("     ┃   1) 번호표 생성   ┃\n");
        printf("     ┃   2) 번호표 입력   ┃\n");
        printf("     ┃   3) 번호표 삭제   ┃\n");
        printf("     ┃   4) 대기열        ┃\n");
        printf("     ┃   5) Exit          ┃\n");
        printf("     ┃                    ┃\n"); 
        printf("     ┃                    ┃    \n"); 
        printf("     ┗━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("     SELECT : ");
        scanf("%d", &val);
        switch(val)
        {
        case 1 : Q = Create_queue(); break;
        case 2 :  Enqueue(Q); break;
        case 3 :  item = Dequeue(Q);
                  printf("\t 맨 앞 번호표가 삭제되었습니다. %d\n", item);
                  break;
        case 4 : Print(Q); break;
        case 5 : exit(1);
        }
    }
}

/* 큐를 초기화 하는 함수(front와 rear를 생성한다.) */
QUEUE* Create_queue()
{
	system("cls");
    QUEUE* Q;
    Q = (QUEUE*)malloc(sizeof(QUEUE));
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}

/* 큐에서 데이터를 입력하는 함수 */
void Enqueue(QUEUE* pQ)
{
	system("cls");
    LIST* newNode, *temp;
    int val;
    printf("\t 번호표를 입력해 주세요. : ");
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

/* 큐에서 데이터를 삭제하는 함수 */
int Dequeue(QUEUE* pQ)
{
	system("cls");
    LIST* temp;
    int item;
   
    if(pQ->front == NULL)
    {
        printf("\n\t 현재 대기열이 없습니다.\n");
        exit(1);
    }
    else
    {
        temp = pQ->front;//삭제할 데이터
        item = temp->data;
        pQ->front = pQ->front->link;//front를 앞으로 증가시킴
        if(pQ->front == NULL)//삭제할 노드가 한개일 경우
        {
            pQ->rear = NULL;
        }
        free(temp);
    }
    return item;
}

/* 큐에 있는 데이터를 출력하는 함수 */
void Print(QUEUE* pQ)
{
	system("cls");
    LIST* temp;
    temp = pQ->front;
    printf("\n\t*** 대기열 ***\n\t");
    while(temp != NULL)
    {
        printf("%d번 ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}


