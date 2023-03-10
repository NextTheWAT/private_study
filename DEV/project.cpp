#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

//메뉴 정보 구조체
typedef struct _MENU {
   char drink[30];
   char price[30];
}MENU;

//고객 정보 구조체
typedef struct _customer {
   char name[30];
   char phone[30];
}CUSTOMER;

//번호표 구조체
typedef struct _ticket_number {
   char number[30];
   char name[30];
   char drink[30];
   char price[30];
}TICKET_NUMBER;


//함수
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

void view_menu();            //메뉴 전체 보기 
void view_customer();         //고객정보 전체 보기 

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

   while(sel!=12)
   {
      system("cls"); //화면지우기
      printf("============================\n");
      printf("|     카페 관리 프로그램    |\n");
      printf("============추가============\n");
      printf("|  1. 신규 메뉴 추가        |\n");
      printf("|  2. 신규 고객 추가        |\n");
      printf("============검색============\n");
      printf("|  3. 기존 메뉴 검색        |\n");
      printf("|  4. 기존 고객 검색        |\n");
      printf("|  5. 번호표 조회           |\n");
      printf("============수정============\n");
      printf("|  6. 기존 고객 수정        |\n");
      printf("|  7. 기존 메뉴 수정        |\n");
      printf("============삭제============\n");
      printf("|  8. 기존 고객 삭제        |\n");
      printf("|  9. 기존 메뉴 삭제        |\n");
      printf("==========전체 보기=========\n");
      printf("|  10. 메뉴 전체 보기       |\n");
      printf("|  11. 고객 전체 보기       |\n");
      printf("============종료============\n");
      printf("|  12. 번호표 추가          |\n");
      printf("|  13. 프로그램 종료        |\n");
      printf("============================\n");
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
   FILE* c_fp = fopen("C:\\project\\Customer.txt", "r");
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
   FILE* fp = fopen("C:\\project\\Menu.txt", "r");
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
   FILE* fp = fopen("C:\\project\\Ticket_number.txt", "r");
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
   FILE* fp = fopen("C:\\project\\Menu.txt", "a");
   printf("\n");
   printf("음료: ");
   scanf("%s", &menu_info[menu_idx].drink);
   printf("가격: ");
   scanf("%s", &menu_info[menu_idx].price);

   fprintf(fp, "%s,%s\n", menu_info[menu_idx].drink, menu_info[menu_idx].price);
   menu_idx++;
   fclose(fp);
}

//2. 신규 고객 정보 추가 
void new_add_customer()
{
   FILE* c_fp = fopen("C:\\project\\Customer.txt", "a");

   printf("\n");
   printf("고객 이름: ");
   scanf("%s", &customer_info[customer_idx].name);
   printf("고객 전화번호: ");
   scanf("%s", &customer_info[customer_idx].phone);
   
   fprintf(c_fp, "\n%s,%s,%s\n", customer_info[customer_idx].name, customer_info[customer_idx].phone);
   customer_idx++;
   fclose(c_fp);
}

//3. 메뉴 종류로 검색하기 
int search_menu()
{
   int i;
   char drink[30]; //여기에 입력할 이름 
   printf("\n음료 종류: ");
   scanf("%s", &drink);
   for(i=0; i<menu_idx++; i++) //menu 유요한 배열만큼 돌립니다. 
   {
      if(strcmp(drink, menu_info[i].drink)==0) //strcmp함수 사용 -> 입력한 drink과 구조체 배열의 옷 종류가 일치하면 0을 반환. 
         return i; //0이 되면 true가 되어 if문에 들어감. 
   }
   return -1; //for문 돌아가도 정보를 못 찾게 될 경우 
}

//4. 이름으로 고객 정보 조회 
int search_customer()
{
   int i;
   char name[30];
   printf("\n이름: ");
   scanf("%s", &name);
   for(i=0; i<customer_idx; i++) 
   {
      if(strcmp(name, customer_info[i].name)==0)  //고객의 유무에 따라 반환하기 위한 형태
         return i;      
   }
   return -1;
} 

