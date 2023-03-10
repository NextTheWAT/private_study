#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <conio.h>

#include <windows.h>


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

 

//�޴� ���� ����ü

typedef struct _MENU 

{

   char drink[30];

   char price[30];

}MENU;

 

//�� ���� ����ü

typedef struct _customer 

{

   char name[30];

   char phone[30];

   char drink[30];

}CUSTOMER;

 

//��ȣǥ ����ü

typedef struct _ticket_number 

{

   char number[30];

   char name[30];

   char drink[30];

   char price[30];

}TICKET_NUMBER;

 

 

 

//�Լ�
QUEUE* Create_queue();
void Enqueue(QUEUE* pQ);
void Print(QUEUE* pQ);   //�Լ����� ����
int Dequeue(QUEUE* pQ);
void Search(QUEUE* pQ);
int Que();

void new_add_menu();           //�޴� �߰� 

void new_add_customer();      //�� �߰� 

void new_add_ticker_number();      //��ȣǥ �߰� 

 

int search_menu();            //�޴� �˻� 

int search_customer();         //�� �˻� 

int search_ticket_number();      //��ȣǥ �˻� 

 

void edit_customer();         //�� ���� 

void edit_menu();            //�޴� ���� 

 

void del_customer();         //�� ���� 

void del_menu();            //�޴� ���� 

void del_ticket();

 

void view_menu();            //�޴� ��ü ���� 

void view_customer();         //������ ��ü ���� 

void view_ticket_number();      // ��ȣǥ ��ü ���� 

 

int cross_search();       // �����˻� 

 

void end();                  //������ 

 

void input_menu();             //ȣ������ ?? ������ ���� ����ü�� ��� �Լ�

void input_customer();

void input_ticket_number();

 

void SetTextColor(int background, int text) // UI

{

   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (background<<4) | text);

   //������ background�� 4��Ʈ ������ ������, text�� ���Ͽ� ����

}

 

//����ü �迭 �������� ����

MENU menu_info[200];

int menu_idx=0;        //�޴� ���� ī����

 

CUSTOMER customer_info[200];

int customer_idx=0;        //�� ���� ī����

 

TICKET_NUMBER ticket_number_info[200];

int ticket_number_idx=0;        //��ȣǥ ���� ī����

 

 

 

int main()  //����ȭ��

{

   int i, sel=1, idx;

   input_menu();

   input_customer();

   input_ticket_number();

 

   SetTextColor(15, 0); //15: ���, 0: ������

 

   while(sel!=17)

   {
      system("cls"); //ȭ�������    
      printf("������������������������������������������������������������\n");
      printf("��                            ��\n");
      printf("��     ī�� ���� ���α׷�     ��\n"); 
      printf("��                            ��\n");
      printf("����������߰�������릭\n");
      printf("��  1.  �ű� �޴� �߰�        ��\n");
      printf("��  2.  �ű� �� �߰�        ��\n");
      printf("��  3.  ��ȣǥ �߰�           ��\n");
      printf("���������˻�������릭\n");
      printf("��  4.  ���� �޴� �˻�        ��\n");
      printf("��  5.  ���� �� �˻�        ��\n");
      printf("��  6.  ��ȣǥ �˻�           ��\n");
      printf("������������������릭\n");
      printf("��  7.  ���� �� ����        ��\n");
      printf("��  8.  ���� �޴� ����        ��\n");
      printf("������������������릭\n");
      printf("��  9.  ���� �� ����        ��\n");
      printf("��  10. ���� �޴� ����        ��\n");
      printf("��  11. ���� ��ȣǥ ����      ��\n");
      printf("����������ü��������릭\n");
      printf("��  12. �޴� ��ü ����        ��\n");
      printf("��  13. �� ��ü ����        ��\n");
      printf("��  14. ��ȣǥ ��ü ����      ��\n");
      printf("�������뱳���˻������릭\n");
      printf("��  15. ���� �˻�             ��\n");
      printf("���������⿭������릭\n");
      printf("��  16. ��⿭ �޴�           ��\n");
      printf("������������������릭\n");
      printf("��  17. ���α׷� ����         ��\n");
      printf("������������������������������������������������������������\n");

      printf("  ���ϴ� �޴��� �����ϼ���: ");

 

      scanf("%d", &sel) ;

 

switch(sel)

      {

      case 1:

         new_add_menu();

         break;

      case 2:

         new_add_customer();

         break;

      case 3:

         new_add_ticker_number();

         break;

      case 4:

         search_menu();

         break;

      case 5:

         search_customer();

         break;

      case 6:

         search_ticket_number();

         break;

      case 7:

         edit_customer();

         break;

      case 8:

         edit_menu();

         break;

      case 9:

         del_customer();

         break;

      case 10:

         del_menu();

         break;

      case 11:

        del_ticket(); 

         break;

      case 12:

         view_menu();

         break;

      case 13:

         view_customer();

         break;

      case 14:

        view_ticket_number();

         break;

      case 15:

         cross_search();

         break;
         
         
      case 16:

         Que();

         break;

      case 17:

         end();

         break;

         

      default:

         printf("\n�߸� �����ϼ̽��ϴ�.\n");

         break;

      }

     

      printf("\n�۾��� �Ϸ��Ͽ����ϴ�.\n���ο� �޴��� �����Ϸ��� Enter�� �����ּ���.\n");

      getch(); // �׸� �Է� �ޱ� ��� -> ����ġ�� ���Ӱ� �׺� ���� ����

   }

   return 0;

}

 

