#include <stdio.h>
//编写程序实现顺序表的操作
#include <stdbool.h>
#include <stdlib.h>

#define Maxsize 50
typedef char ElemType;
typedef struct {
    ElemType data[Maxsize]; //存放顺序表元素
    int Length; //存放顺序表的长度
} SqList; //声明顺序表的类型
void CreateList(SqList* L, ElemType a[], int n)
{
    L = (SqList*)malloc(sizeof(SqList));
    for (int i = 0; i < n; i++)
        L->data[i] = a[i];
    L->Length = n;
}
SqList InitList(SqList* L) //初始化线性表
{
    L = (SqList*)malloc(sizeof(SqList)); //分配存放线性表的空间
    L->Length = 0;
}
SqList DestroyList(SqList* L)
{ //销毁线性表
    free(L);
}
bool ListEmpty(SqList* L)
{ //判断线性表是否为空表
    return (L->Length == 0);
}
int ListLength(SqList* L)
{ //求线性表的长度
    return (L->Length);
}
SqList DispList(SqList* L)
{ //输出线性表
    for (int i = 0; i < L->Length; i++)
        printf("%c", L->data[i]);
    printf("\n");
}
bool GetElem(SqList* L, int i, ElemType* e)
{ //求线性表中第i个元素值
    if (i < 1 || i > L->Length)
        return false;
    e = L->data[i - 1];
    return true;
}
int locateElem(SqList* L, ElemType e)
{ //查找第一个值域为e的元素序号
    int i = 0;
    while (i < L->Length && L->data[i] != e)
        i++;
    if (i > L->Length)
        return 0;
    else
        return i + 1;
}
bool ListInsert(SqList* L, int i, ElemType e)
{ //插入第i个元素
    int j;
    if (i < 1 || i > L->Length + 1)
        return false;
    i--; //将顺序表位序转化位为elem下标
    for (j = L->Length; j > i; j--) //将data[i]及后面元素移一个位
        L->data[j] = L->data[j - 1];
    L->data[i] = e;
    L->Length++; //顺序表长度加1
    return true;
}
bool ListDelete(SqList* L, int i, ElemType e)
{ //删除第i个元素
    int j;
    if (i < 1 || i > L->Length)
        return false;
    i--; //将顺序表位序转化位为elem下标
    e = L->data[i];
    for (j = i; j < L->Length; j++) //将data[i]及后面元素前移一个位
        L->data[j] = L->data[j + 1];

    L->Length--; //顺序表长度减1
    return true;
}
int main()
{
    SqList* L;
    ElemType e;
    printf("顺序表的基本运算如下：\n");
    printf("(1)初始化顺序表L\n");
    InitList(L);
    printf("(2)插入a,b,c,d,e元素\n");
    ListInsert(L, 1, 'a');
    ListInsert(L, 2, 'b');
    ListInsert(L, 3, 'c');
    ListInsert(L, 4, 'd');
    ListInsert(L, 5, 'e');
    printf("(3)输出顺序表\n");
    DispList(L);
    printf("(4)顺序表L长度:%d\n", ListLength(L));
    printf("(5)顺序表L为%s\n", (ListEmpty(L) ? "空" : "非空"));
    GetElem(L, 3, e);
    printf("(6)顺序表L的第3个元素：%c\n", e);
    printf("(7)元素a的位置：%d\n", locateElem(L, "a"));
    printf("(8)在第4个元素位置上插入f元素\n");
    ListInsert(L, 4, 'f');
    printf("(9)输出顺序表L：");
    DispList(L);
    printf("(10)删除L的第3个元素\n");
    ListDelete(L, 3, e);
    printf("(11)输出顺序表L：");
    DispList(L);
    printf("(12)释放顺序表L\n");
    DestroyList(L);
    return 0;
}
