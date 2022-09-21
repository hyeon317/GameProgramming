#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct Node {
	char info;
	struct Node* next;
};

typedef struct Node* nodeptr;

struct Node* getNode()
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	return newNode;
}


void freeNode(nodeptr* q)
{
	free(q);
}


void push(nodeptr* q, char x)
{
	nodeptr foo = *q;
	*q = getNode();
	(*q)->info = x;
	(*q)->next = foo;
}



char pop_q(nodeptr* q)

{
	nodeptr foo = *q;
	char val = 0;
	if (foo == NULL)
	{
		return val;
	}

	if (foo->next == NULL)
	{
		val = foo->info;
		*q = NULL;
		return val;
	}
	else
	{
		//마지막 노드로 이동 
		while ((foo->next)->next != NULL)
		{
			foo = foo->next;
		}
		val = (foo->next)->info;
		foo->next = NULL;
		free(foo->next);
		return val;
	}
}



char pop_stack(nodeptr* s)

{
	nodeptr foo = *s;
	char val = 0;
	if (foo == NULL)
	{
		return val;
	}

	else
	{
		val = foo->info;
		*s = foo->next;
		return val;
	}
}


int main()

{
	nodeptr Queue;
	nodeptr Stack;

	char str[32];
	char bar, foo;
	int i;
	
	Queue = 0;
	Stack = 0;

	printf("%s\n", "회문을 판별할 단어를 입력하세요:\n");
	scanf("%s", str);

	// 큐와 스택에 삽입 

	i = 0;
	while ((bar = tolower(str[i])) != '\0')
	{
		push(&Queue, bar);
		push(&Stack, bar);
		i++;
	}



	// 팝, 출력문 
	i = 1;
	bar = 1;
	foo = 1;
	while (bar != 0 && foo != 0 && i == 1)
	{
		bar = pop_stack(&Stack);
		foo = pop_q(&Queue);

		if (bar != foo)
			i = 0;
	}


	if (i == 1)
		printf("회문입니다\n");
	else
		printf("회문이 아닙니다\n");

	return 0;

}