//�� ���� ���Ͽ��� �Է¹ޱ� 

void input_customer()

 {

   FILE* c_fp = fopen("Customer.txt", "r");

   char line[150];

   char* ptr;

   int word_cnt;

 

    //�� ���� �Է� 

   while(fscanf(c_fp, "%s", line)>0)

   {

      word_cnt = 0;

      ptr = strtok(line,","); //","������ �߶󳻴� strtok�Լ�  

      while(ptr!=NULL)

      {

         word_cnt++;

         switch(word_cnt)

         {

         case 1: //char name

            strcpy(customer_info[customer_idx].name, ptr);

            break;

         case 2: //char phone

            strcpy(customer_info[customer_idx].phone, ptr);

            break;

         }

         ptr=strtok(NULL,",");

      }

      customer_idx++;

   }

   fclose(c_fp); 

}

// �޴� ���� ���Ͽ��� �Է� �ޱ� 

void input_menu()

 {

   FILE* fp = fopen("Menu.txt", "r");

   char line[150];

   char* ptr;

   int word_cnt;

 

   //�޴� ���� �Է� 

   while(fscanf(fp, "%s", line)>0)

   {

      word_cnt = 0;

      ptr = strtok(line,","); //","������ �߶󳻴� strtok �Լ� 

      while(ptr!=NULL)

      {

         word_cnt++;

         switch(word_cnt)

         {

         case 1: //char drink

            strcpy(menu_info[menu_idx].drink, ptr);

            break;

         case 2: //char price

            strcpy(menu_info[menu_idx].price, ptr);

            break;

         }

         ptr=strtok(NULL,",");

      }

      menu_idx++;

   }

   fclose(fp); 

}

//��ȣǥ ���� ���Ͽ��� �Է¹ޱ� 

void input_ticket_number()

 {

   FILE* fp = fopen("Ticket_number.txt", "r");

   char line[150];

   char* ptr;

   int word_cnt;

//   int count=0; //��ȣǥ �ο�  (x)

 

   //���� �Է� 

   while(fscanf(fp, "%s", line)>0)

   {

      word_cnt = 0;

      ptr = strtok(line,","); //","������ �߶󳻴� strtok �Լ� 

      while(ptr!=NULL)

      {

         word_cnt++;          

         switch(word_cnt)

         {

         case 1: //char number

            strcpy(ticket_number_info[ticket_number_idx].number, ptr);

            break;

         case 2: //char name

            strcpy(ticket_number_info[ticket_number_idx].name, ptr);

            break;

         case 3: //char drink

            strcpy(ticket_number_info[ticket_number_idx].drink, ptr);

            break;

         case 4: //char price

            strcpy(ticket_number_info[ticket_number_idx].price, ptr);

            break;

        }

         ptr=strtok(NULL,",");

      }

      ticket_number_idx++;

   }

   fclose(fp); 

}

 

 

 

 

