// Filename:SingleLinkedListList.h
// FileType:Functions
// Beginning Time:11/27/2023
// Author:JimMinseay @CopyRight


#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_02_SINGLELINKEDLIST_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_02_SINGLELINKEDLIST_H

#include "00 Definition.h"
#include "00 Function.h"

///初始化单链表
SingleLinkedList* SingleLinkedList_Initiate(SingleLinkedList* SLL)
{
    //为单链表头结点分配内存空间
    SLL = (SingleLinkedList*) malloc(sizeof (SingleLinkedList));

    //若头结点内存分配失败
    if(SLL == NULL)
    {
        printf("Headnode memory allocation failed.\n");
    }

    else
    {
        //将SLL的next域置为空，代表此时单链表中没有任何数据结点
        SLL->next = NULL;

        //将SLL中的data域置为0，代表此时单链表中的数据结点的个数为0
        SLL->data = 0;
    }

    //返回初始化好的单链表
    return SLL;
}

///头插法建立单链表(逆序建立单链表)
SingleLinkedList* SingleLinkedList_HeadInsert(SingleLinkedList* SLL)
{
    int Value;
    printf("Enter a Value (0 to end):");
    scanf("%d", &Value);

    while (Value != 0)
    {
        SingleLinkedListNode* NewSingleLinkedListNode = (SingleLinkedListNode*)malloc(sizeof(SingleLinkedListNode));
        if (NewSingleLinkedListNode == NULL)
        {
            // 处理内存分配失败的情况
            printf("Memory allocation failed.\n");
            return SLL;
        }

        //为新结点赋值并插入到单链表中
        NewSingleLinkedListNode->data = Value;
        NewSingleLinkedListNode->next = SLL->next; // 将新节点插入在头节点之后
        SLL->next = NewSingleLinkedListNode; // 更新头节点为新插入的节点

        //单链表长度加1
        SLL->data ++;

        //继续输入循环条件
        printf("Enter a Value (0 to end): ");
        scanf("%d", &Value);
    }

    //构建完毕后，返回新的单链表
    return SLL;
}

///尾插法建立单链表(顺序建立单链表)
SingleLinkedList* SingleLinkedList_TailInsert(SingleLinkedList* SLL)
{
    int Value;
    SingleLinkedListNode* TailPointer = SLL; // 找到当前链表的末尾节点

    printf("Enter a Value (0 to end): ");
    scanf("%d", &Value);

    while (Value != 0)
    {
        //创建新结点
        SingleLinkedListNode* NewSingleLinkedListNode = (SingleLinkedListNode*)malloc(sizeof(SingleLinkedListNode));

        // 处理内存分配失败的情况
        if (NewSingleLinkedListNode == NULL)
        {
            printf("Memory allocation failed,\n");
            return SLL;
        }

        //为新结点赋值，并插入新结点
        NewSingleLinkedListNode->data = Value;
        NewSingleLinkedListNode->next = NULL;
        TailPointer->next = NewSingleLinkedListNode; // 将新节点连接到当前链表的末尾
        TailPointer = NewSingleLinkedListNode; // 更新尾节点为新插入的节点

        //单链表长度加1
        SLL->data ++;

        printf("Enter a Value (0 to end): ");
        scanf("%d", &Value);
    }

    return SLL;
}

///插入结点
SingleLinkedList* SingleLinkedList_InsertNode(SingleLinkedList* SLL, int Subscript, ElementType Value)
{
    //检查下标合法性
    if (Subscript <= 0)
    {
        printf("Invalid subscript. Subscript should be greater than or equal to 0.\n");
    }

    //建立新结点
    SingleLinkedListNode* NewSingleLinkedListNode = (SingleLinkedListNode*)malloc(sizeof(SingleLinkedListNode));

    // 处理内存分配失败的情况
    if (NewSingleLinkedListNode == NULL)
    {
        printf("Memory allocation failed.\n");
    }

    //为新结点赋值
    NewSingleLinkedListNode->data = Value;

    //建立临时指针
    SingleLinkedListNode* TemporaryPointer = SLL;

    //建立下标序号计数器
    int count = 0;

    // 寻找插入位置的前一个节点
    while (TemporaryPointer != NULL && count < Subscript - 1)
    {
        TemporaryPointer = TemporaryPointer->next;
        count++;
    }

    //如果在按照下标移动后，临时指针没有指向NULL
    if (TemporaryPointer != NULL)
    {
        //为新结点赋值，并插入新节点
        NewSingleLinkedListNode->data = Value;
        NewSingleLinkedListNode->next = TemporaryPointer->next;
        TemporaryPointer->next = NewSingleLinkedListNode;

        //单链表长度加1
        SLL->data ++;
    }

    // 否则说明下标超过了单链表的数据结点个数,此时将判定为下标错误，同时会销毁新结点的内存空间
    else
    {
        printf("Subscript Error!");
        free(NewSingleLinkedListNode);
    }

    return SLL;
}

