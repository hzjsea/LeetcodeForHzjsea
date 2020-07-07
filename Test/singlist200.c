// 线性链式存储
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node,*LinkList;
 
 
int InitList(LinkList *L)//初始化
{
    *L=(LinkList)malloc(sizeof(Node));
    if(!(*L))
        return 0;
    else
        (*L)->next=NULL;
    return 1;
}
//LinkList L,L有定义时，值要么为NULL，为一个空表，要么为第一个节点的地址，既头指针
int ListLength(LinkList L)//求表长,LinkList L指某链表的第一个节点地址放在指针变量L中
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}
 
int ListEmpty(LinkList L)
{
    LinkList p=L->next;
    if(p)
        return 0;
    else
        return 1;
}
 
int ClearList(LinkList *L)//整表删除
{
    LinkList p,q;
    p=(*L)->next;//P指向第一个结点
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;//头结点指针域为空
    return 1;
}
 
int GetElem(LinkList L,int i,ElemType *e)
{
    int j=1;
    LinkList p;
    p=L->next;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i) //if(!p||j>=i)
    {
 
        return 0;
    }
    *e=p->data;
    return 1;
}
 
int ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        printf("%3d",p->data);
        p=p->next;
    }
    printf("\n");
    return 1;
}
 
int ListInsert(LinkList *L,int i,ElemType e)
{
    LinkList p,s;
    p=*L;
    int j=1;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p&&j>i)
    {
        return 0;
    }
    else
        s=(LinkList)malloc(sizeof(Node));
        s->data=e;
        s->next=p->next;
        p->next=s;
 
    return 1;
}
 
int ListDelete(LinkList *L,int i,ElemType *e)
{
    int j=1;
    LinkList p,q;
    p=*L;
    while(p->next&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!(p->next)||j>i)
        return 0;
    q=p->next;
    p->next=q->next;
    *e=q->data;
    free(q);
    return  1;
}
 
int main()
{
    LinkList L;
    ElemType e,f;
    int i,j,k,m;
    i=InitList(&L);
    printf("初始化后长度为:L.length=%d\n",ListLength(L));
 
    for(j=1;j<=5;j++)
    {
        i=ListInsert(&L,1,j);
    }
    printf("在表头插入1到5之后:L.data=");
    ListTraverse(L);
 
    printf("表长:ListLength=%d\n",ListLength(L));
 
    i=ListEmpty(L);
    printf("表是否为空:i=%d(1代表是，0代表否)\n",i);
 
    i=ClearList(&L);
    printf("清空表后表长:ListLength=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("表是否为空:i=%d(1代表是，0代表否)\n",i);
 
    for(j=1;j<=5;j++)
    {
        i=ListInsert(&L,j,j);
    }
    printf("表尾插入1到5之后:L.data=");
    ListTraverse(L);
 
    i=ListLength(L);
    printf("你想查找第几个元素？");
    scanf("%d",&k);
    if(k>0&&k<=i)
    {
        GetElem(L,k,&e);
        printf("第%d个元素的值是%d\n",k,e);
    }
    else
        printf("查找元素不存在\n");
 
    j=ListLength(L);
    printf("你想删除第几个数字?");
    scanf("%d",&m);
    if(m>0&&m<=j)
    {
        ListDelete(&L, m,&f);
        printf("删除成功，删除的数字是%d\n",f);
        printf("删除后表为:");
        ListTraverse(L);
    }
    else
        printf("不存在此元素\n");
    return 0;
}