//1. �ű� �޴� �߰�

void new_add_menu()

{

   FILE* fp = fopen("Menu.txt", "a");

   

   system("cls");

    printf("��������������������������������������������������������\n");

    printf("��                          ��\n");

   printf("��      �ű� �޴� �߰�      ��\n");

   printf("��                          ��\n");

   printf("��������������������������������������������������������\n");   

 

   printf("\n"); 

   printf("�޴� �̸�: ");

   scanf("%s", &menu_info[menu_idx].drink);

   printf("����: ");

   scanf("%s", &menu_info[menu_idx].price);

   printf("=====================\n");

   printf("�ű� �޴� �߰� �Ϸ�\n");

   printf("=====================\n");

 

 

 

   fprintf(fp, "%s,%s\n", menu_info[menu_idx].drink, menu_info[menu_idx].price);

   menu_idx++;

   fclose(fp);

}

 

//2. �ű� �� ���� �߰� 

void new_add_customer()

{

   FILE* c_fp = fopen("Customer.txt", "a");

   

   system("cls");

    printf("��������������������������������������������������������\n");

    printf("��                          ��\n");

   printf("��      �ű� �� �߰�      ��\n");

   printf("��                          ��\n");

   printf("��������������������������������������������������������\n");   

 

 

 

   printf("\n");

   printf("�� �̸�: ");

   scanf("%s", &customer_info[customer_idx].name);

   printf("�� ��ȭ��ȣ: ");

   scanf("%s", &customer_info[customer_idx].phone);

   printf("====================\n");

   printf("�ű� �� �߰� �Ϸ�\n");

   printf("====================\n");

   

   fprintf(c_fp, "\n%s,%s\n", customer_info[customer_idx].name, customer_info[customer_idx].phone);

   customer_idx++;

   fclose(c_fp);

}

 

 

//3. �ű� ��ȣǥ �߰� 

void new_add_ticker_number()

{

   FILE* fp = fopen("Ticket_number.txt", "a");

   system("cls");

    printf("��������������������������������������������������������\n");

    printf("��                          ��\n");

   printf("��     �ű� ��ȣǥ  �߰�    ��\n");

   printf("��                          ��\n");

   printf("��������������������������������������������������������\n");   

 

   

   printf("\n");

   printf("��ȣ: ");

   scanf("%s", &ticket_number_info[ticket_number_idx].number);

   printf("�̸�: ");

   scanf("%s", &ticket_number_info[ticket_number_idx].name);

   printf("����: ");

   scanf("%s", &ticket_number_info[ticket_number_idx].drink);

   printf("����: ");

   scanf("%s", &ticket_number_info[ticket_number_idx].price);

 

   fprintf(fp, "%s,%s,%s,%s\n", ticket_number_info[ticket_number_idx].number, ticket_number_info[ticket_number_idx].name, ticket_number_info[ticket_number_idx].drink, ticket_number_info[ticket_number_idx].price);

   ticket_number_idx++;

   

   fclose(fp);

}

 

//4. �޴� ������ �˻��ϱ� 

int search_menu()

