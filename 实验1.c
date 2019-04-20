#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node * next;

}Node, *LinkList;
InitList(LinkList *L){
	*L = (LinkList)mallco(sizeof(Node));
	(*L)->next = NULL;
}
void CreateFromHead(LinkList L){
	Node *s;
	int c;
	scanf("%d\n", &c);
	int flag = 1;
	while (flag){
		c = getchar();
		if (c != '$'){
			s = (Node*)malloc(sizeof(Node));
			s->data = c;
			s->next = L->next;
			L->next = s;
			scanf("%d\n", &c);
		}
		else flag = 0;
	}
}
void Print(LinkList L){
	Node* p;
	p = L->next;
	while (p != NULL){
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}
void NiZhi(LinkList L){
	LinkList p, s;
	p = L->next;
	L->next = NULL;
	while (p){
		s = p;
		p = p->next;
		s->next = L->next;
		L->next = s;
	}
}
void FeiDiJian(LinkList L, int x){
	LinkList p, s;
	s = (LinkList)malloc(sizeof(LinkList));
	s->data = x;
	p = L;
	while (p->next&&p->next->data <= x){
		p = p->next;
		s->next = p->next;
		p->next = s;
	}
}
void FeiDiJian2(LinkList L){
	int x;
	L = (LinkList)malloc(sizeof(LinkList));
	L->next = NULL;
	printf("�����ǵݼ����������漴����һ�����ݲ���0������\n");
	scanf("%d", &x);
	while (x){
		FeiDiJian(L, x);
		scanf("%d", &x);
	}
}
void ChaRu(LinkList La, LinkList Lb, LinkList Lc){
	LinkList p, q, s, rear;
	p = La->next;
	q = Lb->next;
	Lc = rear = La;
	free(Lb);
	while (p&&q){
		if (p->data < q->data){
			s = p;
			p = p->next;
		}
		else{
			s = q;
			q = q->next;
		}
		rear->next = s;
		rear = rear->next;
	}
	if (p){
		rear->next = p;
	}
	else rear->next = q;
}
void ShanChu(LinkList L, int x){
	LinkList p, q;
	q = L->next;
	p = L;
	while (q&&q->data != x){
		p = q;
		q = q->next;
	}
	if (!q){
		printf("not deleted");
	}
	else{
		p->next = q->next;
		free(q);
	}
}
int main(){
	LinkList La, Lb, Lc;
	InitList(&La);
	InitList(&Lb);
	InitList(&Lc);
	int x;
	int n = 0;
	printf("1.�������һ�����ݣ���������������0������\n");
	printf("2.���������ʽ����������\n");
	printf("3.�ѵ������е�Ԫ������\n");
	printf("4.����һ���ǵݼ���������\n");
	printf("5.���������ǵݼ���������Ȼ��ϲ���һ���ǵݼ�������\n");
	printf("6.�ڷǵݼ����������в���һ��Ԫ��\n");
	printf("7.ɾ��ָ����Ԫ��\n");
	while (1){
		printf("��ѡ��\n");
		scanf("%d", &n);
		switch (n){
		case1:
			printf("������һ��Ԫ���Խ�����������0������\n");
			CreateFromHead(La);
			break;
		case2:
			printf("�������������ʽ����Ϊ��\n");
			Print(La);
			break;
		case3:
			NiZhi(La);
			printf("�ѽ����������е�Ԫ�����ã�\n");
			Print(La);
			break;
		case4:
			FeiDiJian2(La);
			printf("�����ǵݼ���������Ϊ��\n");
			Print(La);
			break;
		case5:
			FeiDiJian2(La);
			FeiDiJian2(Lb);
			ChaRu(La, Lb, Lc);
			printf("�ϲ���ĵ�����Ϊ��\n");
			Print(Lc);
			break;
		case6:
			FeiDiJian2(La);
			printf("�½��ǵݼ���������Ϊ��");
			Print(La);
			printf("������Ҫ���뵥�����Ԫ��x:");
			scanf("%d", &x);
			FeiDiJian(La, x);
			Print(La);
			break;
		case7:
			FeiDiJian2(La);
			printf("�½��ǵݼ���������Ϊ��\n");
			Print(La);
			printf("������Ҫɾ����Ԫ��x: \n");
			scanf("%d", &x);
			ShanChu(La, x);
			Print(La);
			break;
		default:printf("��������������ѡ��\n");
		}
	}

}