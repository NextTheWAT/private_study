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
                          //queue를 위한 구조체 선언
typedef struct queue
{
    LIST* front;
    LIST* rear;
}QUEUE;

 

//메뉴 정보 구조체

typedef struct _MENU 

{

   char drink[30];

   char price[30];

}MENU;

 

//고객 정보 구조체

typedef struct _customer 

{

   char name[30];

   char phone[30];

   char drink[30];

}CUSTOMER;

 

//번호표 구조체

typedef struct _ticket_number 

{

   char number[30];

   char name[30];

   char drink[30];

   char price[30];

}TICKET_NUMBER;

 

 

 

//함수
QUEUE* Create_queue();
void Enqueue(QUEUE* pQ);
void Print(QUEUE* pQ);   //함수원형 선언
int Dequeue(QUEUE* pQ);
void Search(QUEUE* pQ);
int Que();

void new_add_menu();           //메뉴 추가 

void new_add_customer();      //고객 추가 

void new_add_ticker_number();      //번호표 추가 

 

int search_menu();            //메뉴 검색 

int search_customer();         //고객 검색 

int search_ticket_number();      //번호표 검색 

 

void edit_customer();         //고객 수정 

void edit_menu();            //메뉴 수정 

 

void del_customer();         //고객 삭제 

void del_menu();            //메뉴 삭제 

void del_ticket();

 

void view_menu();            //메뉴 전체 보기 

void view_customer();         //고객정보 전체 보기 

void view_ticket_number();      // 번호표 전체 보기 

 

int cross_search();       // 교차검색 

 

void end();                  //끝내기 

 

void input_menu();             //호출했을 ?? 정보를 전부 구조체에 담는 함수

void input_customer();

void input_ticket_number();

 

void SetTextColor(int background, int text) // UI

{

   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (background<<4) | text);

   //배경색인 background를 4비트 앞으로 보내고, text와 더하여 적용

}

 

//구조체 배열 전역변수 선언

MENU menu_info[200];

int menu_idx=0;        //메뉴 정보 카운팅

 

CUSTOMER customer_info[200];

int customer_idx=0;        //고객 정보 카운팅

 

TICKET_NUMBER ticket_number_info[200];

int ticket_number_idx=0;        //번호표 정보 카운팅

 

 

 

int main()  //메인화면

{

   int i, sel=1, idx;

   input_menu();

   input_customer();

   input_ticket_number();

 

   SetTextColor(15, 0); //15: 흰색, 0: 검은색

 

   while(sel!=17)

   {
      system("cls"); //화면지우기    
      printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
      printf("┃                            ┃\n");
      printf("┃     카페 관리 프로그램     ┃\n"); 
      printf("┃                            ┃\n");
      printf("┃〓〓〓〓〓〓추가〓〓〓〓〓〓┃\n");
      printf("┃  1.  신규 메뉴 추가        ┃\n");
      printf("┃  2.  신규 고객 추가        ┃\n");
      printf("┃  3.  번호표 추가           ┃\n");
      printf("┃〓〓〓〓〓〓검색〓〓〓〓〓〓┃\n");
      printf("┃  4.  기존 메뉴 검색        ┃\n");
      printf("┃  5.  기존 고객 검색        ┃\n");
      printf("┃  6.  번호표 검색           ┃\n");
      printf("┃〓〓〓〓〓〓수정〓〓〓〓〓〓┃\n");
      printf("┃  7.  기존 고객 수정        ┃\n");
      printf("┃  8.  기존 메뉴 수정        ┃\n");
      printf("┃〓〓〓〓〓〓삭제〓〓〓〓〓〓┃\n");
      printf("┃  9.  기존 고객 삭제        ┃\n");
      printf("┃  10. 기존 메뉴 삭제        ┃\n");
      printf("┃  11. 기존 번호표 삭제      ┃\n");
      printf("┃〓〓〓〓〓전체보기〓〓〓〓〓┃\n");
      printf("┃  12. 메뉴 전체 보기        ┃\n");
      printf("┃  13. 고객 전체 보기        ┃\n");
      printf("┃  14. 번호표 전체 보기      ┃\n");
      printf("┃〓〓〓〓〓교차검색〓〓〓〓〓┃\n");
      printf("┃  15. 교차 검색             ┃\n");
      printf("┃〓〓〓〓〓대기열〓〓〓〓〓〓┃\n");
      printf("┃  16. 대기열 메뉴           ┃\n");
      printf("┃〓〓〓〓〓〓종료〓〓〓〓〓〓┃\n");
      printf("┃  17. 프로그램 종료         ┃\n");
      printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

      printf("  원하는 메뉴를 선택하세요: ");

 

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

         printf("\n잘못 선택하셨습니다.\n");

         break;

      }

     

      printf("\n작업을 완료하였습니다.\n새로운 메뉴를 선택하려면 Enter를 눌러주세요.\n");

      getch(); // 항목 입력 받기 대기 -> 엔터치면 새롭게 항복 선택 가능

   }

   return 0;

}

 

