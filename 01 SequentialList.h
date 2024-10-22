// Filename:SequentialList.h
// FileType:Function
// Beginning Time:9/16/2023
// Author:JimMinseay @CopyRight


#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_01_SEQUENTIALLIST_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_01_SEQUENTIALLIST_H

#include "00 Definition.h"
#include "00 Function.h"

///初始化顺序表
//构造一个空的顺序表
bool SequenceList_Initiate(SequentialList* SL)
{
    SL->SequentialListLength = 0;
    return true;
}

///插入元素
//在顺序表的第i个位置插入新元素element（非数组下标为i的位置，第i个位置对应的数组下标为i-1）
bool SequenceList_InsertElement(SequentialList* SL, int i, ElementType element)
{
    int j;//定义局部变量j，用于暂存数组的当前长度

    if(SL->SequentialListLength >= SequentialListMaxLength) //检查该顺序表是否空间已满，空间已满会导致插入失败
        return false;

    if(i < 1 || i > SequentialListMaxLength) //检查插入位置是否合法，插入序号小于0或者大于等于表的最大长度长都会导致插入失败
        return false;

    for(j = SL->SequentialListLength; j >= i; j--) //从顺序表的最后一位开始，逐位将表中元素向后移动一位，直到来到序号为i+1的位置
    {
        SL->data[j] = SL->data[j - 1];
    }

    SL->data[i - 1] = element; //将要插入的元素e插入到表的 i-1 的位置
    SL->SequentialListLength++; //由于插入了一个元素，表长+1

    FunctionFinishedSignal();
    return true;
}

///删除元素
//删除顺序表中指定下标的元素
bool SequenceList_DeleteElement(SequentialList* SL, int i)
{
    int j;

    if(SL->SequentialListLength == 0) //检查该顺序表是否是空表，空表无法进行删除操作
    {
        return false;
    }

    if(i<1 || i > SL->SequentialListLength)
    {
        return false;
    }

//    新建局部变量用于存储被删除的元素值
//    ElementType *element = NULL;
//    *element = SL->Data[i-1];

    for(j = i; j < SL->SequentialListLength; j++) //定义变量j，从序号i开始，一直到表L的表长SequentialListLength，执行将使得每个元素前移一位
        SL->data[j - 1] = SL->data[j];

    SL->SequentialListLength--; //由于删除了一个元素，表长-1

    FunctionFinishedSignal();
    return true;
}

///按下标查找
//根据程序员提供的下标，查找顺序表中该下标的元素，并返回它的值
ElementType SequentialList_SearchElementBySubscript(SequentialList SL, int i)
{
    printf("The NO.%d Element In The SequentialList is: %d \n", i, SL.data[i - 1]); //查找第i个元素，寻找数组下标为为i-1的元素
    return SL.data[i - 1];
}

///按值查找
//根据程序员提供的值，查找顺序表中第一个符合值的元素，并返回它的下标
ElementType SequentialList_SearchElementByValue(SequentialList SL, ElementType element)
{
    int i;

    for(i = 0; i < SL.SequentialListLength; i++) //
    {
        if(SL.data[i] == element)
            return i+1;
    }

    FunctionFinishedSignal();
    return -1;
}

///查找元素前驱
//根据程序员提供的下标，查找其前驱元素，并返回前驱元素的值
ElementType SequentialList_SearchPriorElement(SequentialList SL, int i)
{
    if (i <= 1 || i > SL.SequentialListLength)
    {
        // 如果下标超出范围或是第一个元素，则没有前驱元素，这里可以根据需求返回错误码或特定值
        // 这里假设返回一个默认值 0，你可以根据实际情况修改
        return -1;
    }
    else
    {
        // 返回指定下标元素的前驱元素值
        return SL.data[i - 2]; //
    }
}

///查找元素后继
//根据程序员提供的下标，查找其后继元素，并返回后继元素的值
ElementType SequentialList_SearchNextElement(SequentialList SL, int i)
{
    if (i < 1 || i >= SL.SequentialListLength) {
        // 如果下标超出范围或是最后一个元素，则没有后继元素，返回默认值或错误码
        // 这里假设返回一个默认值 0，你可以根据实际情况修改
        return 0;
    }
    else
    {
        printf("%d", SL.data[i]);
        // 返回指定下标元素的后继元素值
        return SL.data[i]; //
    }

}

///遍历顺序表
//遍历顺序表
bool SequentialList_Traverse(SequentialList SL)
{
    if (SL.SequentialListLength == 0)
    {
        // 如果顺序表为空，返回 false 表示遍历失败
        return false;
    }
    else
    {
        printf("Sequential List Elements:\n");
        int i;
        for (i = 0; i < SL.SequentialListLength; i++) {
            printf("%d ", SL.data[i]); // 假设 ElementType 是 int 类型
        }
        printf("\n");
        // 返回 true 表示遍历成功
        return true;
    }
}

///顺序表判空
//判断顺序表是否为空表,可以通过检查顺序表的长度来完成。如果顺序表的长度为0，则说明表中没有元素，即为空表。
bool SequentialList_JudgeEmpty(SequentialList SL)
{
    if (SL.SequentialListLength == 0)
    {
        printf("This SequentialList is empty.\n");
        // 如果顺序表长度为0，表示为空表，返回 true
        return true;
    }

    else
    {
        printf("This SequentialList is not empty.\n");
        // 否则，顺序表不为空表，返回 false
        return false;
    }
}

///求表长
//返回顺序表的元素个数（元素个数代表该顺序表的表长）
void SequentialList_GetSequentialListLength(SequentialList SL)
{
    printf("The Length of This SequentialList is %d\n", SL.SequentialListLength);
}

///打印顺序表
//输出顺序表中的所有元素以便查看
bool SequentialList_PrintSequentialList(SequentialList SL)
{
    int i;

    if (SL.SequentialListLength == 0)
    {
        printf("Empty List!\n");
        return false;
    }

    else

        for(i = 1; i <= SL.SequentialListLength; i++)
        {
            printf("The No.%d Element is: %d\n", i, SL.data[i - 1]);
        }


    return true;
}

///清空顺序表
//清空顺序表中当前的所有元素，使其成为空表（并不销毁该顺序表的内存空间）
bool SequentialList_Clear(SequentialList *SL) {
    if (SL != NULL)
    {
        SL->SequentialListLength = 0; // 将顺序表的长度设置为0，即清空顺序表
        return true; // 返回 true 表示清空成功
    }
    else
    {
        return false; // 返回 false 表示顺序表为空指针，清空失败
    }
}

///销毁顺序表
//销毁一个顺序表（销毁该顺序表的内存空间）
bool SequentialList_Destroy(SequentialList *SL)
{
    if (SL != NULL)
    {
        free(SL); // 释放顺序表占用的内存空间
        return true; // 返回 true 表示销毁成功
    }
    else
    {
        return false; // 返回 false 表示顺序表为空指针，销毁失败
    }
}
#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_01_SEQUENTIALLIST_H