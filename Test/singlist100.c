// 线性顺序存储
// https://blog.csdn.net/homedjy/article/details/8689639
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef int DataType ;
typedef struct
{
    int length;
    DataType data[MAX];
 
}SqList;
 
int InitList(SqList *L)
{
    //L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
    return 0;
}
 
int ListEmpty(SqList L)
{
    if(L.length==0)
        return 1;
    else
        return 0;
}
 
int ClearList(SqList *L)
{
    L->length=0;
    return 0;
}
 
int getData(SqList *L,int i,DataType *e)
{
    if(L->length==0||i<1||i>L->length)
        return 0;
    else
        *e=L->data[i-1];
    return 1;
}
 
int ListInsert(SqList *L,int i,DataType e)
{
    int k;
    if(L->length==MAX)
    {
       // printf("顺序表已满\n");
        return 0;
    }
    if(i<0||i>L->length+1)
    {
        //printf("插入位置不合法\n");
        return 0;
    }
    else
    {
        for(k=L->length-1;k>=i-1;k--)
            L->data[k+1]=L->data[k];
    }
    L->data[i-1]=e;
    L->length++;
    return 1;
}
 
int ListDelete(SqList *L,int i,DataType *e)
{
    int k;
    if(i<1||i>L->length)
        return 0;   //删除位置不正确
    if(L->length==0)
        return 0;   //空表
    *e=L->data[i-1];
    if(i<=L->length)
    {
         for(k=i;k<L->length;k++)
            L->data[k-1]=L->data[k];
    }
    L->length--;
    return 0;
}
 
int ListTraverse(SqList L)
{
    int i;
    for(i=0;i<=L.length-1;i++)
    {
        printf("%3d",L.data[i]);
    }
    printf("\n");
    return 1;
}
 
int main()
{
    int i,j,k;
    SqList L;
    DataType e;
    i=InitList(&L);
    printf("初始化后表长:%d\n",L.length);
 
    for(j=1;j<=5;j++)
        i=ListInsert(&L,1,j);
    printf("表头插入数字1到5之后:");
    ListTraverse(L);
    printf("插入五个数字后表长:%d\n",L.length);
 
    i=ListEmpty(L);
    printf("此时表是否为空(1代表是,0代表否):%d\n",i);
 
    i=ClearList(&L);
    printf("\n清空表后，表长为%d\n",L.length);
    printf("此时表是否为空(1代表是,0代表否):%d\n",i);
    for(j=1;j<=5;j++)
        i=ListInsert(&L,j,j);
    printf("表尾插入五个数字之后:");
    ListTraverse(L);
    printf("插入五个数字后表长:%d\n",L.length);
 
    getData(&L,3,&e);
    printf("第三个数字是:%d\n",e);
 
    i=ListDelete(&L,2,&e);
    printf("删除第2个数据后为:");
    ListTraverse(L);
    printf("被删除的数字是:%d\n",e);
 
    i=L.length;
    printf("输入想要删除的数据的序号:");
    scanf("%d",&k);
    if(k>i||k<=0)
        printf("删除位置不正确\n");
    else
    {
        i=ListDelete(&L,k,&e);
        printf("删除第%d个数字的值为%d,删除后表为",k,e);
        ListTraverse(L);
    }
    return 0;
}
————————————————
版权声明：本文为CSDN博主「vicious_net」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/homedjy/java/article/details/8689639