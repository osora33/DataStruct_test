#include <stdio.h>
#include <ctype.h>
#pragma warning(disable: 4996)

typedef struct Node {
	char data;
	struct Node* next;
}node;

void createNode(node*, node*, char);
void createNodeProc(node*, char);

void createNode(node* hu, node* hl, char d) {
	//대문자일 경우
	if (isupper(d)) {
		createNodeProc(hu, d);
	}
	//소문자일 경우
	else if (islower(d)) {
		createNodeProc(hl, d);
	}
	else {
		printf("\n잘못된 입력입니다.\n");
		return;
	}
}

void createNodeProc(node* h, char d) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = d;
	newNode->next = NULL;

	//노드가 하나도 없을때
	if (h->next == NULL) {
		h->next = newNode;
	}
	else {
		char insData;
		int flag;

		//먼저 첫번째 노드로 newNode를 집어넣기
		newNode->next = h->next;
		h->next = newNode;

		//삽입정렬 실행
		h = h->next;
		while (1) {
			flag = 0;
			while (h->next != NULL) {
				//다음 노드의 값보다 현재 노드의 값이 크면
				if(h->data > h->next->data){
					insData = h->next->data;
					h->next->data = h->data;
					h->data = insData;
					flag = -1;
				}
				h = h->next;
			}
			if (flag == 0) {
				break;
			}
		}
		
	}
}

void printNode(node* hu, node* hl) {
	printf("대문자 : ");
	hu = hu->next;
	while (hu != NULL) {
		printf("%c ", hu->data);
		hu = hu->next;
	}
	printf("\n");
	printf("소문자 : ");
	hl = hl->next;
	while (hl != NULL) {
		printf("%c ", hl->data);
		hl = hl->next;
	}
}

int main() {
	char input = 'a';
	//대문자 저장 헤더
	node* hu = (node*)malloc(sizeof(node));
	//소문자 저장 헤더
	node* hl = (node*)malloc(sizeof(node));
	hu->next = NULL;
	hl->next = NULL;

	printf("0을 누르면 입력을 종료합니다.\n");
	while (1) {
		printf("알파벳 입력 : ");
		scanf("%c", &input);
		if (input == '0') {
			break;
		}
		createNode(hu, hl, input);
		getchar();
	}

	printNode(hu, hl);

	return 0;
}