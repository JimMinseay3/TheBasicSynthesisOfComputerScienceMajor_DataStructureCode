// Filename:SequentialQueue.h
// FileType:Functions
// Beginning Time:12/20/2023
// Author:JimMinseay @CopyRight

#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_06_SEQUENTIALQUEUE_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_06_SEQUENTIALQUEUE_H

#include "00 Definition.h"
#include "00 Function.h"

/*本顺序队列采用循环队列逻辑结构*/
/*为了区分队空还是队满，采用牺牲一个单元来区分，入队时少用一个队列单元
 *约定以“队头指针在队尾指针的下一位置”作为队满的标志
 * 队满条件：(SQ->Rear + 1) % SequentialQueueMaxLength == SQ->Front
 * 队空条件：SQ->Front == SQ->Rear
 * 队列中元素的个数：(SQ->Rear - SQ->Front + SequentialQueueMaxLength) % SequentialQueueMaxLength */

///初始化顺序队列
SequentialQueue* SequentialQueue_Initiate(SequentialQueue* SQ)
{
    // 分配内存给新的队列
    SQ = (SequentialQueue*)malloc(sizeof(SequentialQueue));

    // 内存分配失败处理
    if (SQ == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // 初始化队列的头部和尾部指针为0，表示队列为空
    SQ->front = SQ->rear = 0;

    return SQ;
}

///入队
SequentialQueue* SequentialQueue_Enqueue(SequentialQueue* SQ, ElementType Value)
{
    // 队列未初始化，无法执行入队操作
    if (SQ == NULL)
    {
        printf("Queue is not initialized.\n");
        return SQ;
    }

    // 队列已满，无法执行入队操作
    if ((SQ->rear + 1) % SequentialQueueMaxLength == SQ->front)
    {
        printf("Queue is full. Cannot perform enqueue operation.\n");
        return SQ;
    }

    // 将元素插入队列尾部
    SQ->rear = (SQ->rear + 1) % SequentialQueueMaxLength;
    SQ->data[SQ->rear] = Value;

    return SQ;
}

///出队
SequentialQueue* SequentialQueue_Dequeue(SequentialQueue* SQ)
{
    // 队列未初始化，无法执行出队操作
    if (SQ == NULL)
    {
        printf("Queue is not initialized.\n");
        return SQ;
    }

    // 队列为空，无法执行出队操作
    if (SQ->front == SQ->rear)
    {
        printf("Queue is empty. Cannot perform dequeue operation.\n");
        return SQ;
    }

    // 取出队头元素
    ElementType DequeuedElement = SQ->data[SQ->front];

    // 更新队头指针
    SQ->front = (SQ->front + 1) % SequentialQueueMaxLength;

    printf("Dequeued element: %d\n", DequeuedElement); // 可以根据需要打印出队元素

    return SQ;
}

///判断队空
bool SequentialQueue_JudgeEmpty(SequentialQueue* SQ)
{
    if(SQ->front == SQ->rear)
        return true;
    else
        return false;
}

///清空队列
SequentialQueue* SequentialQueue_Clear(SequentialQueue* SQ)
{
    // 队列未初始化，无法执行清空操作
    if (SQ == NULL)
    {
        printf("Queue is not initialized.\n");
        return SQ;
    }

    // 将队列头尾指针重置为-1，表示队列为空
    SQ->front = SQ->rear = 0;

    return SQ;
}

///打印顺序队列
void SequentialQueue_Print(SequentialQueue* SQ)
{
    if (SQ->front == SQ->rear)
    {
        printf("SequentialQueue is empty.\n");
        return;
    }

    printf("Elements in SequentialQueue: ");
    int count;
    for (count = SQ->front; count < SQ->rear; ++count)
    {
        printf("%d ", SQ->data[count]);
    }
    printf("\n");
}

///求顺序队列的长度
int SequentialQueue_GetSequentialQueueLength(SequentialQueue* SQ)
{

    // //队列未初始化以及队列长度为0的情况
    if (SQ == NULL || SQ->front == SQ->rear)
    {
        return 0;
    }

    //队列的实际长度
    int length = (SQ->rear - SQ->front + SequentialQueueMaxLength + 1) % SequentialQueueMaxLength;

    return length;
}

///销毁顺序队列
SequentialQueue* SequentialQueue_Destroy(SequentialQueue* SQ)
{
    if (SQ != NULL)
    {
        free(SQ); // 释放队列结构占用的内存
        SQ = NULL; // 将队列指针置为空
    }

    return SQ;
}

#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_06_SEQUENTIALQUEUE_H
