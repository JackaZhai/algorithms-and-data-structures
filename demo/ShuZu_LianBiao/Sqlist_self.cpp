#include <stdlib.h>
#include <stdio.h>
#define MaxSize 50 

typedef int ElemType;
typedef struct 
{
    ElemType data[MaxSize];
    int length;
}SqList;

//创建顺序表
void CreatList(SqList *&L,ElemType a[],int n)
{
    int i=0,k=0;
    L=(SqList*)malloc(sizeof(SqList));
    while (i<n)
    {
        L->data[k]=a[i];
        k++;i++;
    }
    L->length=k;
}

//顺序表的基本算法
//初始化线性表
void InitList(SqList *&L)
{
    L=(SqList*)malloc(sizeof(SqList));
    L->length;
}

//销毁线性表
void DestoryList(SqList *&L)
{
    free(L);
}

//判断线性表是否为空表
bool ListEmpty(SqList *L)
{
    return(L->length==0);
}

//求线性表的长度
int ListLength(SqList *L)
{
    return(L->length);
}

//输出线性表
void DispList(SqList *L)
{
    for (int i =0;i<L->length;i++)
    {
        printf("%d",L->data[i]);
    }
    printf("\n");
}

//求线性表中的某个元素值
//在顺序表L中查找第i个元素，e 的作用是作为一个容器，用于存储和返回在顺序表中查找到的元素值。
bool GetElem(SqList *L,int i,ElemType &e)
{
    if(i<1||i>L->length)
    {
        return false;
    }
    e=L->data[i-1];
    return true;
}

//按元素值查找
//在顺序表L中查找第一个值为e的元素
int LocateElem(SqList *L,ElemType e)
{
    int i=0;
    while (i<L->length&&L->data[i]!=e)
    {
        i++;
    }
    if(i>=L->length)
    {
        return 0;
    }
    else
        return i+1;
}

//插入元素
//在顺序表L的第i个位置插入元素e
bool ListInsert(SqList *&L,int i,ElemType e)
{
    int j;
    if(i<1 || i>L->length+1 || L->length>=MaxSize)
    {
        return false;
    }
    i--;
    for(j=L->length;j>i;j--)
    {
        L->data[j]=L->data[j-1];
    }
    L->data[i]=e;
    L->length++;
    return true;
}

//删除元素
//在顺序表L中删除第i个元素，并用e返回其值
bool ListDelete(SqList *&L,int i,ElemType &e)
{
    int j;
    if(i<1||i>L->length)
    {
        return false;
    }
    i--;
    e=L->data[i];
    for(j=i;j<L->length-1;j++)
    {
        L->data[j]=L->data[j+1];
    }
    L->length--;
    return true;
}

void CreatList(SqList *&L,ElemType a[],int n);
void InitList(SqList *&L);
void DestoryList(SqList *&L);
bool ListEmpty(SqList *L);
int ListLength(SqList *L);
void DispList(SqList *L);
bool GetElem(SqList *L,int i,ElemType &e);
int LocateElem(SqList *L,ElemType e);
bool ListInsert(SqList *&L,int i,ElemType e);
bool ListDelete(SqList *&L,int i,ElemType &e);

int main()
{
    SqList *L;
    ElemType a[]={1,2,3,4,5,6,7,8,9};
    CreatList(L,a,9);
    printf("线性表L中的元素：");
    DispList(L);
    printf("线性表L的长度：%d\n",ListLength(L));
    printf("线性表L是否为空表：%d\n",ListEmpty(L));
    ElemType e;
    GetElem(L,4,e);
    printf("线性表L的第4个元素：%d\n",e);
    printf("元素5的位置：%d\n",LocateElem(L,5));
    ListInsert(L,4,10);
    printf("在L的第4个位置插入元素10后，线性表L中的元素：");
    DispList(L);
    ListDelete(L,4,e);
    printf("删除L的第4个元素%d后，线性表L中的元素：",e);
    DispList(L);
    DestoryList(L);
    return 0;
}