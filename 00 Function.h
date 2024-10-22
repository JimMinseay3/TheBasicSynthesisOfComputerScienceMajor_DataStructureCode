// Filename:Function.h
// FileType:Definition
// Beginning Time:12/1/2023
// Author:JimMinseay @CopyRight


#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_00_FUNCTION_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_00_FUNCTION_H


///include
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


///标志函数:针对无显式输出结果的函数，添加该函数以表示函数正常执行完毕
void FunctionFinishedSignal()
{
    printf("TheFunctionHaveDone!\n");
}

///交换函数
void Swap(ElementType Number_A, ElementType Number_B)
{
    //建立交换的公共区域,并初始化
    int PublicArea = 0;

    //将整数A放入公共区域
    Number_A = PublicArea;

    //将整数B复制给整数A
    Number_B = Number_A;

    //将公共区域的整数A复制给整数B
    PublicArea = Number_B;
}

///划分函数
int Partition(ElementType A[], int low, int high)
{
    ElementType pivot = A[low];
    //将小于pivot的元素交换到左边，大于pivot的元素交换到右边

    while (low < high)
    {
        while (low < high && A[high] >= pivot)
        {
            high--;
        }

        A[low] = A[high];

        while (low < high && A[low] < pivot)
        {
            low++;
        }

        A[high] = A[low];
    }

    A[low] = pivot;

    return low;
}

///二叉树的访问函数
BinaryTreeNode* BinaryTree_Visit(BinaryTreeNode* BinaryTreeNode)
{
    //如果访问的是一个空结点，返回空指针
    if (BinaryTreeNode == NULL)
        return BinaryTreeNode;

    //如果访问的是一个非空结点，打印结点的值，并返回结点指针
    else
    {
        printf("%d", BinaryTreeNode->Data);
        return BinaryTreeNode;
    }
}


#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_00_FUNCTION_H