// Filename:DoubleLinkedList.h
// FileType:Functions
// Beginning Time:12/2/2023
// Author:JimMinseay @CopyRight


#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_03_DOUBLELINKEDLIST_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_03_DOUBLELINKEDLIST_H

#include "00 Definition.h"
#include "00 Function.h"

///初始化双链表
DoubleLinkedList* DoubleLinkedList_Initiate(DoubleLinkedList* DLL)
{
    //为双链表头结点申请空间
    DLL = (DoubleLinkedList*) malloc(sizeof (DoubleLinkedList));

    //初始化DLL的Data域，表示此时双链表中无数据结点
    DLL->data = 0;

    //将DLL的prior域和next域置为NULL
    DLL->prior = NULL;
    DLL->next = NULL;

    //返回初始化完毕的DLL头指针
    return DLL;
}

///按下标插入元素
// 在双链表的指定下标处插入元素
DoubleLinkedList* DoubleLinkedList_InsertNode(DoubleLinkedList* DLL, int Subscript, ElementType Value)
{
    //判断链表合法性
    if(DLL == NULL)
    {
        printf("The DoubleLinkedList is Error!");
        return DLL;
    }

    //判断下标是否合法
    if(Subscript <= 0 || Subscript > DLL->data)
    {
        printf("Subscript Error!");
        return DLL;
    }

    //为新结点创建空间
    DoubleLinkedListNode* NewDoubleLinkedListNode = (DoubleLinkedListNode*)malloc(sizeof(DoubleLinkedListNode)); // 创建新节点

    //若内存分配失败
    if (NewDoubleLinkedListNode == NULL)
    {
        printf("Memory allocation failed!\n"); //显示错误信息
        return DLL; // 如果内存分配失败，返回原链表头节点指针
    }

    // 设置新节点的数据域为传入的值，并初始化前驱指针域和后继指针域的值
    NewDoubleLinkedListNode->data = Value;
    NewDoubleLinkedListNode->prior = NULL;
    NewDoubleLinkedListNode->next = NULL;

    //建立临时指针
    DoubleLinkedListNode* TemporaryPointer = DLL;

    //建立下标序号计数器，并初始化为0
    int count = 0;

    // 寻找要插入位置的前一个节点
    while (count < Subscript - 1)
    {
        TemporaryPointer = TemporaryPointer->next;
        count++;
    }
    /**循环的另一种实现方式：
     * for(count = 0; count < Subscript - 1; count++)
     * {
     *      TemporaryPointer = TemporaryPointer->Next;
     * }
     */

    //将创建的新结点插入到双链表中
    NewDoubleLinkedListNode->next = TemporaryPointer->next;
    NewDoubleLinkedListNode->prior = TemporaryPointer;

    //若临时指针指向的不是NULL（即临时指针指向的结点的后面仍然有结点），那么还需要将该结点的前驱指针指向新结点
    //否则可不做任何处理
    if (TemporaryPointer->next != NULL)
    {
        TemporaryPointer->next->prior = NewDoubleLinkedListNode;
    }

    //最后将临时指针指向的结点的后继指针指向新结点，插入完毕
    TemporaryPointer->next = NewDoubleLinkedListNode;

    //双链表头结点中的data域加1，表示双链表中增加了一个数据结点
    DLL->data ++;

    //返回新的双链表
    return DLL; // 返回更新后的链表头节点指针
}

///按下标删除元素
DoubleLinkedList* DoubleLinkedList_DeleteNode(DoubleLinkedList* DLL, int Subscript)
{
    //判断双链表合法性
    if(DLL == NULL)
    {
        printf("This DoubleLinkedList is Error!");
        return DLL;
    }

    //判断下标
    if(Subscript <= 0 || Subscript > DLL->data)
    {
        printf("Subscript Error!");
        return DLL;
    }

    //建立临时指针并指向头结点
    DoubleLinkedListNode* TemporaryPointer = DLL;

    //建立下标序号计数器
    int count;

    //将临时指针移动指欲删除的结点的前一个结点
    for (count = 0; count < Subscript - 1; count++)
    {
        TemporaryPointer = TemporaryPointer->next;
    }

    //建立内存释放指针，并指向欲删除的结点
    DoubleLinkedListNode* FreeMemoryPointer = TemporaryPointer->next;

    //更改双链表链接关系
    TemporaryPointer->next = FreeMemoryPointer->next;
    FreeMemoryPointer->next->prior = TemporaryPointer;

    //释放欲删除结点的内存
    free(FreeMemoryPointer);

    //修改双链表长度
    DLL->data --;

    //返回修改后的双链表
    return DLL;
}

///双链表循环化
DoubleLinkedList* DoubleLinkedList_Circularize(DoubleLinkedList* DLL)
{
    // 处理链表为空或只有一个节点的情况
    if (DLL == NULL)
    {
        printf("This DoubleLinkedList is Empty!");
        return DLL;
    }

    if(DLL->next == NULL)
    {
        printf("This DoubleLinkedList Only Have Head Node!");
        return DLL;
    }

    //建立临时指针
    DoubleLinkedList* TemporaryPointer = DLL;

    // 遍历链表找到最后一个节点
    while (TemporaryPointer->next != NULL)
    {
        TemporaryPointer = TemporaryPointer->next;
    }

    // 将最后一个节点的 Next 指针指向头结点
    TemporaryPointer->next = DLL;

    // 将头节点的前指针指向最后一个节点
    DLL->prior = TemporaryPointer;

    //设置尾指针
    DoubleLinkedListNode* TailPointer = TemporaryPointer;

    //释放临时指针的内存空间
    free(TemporaryPointer);


    return DLL;
}

#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_03_DOUBLELINKEDLIST_H
