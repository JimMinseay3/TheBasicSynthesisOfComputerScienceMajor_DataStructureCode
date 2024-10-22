// Filename:Definition.h
// FileType:Functions
// Beginning Time:12/24/2023
// Author:JimMinseay @CopyRight

#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_13_UNIONFINDSET_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_13_UNIONFINDSET_H

#include "00 Definition.h"
#include "00 Function.h"

///并查集的初始化
void UnionFindSet_Initiate(ElementType UnionFindSet[])
{
    int i;

    for (i = 0; i < UnionFindMaxSize; ++i)
    {
        UnionFindSet[i] = -1;
    }
}

///Find操作
//函数在并查集UnionFindSet中查找并返回包含元素x的树的根
int UnionFindSet_Find()
{

}

///Union操作
//函数求两个不相交的子集合的并集
void UnionFindSet_Union()
{

}



#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_13_UNIONFINDSET_H