///删除结点
SingleLinkedListNode* SinglelinkedList_DeleteNode(SingleLinkedList* SLL, int Subscript)
{
    //检查单链表是否为空表
    if(SLL == NULL)
    {
        printf("This SinglelinkedList is Empty!");
        return NULL;
    }

    //检查下标是否合法
    if(Subscript <= 0 || Subscript > SLL->data)
    {
        printf("Subscript Error!");
        return NULL;
    }

    //创建下标序号计数器
    int count;

    //创建临时指针，初始指向为头指针
    SingleLinkedListNode* TemporaryPointer = SLL;

    // 从链表的第一个数据结点（非头结点）开始遍历，向后移动直到达到指定的下标
    for(count = 0; count < Subscript - 1; count++)
    {
        TemporaryPointer = TemporaryPointer->next;
    }

    //建立内存释放指针指向即将被删除的结点，用以在将欲删除的结点移出单链表后释放该结点的内存空间
    SingleLinkedListNode* FreeMemoryPointer = TemporaryPointer->next;

    //将临时指针的链接绕过被删除的结点链接至下一个结点，以维持单链表的链接
    TemporaryPointer->next = FreeMemoryPointer->next;

    //释放被删除的结点的内存空间
    free(FreeMemoryPointer);

    //结点删除完毕后单链表的长度减1
    SLL->data --;

    //返回修改后的单链表
    return  SLL;
}

///按下标查找结点
SingleLinkedListNode* SingleLinkedList_SearchNodeBySubscript(SingleLinkedList* SLL, int Subscript)
{
    //检查单链表是否为空表
    if(SLL == NULL)
    {
        printf("This SinglelinkedList is Empty!");
        return NULL;
    }

    //检查下标是否合法
    //若下标不合法则显示失败信息并返回原单链表
    if(Subscript <= 0 || Subscript > SLL->data)
    {
        printf("Subscript Error!");
        return SLL;
    }

    //创建下标序号计数器变量
    int count;

    //创建临时指针,初始指向为第一个数据节点
    //这里并不用担心TemporaryPointer会指向NULL,因为上文已经做了空表检查，也就是说SLL中至少会有一个数据结点
    SingleLinkedListNode* TemporaryPointer = SLL->next;

    // 从链表的第一个数据结点（非头结点）开始遍历，向后移动直到达到指定的下标
    // 如果找到相应下标的结点，则返回该结点的指针；
    for(count = 1; count < Subscript; count++)
    {
        TemporaryPointer = TemporaryPointer->next;
    }
    return  TemporaryPointer;

}

///按值查找结点
SingleLinkedListNode* SingleLinkedList_SearchByValue(SingleLinkedList* SLL, ElementType Value)
{
    //如果单链表为空表
    if (SLL == NULL)
    {
        printf("This SingleLinkedList is Empty!");
        return NULL; // 链表为空
    }

    //建立临时指针，初始指向为头结点
    SingleLinkedListNode* TemporaryPointer = SLL;

    //
    int count = 0;

    //建立循环，且循环条件为：在完全遍历单链表之前找到相应的值对应的结点
    while (TemporaryPointer != NULL)
    {
        //若在某次循环中，找到了想要找的值
        if (TemporaryPointer->data == Value)
        {
            //显示输出信息
            printf("The Value: %d is in %d of the SingleLinkedList.\n", Value, count);

            //返回对应结点的指针
            return TemporaryPointer; // 找到匹配值的结点，返回该结点指针
        }

        //否则
        else
        {
            //指针继续向后移动
            TemporaryPointer = TemporaryPointer->next;
            count ++;
        }
    }

    //返回指针
    return TemporaryPointer;
}

///求单链表的表长
//虽然在头结点的data域中记录了单链表的长度，但是本函数用不断移动临时指针的方式逐一记录单链表中数据结点的个数
//以达到求出数据结点个数总和，也就是单链表的长度的目的
int SingleLinkedList_GetSingleLinkedListLength(SingleLinkedList* SLL)
{
    if(SLL->next == NULL)
    {
        printf("This SingleLinkedList is Empty!\n");
        return 0;
    }

    else
    {
        //建立数据结点个数计数器
        int count = 0;

        // 从头节点(非第一个数据结点)开始遍历
        SingleLinkedListNode* TemporaryPointer = SLL;

        while (TemporaryPointer->next != NULL)
        {
            TemporaryPointer = TemporaryPointer->next;
            count++;
        }

        printf("The Length Of The SingleLinkedList is %d\n", count);
        return count;
    }
}

///打印单链表
void SingleLinkedList_Print(SingleLinkedList* SLL)
{
    //建立临时指针，指向第一个数据结点，从第一个数据结点开始遍历
    SingleLinkedListNode* TemporaryPointer = SLL->next;

    //只要此时临时指针仍然指向某个数据结点，即不指向NULL
    //那么循环就继续执行
    while (TemporaryPointer != NULL)
    {
        printf("%d ", TemporaryPointer->data); // 打印节点的数据域
        TemporaryPointer = TemporaryPointer->next; // 移动到下一个节点
    }

    printf("\n");
}

///单链表循环化
//使单链表最后一个数据结点的next域指向头结点，使整个单链表循环化，并设置尾指针指向最后一个数据结点
SingleLinkedList* SingleLinkedList_Circularize(SingleLinkedList* SLL)
{
    // 处理链表为空或只有一个节点的情况
    if (SLL == NULL)
    {
        printf("This SingleLinkedList is Empty!");
        return SLL;
    }

    if(SLL->next == NULL)
    {
        printf("This SingleLinkedList Only Have Head Node!");
        return SLL;
    }

    SingleLinkedList* TemporaryPointer = SLL;

    // 遍历链表找到最后一个节点
    while (TemporaryPointer->next != NULL)
    {
        TemporaryPointer = TemporaryPointer->next;
    }

    // 将最后一个节点的next域指向头结点
    TemporaryPointer->next = SLL;

    //设置尾指针
    SingleLinkedListNode* TailPointer = TemporaryPointer;

    //释放临时指针的内存空间
    free(TemporaryPointer);

    return SLL;
}


#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_02_SINGLELINKEDLIST_H
