#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;//#define DataType int;

typedef struct node
{
	DataType data;
	struct node* next;
}LNode, * LinkList;     /*   LNode是结点的类型，LinkList是指向LNode类型结点的指针类型   */

//创建空单链表
LinkList Creat_LinkList()
{
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if (H)   /*确认创建头结点是否成功，若成功，修改单链表头结点的指针域为0，代表空表*/
		H->next = NULL;
	return H;
}

//根据输入创建单链表 - 顺序
LinkList Create_LinkListWithInput_seq()
{
	LinkList H, p, pre;
	H = (LinkList)malloc(sizeof(LNode));
	if (H)
		H->next = NULL;

	int data;
	scanf("%d", &data);
	pre = H;
	while (data != 0)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->data = data;
		pre->next = p;
		pre = p;

		scanf("%d", &data);
	}
	return H;
}

//创建循环链表不带头节点
LinkList Create_CirLinkList(DataType x)
{
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if (H)
	{
		H->next = H;
		H->data = x;
	}
	return H;
}

//创建循环链表带头节点
LinkList Create_CirLinkListHead()
{
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if (H)
	{
		H->next = H;
	}
	return H;
}
//销毁单链表
void Destroy_LinkList(LinkList* H)
{
	LinkList p, q;
	p = *H;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	*H = NULL;
}

//求表长
int Length_LinkList(LinkList H)
{
	LinkList p = H;//p指向头结点
	int count = -1;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}

//查找操作（按序号进行查找）
LinkList Locate_Linklist_Pos(LinkList H, int i)
{

	/*i不正确或者链表不存在，则返回NULL，i==0返回头指针，否则返回第i个结点的指针*/
	LinkList p;
	int j;
	p = H; j = 0;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (j != i || !p)
	{
		printf("参数i错误或者单链表不存在");
		return (NULL);
	}
	return (p);
}

//查找操作（按值查找）
LinkList Locate_LinkList_Value(LinkList H, DataType x)
{
	LinkList p = H->next;
	while (p && p->data != x)
		p = p->next;
	return (p);
}

//插入
int Insert_LinkList(LinkList H, int i, DataType x)
{
	/*在单链表H的第i个结点位置前插入值为x的结点*/
	LinkList p, q;
	p = Locate_Linklist_Pos(H, i - 1);//找到第i-1个结点地址
	if (!p)
	{
		printf("i有误");
		return(0);
	}
	q = (LinkList)malloc(sizeof(LNode));
	if (!q)
	{
		printf("申请空间失败");
		return (0);
	}
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

//删除
int Del_LinkList(LinkList H, int i)
{
	/*删除单链表H上第i个结点*/
	LinkList p, q;
	if (H == NULL || H->next == NULL)
	{
		printf("链表不存在或者空链表不能删除");
		return (0);
	}
	p = Locate_Linklist_Pos(H, i - 1);
	if (p == NULL || p->next == NULL)
	{
		printf("参数i错误");
		return (0);
	}
	q = p->next;
	p->next = q->next;
	free(q);
	return (1);
}

int main()
{

}