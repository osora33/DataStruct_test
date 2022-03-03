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
	//�빮���� ���
	if (isupper(d)) {
		createNodeProc(hu, d);
	}
	//�ҹ����� ���
	else if (islower(d)) {
		createNodeProc(hl, d);
	}
	else {
		printf("\n�߸��� �Է��Դϴ�.\n");
		return;
	}
}

void createNodeProc(node* h, char d) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = d;
	newNode->next = NULL;

	//��尡 �ϳ��� ������
	if (h->next == NULL) {
		h->next = newNode;
	}
	else {
		char insData;
		int flag;

		//���� ù��° ���� newNode�� ����ֱ�
		newNode->next = h->next;
		h->next = newNode;

		//�������� ����
		h = h->next;
		while (1) {
			flag = 0;
			while (h->next != NULL) {
				//���� ����� ������ ���� ����� ���� ũ��
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
	printf("�빮�� : ");
	hu = hu->next;
	while (hu != NULL) {
		printf("%c ", hu->data);
		hu = hu->next;
	}
	printf("\n");
	printf("�ҹ��� : ");
	hl = hl->next;
	while (hl != NULL) {
		printf("%c ", hl->data);
		hl = hl->next;
	}
}

int main() {
	char input = 'a';
	//�빮�� ���� ���
	node* hu = (node*)malloc(sizeof(node));
	//�ҹ��� ���� ���
	node* hl = (node*)malloc(sizeof(node));
	hu->next = NULL;
	hl->next = NULL;

	printf("0�� ������ �Է��� �����մϴ�.\n");
	while (1) {
		printf("���ĺ� �Է� : ");
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