{

   int i;

   char drink[30]; //���⿡ �Է��� �̸� 

 

   system("cls");

   printf("��������������������������������������������������������\n");

   printf("��                          ��\n");

   printf("��        �޴� �˻�         ��\n");

   printf("��                          ��\n");

   printf("��������������������������������������������������������\n");   

 

   printf("\n���� �̸�: ");

   scanf("%s", &drink);

   for(i=0; i<=menu_idx; i++) //menu ������ �迭��ŭ �����ϴ�. 

   {

      if(strcmp(drink, menu_info[i].drink)==0)

      { //strcmp�Լ� ��� -> �Է��� drink�� ����ü �迭�� �޴��� ��ġ�ϸ� 0�� ��ȯ. 

             printf("=====================\n");

            printf("����: %s \n����: %s\n", menu_info[i].drink, menu_info[i].price);

             printf("=====================\n");

            return i;

      }

      

      else if(strcmp(drink, menu_info[i].drink)!=0 && i==menu_idx)

      {

            printf("============================\n");

             printf("ã���ô� ������ �����ϴ�.\n");

             printf("============================\n");

             return i;

      }

      

      else

      continue;

   }

}

 

//5. �̸����� �� ���� �˻� 

int search_customer()

{

   int i;

   char name[30];

   

      system("cls");

    printf("��������������������������������������������������������\n");

    printf("��                          ��\n");

   printf("��        �� �˻�         ��\n");

   printf("��                          ��\n");

   printf("��������������������������������������������������������\n");   

   

   printf("\n�̸�: ");

   scanf("%s", &name);

   for(i=0; i<=customer_idx; i++) 

   {

      if(strcmp(name, customer_info[i].name)==0)

     {  //���� ������ ���� ��ȯ�ϱ� ���� ����

         printf("=================================\n");

         printf("�� �̸�: %s \n�� ��ȭ��ȣ: %s\n", customer_info[i].name, customer_info[i].phone);   

         printf("=================================\n");

         return i;

       }

       

       else if(strcmp(name ,customer_info[i].name)!=0 && i==customer_idx)

       {

          printf("============================\n");

          printf("ã���ô� ������ �����ϴ�.\n");

          printf("============================\n");

      return i;   

     }

     

     else continue;

   }

}

 

//6. ��ȣǥ ��ȸ 

int search_ticket_number()

{

   int i;

   char number[30];

   

      system("cls");

    printf("��������������������������������������������������������\n");

    printf("��                          ��\n");

   printf("��       ��ȣǥ �˻�        ��\n");

   printf("��                          ��\n");

   printf("��������������������������������������������������������\n");   

 

   

   printf("\n��ȣǥ: ");

   scanf("%s", &number);

   for(i=0; i<ticket_number_idx; i++) 

   {

      if(strcmp(number, ticket_number_info[i].number)==0)

     {  

      printf("=====================\n");

      printf("��ȣ: %s \n�̸�: %s \n����: %s \n����: %s \n", ticket_number_info[i].number, ticket_number_info[i].name,ticket_number_info[i].drink,ticket_number_info[i].price);

       printf("=====================\n");

         return i;

        }

   }

   return -1;

}

 

//7. �� ���� ���� 

 void edit_customer()

{

   int i, j, k;

   char name[20];

   char info[20];

   

      system("cls");

    printf("����������������������������������������������������������\n");

    printf("��                           ��\n");

   printf("��      �� ���� ����       ��\n");

   printf("��                           ��\n");

   printf("����������������������������������������������������������\n");   

 

 

   

   printf("\n�̸��� �Է����ּ���: "); 

   scanf("%s", name);

   printf("\n");

 

   for(i=0; i<customer_idx; i++)

   {

      if(strcmp(name, customer_info[i].name)==0)

      { 

         printf("�̸�: %s\n��ȭ��ȣ: %s\n", customer_info[i].name, customer_info[i].phone);

         printf("\n");

         printf("1.�̸� 2.��ȭ��ȣ\n");

         printf("��ȣ�� �����ϼ���: ");

         scanf("%d", &j);

         if(j==1)

         {

            printf("������ �̸�: ");

            scanf("%s", customer_info[i].name); 

         } 

         else if(j==2)

         {

            printf("������ ��ȭ��ȣ: ");

            scanf("%s", customer_info[i].phone); 

         } 

         printf("\n");

      }

   }

}

 

//8. �޴� ���� ���� 

 void edit_menu()

