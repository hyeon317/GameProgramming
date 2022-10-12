#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// Ű���� ��
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

#define box_length 15 // ���� ���� ( �¿� )
#define box_height 15 // �ٴ� ���� ( ���� ) 

int keyControl(); 
void init();
void titleDraw();
int menuDraw();
void infoDraw();
void gameControl();
int left_right_move(int number);
void move_down(int number, int x);
void draw_rectangle(int c, int r);
int max_block();
void conclusion(); // ��� 
// void drawUI(int*, int*);
void gotoxy(int x, int y);

int block_stack[box_length*2+1] = {0}; // �ش���ġ ���� 0���� �ʱ�ȭ 
int block[box_length * 2 + 1] = { 0 }; // ó�� ���� ����� ���
int block_num[box_length * 2 + 1] = {0}; // ���������� ���� ���
int last[box_length * 2 + 1] = {0}; // x���� ���������� ���� ��� ���
int count[4] = {0}; // �õ��� Ƚ��  

int main() {
	init();
	while(1){
		titleDraw();
		int menuCode = menuDraw();
		if(menuCode == 0) {
			srand ((unsigned)time(NULL));
			for(int i = 0; i < box_length * 2 + 1; i++)
				last[i] = 4; // ó���� ����� ��ġ�� �ʰ� �ʱ�ȭ(0-3) 
			gameControl(); // ���ӽ��� 
			gotoxy(1, box_height + 3);
			printf("������ ����Ǿ����ϴ�");
			conclusion();
			return 0; 
		} else if(menuCode == 1) {
			infoDraw(); // �������� 
		} else if(menuCode == 2) {
			return 0; // ���� 
		}
		system("cls");
	} 
	return 0;
}

// ���� 
enum {
	BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VIOLET,
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

// �ܼ� �ؽ�Ʈ ������ �������ִ� �Լ�
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
} 

void gameControl() {
	int x, count = 0;
	int number = rand() %4;
	int last = number;
	system("cls");
	draw_rectangle(box_length, box_height);
	gotoxy(box_length*2 + 5, 3);
	printf("����� ���� : %2d", box_height);
	gotoxy(1, box_height + 4);
	printf("�����̽�Ű�� ������ ����� ������ ���Դϴ�");
	gotoxy(1, box_height + 5);
	printf("���� ��� �ΰ��� ���̸� ���� �ִ� ����� �ı��˴ϴ�");
	gotoxy(1, box_height + 6);
	printf("�ı��� ����� ���� ������ �̱�ϴ�!");
	
	
	while(count<box_height) 
	{
		while (number == last)
		{
			number = rand() % 4;
		}
		setColor(WHITE);
		gotoxy(box_length * 2 + 5, 4);
		printf("�õ��� Ƚ�� : %2d", count+1);
		gotoxy(box_length * 2 + 5, 5);
		printf("��� �ı� �õ� Ƚ�� : %2d", max_block());
		x = left_right_move(number);
		move_down(number, x);
		count++;
		gotoxy(box_length * 2 + 5, 5);
		setColor(WHITE);
		printf("��� �ı� �õ� Ƚ�� : %2d", max_block());
		last = number;
		getch();
	} 
}

int left_right_move(int number) {
	int x = 3, y = 2, temp = 2;
	int num; // ����� ������ ����  
	do
	{
		x += temp;
		if (x > (box_length * 2)) // x���� �ִ밪 ����
			temp=-2;
		if (x<3)
		{
			x=3;
			temp=2;
		}

		gotoxy(x, y);
		switch (number)
		{
			case 0:
				setColor(DARK_GREEN);
				printf("��");
				break;
			case 1:
				setColor(DARK_YELLOW);
				printf("��");
				break;
			case 2:
				setColor(DARK_VIOLET);
				printf("��");
				break;
			case 3:
				setColor(DARK_BLUE);
				printf("��");
				break;
		}
		Sleep(100);
		gotoxy(x, y);
		printf("  ");
	} while(!kbhit());
	return x;
}

