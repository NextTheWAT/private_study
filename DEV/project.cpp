#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

//�޴� ���� ����ü
typedef struct _MENU {
   char drink[30];
   char price[30];
}MENU;

//�� ���� ����ü
typedef struct _customer {
   char name[30];
   char phone[30];
}CUSTOMER;

//��ȣǥ ����ü
typedef struct _ticket_number {
   char number[30];
   char name[30];
   char drink[30];
   char price[30];
}TICKET_NUMBER;


//�Լ�
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

void view_menu();            //�޴� ��ü ���� 
void view_customer();         //������ ��ü ���� 

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

   while(sel!=12)
   {
      system("cls"); //ȭ�������
      printf("============================\n");
      printf("|     ī�� ���� ���α׷�    |\n");
      printf("============�߰�============\n");
      printf("|  1. �ű� �޴� �߰�        |\n");
      printf("|  2. �ű� �� �߰�        |\n");
      printf("============�˻�============\n");
      printf("|  3. ���� �޴� �˻�        |\n");
      printf("|  4. ���� �� �˻�        |\n");
      printf("|  5. ��ȣǥ ��ȸ           |\n");
      printf("============����============\n");
      printf("|  6. ���� �� ����        |\n");
      printf("|  7. ���� �޴� ����        |\n");
      printf("============����============\n");
      printf("|  8. ���� �� ����        |\n");
      printf("|  9. ���� �޴� ����        |\n");
      printf("==========��ü ����=========\n");
      printf("|  10. �޴� ��ü ����       |\n");
      printf("|  11. �� ��ü ����       |\n");
      printf("============����============\n");
      printf("|  12. ��ȣǥ �߰�          |\n");
      printf("|  13. ���α׷� ����        |\n");
      printf("============================\n");
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
         search_menu();
         break;
      case 4:
         search_customer();
         break;
      case 5:
         search_ticket_number();
         break;
      case 6:
         edit_customer();
         break;
      case 7:
         edit_menu();
         break;
      case 8:
         del_customer();
         break;
      case 9:
         del_menu();
         break;
      case 10:
         view_menu();
         break;
      case 11:
         view_customer();
         break;
      case 12:
         new_add_ticker_number();
         break;
      case 13:
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
   FILE* c_fp = fopen("C:\\project\\Customer.txt", "r");
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
   FILE* fp = fopen("C:\\project\\Menu.txt", "r");
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
   FILE* fp = fopen("C:\\project\\Ticket_number.txt", "r");
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
   FILE* fp = fopen("C:\\project\\Menu.txt", "a");
   printf("\n");
   printf("����: ");
   scanf("%s", &menu_info[menu_idx].drink);
   printf("����: ");
   scanf("%s", &menu_info[menu_idx].price);

   fprintf(fp, "%s,%s\n", menu_info[menu_idx].drink, menu_info[menu_idx].price);
   menu_idx++;
   fclose(fp);
}

//2. �ű� �� ���� �߰� 
void new_add_customer()
{
   FILE* c_fp = fopen("C:\\project\\Customer.txt", "a");

   printf("\n");
   printf("�� �̸�: ");
   scanf("%s", &customer_info[customer_idx].name);
   printf("�� ��ȭ��ȣ: ");
   scanf("%s", &customer_info[customer_idx].phone);
   
   fprintf(c_fp, "\n%s,%s,%s\n", customer_info[customer_idx].name, customer_info[customer_idx].phone);
   customer_idx++;
   fclose(c_fp);
}

//3. �޴� ������ �˻��ϱ� 
int search_menu()
{
   int i;
   char drink[30]; //���⿡ �Է��� �̸� 
   printf("\n���� ����: ");
   scanf("%s", &drink);
   for(i=0; i<menu_idx++; i++) //menu ������ �迭��ŭ �����ϴ�. 
   {
      if(strcmp(drink, menu_info[i].drink)==0) //strcmp�Լ� ��� -> �Է��� drink�� ����ü �迭�� �� ������ ��ġ�ϸ� 0�� ��ȯ. 
         return i; //0�� �Ǹ� true�� �Ǿ� if���� ��. 
   }
   return -1; //for�� ���ư��� ������ �� ã�� �� ��� 
}