//고객 정보 파일에서 입력받기 

void input_customer()

 {

   FILE* c_fp = fopen("Customer.txt", "r");

   char line[150];

   char* ptr;

   int word_cnt;

 

    //고객 정보 입력 

   while(fscanf(c_fp, "%s", line)>0)

   {

      word_cnt = 0;

      ptr = strtok(line,","); //","단위로 잘라내는 strtok함수  

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

// 메뉴 정보 파일에서 입력 받기 

void input_menu()

 {

   FILE* fp = fopen("Menu.txt", "r");

   char line[150];

   char* ptr;

   int word_cnt;

 

   //메뉴 정보 입력 

   while(fscanf(fp, "%s", line)>0)

   {

      word_cnt = 0;

      ptr = strtok(line,","); //","단위로 잘라내는 strtok 함수 

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

//번호표 정보 파일에서 입력받기 

void input_ticket_number()

 {

   FILE* fp = fopen("Ticket_number.txt", "r");

   char line[150];

   char* ptr;

   int word_cnt;

//   int count=0; //번호표 부여  (x)

 

   //정보 입력 

   while(fscanf(fp, "%s", line)>0)

   {

      word_cnt = 0;

      ptr = strtok(line,","); //","단위로 잘라내는 strtok 함수 

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

 

 

 

 

//1. 신규 메뉴 추가

void new_add_menu()

{

   FILE* fp = fopen("Menu.txt", "a");

   

   system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                          ┃\n");

   printf("┃      신규 메뉴 추가      ┃\n");

   printf("┃                          ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

 

   printf("\n"); 

   printf("메뉴 이름: ");

   scanf("%s", &menu_info[menu_idx].drink);

   printf("가격: ");

   scanf("%s", &menu_info[menu_idx].price);

   printf("=====================\n");

   printf("신규 메뉴 추가 완료\n");

   printf("=====================\n");

 

 

 

   fprintf(fp, "%s,%s\n", menu_info[menu_idx].drink, menu_info[menu_idx].price);

   menu_idx++;

   fclose(fp);

}

 

//2. 신규 고객 정보 추가 

void new_add_customer()

{

   FILE* c_fp = fopen("Customer.txt", "a");

   

   system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                          ┃\n");

   printf("┃      신규 고객 추가      ┃\n");

   printf("┃                          ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

 

 

 

   printf("\n");

   printf("고객 이름: ");

   scanf("%s", &customer_info[customer_idx].name);

   printf("고객 전화번호: ");

   scanf("%s", &customer_info[customer_idx].phone);

   printf("====================\n");

   printf("신규 고객 추가 완료\n");

   printf("====================\n");

   

   fprintf(c_fp, "\n%s,%s\n", customer_info[customer_idx].name, customer_info[customer_idx].phone);

   customer_idx++;

   fclose(c_fp);

}

 

 

//3. 신규 번호표 추가 

void new_add_ticker_number()

{

   FILE* fp = fopen("Ticket_number.txt", "a");

   system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                          ┃\n");

   printf("┃     신규 번호표  추가    ┃\n");

   printf("┃                          ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

 

   

   printf("\n");

   printf("번호: ");

   scanf("%s", &ticket_number_info[ticket_number_idx].number);

   printf("이름: ");

   scanf("%s", &ticket_number_info[ticket_number_idx].name);

   printf("음료: ");

   scanf("%s", &ticket_number_info[ticket_number_idx].drink);

   printf("가격: ");

   scanf("%s", &ticket_number_info[ticket_number_idx].price);

 

   fprintf(fp, "%s,%s,%s,%s\n", ticket_number_info[ticket_number_idx].number, ticket_number_info[ticket_number_idx].name, ticket_number_info[ticket_number_idx].drink, ticket_number_info[ticket_number_idx].price);

   ticket_number_idx++;

   

   fclose(fp);

}

 

//4. 메뉴 종류로 검색하기 

int search_menu()

{

   int i;

   char drink[30]; //여기에 입력할 이름 

 

   system("cls");

   printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

   printf("┃                          ┃\n");

   printf("┃        메뉴 검색         ┃\n");

   printf("┃                          ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

 

   printf("\n음료 이름: ");

   scanf("%s", &drink);

   for(i=0; i<=menu_idx; i++) //menu 유요한 배열만큼 돌립니다. 

   {

      if(strcmp(drink, menu_info[i].drink)==0)

      { //strcmp함수 사용 -> 입력한 drink과 구조체 배열의 메뉴가 일치하면 0을 반환. 

             printf("=====================\n");

            printf("음료: %s \n가격: %s\n", menu_info[i].drink, menu_info[i].price);

             printf("=====================\n");

            return i;

      }

      

      else if(strcmp(drink, menu_info[i].drink)!=0 && i==menu_idx)

      {

            printf("============================\n");

             printf("찾으시는 정보가 없습니다.\n");

             printf("============================\n");

             return i;

      }

      

      else

      continue;

   }

}

 

//5. 이름으로 고객 정보 검색 

int search_customer()

{

   int i;

   char name[30];

   

      system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                          ┃\n");

   printf("┃        고객 검색         ┃\n");

   printf("┃                          ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

   

   printf("\n이름: ");

   scanf("%s", &name);

   for(i=0; i<=customer_idx; i++) 

   {

      if(strcmp(name, customer_info[i].name)==0)

     {  //고객의 유무에 따라 반환하기 위한 형태

         printf("=================================\n");

         printf("고객 이름: %s \n고객 전화번호: %s\n", customer_info[i].name, customer_info[i].phone);   

         printf("=================================\n");

         return i;

       }

       

       else if(strcmp(name ,customer_info[i].name)!=0 && i==customer_idx)

       {

          printf("============================\n");

          printf("찾으시는 정보가 없습니다.\n");

          printf("============================\n");

      return i;   

     }

     

     else continue;

   }

}

 

//6. 번호표 조회 

int search_ticket_number()

{

   int i;

   char number[30];

   

      system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                          ┃\n");

   printf("┃       번호표 검색        ┃\n");

   printf("┃                          ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

 

   

   printf("\n번호표: ");

   scanf("%s", &number);

   for(i=0; i<ticket_number_idx; i++) 

   {

      if(strcmp(number, ticket_number_info[i].number)==0)

     {  

      printf("=====================\n");

      printf("번호: %s \n이름: %s \n음료: %s \n가격: %s \n", ticket_number_info[i].number, ticket_number_info[i].name,ticket_number_info[i].drink,ticket_number_info[i].price);

       printf("=====================\n");

         return i;

        }

   }

   return -1;

}

 

//7. 고객 정보 수정 

 void edit_customer()

{

   int i, j, k;

   char name[20];

   char info[20];

   

      system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                           ┃\n");

   printf("┃      고객 정보 수정       ┃\n");

   printf("┃                           ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

 

 

   

   printf("\n이름을 입력해주세요: "); 

   scanf("%s", name);

   printf("\n");

 

   for(i=0; i<customer_idx; i++)

   {

      if(strcmp(name, customer_info[i].name)==0)

      { 

         printf("이름: %s\n전화번호: %s\n", customer_info[i].name, customer_info[i].phone);

         printf("\n");

         printf("1.이름 2.전화번호\n");

         printf("번호를 선택하세요: ");

         scanf("%d", &j);

         if(j==1)

         {

            printf("수정할 이름: ");

            scanf("%s", customer_info[i].name); 

         } 

         else if(j==2)

         {

            printf("수정할 전화번호: ");

            scanf("%s", customer_info[i].phone); 

         } 

         printf("\n");

      }

   }

}

 

//8. 메뉴 정보 수정 

 void edit_menu()

{

   int i, j, k;

   char drink[20];

   char info[20];

   

      system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                          ┃\n");

   printf("┃        메뉴 수정         ┃\n");

   printf("┃                          ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

 

   

   printf("\n메뉴를 입력해주세요: "); 

   scanf("%s", drink);

   printf("\n");

 

   for(i=0; i<menu_idx; i++)

   {

      if(strcmp(drink, menu_info[i].drink)==0)

      {

         printf("음료: %s\n가격: %s\n", menu_info[i].drink, menu_info[i].price);

         printf("\n");

         printf("1.음료 2.가격\n");

         printf("번호를 선택하세요: ");

         scanf("%d", &j);

         if(j==1)

         {

            printf("수정할 음료: ");

            scanf("%s", menu_info[i].drink); 

         } 

         else if(j==2)

         {

            printf("수정할 가격: ");

            scanf("%s", menu_info[i].price); 

         } 

         printf("\n");

      }

   }

}

 

 

 

//9. 기존 고객 삭제 

void del_customer()

 {   

   FILE* fp = fopen("Customer.txt", "r+");

    int i=0;

   char name[30];

   

      system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                          ┃\n");

   printf("┃        고객 삭제         ┃\n");

   printf("┃                          ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

 

   

   printf("\n이름: ");

   scanf("%s", &name);   

 

    //입력된 이름으로 고객 정보 삭제 

    for(i=0; i<customer_idx; i++)

    {

        //삭제할 고객 정보 출력

        if(strcmp(name, customer_info[i].name)==0)

        {

           printf("====================\n");

           printf("삭제할 고객 이름\n이름: %s\n전화번호: %s\n",customer_info[i].name, customer_info[i].phone);

           printf("====================\n");

            memset(&customer_info[i], 0x00, sizeof(CUSTOMER));

         fprintf(fp, "%s %s\n", customer_info[i].name, customer_info[i].phone);

         fclose(fp);

        }

    }

}

 

 

 

 

//10. 기존 메뉴 삭제 

void del_menu()

 {   

   FILE* fp = fopen("Menu.txt", "r+");

 

    int i=0;

   char drink[30];

   

      system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                          ┃\n");

   printf("┃        메뉴 삭제         ┃\n");

   printf("┃                          ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

 

   

   printf("\n메뉴 이름: ");

   scanf("%s", &drink);   

 

    //입력된 메뉴로 음료 정보 삭제 

    for(i=0; i<menu_idx; i++)

    {

        //삭제할 음료 정보 출력

        if(strcmp(drink, menu_info[i].drink)==0)

        {

           printf("====================\n");

           printf("삭제할 메뉴\n음료: %s\n가격: %s\n",menu_info[i].drink, menu_info[i].price);

           printf("====================\n");

           memset(&menu_info[i], 0x00, sizeof(MENU));

         fprintf(fp, "%s %s\n", menu_info[i].drink, menu_info[i].price);

         fclose(fp);

        }

    }

}

 

 

//11. 기존 번호표 삭제  

void del_ticket()

 {   

   FILE* fp = fopen("Ticket_number.txt", "r+");

    int i=0;

   char num[30];

   

      system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                          ┃\n");

   printf("┃        번호표 삭제        ┃\n");

   printf("┃                          ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

 

    

   printf("\n 번호표 번호: ");

   scanf("%s", &num);   

 

    

    for(i=0; i<ticket_number_idx; i++) 

    {

       

        if(strcmp(num, ticket_number_info[i].number)==0)

        {

           printf("====================\n");

           printf("삭제되었습니다!\n"); //음료 정보 삭제 

           printf("====================\n");

           memset(&ticket_number_info[i], 0x00, sizeof(TICKET_NUMBER));

         fprintf(fp, "%s %s %s %s\n", ticket_number_info[i].number, ticket_number_info[i].name, ticket_number_info[i].drink, ticket_number_info[i].price);

         fclose(fp);

        }

    }

}

 

 

 

 

//12. 메뉴 전체보기

void view_menu()

{

   int i;

   

      system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                            ┃\n");

   printf("┃        메뉴 전체보기       ┃\n");

   printf("┃                            ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

 

   

   printf("\n          Menu                    Price \n");

   printf("------------------------------------------------\n");

   

   

   

   for(i=0; i<menu_idx; i++) //유효한 배열 불러오기 

   {

      printf("%15s%20s\n",menu_info[i].drink,menu_info[i].price);

   }

}

 

 

 

 

 

//13. 고객 전체보기  

void view_customer()

{

   int i;

   

         system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                            ┃\n");

   printf("┃        고객 전체보기       ┃\n");

   printf("┃                            ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

   printf("\n          Name           Phone       \n");

   printf("---------------------------------------\n");

   

   for(i=0; i<customer_idx; i++)

   {

      printf("%15s%20s\n", customer_info[i].name, customer_info[i].phone);

   }

}

 

 

 

 

 

//14. 번호표 전체보기  

void view_ticket_number()

{

   int i;

   TICKET_NUMBER temp;

         system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                              ┃\n");

   printf("┃        번호표 전체보기       ┃\n");

   printf("┃                              ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

   printf("\n          번호           이름           음료           가격\n");

   printf("-------------------------------------------------------------\n");

   

   for(i=0; i<ticket_number_idx-1; i++) //정렬  

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

 

 

 

 

 

//15. 메뉴 종류, 고객 종류 검색하기 

int cross_search()

{

   int i,j;

   char drink[30]; //여기에 입력할 이름 

   char name[30];

 

   system("cls");

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

    printf("┃                          ┃\n");

   printf("┃        교차 검색         ┃\n");

   printf("┃                          ┃\n");

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");   

 

   

   printf("\n고객 이름: ");

   scanf("%s", &name);

   

   

   for(j=0; j<customer_idx; j++) 

   {

      if(strcmp(name,  ticket_number_info[j].name)==0) //고객의 유무에 따라 반환하기 위한 형태

     {  

         printf("고객 이름: %s \n 고르신 메뉴: %s\n", customer_info[j].name, ticket_number_info[j].drink);   

      return j; 

       }

    }

     

}

 

 

 

 
// 16번 
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
                  printf("\t 맨 앞 번호표가 삭제되었습니다.\n \t삭제된 번호표 = %d\n", item);
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

 

//17. 프로그램 종료

void end()

{

   printf("\n프로그램을 종료합니다\n");

   exit(1);

}

