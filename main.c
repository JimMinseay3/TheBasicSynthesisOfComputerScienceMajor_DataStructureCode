#include "00 Definition.h"
#include "01 SequentialList.h"
#include "02 SingleLinkedList.h"
#include "03 DoubleLinkedList.h"
#include "04 SequentialStack.h"
#include "05 LinkedStack.h"
#include "06 SequentialQueue.h"
#include "07 LinkedQueue.h"


int main()
{
///顺序表函数测试区
//    SequentialList Sequential_one;
//    SequenceList_Initiate(&Sequential_one);
//    SequenceList_InsertElement(&Sequential_one, 1, 2002);
//    SequenceList_InsertElement(&Sequential_one, 2, 9);
//    SequenceList_InsertElement(&Sequential_one, 3, 1);
//    SequentialList_GetSequentialListLength(Sequential_one);
//    SequentialList_PrintSequentialList(Sequential_one);
//    SequentialList_Traverse(Sequential_one);


///单链表函数测试区
    SingleLinkedList SingleLinkedList_Testing;
    SingleLinkedList_Initiate(&SingleLinkedList_Testing);

    printf("the SingleLinkedList Data is :%d\n", SingleLinkedList_Testing.data);

    SingleLinkedList_Print(&SingleLinkedList_Testing);


///双链表函数测试区


///静态链表函数测试区


///顺序栈函数测试区


///链式栈函数测试区


///顺序队列函数测试区


///链式队列函数测试区
//    LinkedQueue LinkedQueue_Test;
//    LinkedQueue_Initiate(&LinkedQueue_Test);
//    LinkedQueue_JudgeEmpty(&LinkedQueue_Test);
//
//
//    LinkedQueue_EnQueue(&LinkedQueue_Test, 999);
//    LinkedQueue_EnQueue(&LinkedQueue_Test, 666);
//    LinkedQueue_Print(&LinkedQueue_Test);
//    LinkedQueue_GetLinkedQueueLength(&LinkedQueue_Test);
//    LinkedQueue_JudgeEmpty(&LinkedQueue_Test);
//
//    LinkedQueue_Dequeue(&LinkedQueue_Test);
//    LinkedQueue_Print(&LinkedQueue_Test);
//    LinkedQueue_GetLinkedQueueLength(&LinkedQueue_Test);
//
//    LinkedQueue_Clear(&LinkedQueue_Test);
//    LinkedQueue_JudgeEmpty(&LinkedQueue_Test);
//
//    LinkedQueue_Destroy(&LinkedQueue_Test);

///串函数测试区


///树函数测试区


///图函数测试区


///排序函数测试区


///查找函数测试区





}