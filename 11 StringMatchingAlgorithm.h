// Filename:Definition.h
// FileType:Algorithm
// Beginning Time:12/23/2023
// Author:JimMinseay @CopyRight

#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_11_STRINGMATCHINGALGORITHM_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_11_STRINGMATCHINGALGORITHM_H

#include "00 Definition.h"
#include "08 SequentialString.h"
#include "09 HeapString.h"
#include "10 LinkedString.h"

///串的简单的模式匹配算法
/*这个函数接受两个串作为参数：主串 S 和要搜索的模式串 T。它会遍历主串并在每个位置开始尝试匹配模式串 T。
 * 如果找到了完全匹配的子串，函数将返回子串在主串中第一次出现的位置；
 * 如果未找到，则返回 -1 表示未匹配。*/
int String_NaiveStringMatchingAlgorithm(SequentialString S, SequentialString T)
{
    int i, j;

    for (i = 0; i <= S.length - T.length; ++i)
    {
        for (j = 0; j < T.length; ++j)
        {
            if (S.character[i + j] != T.character[j])
            {
                break;
            }
        }

        if (j == T.length)
        {
            return i; // 找到匹配的位置，返回在主串中的位置
        }
    }

    return -1; // 未找到匹配的子串，返回 -1
}

///KMP算法的前置工作——建立next数组
void String_BuildNext(SequentialString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;

    while (i < T.length)
    {
        if(j == 0 || T.character[i] == T.character[j])
        {
           ++i;
           ++j;
           next[i] = j;
        }

        else
        {
            j = next[j];
        }
    }
}


///串的模式匹配算法——KMP算法
/*
 * */
int String_KnuthMorrisPratt(SequentialString S, SequentialString T, const int next[])
{
    int i = 1;
    int j = 1;

    while (i < S.length && j < T.length)
    {
        if(j == 0 || S.character[i] == T.character[i])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }

    if(j > T.length)
        return i - T.length;
    else
        return 0;
}

///KMP算法的进一步优化——建立NextValue数组
void String_BuildNextValue(SequentialString T, int NextValue[])
{
    //i表示主串的下标，j表示模式串的下标
    int i = 0;
    int j = 0;

    //初始化NextValue数组
    NextValue[1] = 0;

    //从主串的第二个字符开始计算NextValue数组
    while (i < T.length)
    {
        //如果j为0或者主串和模式串当前字符相等
        if (j == 0 || T.character[i] == T.character[j])
        {
            //主串和模式串当前字符相等，则i和j同时加1
            ++i;
            ++j;

            //如果主串和模式串当前字符不相等，则NextValue[i]等于j
            if (T.character[i] != T.character[j])
                NextValue[i] = j;
            else
            {
                //如果主串和模式串当前字符相等，则NextValue[i]等于NextValue[j]
                //这是对KMP算法原始Next数组的优化，可以避免重复计算
                NextValue[i] = NextValue[j];
            }
        }

        //如果主串和模式串当前字符不相等
        else
        {
            //j回退到NextValue[j]处
            j = NextValue[j];
        }
    }
}



#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_11_STRINGMATCHINGALGORITHM_H
