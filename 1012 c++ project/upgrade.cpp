#include <stdio.h>
#include <windows.h>
#include <conio.h>

// 키보드 값
#define UP 0
#define DOWN 1
//#define LEFT 2
//#define RIGHT 3
#define SUBMIT 4

#define box_length 15 // 게임 영역 ( 좌우 )
#define box_height 15 // 바닥 높이 ( 상하 ) 

int keyControl(); 
void init();
void titleDraw();
int menuDraw();
void infoDraw();
void gameControl();
int left_right_move();
void move_down(int x);
void draw_rectangle(int c, int r);
int max_block();
// void drawUI(int*, int*);
void gotoxy(int x, int y);

int block_stack[box_length*2+1] = {0}; // 해당위치 값을 0으로 초기화 

int main() {
	init();
	while(1){
		titleDraw();
		int menuCode = menuDraw();
		if(menuCode == 0) {
			gameControl(); // 게임시작 
		} else if(menuCode == 1) {
			infoDraw(); // 게임정보 
		} else if(menuCode == 2) {
			return 0; // 종료 
		}
		system("cls");
	} 
	return 0;
}

// 색상 
enum {
	BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VOILET,
    DARK_YELLOW,
    GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    SKYBLUE,
    RED,
    VIOLET,
    YELLOW,
    WHITE,};

// 콘솔 텍스트 색상을 변경해주는 함수
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
} 

void gameControl() {
	int x, count = 0;
	system("cls");
	draw_rectangle(box_length, box_height);
	gotoxy(box_length*2 + 5, 3);
	printf("블록의 개수 : %2d", box_height);
	gotoxy(1, box_height + 3);
	printf("스페이스키를 누르면 블록이 떨어져 쌓입니다");
	
	while(count<box_height) 
	{
		gotoxy(box_length * 2 + 5, 4);
		setColor(WHITE);
		printf("시도한 횟수 : %2d", count+1);
		gotoxy(box_length * 2 + 5, 5);
		setColor(WHITE);
		printf("쌓인 블록수 : %2d", max_block());
		x = left_right_move();
		move_down(x);
		count++;
		getch();
	} 
}

int left_right_move() {
	int x = 3, y = 2, temp = 2;
	do
	{
		x += temp;
		if (x > (box_length * 2)) // x방향 최대값 설정
			temp=-2;
		if (x<3)
		{
			x=3;
			temp=2;
		}

		gotoxy(x, y);
		setColor(DARK_YELLOW);
		printf("☆");
		Sleep(50); //블록이 좌우로 움직이는 속도를 조절
		gotoxy(x, y);
		printf("  ");

	}while(!kbhit());
	block_stack[x]+=1;
	return x; 
}

void move_down(int x)
{
	int y;
	for(y=2;y<box_height+2-block_stack[x];y+=1)
	{
		gotoxy(x, y);
		setColor(DARK_YELLOW);
		printf("☆");
		Sleep(20);
		gotoxy(x, y);
		printf("  ");
		Sleep(10);
	}
	gotoxy(x,box_height+2-block_stack[x]);
	setColor(DARK_YELLOW);
	printf("☆");
}

void draw_rectangle(int c, int r)
{
	int i, j;
    unsigned char a=0xa6;
    unsigned char b[7]; 
    for(i=1;i<7;i++)
   		b[i]=0xa0+i;

    printf("%c%c",a, b[3]);
    for(i=0;i<c;i++)
  		printf("%c%c", a, b[1]);
    printf("%c%c", a, b[4]);
    printf("\n");
    for(i=0;i<r;i++)
    {
		printf("%c%c", a, b[2]);
		for(j=0;j<c;j++)
			printf("  ");
		printf("%c%c",a, b[2]);
		printf("\n");
    }
    printf("%c%c", a, b[6]);
    for(i=0;i<c;i++)
		printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);
    printf("\n");
}

int max_block(void)
{
	int i, max=0;
	for(i=1;i<box_height*2+1;i++)
	{
		if (max<=block_stack[i])
			max=block_stack[i];
	}
	return max;
}

//void drawUI(int* x, int* y) {
//	gotoxy(3, 16);
//	printf("스페이스키를 누르면 블록이 떨어지고");
//	gotoxy(34, 17);
//	printf("바닥에 쌓입니다");
//}

void infoDraw() {
	system("cls");
	printf("\n\n");
	printf("                        [조작법]\n");
	printf("                  이동 : W, S, A, D\n");
	printf("                  선택 : 스페이스바\n\n\n");
	printf("            개발자 : 2020875042 이수현\n");
	printf("       스페이스바를 누르면 메인화면으로 이동\n");
	
	while(1) {
		if(keyControl() == SUBMIT) {
			break;
		}
	}
}

int keyControl() {
	char temp = getch();
	
	if(temp == 'w' || temp == 'W'){
		return UP;
//	} else if(temp == 'a' || temp == 'A'){
//		return LEFT;
	} else if(temp == 's' || temp == 'S'){
		return DOWN;
//	} else if(temp == 'd' || temp == 'D'){
//		return RIGHT;}
	} else if(temp == ' '){ // 스페이스바(공백)이 선택 버튼  
		return SUBMIT;
	} 
}

void init() {
	system("mode con cols=52 lines=20 | title 2020875042");
	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; // false or 0 => 숨기기
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor); 
}

void titleDraw() {
	printf("\n\n");
	setColor(DARK_YELLOW);
	printf("       #####   #####     #     #####   #####       \n");
	printf("       #         #      # #    #   #     #         \n");
	printf("       #####     #     #####   #####     #         \n");
	printf("           #     #     #   #   #  #      #         \n");
	printf("       #####     #     #   #   #   #     #         \n\n");
	setColor(WHITE);
	printf("===================================================\n\n");
}

int menuDraw() {
	int x = 20;
	int y = 10;
	gotoxy(x - 2, y); // -2는 > 출력을 위함 
	printf("> 게임시작");
	gotoxy(x,y + 1);
	printf("게임정보");
	gotoxy(x,y + 2);
	printf("  종료  ");
	
	gotoxy(x, y+4);
	printf("방향이동");
	gotoxy(x, y+5);
	printf(" UP : w ");
	gotoxy(x, y+6);
	printf("DOWN : s");
	
	while(1) { // 무한반복  
		int n = keyControl(); 
		switch(n){
			case UP: { // 입력된 키 값이 UP이라면 
				if( y > 10 ) { // y는 10-12까지 이동 
					gotoxy(x-2, y); // x-2인 이유는 > 때문 
					printf(" "); // 원래 위치를 지우고 
					gotoxy(x-2, --y); // 새로 이동한 위치에 
					printf("> "); // 다시 >출력 
				}
				break;
			} 
			case DOWN: {
				if( y < 12 ) {
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, ++y);
					printf("> ");
				}
				break;
			} 
			case SUBMIT: {
				return y-10; // 0,1,2의 숫자로 선택 받기 위함 
			}
		}
	}
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
