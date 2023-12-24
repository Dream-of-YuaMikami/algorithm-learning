#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;//#define DataType int;

typedef struct node
{
	DataType data;
	struct node* next;
}LNode, * LinkList;     /*   LNode�ǽ������ͣ�LinkList��ָ��LNode���ͽ���ָ������   */

//�����յ�����
LinkList Creat_LinkList()
{
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if (H)   /*ȷ�ϴ���ͷ����Ƿ�ɹ������ɹ����޸ĵ�����ͷ����ָ����Ϊ0������ձ�*/
		H->next = NULL;
	return H;
}

//�������봴�������� - ˳��
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

//����ѭ��������ͷ�ڵ�
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

//����ѭ�������ͷ�ڵ�
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
//���ٵ�����
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

//���
int Length_LinkList(LinkList H)
{
	LinkList p = H;//pָ��ͷ���
	int count = -1;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}

//���Ҳ���������Ž��в��ң�
LinkList Locate_Linklist_Pos(LinkList H, int i)
{

	/*i����ȷ�����������ڣ��򷵻�NULL��i==0����ͷָ�룬���򷵻ص�i������ָ��*/
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
		printf("����i������ߵ���������");
		return (NULL);
	}
	return (p);
}

//���Ҳ�������ֵ���ң�
LinkList Locate_LinkList_Value(LinkList H, DataType x)
{
	LinkList p = H->next;
	while (p && p->data != x)
		p = p->next;
	return (p);
}

//����
int Insert_LinkList(LinkList H, int i, DataType x)
{
	/*�ڵ�����H�ĵ�i�����λ��ǰ����ֵΪx�Ľ��*/
	LinkList p, q;
	p = Locate_Linklist_Pos(H, i - 1);//�ҵ���i-1������ַ
	if (!p)
	{
		printf("i����");
		return(0);
	}
	q = (LinkList)malloc(sizeof(LNode));
	if (!q)
	{
		printf("����ռ�ʧ��");
		return (0);
	}
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

//ɾ��
int Del_LinkList(LinkList H, int i)
{
	/*ɾ��������H�ϵ�i�����*/
	LinkList p, q;
	if (H == NULL || H->next == NULL)
	{
		printf("�������ڻ��߿�������ɾ��");
		return (0);
	}
	p = Locate_Linklist_Pos(H, i - 1);
	if (p == NULL || p->next == NULL)
	{
		printf("����i����");
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