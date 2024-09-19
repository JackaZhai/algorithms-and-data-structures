#include <stdlib.h>
#include <stdio.h>


#define MaxSize 50 // 预处理指令，用于定义一个名为 MaxSize 的宏。宏是一种在编译时进行文本替换的机制。具体来说，这行代码的作用是告诉编译器在编译过程中将所有出现 MaxSize 的地方替换为 50。这在代码中可以用来定义数组的大小或其他需要固定值的地方。

typedef int ElemType; // 数据元素的类型，typedef 是 C++ 中的一个关键字，用于给现有类型定义一个新的名字。这里定义了一个名为 ElemType 的新类型，它是 int 类型的别名。

typedef struct { // 定义一个结构体类型，用于表示顺序表。结构体是一种用户自定义的数据类型，它可以包含多个不同类型的成员变量。
    ElemType data[MaxSize]; // 用于存储顺序表中的数据元素。这里定义了一个名为 data 的数组，它的长度为 MaxSize，即 50。
    int length; // 用于记录顺序表中的元素个数。这里定义了一个名为 length 的整型变量。
} SqList; // 结构体类型的名字，这里定义了一个名为 SqList 的结构体类型。

// 建立顺序表
void CreateList(SqList *&L, ElemType a[], int n)  // 传入 SqList 类型的指针 L，以及一个 ElemType 类型的数组 a 和一个整型变量 n
{
    int i=0,k=0;  // 定义两个整型变量 i 和 k，并初始化为 0
    L=(SqList *)malloc(sizeof(SqList));  // 为 L 分配内存空间，大小为 SqList 结构体的大小
    while(i<n)  // 当 i 小于 n 时执行循环
    {
        L->data[k]=a[i];  // 将数组 a 中的元素逐个赋值给顺序表 L 中的 data 数组
        i++;  // i 自增 1
        k++;  // k 自增 1
        
    }
    L->length=k;  // 将 k 赋值给顺序表 L 的 length 成员变量
}

//初始化顺序表
void InitList(SqList *&L)  // 传入 SqList 类型的指针 L
{
    L=(SqList *)malloc(sizeof(SqList));  // 为 L 分配内存空间，大小为 SqList 结构体的大小
    L->length=0;  // 将 0 赋值给顺序表 L 的 length 成员变量
}

//销毁顺序表
void DestroyList(SqList *&L)  // 传入 SqList 类型的指针 L
{
    free(L);  // 释放 L 所指向的内存空间
}

//判断顺序表是否为空
bool ListEmpty(SqList *L)  // 传入 SqList 类型的指针 L
{
    return (L->length==0);  // 返回 L 的 length 成员变量是否等于 0
}

//求顺序表的长度
int ListLength(SqList *L)  // 传入 SqList 类型的指针 L
{
    return (L->length);  // 返回 L 的 length 成员变量
}

//输出顺序表
void DispList(SqList *L)  // 传入 SqList 类型的指针 L
{
    int i;  // 定义一个整型变量 i
    for(i=0;i<L->length;i++)  // 循环遍历顺序表 L 中的元素
    {
        printf("%d ",L->data[i]);  // 输出顺序表 L 中的元素
    }
    printf("\n");  // 输出换行符
}

//求顺序表中的某个元素值
bool GetElem(SqList *L,int i,ElemType &e)  // 传入 SqList 类型的指针 L，一个整型变量 i，以及一个 ElemType 类型的引用 e
{
    if(i<1||i>L->length)  // 如果 i 小于 1 或者 i 大于 L 的 length 成员变量
    {
        return false;  // 返回 false
    }
    e=L->data[i-1];  // 将顺序表 L 中的第 i 个元素赋值给 e
    return true;  // 返回 true
}

//按元素值查找
int LocateElem(SqList *L,ElemType e)  // 传入 SqList 类型的指针 L，以及一个 ElemType 类型的 e
{
    int i=0;  // 定义一个整型变量 i，并初始化为 0
    while(i<L->length&&L->data[i]!=e)  // 当 i 小于 L 的 length 成员变量并且 L 的 data 数组中的第 i 个元素不等于 e 时执行循环
    {
        i++;  // i 自增 1
    }
    if(i>=L->length)  // 如果 i 大于等于 L 的 length 成员变量
    {
        return 0;  // 返回 0
    }
    return i+1;  // 返回 i+1
}

//插入元素
bool ListInsert(SqList *&L,int i,ElemType e)  // 传入 SqList 类型的指针 L，一个整型变量 i，以及一个 ElemType 类型的 e
{
    int j;  // 定义一个整型变量 j
    if(i<1||i>L->length+1)  // 如果 i 小于 1 或者 i 大于 L 的 length 成员变量加 1
    {
        return false;  // 返回 false
    }
    i--;  // i 自减 1
    for(j=L->length;j>i;j--)  // 从 L 的 length 成员变量开始向前遍历到 i
    {
        L->data[j]=L->data[j-1];  // 将 L 的 data 数组中的第 j-1 个元素赋值给第 j 个元素
    }
    L->data[i]=e;  // 将 e 赋值给 L 的 data 数组中的第 i 个元素
    L->length++;  // L 的 length 成员变量自增 1
    return true;  // 返回 true
}

//删除元素
bool ListDelete(SqList *&L,int i,ElemType &e)  // 传入 SqList 类型的指针 L，一个整型变量 i，以及一个 ElemType 类型的引用 e
{
    int j;  // 定义一个整型变量 j
    if(i<1||i>L->length)  // 如果 i 小于 1 或者 i 大于 L 的 length 成员变量
    {
        return false;  // 返回 false
    }
    i--;  // i 自减 1
    e=L->data[i];  // 将 L 的 data 数组中的第 i 个元素赋值给 e
    for(j=i;j<L->length-1;j++)  // 从 i 开始遍历到 L 的 length 成员变量减 1
    {
        L->data[j]=L->data[j+1];  // 将 L 的 data 数组中的第 j+1 个元素赋值给第 j 个元素
    }
    L->length--;  // L 的 length 成员变量自减 1
    return true;  // 返回 true
}