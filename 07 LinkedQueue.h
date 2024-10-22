// Filename:Definition.h
// FileType:Definition
// Beginning Time:12/20/2023
// Author:JimMinseay @CopyRight

#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_07_LINKEDQUEUE_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_07_LINKEDQUEUE_H

#include "00 Definition.h"
#include "00 Function.h"

///链式队列初始化
LinkedQueue* LinkedQueue_Initiate(LinkedQueue* LQ)
{
    // 初始化 Front 和 Rear 指针为NULL,表示队列为空
    LQ->Front = NULL;
    LQ->Rear = NULL;

    // 如果队列指针为空,则动态分配内存创建一个新的队列
    LQ = (LinkedQueue*)malloc(sizeof(LinkedQueue));

    //若空间分配失败则输出错误信息
    if (LQ == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    printf("Initiate success.\n");
    return LQ;
}

///入队
LinkedQueue* LinkedQueue_EnQueue(LinkedQueue* LQ, ElementType Value)
{
    // 创建新节点
    LinkedQueueNode* NewLinkedQueueNode = (LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));

    // 处理内存分配失败的情况
    if (NewLinkedQueueNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return LQ; // 返回未修改的队列
    }

    NewLinkedQueueNode->Data = Value;
    NewLinkedQueueNode->Next = NULL; // 新节点将成为队列的末尾，所以将其next指针设置为NULL


    // 如果队列为空，则新节点既是队列的头部又是尾部
    if (LQ->Rear == NULL)
    {
        LQ->Front = NewLinkedQueueNode;
        LQ->Rear = NewLinkedQueueNode;
    }

    // 否则直接将新节点连接到队列尾部并更新rear指针
    else
    {
        LQ->Rear->Next = NewLinkedQueueNode;
        LQ->Rear = LQ->Rear->Next;
    }

    return LQ; // 返回更新后的队列
}

///出队
LinkedQueue* LinkedQueue_Dequeue(LinkedQueue* LQ)
{
    if (LQ->Front == NULL)
    {
        // 队列为空，无法执行出队操作
        printf("Queue is empty. Cannot dequeue.\n");
        return LQ; // 返回未修改的队列
    }

    // 暂存头部节点以便释放内存
    LinkedQueueNode* TemporaryPointer = LQ->Front;

    // 移动队列头部指针指向下一个节点
    LQ->Front = LQ->Front->Next;

    // 如果队列只有一个节点，出队后队列为空，需要更新rear指针同样指向front
    if (LQ->Front == NULL)
    {
        LQ->Rear = LQ->Front;
    }

    free(TemporaryPointer); // 释放被出队的节点的内存空间

    return LQ; // 返回更新后的队列
}

///判断链式队列队空
bool LinkedQueue_JudgeEmpty(LinkedQueue* LQ)
{
    //队列空
    if(LQ->Front == NULL)
    {
        printf("The LinkedQueue is empty.\n");
        return true;
    }

    //队列非空
    else
    {
        printf("The LinkedQueue is not empty.\n");
        return false;
    }
}

///打印链式队列
void LinkedQueue_Print(LinkedQueue* LQ)
{
    // 队列为空，无需打印
    if (LQ->Front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    LinkedQueueNode* TemporaryPointer = LQ->Front; // 从队列头部开始遍历

    while (TemporaryPointer != NULL)
    {
        printf("%d ", TemporaryPointer->Data); // 输出节点的数据
        TemporaryPointer = TemporaryPointer->Next; // 移动到下一个节点
    }

    printf("\n");
}

///求链式队列队长
int LinkedQueue_GetLinkedQueueLength(LinkedQueue* LQ)
{
    int length = 0; // 初始化队列长度为0

    LinkedQueueNode* TemporaryPointer = LQ->Front; // 从队列头部开始遍历

    while (TemporaryPointer != NULL)
    {
        length++; // 每遍历一个节点，增加队列长度
        TemporaryPointer = TemporaryPointer->Next; // 移动到下一个节点
    }

    printf("the length of linkedqueue is %d\n", length);
    return length; // 返回队列的长度
}

///清除所有节点使链式队列中无节点但保留首尾指针
LinkedQueue* LinkedQueue_Clear(LinkedQueue* LQ)
{
    LinkedQueueNode* MovingPointer = LQ->Front;
    LinkedQueueNode* ChasePointer;

    while (MovingPointer != NULL)
    {
        ChasePointer = MovingPointer;
        MovingPointer = MovingPointer->Next;
        free(ChasePointer); // 释放当前节点的内存
    }

    // 将队列的头部和尾部指针都设置为 NULL，表示队列中没有节点了
    LQ->Front = NULL;
    LQ->Rear = NULL;

    return LQ; // 返回更新后的队列
}

///销毁链式队列
void LinkedQueue_Destroy(LinkedQueue* LQ)
{
    //如果链式队列中一个数据结点都没有，那么直接销毁链式队列的首尾指针
    if(LQ->Front == NULL && LQ->Rear == NULL)
    {
        free(LQ); // 释放队列结构体所占用的内存
        printf("LinkedQueue has been destroyed.\n");
    }

    //如果存在有数据结点，则需要依次销毁各个数据结点，最后销毁首尾指针
    else
    {
        LinkedQueueNode* MovingPointer = LQ->Front;
        LinkedQueueNode* ChasePointer;

        while (MovingPointer != NULL)
        {
            ChasePointer = MovingPointer;
            MovingPointer = MovingPointer->Next;
            free(ChasePointer); // 释放当前节点的内存
        }

        free(LQ); // 释放队列结构体所占用的内存
        printf("LinkedQueue has been destroyed.\n");
    }
}

#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_07_LINKEDQUEUE_H