//5. 번호표 조회 
int search_ticket_number()
{
   int i;
   char number[30];
   printf("\n번호표: ");
   scanf("%s", &number);
   for(i=0; i<ticket_number_idx; i++) 
   {
      if(strcmp(number, ticket_number_info[i].number)==0)  //고객의 유무에 따라 반환하기 위한 형태
         return i;
   }
   return -1;
} 

//6. 고객 정보 수정 
 void edit_customer()
{
	int i, j, k;
	char name[20];
	char info[20];
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
				scanf("%s", customer_info[i].name); 
			} 
			printf("\n");
		}
	}
}

//7. 메뉴 정보 수정 
 void edit_menu()
{
	int i, j, k;
	char drink[20];
	char info[20];
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

//8. 기존 고객 삭제 
void del_customer()
 {	
	FILE* fp = fopen("D:\\project\\customer_info.txt", "r+");

 	int i=0;
	char name[30];
	printf("\n이름: ");
	scanf("%s", &name);	

 	//입력된 이름으로 고객 정보 삭제 
 	for(i=0; i<customer_idx; i++)
 	{
  		//삭제할 고객 정보 출력
  		if(strcmp(name, customer_info[i].name)==0)
  		{
  			printf("\n삭제할 고객 이름\n이름: %s\n전화번호: %s\n",customer_info[i].name, customer_info[i].phone);
  			//고객 정보 삭제 
  			memset(&customer_info[i], 0x00, sizeof(CUSTOMER));
			fprintf(fp, "%s %s\n", customer_info[i].name, customer_info[i].phone);
			fclose(fp);
  		}
 	}
}

//9. 기존 메뉴 삭제 
void del_menu()
 {	
	FILE* fp = fopen("D:\\project\\menu_info.txt", "r+");

 	int i=0;
	char drink[30];
	printf("\n이름: ");
	scanf("%s", &drink);	

 	//입력된 메뉴로 음료 정보 삭제 
 	for(i=0; i<menu_idx; i++)
 	{
  		//삭제할 음료 정보 출력
  		if(strcmp(drink, menu_info[i].drink)==0)
  		{
  			printf("\n삭제할 메뉴\n음료: %s\n가격: %s\n",menu_info[i].drink, menu_info[i].price);
  			//음료 정보 삭제 
  			memset(&menu_info[i], 0x00, sizeof(MENU));
			fprintf(fp, "%s %s\n", menu_info[i].drink, menu_info[i].price);
			fclose(fp);
  		}
 	}
}

//10. 메뉴 전체보기
void view_menu()
{
   int i;
   printf("\n          Menu                    Price \n");
   printf("------------------------------------------------\n");
   for(i=0; i<menu_idx; i++) //유효한 배열 불러오기 
   {
      printf("%15s%20s\n",menu_info[i].drink,menu_info[i].price);
   }
}

//11. 고객 전체보기  
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

//12. 신규 번호표 추가 
void new_add_ticker_number()
{
   FILE* fp = fopen("C:\\project\\Ticket_number.txt", "a");
   printf("\n");
   printf("번호: ");
   scanf("%s", &ticket_number_info[menu_idx].number);
   printf("이름: ");
   scanf("%s", &ticket_number_info[menu_idx].name);
   printf("음료: ");
   scanf("%s", &ticket_number_info[menu_idx].drink);
   printf("가격: ");
   scanf("%s", &ticket_number_info[menu_idx].price);

   fprintf(fp, "%s,%s,%s,%s\n", ticket_number_info[menu_idx].number, ticket_number_info[menu_idx].name, ticket_number_info[menu_idx].drink,ticket_number_info[menu_idx].price);
   ticket_number_idx++;
   fclose(fp);
}


//13. 프로그램 종료
void end()
{
   printf("\n프로그램을 종료합니다\n");
   exit(1);
}