{

   int i, j, k;

   char drink[20];

   char info[20];

   

      system("cls");

    printf("��������������������������������������������������������\n");

    printf("��                          ��\n");

   printf("��        �޴� ����         ��\n");

   printf("��                          ��\n");

   printf("��������������������������������������������������������\n");   

 

   

   printf("\n�޴��� �Է����ּ���: "); 

   scanf("%s", drink);

   printf("\n");

 

   for(i=0; i<menu_idx; i++)

   {

      if(strcmp(drink, menu_info[i].drink)==0)

      {

         printf("����: %s\n����: %s\n", menu_info[i].drink, menu_info[i].price);

         printf("\n");

         printf("1.���� 2.����\n");

         printf("��ȣ�� �����ϼ���: ");

         scanf("%d", &j);

         if(j==1)

         {

            printf("������ ����: ");

            scanf("%s", menu_info[i].drink); 

         } 

         else if(j==2)

         {

            printf("������ ����: ");

            scanf("%s", menu_info[i].price); 

         } 

         printf("\n");

      }

   }

}

 

 

 

//9. ���� �� ���� 

void del_customer()

 {   

   FILE* fp = fopen("Customer.txt", "r+");

    int i=0;

   char name[30];

   

      system("cls");

    printf("��������������������������������������������������������\n");

    printf("��                          ��\n");

   printf("��        �� ����         ��\n");

   printf("��                          ��\n");

   printf("��������������������������������������������������������\n");   

 

   

   printf("\n�̸�: ");

   scanf("%s", &name);   

 

    //�Էµ� �̸����� �� ���� ���� 

    for(i=0; i<customer_idx; i++)

    {

        //������ �� ���� ���

        if(strcmp(name, customer_info[i].name)==0)

        {

           printf("====================\n");

           printf("������ �� �̸�\n�̸�: %s\n��ȭ��ȣ: %s\n",customer_info[i].name, customer_info[i].phone);

           printf("====================\n");

            memset(&customer_info[i], 0x00, sizeof(CUSTOMER));

         fprintf(fp, "%s %s\n", customer_info[i].name, customer_info[i].phone);

         fclose(fp);

        }

    }

}

 

 

 

 

//10. ���� �޴� ���� 

void del_menu()

 {   

   FILE* fp = fopen("Menu.txt", "r+");

 

    int i=0;

   char drink[30];

   

      system("cls");

    printf("��������������������������������������������������������\n");

    printf("��                          ��\n");

   printf("��        �޴� ����         ��\n");

   printf("��                          ��\n");

   printf("��������������������������������������������������������\n");   

 

   

   printf("\n�޴� �̸�: ");

   scanf("%s", &drink);   

 

    //�Էµ� �޴��� ���� ���� ���� 

    for(i=0; i<menu_idx; i++)

    {

        //������ ���� ���� ���

        if(strcmp(drink, menu_info[i].drink)==0)

        {

           printf("====================\n");

           printf("������ �޴�\n����: %s\n����: %s\n",menu_info[i].drink, menu_info[i].price);

           printf("====================\n");

           memset(&menu_info[i], 0x00, sizeof(MENU));

         fprintf(fp, "%s %s\n", menu_info[i].drink, menu_info[i].price);

         fclose(fp);

        }

    }

}

 

 

//11. ���� ��ȣǥ ����  

void del_ticket()

 {   

   FILE* fp = fopen("Ticket_number.txt", "r+");

    int i=0;

   char num[30];

   

      system("cls");

    printf("��������������������������������������������������������\n");

    printf("��                          ��\n");

   printf("��        ��ȣǥ ����        ��\n");

   printf("��                          ��\n");

   printf("��������������������������������������������������������\n");   

 

    

   printf("\n ��ȣǥ ��ȣ: ");

   scanf("%s", &num);   

 

    

    for(i=0; i<ticket_number_idx; i++) 

    {

       

        if(strcmp(num, ticket_number_info[i].number)==0)

        {

           printf("====================\n");

           printf("�����Ǿ����ϴ�!\n"); //���� ���� ���� 

           printf("====================\n");

           memset(&ticket_number_info[i], 0x00, sizeof(TICKET_NUMBER));

         fprintf(fp, "%s %s %s %s\n", ticket_number_info[i].number, ticket_number_info[i].name, ticket_number_info[i].drink, ticket_number_info[i].price);

         fclose(fp);

        }

    }

}

 

 

 

 

