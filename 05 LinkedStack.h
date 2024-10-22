// Filename:LinkedStack.h
// FileType:Functions
// Beginning Time:12/20/2023
// Author:JimMinseay @CopyRight

#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_05_LINKEDSTACK_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_05_LINKEDSTACK_H

#include "00 Definition.h"
#include "00 Function.h"

///初始化链式栈
LinkedStack* LinkedStack_Initiate(LinkedStack* LS)
{
    // 分配内存给新的栈
    LS = (LinkedStack*)malloc(sizeof(LinkedStack));

    if (LS == NULL)
    {
        // 内存分配失败处理
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // 将栈顶指针置为空，表示链式栈为空
    LS->next = NULL;

    return LS;
}

///在链式栈的头部插入元素（入栈）
LinkedStack* LinkedStack_Insert(LinkedStack* LS, ElementType Value)
{
    // 创建新的节点
    LinkedStackNode* NewLinkedStackNode = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));

    // 内存分配失败处理
    if (NewLinkedStackNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return LS;
    }

    // 将数据存储到新节点
    NewLinkedStackNode->data = Value;

    // 将新节点的指针指向原来链表的头部
    NewLinkedStackNode->next = LS;

    // 更新链表的头指针
    LS = NewLinkedStackNode;

    return LS;
}

///删除链式栈的栈首元素（出栈）
LinkedStack* LinkedStack_Delete(LinkedStack* LS)
{
    // 空栈，无法出栈
    if (LS == NULL)
    {
        printf("Stack is empty. Cannot perform pop operation.\n");
        return LS;
    }

    // 保存原始栈顶指针
    LinkedStackNode* TemporaryPointer = LS;

    // 更新栈顶指针为下一个节点
    LS = LS->next;

    // 释放原来栈顶节点的内存
    free(TemporaryPointer);

    return LS;
}

///链式栈判空
bool LinkedStack_JudgeEmpty(LinkedStack* LS)
{
    if(LS == NULL)
    {
        return true;
    }

    else
    {
        return false;
    }
}

///求链式栈的长度
int LinkedStack_GetLinkedStackLength(LinkedStack* LS)
{
    int length = 0;
    LinkedStackNode* TemporaryPointer = LS;

    while (TemporaryPointer != NULL)
    {
        length++;
        TemporaryPointer = TemporaryPointer->next;
    }

    return length;
}

///打印链式栈
void LinkedStack_Print(LinkedStack* LS)
{
    LinkedStackNode* TemporaryPointer = LS;

    printf("Linked Stack: ");
    while (TemporaryPointer != NULL)
    {
        printf("%d ", TemporaryPointer->data); // 假设元素类型为整数，可以根据实际类型修改打印方式
        TemporaryPointer = TemporaryPointer->next;
    }

    printf("\n");
}

///销毁链式栈
LinkedStack* LinkedStack_Destroy(LinkedStack* LS)
{
    //建立移动指针
    LinkedStackNode* MovingPointer = LS;

    //建立追逐指针
    LinkedStackNode* ChasePointer;

    while (MovingPointer != NULL)
    {
        ChasePointer = MovingPointer;
        MovingPointer = MovingPointer->next;
        free(ChasePointer); // 释放节点内存
    }

    LS = NULL; // 将链表头指针置为空

    return LS;
}



#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_05_LINKEDSTACK_H
