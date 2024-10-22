// Filename:SequentialStack.h
// FileType:Functions
// Beginning Time:12/12/2023
// Author:JimMinseay @CopyRight

#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_04_SEQUENTIALSTACK_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_04_SEQUENTIALSTACK_H

#include "00 Definition.h"
#include "00 Function.h"

///初始化顺序栈
void SequentialStack_Initiate(SequentialStack* SS)
{
    SS->top = -1; // 将栈顶指针初始化为-1，表示空栈
}

///进栈
//入栈操作
void SequentialStack_Push(SequentialStack *SS, ElementType Element)
{
    //栈满的情况
    if (SS->top == SequentialStackMaxLength - 1)
    {
        printf("The SequentialStack is full.\n");
    }

    SS->data[++SS->top] = Element;
}

///出栈
void SequentialStack_Pop(SequentialStack* SS)
{
    if(SS->top == -1)
    {
        printf("The SequentialStack is empty.\n");
    }

    SS->top--;
}

///读栈顶元素


///求栈的长度


///栈置空，把栈置为空栈


///顺序栈判空


///打印栈


///销毁栈










#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_04_SEQUENTIALSTACK_H