void move_down(int number, int x)
{
	int y;
	for(y=2;y<box_height+2-block_stack[x];y+=1)
	{
		gotoxy(x, y);
		switch(number)
		{
			case 0:
				setColor(DARK_GREEN);
				printf("��");
				break;
			case 1:
				setColor(DARK_YELLOW);
				printf("��");
				break;
			case 2:
				setColor(DARK_VIOLET);
				printf("��");
				break;
			case 3:
				setColor(DARK_BLUE);
				printf("��");
				break;
		}
		Sleep(20);
		gotoxy(x,y);
		printf("  ");
		Sleep(10);
	}
	
	if(block_stack[x] == 0) // ��ġ�� �ƹ� ��ϵ� ���ٸ�
	{
		block_stack[x] += 1; // ���� ��� ���� �ö󰡰�
		block_num[x] += 1;
		block[x] = number; // ����� ���� 
	} 
	else if (number == last[x]) // �عٴ� ���� �����ϴٸ�
	{
		block_stack[x] += 1; // ���� ��� ���� �ö�
		block_num[x] += 1;
		gotoxy(x, box_height + 2 - block_num[x]);
		switch(number)
		{
			case 0:
				setColor(DARK_GREEN);
				printf("��");
				break;
			case 1:
				setColor(DARK_YELLOW);
				printf("��");
				break;
			case 2:
				setColor(DARK_VIOLET);
				printf("��");
				break;
			case 3:
				setColor(DARK_BLUE);
				printf("��");
				break;
		} 
		Sleep(100);
		gotoxy(x, box_height + 2 - block_num[x]);
		printf("  ");
		block_num[x] -= 1;
		block_stack[x] -= 1;
		count[number]++;
	} 
	else
		block_num[x] += 1;
	gotoxy(x, box_height + 2 - block_num[x]);
	switch(number)
	{
		case 0:
				setColor(DARK_GREEN);
				printf("��");
				break;
			case 1:
				setColor(DARK_YELLOW);
				printf("��");
				break;
			case 2:
				setColor(DARK_VIOLET);
				printf("��");
				break;
			case 3:
				setColor(DARK_BLUE);
				printf("��");
				break;
	}
	last[x] = number;
}

// ���
void conclusion()
{
	gotoxy(1, 24);
	setColor(WHITE);
	printf("�̱� ��� : ");
	switch(max_block())
	{
		case 0:
				setColor(DARK_GREEN);
				printf("��");
				break;
			case 1:
				setColor(DARK_YELLOW);
				printf("��");
				break;
			case 2:
				setColor(DARK_VIOLET);
				printf("��");
				break;
			case 3:
				setColor(DARK_BLUE);
				printf("��");
				break;
	}
	gotoxy(1, 25);
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
      printf(" ");
   printf("%c%c",a, b[2]);
   printf("\n");
    }
    
    printf("%c%c", a, b[6]);
    for(i=0;i<c;i++){
      printf("%c%c", a, b[1]);
   }
    printf("%c%c", a, b[5]);
    printf("\n");
}

int max_block(void)
{
	int i, max=0;
	for(i = 0; i<4; i++)
	{
		if(count[i]>max)
			max = count[i];
	}
	return max;
}

//void drawUI(int* x, int* y) {
//	gotoxy(3, 16);
//	printf("�����̽�Ű�� ������ ����� ��������");
//	gotoxy(34, 17);
//	printf("�ٴڿ� ���Դϴ�");
//}

void infoDraw() {
	system("cls");
	printf("\n\n");
	printf("                        [���۹�]\n");
	printf("                  �̵� : W, S, A, D\n");
	printf("                  ���� : �����̽���\n\n");
//	printf("       ����� �¿�� ������ �� �����̽��ٸ� ������\n");
//	printf("              ����� ������ �ٴڿ� ���Դϴ�\n");
//	printf("    ���� ��� �ΰ��� ���̸� ���� �ִ� ����� �ı��˴ϴ�\n");
//	printf("            �ı��� ����� ���� ����� �̱�ϴ�!\n\n");
	printf("            ������ : 2020875042 �̼���\n");
	printf("       �����̽��ٸ� ������ ����ȭ������ �̵�\n");
	
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
	} else if(temp == 'a' || temp == 'A'){
		return LEFT;
	} else if(temp == 's' || temp == 'S'){
		return DOWN;
	} else if(temp == 'd' || temp == 'D'){
		return RIGHT;
	} else if(temp == ' '){ // �����̽���(����)�� ���� ��ư  
		return SUBMIT;
	}
}

void init() {
	system("mode con cols=60 lines=25 | title 2020875042");
	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; // false or 0 => �����
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
	gotoxy(x - 2, y); // -2�� > ����� ���� 
	printf("> ���ӽ���");
	gotoxy(x,y + 1);
	printf("��������");
	gotoxy(x,y + 2);
	printf("  ����  ");
	
	gotoxy(x, y+4);
	printf("�����̵�");
	gotoxy(x, y+5);
	printf(" UP : w ");
	gotoxy(x, y+6);
	printf("DOWN : s");
	
	while(1) { // ���ѹݺ�  
		int n = keyControl(); 
		switch(n){
			case UP: { // �Էµ� Ű ���� UP�̶�� 
				if( y > 10 ) { // y�� 10-12���� �̵� 
					gotoxy(x-2, y); // x-2�� ������ > ���� 
					printf(" "); // ���� ��ġ�� ����� 
					gotoxy(x-2, --y); // ���� �̵��� ��ġ�� 
					printf("> "); // �ٽ� >��� 
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
				return y-10; // 0,1,2�� ���ڷ� ���� �ޱ� ���� 
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
