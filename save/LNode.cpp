#include <stdlib.h>
#include <stdio.h>

// 定义链表节点结构体
typedef struct LNode
{
    int data; // 节点数据
    struct LNode *next; // 指向下一个节点的指针
} LinkNode;

typedef int ElemType; // 定义元素类型为int

// 头插法创建链表
void CreateListF(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s; // 临时节点指针
    int i; // 循环变量
    L = (LinkNode *)malloc(sizeof(LinkNode)); // 分配头节点内存
    L->next = NULL; // 初始化头节点的next指针
    for (i = 0; i < n; i++) // 遍历数组a
    {
        s = (LinkNode *)malloc(sizeof(LinkNode)); // 分配新节点内存
        s->data = a[i]; // 将数组元素赋值给新节点的数据域
        s->next = L->next; // 将新节点的next指针指向当前头节点的next指针
        L->next = s; // 将头节点的next指针指向新节点
    }
}

// 尾插法创建链表
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s, *r; // 临时节点指针和尾指针
    int i; // 循环变量
    L = (LinkNode *)malloc(sizeof(LinkNode)); // 分配头节点内存
    r = L; // 初始化尾指针指向头节点
    for (i = 0; i < n; i++) // 遍历数组a
    {
        s = (LinkNode *)malloc(sizeof(LinkNode)); // 分配新节点内存
        s->data = a[i]; // 将数组元素赋值给新节点的数据域
        r->next = s; // 将尾节点的next指针指向新节点
        r = s; // 更新尾指针指向新节点
    }
    r->next = NULL; // 将尾节点的next指针置为空
}

// 初始化链表
void InitList(LinkNode *&L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode)); // 分配头节点内存
    L->next = NULL; // 初始化头节点的next指针
}

// 销毁链表
void DestroyList(LinkNode *&L)
{
    LinkNode *pre = L, *p = L->next; // 定义前驱节点和当前节点指针
    while (p != NULL) // 遍历链表
    {
        free(pre); // 释放前驱节点内存
        pre = p; // 更新前驱节点指针
        p = p->next; // 更新当前节点指针
    }
    free(pre); // 释放最后一个节点内存
}

// 判断链表是否为空
bool ListEmpty(LinkNode *L)
{
    return (L->next == NULL); // 如果头节点的next指针为空，则链表为空
}

// 获取链表长度
int ListLength(LinkNode *L)
{
    int i = 0; // 计数器
    LinkNode *p = L->next; // 当前节点指针
    while (p != NULL) // 遍历链表
    {
        i++; // 计数器加1
        p = p->next; // 更新当前节点指针
    }
    return i; // 返回链表长度
}

// 输出链表元素
void DispList(LinkNode *L)
{
    LinkNode *p = L->next; // 当前节点指针
    while (p != NULL) // 遍历链表
    {
        printf("%d ", p->data); // 输出当前节点数据
        p = p->next; // 更新当前节点指针
    }
    printf("\n"); // 换行
}

// 获取第i个元素
bool GetElem(LinkNode *L, int i, ElemType &e)
{
    int j = 0; // 计数器
    LinkNode *p = L; // 当前节点指针
    if (i <= 0) // 如果i小于等于0，返回false
    {
        return false;
    }
    while (j < i && p != NULL) // 遍历链表直到第i个节点
    {
        j++; // 计数器加1
        p = p->next; // 更新当前节点指针
    }
    if (p == NULL) // 如果当前节点为空，返回false
    {
        return false;
    }
    e = p->data; // 将当前节点数据赋值给e
    return true; // 返回true
}

// 查找元素位置
int LocateElem(LinkNode *L, ElemType e)
{
    int i = 0; // 计数器
    LinkNode *p = L->next; // 当前节点指针
    while (p != NULL && p->data != e) // 遍历链表直到找到元素e
    {
        i++; // 计数器加1
        p = p->next; // 更新当前节点指针
    }
    if (p == NULL) // 如果当前节点为空，返回0
    {
        return 0;
    }
    return i; // 返回元素位置
}

// 在第i个位置插入元素
bool ListInsert(LinkNode *&L, int i, ElemType e)
{
    int j = 0; // 计数器
    LinkNode *p = L, *s; // 当前节点指针和新节点指针
    if (i <= 0) // 如果i小于等于0，返回false
    {
        return false;
    }
    while (j < i - 1 && p != NULL) // 遍历链表直到第i-1个节点
    {
        j++; // 计数器加1
        p = p->next; // 更新当前节点指针
    }
    if (p == NULL) // 如果当前节点为空，返回false
    {
        return false;
    }
    s = (LinkNode *)malloc(sizeof(LinkNode)); // 分配新节点内存
    s->data = e; // 将元素e赋值给新节点的数据域
    s->next = p->next; // 将新节点的next指针指向当前节点的next指针
    p->next = s; // 将当前节点的next指针指向新节点
    return true; // 返回true
}

// 删除第i个元素
bool ListDelete(LinkNode *&L, int i, ElemType &e)
{
    int j = 0; // 计数器
    LinkNode *p = L, *q; // 当前节点指针和待删除节点指针
    if (i <= 0) // 如果i小于等于0，返回false
    {
        return false;
    }
    while (j < i - 1 && p != NULL) // 遍历链表直到第i-1个节点
    {
        j++; // 计数器加1
        p = p->next; // 更新当前节点指针
    }
    if (p == NULL || p->next == NULL) // 如果当前节点为空或当前节点的next指针为空，返回false
    {
        return false;
    }
    q = p->next; // 更新待删除节点指针
    p->next = q->next; // 将当前节点的next指针指向待删除节点的next指针
    e = q->data; // 将待删除节点的数据赋值给e
    free(q); // 释放待删除节点内存
    return true; // 返回true
}