//4. �̸����� �� ���� ��ȸ 
int search_customer()
{
   int i;
   char name[30];
   printf("\n�̸�: ");
   scanf("%s", &name);
   for(i=0; i<customer_idx; i++) 
   {
      if(strcmp(name, customer_info[i].name)==0)  //���� ������ ���� ��ȯ�ϱ� ���� ����
         return i;      
   }
   return -1;
} 

//5. ��ȣǥ ��ȸ 
int search_ticket_number()
{
   int i;
   char number[30];
   printf("\n��ȣǥ: ");
   scanf("%s", &number);
   for(i=0; i<ticket_number_idx; i++) 
   {
      if(strcmp(number, ticket_number_info[i].number)==0)  //���� ������ ���� ��ȯ�ϱ� ���� ����
         return i;
   }
   return -1;
} 

//6. �� ���� ���� 
 void edit_customer()
{
	int i, j, k;
	char name[20];
	char info[20];
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
				scanf("%s", customer_info[i].name); 
			} 
			printf("\n");
		}
	}
}

//7. �޴� ���� ���� 
 void edit_menu()
{
	int i, j, k;
	char drink[20];
	char info[20];
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

//8. ���� �� ���� 
void del_customer()
 {	
	FILE* fp = fopen("D:\\project\\customer_info.txt", "r+");

 	int i=0;
	char name[30];
	printf("\n�̸�: ");
	scanf("%s", &name);	

 	//�Էµ� �̸����� �� ���� ���� 
 	for(i=0; i<customer_idx; i++)
 	{
  		//������ �� ���� ���
  		if(strcmp(name, customer_info[i].name)==0)
  		{
  			printf("\n������ �� �̸�\n�̸�: %s\n��ȭ��ȣ: %s\n",customer_info[i].name, customer_info[i].phone);
  			//�� ���� ���� 
  			memset(&customer_info[i], 0x00, sizeof(CUSTOMER));
			fprintf(fp, "%s %s\n", customer_info[i].name, customer_info[i].phone);
			fclose(fp);
  		}
 	}
}

//9. ���� �޴� ���� 
void del_menu()
 {	
	FILE* fp = fopen("D:\\project\\menu_info.txt", "r+");

 	int i=0;
	char drink[30];
	printf("\n�̸�: ");
	scanf("%s", &drink);	

 	//�Էµ� �޴��� ���� ���� ���� 
 	for(i=0; i<menu_idx; i++)
 	{
  		//������ ���� ���� ���
  		if(strcmp(drink, menu_info[i].drink)==0)
  		{
  			printf("\n������ �޴�\n����: %s\n����: %s\n",menu_info[i].drink, menu_info[i].price);
  			//���� ���� ���� 
  			memset(&menu_info[i], 0x00, sizeof(MENU));
			fprintf(fp, "%s %s\n", menu_info[i].drink, menu_info[i].price);
			fclose(fp);
  		}
 	}
}

//10. �޴� ��ü����
void view_menu()
{
   int i;
   printf("\n          Menu                    Price \n");
   printf("------------------------------------------------\n");
   for(i=0; i<menu_idx; i++) //��ȿ�� �迭 �ҷ����� 
   {
      printf("%15s%20s\n",menu_info[i].drink,menu_info[i].price);
   }
}

//11. �� ��ü����  
void view_customer()
{
   int i;
   printf("\n          Name           Phone       \n");
   printf("---------------------------------------\n");
   for(i=0; i<customer_idx; i++)
   {
      printf("%15s%20s\n", customer_info[i].name, customer_info[i].phone);
   }
}

//12. �ű� ��ȣǥ �߰� 
void new_add_ticker_number()
{
   FILE* fp = fopen("C:\\project\\Ticket_number.txt", "a");
   printf("\n");
   printf("��ȣ: ");
   scanf("%s", &ticket_number_info[menu_idx].number);
   printf("�̸�: ");
   scanf("%s", &ticket_number_info[menu_idx].name);
   printf("����: ");
   scanf("%s", &ticket_number_info[menu_idx].drink);
   printf("����: ");
   scanf("%s", &ticket_number_info[menu_idx].price);

   fprintf(fp, "%s,%s,%s,%s\n", ticket_number_info[menu_idx].number, ticket_number_info[menu_idx].name, ticket_number_info[menu_idx].drink,ticket_number_info[menu_idx].price);
   ticket_number_idx++;
   fclose(fp);
}


//13. ���α׷� ����
void end()
{
   printf("\n���α׷��� �����մϴ�\n");
   exit(1);
}