//12. �޴� ��ü����

void view_menu()

{

   int i;

   

      system("cls");

    printf("������������������������������������������������������������\n");

    printf("��                            ��\n");

   printf("��        �޴� ��ü����       ��\n");

   printf("��                            ��\n");

   printf("������������������������������������������������������������\n");   

 

   

   printf("\n          Menu                    Price \n");

   printf("------------------------------------------------\n");

   

   

   

   for(i=0; i<menu_idx; i++) //��ȿ�� �迭 �ҷ����� 

   {

      printf("%15s%20s\n",menu_info[i].drink,menu_info[i].price);

   }

}

 

 

 

 

 

//13. �� ��ü����  

void view_customer()

{

   int i;

   

         system("cls");

    printf("������������������������������������������������������������\n");

    printf("��                            ��\n");

   printf("��        �� ��ü����       ��\n");

   printf("��                            ��\n");

   printf("������������������������������������������������������������\n");   

   printf("\n          Name           Phone       \n");

   printf("---------------------------------------\n");

   

   for(i=0; i<customer_idx; i++)

   {

      printf("%15s%20s\n", customer_info[i].name, customer_info[i].phone);

   }

}

 

 

 

 

 

//14. ��ȣǥ ��ü����  

void view_ticket_number()

{

   int i;

   TICKET_NUMBER temp;

         system("cls");

    printf("����������������������������������������������������������������\n");

    printf("��                              ��\n");

   printf("��        ��ȣǥ ��ü����       ��\n");

   printf("��                              ��\n");

   printf("����������������������������������������������������������������\n");   

   printf("\n          ��ȣ           �̸�           ����           ����\n");

   printf("-------------------------------------------------------------\n");

   

   for(i=0; i<ticket_number_idx-1; i++) //����  

   {

         for(int j=i+1; j<ticket_number_idx; j++)

         {

            if(strcmp(ticket_number_info[i].number, ticket_number_info[j].number)> 0)

             {

                  temp = ticket_number_info[i];

                  ticket_number_info[i] = ticket_number_info[j];

                  ticket_number_info[j] = temp;

            }   

      }

   }

   

   

   for(i=0; i<ticket_number_idx; i++)

   {

      printf("%12s%15s%18s%15s\n", ticket_number_info[i].number, ticket_number_info[i].name, ticket_number_info[i].drink, ticket_number_info[i].price);

   }

}

 

 

 

 

 

//15. �޴� ����, �� ���� �˻��ϱ� 

int cross_search()

{

   int i,j;

   char drink[30]; //���⿡ �Է��� �̸� 

   char name[30];

 

   system("cls");

    printf("��������������������������������������������������������\n");

    printf("��                          ��\n");

   printf("��        ���� �˻�         ��\n");

   printf("��                          ��\n");

   printf("��������������������������������������������������������\n");   

 

   

   printf("\n�� �̸�: ");

   scanf("%s", &name);

   

   

   for(j=0; j<customer_idx; j++) 

   {

      if(strcmp(name,  ticket_number_info[j].name)==0) //���� ������ ���� ��ȯ�ϱ� ���� ����

     {  

         printf("�� �̸�: %s \n ���� �޴�: %s\n", customer_info[j].name, ticket_number_info[j].drink);   

      return j; 

       }

    }

     

}

 

 

 

 
// 16�� 
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
                  printf("\t �� �� ��ȣǥ�� �����Ǿ����ϴ�.\n \t������ ��ȣǥ = %d\n", item);
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

 

//17. ���α׷� ����

void end()

{

   printf("\n���α׷��� �����մϴ�\n");

   exit(1);

}

