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
	printf("建立非递减有序单链表，随即输入一组数据并以0结束：\n");
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
	printf("1.随机输入一组数据，建立无序单链表，以0结束：\n");
	printf("2.以输出的形式遍历单链表\n");
	printf("3.把单链表中的元素逆置\n");
	printf("4.建立一个非递减有序单链表\n");
	printf("5.建立两个非递减有序单链表，然后合并成一个非递减单链表\n");
	printf("6.在非递减有序单链表中插入一个元素\n");
	printf("7.删除指定的元素\n");
	while (1){
		printf("请选择：\n");
		scanf("%d", &n);
		switch (n){
		case1:
			printf("请输入一组元素以建立单链表，以0结束：\n");
			CreateFromHead(La);
			break;
		case2:
			printf("单链表以输出形式遍历为：\n");
			Print(La);
			break;
		case3:
			NiZhi(La);
			printf("已建立单链表中的元素逆置：\n");
			Print(La);
			break;
		case4:
			FeiDiJian2(La);
			printf("所建非递减有序单链表为：\n");
			Print(La);
			break;
		case5:
			FeiDiJian2(La);
			FeiDiJian2(Lb);
			ChaRu(La, Lb, Lc);
			printf("合并后的单链表为：\n");
			Print(Lc);
			break;
		case6:
			FeiDiJian2(La);
			printf("新建非递减有序单链表为：");
			Print(La);
			printf("请输入要插入单链表的元素x:");
			scanf("%d", &x);
			FeiDiJian(La, x);
			Print(La);
			break;
		case7:
			FeiDiJian2(La);
			printf("新建非递减有序单链表为：\n");
			Print(La);
			printf("请输入要删除的元素x: \n");
			scanf("%d", &x);
			ShanChu(La, x);
			Print(La);
			break;
		default:printf("输入有误，请重新选择！\n");
		}
	}

}