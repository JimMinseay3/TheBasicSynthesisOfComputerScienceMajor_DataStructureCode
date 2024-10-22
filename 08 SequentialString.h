// Filename:Definition.h
// FileType:Definition
// Beginning Time:12/22/2023
// Author:JimMinseay @CopyRight

#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_08_SEQUENTIALSTRING_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_08_SEQUENTIALSTRING_H

#include "00 Definition.h"
#include "00 Function.h"
#include <string.h> // 导入头文件以使用 strcpy 函数

///串初始化
void SequentialString_Initiate(SequentialString* SS)
{
    int count;

    for (count = 0; count < SequentialStringMaxLength; count++)
    {
        SS->Character[count] = '\0';
    }

    SS->Length = 0;

    printf("Initiate successfully.\n");
}

///插入字符
void SequentialString_Insert(SequentialString *SS, char Character)
{
    SS->Character[SS->Length] = Character;
    SS->Length++;
}

///删除字符
void SequentialString_Delete(SequentialString *SS, int index)
{
    SS->Character[index] = '\0';
    SS->Length--;
}

///查找字符
int SequentialString_Search(SequentialString *SS, char Character)
{
    int count;

    for (count = 0; count < SS->Length; count++)
    {
        if (SS->Character[count] == Character)
        {
            return count;
        }
    }

    return -1;
}

///串赋值
SequentialString* SequentialString_StringAssign(SequentialString* SS, const char* sourceString)
{
    //检查串是否分配空间
    if (SS == NULL || sourceString == NULL)
    {
        return NULL;
    }

    int sourceLength = strlen(sourceString);

    // 确保目标串有足够的空间来存储待复制的字符串
    if (sourceLength >= SequentialStringMaxLength)
    {
        return NULL; // 待复制字符串长度超过目标串的容量，无法复制
    }

    // 逐个字符赋值到目标串中
    int i;
    for (i = 0; i < sourceLength; ++i)
    {
        SS->Character[i] = sourceString[i];
    }
    SS->Character[sourceLength] = '\0'; // 添加字符串结束符
    SS->Length = sourceLength;

    return SS;
}

///串复制
SequentialString* SequentialString_Copy(SequentialString* SS_Old, SequentialString SS_New)
{
    // 检查传入的 SS_Old 是否为空指针
    if (SS_Old == NULL)
    {
        return NULL;
    }

    // 复制 SS_New 的实际长度和字符数组内容到 SS_Old 对应的位置
    SS_Old->Length = SS_New.Length;
    strcpy(SS_Old->Character, SS_New.character);

    return SS_Old;
}

///串判空
bool SequentialString_JudgeEmpty(SequentialString SS)
{
    if (SS.Length == 0)
    {
        printf("The SequentialString is empty.\n");
        return true;
    }
    else
    {
        printf("The SequentialString is not empty.\n");
        return false;
    }
}

///求串长
int SequentialString_GetSequentialStringLength(SequentialString SS)
{
    printf("The Length of SequentialString is: %d\n", SS.length);
    return SS.Length;
}

///串比较
//比较操作，若S.Length > T.Length，则返回值为1，若等于，返回值为0，若小于，返回值为-1
int SequentialString_Compare(SequentialString S, SequentialString T)
{
    if (S.Length > T.Length)
    {
        return 1;
    }

    else if (S.Length == T.Length)
    {
        return 0;
    }

    else
    {
        return -1;
    }
}

///求子串
//用SubString返回串S的第Position个字符起长度为Length的子串
SequentialString SequentialString_SubString(SequentialString* SS, int Position, int Length) {
    SequentialString subString;

    // 检查输入的串是否为空或位置参数是否有效
    if (SS == NULL || Position < 1 || Position > SS->Length || Length < 0 || Position + Length - 1 > SS->Length)
    {
        // 返回空串
        subString.Length = 0;
        subString.Character[0] = '\0';
        return subString;
    }

    // 构建子串
    subString.length = Length;
    int i, j;
    for (i = Position - 1, j = 0; j < Length; ++i, ++j) {
        subString.character[j] = SS->character[i];
    }
    subString.character[j] = '\0'; // 添加字符串结束符

    return subString;
}

///串连接
//用新串NewString返回用SequentialString_1 和 SequentialString_2连接而成的新串
SequentialString* SequentialString_Concatenate(SequentialString* NewString, SequentialString SequentialString_1, SequentialString SequentialString_2) {
    // 检查传入的指针是否有效
    if (NewString == NULL)
    {
        return NULL;
    }

    // 计算连接后的串的长度
    int totalLength = SequentialString_1.length + SequentialString_2.length;

    // 检查连接后的长度是否超过目标串的最大容量
    if (totalLength >= SequentialStringMaxLength)
    {
        return NULL; // 返回空串，因为连接后的长度超过了目标串的最大容量
    }

    // 将第一个串的内容复制到目标串中
    int i;
    for (i = 0; i < SequentialString_1.length; ++i)
    {
        NewString->character[i] = SequentialString_1.character[i];
    }

    // 将第二个串的内容连接到目标串的末尾
    int j;
    for (j = 0; j < SequentialString_2.length; ++j, ++i)
    {
        NewString->character[i] = SequentialString_2.character[j];
    }

    // 更新目标串的长度
    NewString->length = totalLength;
    NewString->character[NewString->length] = '\0'; // 添加字符串结束符

    return NewString;
}

///子串定位
//若主串S中存在与串T值相同的子串，则返回他在主串S中第一次出现的位置。否则函数返回值就为0
int SequentialString_Index(SequentialString S, SequentialString T)
{
    int i, j;

    // 遍历主串
    for (i = 0; i <= S.length - T.length; ++i)
    {
        // 在主串中寻找子串
        for (j = 0; j < T.length; ++j)
        {
            if (S.character[i + j] != T.character[j])
            {
                break; // 子串中有字符不匹配，继续主串的下一个位置匹配
            }
        }

        if (j == T.length)
        {
            return i + 1; // 找到子串，返回在主串中的位置（+1 是因为返回的位置从 1 开始）
        }
    }

    return 0; // 未找到子串，返回 0
}

///清空串
//清空串，将S清空为空串
SequentialString* SequentialString_Clear(SequentialString* SS)
{
    if (SS != NULL)
    {
        SS->length = 0;
        SS->character[0] = '\0'; // 添加字符串结束符
    }

    return SS;
}

///销毁串
//销毁串，将串S销毁
SequentialString* SequentialString_Destroy(SequentialString* SS)
{
    if (SS != NULL)
    {
        free(SS); // 释放串所占用的内存空间
        SS = NULL; // 将串指针置为空指针
    }

    return SS;
}



#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_08_SEQUENTIALSTRING_H
