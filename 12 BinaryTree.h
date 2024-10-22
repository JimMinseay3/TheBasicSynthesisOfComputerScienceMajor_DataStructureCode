// Filename:Definition.h
// FileType:Functions
// Beginning Time:12/23/2023
// Author:JimMinseay @CopyRight

#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_12_BINARYTREE_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_12_BINARYTREE_H

#include "00 Definition.h"
#include "00 Function.h"

//普通二叉树
///初始化二叉树
BinaryTree* BinaryTree_Initiate(BinaryTree* BinaryTree)
{
    // 检查输入的二叉树指针是否为空
    if (BinaryTree == NULL)
    {
        // 如果为空，则分配空间初始化二叉树
        BinaryTree = (BinaryTree*)malloc(sizeof(BinaryTree));

        // 检查分配空间是否成功
        if (BinaryTree == NULL)

            // 如果分配空间失败，则返回 NULL
            return NULL;

    }
    else
    {
        // 初始化二叉树的左右子树
        BinaryTree->LeftChild = NULL;
        BinaryTree->RightChild = NULL;
    }

    // 返回二叉树
    return BinaryTree;
}

///销毁二叉树
BinaryTree* BinaryTree_Destroy(BinaryTree* BT)
{

}

///将二叉树清空为空树
BinaryTree* BinaryTree_Clear(BinaryTree* BT)
{

}

///二叉树判空
bool BinaryTree_JudgeEmpty(BinaryTree BT)
{

}

///返回二叉树的深度
int BinaryTree_GetBinaryTreeDepth(BinaryTree BT)
{

}

///返回二叉树的根
BinaryTree* BinaryTree_FindRoot(BinaryTree* BT)
{

}

///返回二叉树中某个节点的值
ElementType BinaryTree_GetValue(BinaryTree* BT, BinaryTreeNode* BTN)
{

}

///为二叉树的某个结点赋值
void BinaryTree_Assign(BinaryTree* BT, BinaryTreeNode* BTN, ElementType Value)
{

}

///返回二叉树中某个结点的双亲


///返回二叉树中某个结点的左孩子


///返回二叉树中某个结点的右孩子


///返回二叉树中某个结点的左兄弟


///返回二叉树中某个结点的右兄弟


///插入结点


///删除结点


///先序遍历二叉树
void BinaryTree_PreOrderTraverse(BinaryTree* BinaryTree)
{
    // 检查二叉树是否为空
    if (BinaryTree == NULL)
        printf("BinaryTree is empty!\n");

    //
    else
    {
        BinaryTree_Visit(BinaryTree);

        BinaryTree_PreOrderTraverse(BinaryTree->LeftChild);

        BinaryTree_PreOrderTraverse(BinaryTree->RightChild);
    }
}

///先序遍历的非递归算法


///中序遍历二叉树
void BinaryTree_InOrderTraverse(BinaryTree* BinaryTree)
{
    //
    if (BinaryTree == NULL)
        printf("BinaryTree is empty!\n");

    //
    else
    {
        BinaryTree_InOrderTraverse(BinaryTree->LeftChild);
        BinaryTree_Visit(BinaryTree);
        BinaryTree_InOrderTraverse(BinaryTree->RightChild);
    }
}

///后序遍历二叉树
void BinaryTree_PostOrderTraverse(BinaryTree* BinaryTree)
{
    // 检查二叉树是否为空
    if (BinaryTree == NULL)
        printf("BinaryTree is empty!\n");

    //
    else
    {
        BinaryTree_PostOrderTraverse(BinaryTree->LeftChild);
        BinaryTree_PostOrderTraverse(BinaryTree->RightChild);
        BinaryTree_Visit(BinaryTree);
    }
}

///后序遍历的非递归算法


///层次遍历二叉树



///中序遍历下某个结点的前驱结点和后继结点
void BinaryTree_FindProdromalNode_Visit(BinaryTreeNode* BinaryTreeNodePointer,BinaryTreeNode* TargetBinaryTreeNode,BinaryTreeNode* Pre)
{
    if(BinaryTreeNodePointer == TargetBinaryTreeNode)
        ;

    else
        Pre = BinaryTreeNodePointer;
}

BinaryTreeNode* BinaryTree_FindProdromalNode_InOrderTraverse(BinaryTree* BinaryTree,BinaryTreeNode* TargetBinaryTreeNode,BinaryTreeNode* Pre)
{
    if(BinaryTree != NULL)
    {
        BinaryTree_FindProdromalNode_InOrderTraverse(BinaryTree->LeftChild, TargetBinaryTreeNode, Pre);
        BinaryTree_FindProdromalNode_Visit(BinaryTree, TargetBinaryTreeNode, Pre);
        BinaryTree_FindProdromalNode_InOrderTraverse(BinaryTree->RightChild, TargetBinaryTreeNode, Pre);
    }

    return Pre;
}


//线索二叉树
///线索化中需要的遍历函数
void ThreadedBinaryTree_Threading_Visit(ThreadBinaryTreeNode* ThreadedBinaryTreeNode, ThreadBinaryTreeNode* Pre)
{
    // 左子树为空，建立前驱线索
    if(ThreadedBinaryTreeNode->LeftChild == NULL)
    {
        ThreadedBinaryTreeNode->LeftChild = Pre;
        ThreadedBinaryTreeNode->LeftChildTag = 1;
    }

    // 右子树为空，建立后继线索
    if(Pre != NULL && Pre->RightChild == NULL)
    {
        Pre->RightChild = ThreadedBinaryTreeNode;
        Pre->RightChildTag = 1;
    }

    Pre = ThreadedBinaryTreeNode;
}


///中序线索化二叉树
void ThreadedBinaryTree_InOrderThreading(ThreadBinaryTree* ThreadedBinaryTree,ThreadBinaryTreeNode* Pre)
{
    if(ThreadedBinaryTree != NULL)
    {
        ThreadedBinaryTree_InOrderThreading(ThreadedBinaryTree->LeftChild, Pre);
        ThreadedBinaryTree_Threading_Visit(ThreadedBinaryTree, Pre);
        ThreadedBinaryTree_InOrderThreading(ThreadedBinaryTree->RightChild, Pre);
    }
}

ThreadBinaryTree* ThreadedBinaryTree_InOrderThreadingCreateThreadBinaryTree(ThreadBinaryTree* ThreadBinaryTree)
{
    // 创建全局变量Pre，用于记录前驱结点
    ThreadBinaryTreeNode* Pre = NULL;

    //
    if(ThreadBinaryTree != NULL)
    {
        // 中序线索化二叉树
        ThreadedBinaryTree_InOrderThreading(ThreadBinaryTree, Pre);

        // 处理最后一个结点
        if(Pre->RightChild == NULL)
            Pre->RightChildTag = 1;
    }

    return ThreadBinaryTree;
}


///先序线索化二叉树
void ThreadedBinaryTree_PreOrderThreading(ThreadBinaryTree* ThreadedBinaryTree,ThreadBinaryTreeNode* Pre)
{
    if(ThreadedBinaryTree!= NULL)
    {
        ThreadedBinaryTree_Threading_Visit(ThreadedBinaryTree, Pre);

        if(ThreadedBinaryTree->LeftChildTag == 0) // 只有LeftChildTag为0时才进行递归，避免重复线索化
            ThreadedBinaryTree_PreOrderThreading(ThreadedBinaryTree->LeftChild, Pre);

        ThreadedBinaryTree_PreOrderThreading(ThreadedBinaryTree->RightChild, Pre);
    }
}

ThreadBinaryTree* ThreadedBinaryTree_PreOrderThreadingCreateThreadBinaryTree(ThreadBinaryTree* ThreadBinaryTree)
{
    // 创建全局变量Pre，用于记录前驱结点
    ThreadBinaryTreeNode* Pre = NULL;

    //
    if(ThreadBinaryTree != NULL)
    {
        // 线索化二叉树
        ThreadedBinaryTree_PreOrderThreading(ThreadBinaryTree, Pre);

        // 处理最后一个结点
        if(Pre->RightChild == NULL)
            Pre->RightChildTag = 1;
    }

    return ThreadBinaryTree;
}


///后序线索化二叉树
void ThreadedBinaryTree_PostOrderThreading(ThreadBinaryTree* ThreadedBinaryTree,ThreadBinaryTreeNode* Pre)
{
    if(ThreadedBinaryTree!= NULL)
    {
        ThreadedBinaryTree_PostOrderThreading(ThreadedBinaryTree->LeftChild, Pre);
        ThreadedBinaryTree_PostOrderThreading(ThreadedBinaryTree->RightChild, Pre);
        ThreadedBinaryTree_Threading_Visit(ThreadedBinaryTree, Pre);
    }
}

ThreadBinaryTree* ThreadedBinaryTree_PostOrderThreadingCreateThreadBinaryTree(ThreadBinaryTree* ThreadBinaryTree)
{
    // 创建全局变量Pre，用于记录前驱结点
    ThreadBinaryTreeNode* Pre = NULL;

    //
    if(ThreadBinaryTree != NULL)
    {
        // 线索化二叉树
        ThreadedBinaryTree_PostOrderThreading(ThreadBinaryTree, Pre);

        // 处理最后一个结点
        if(Pre->RightChild == NULL)
            Pre->RightChildTag = 1;
    }
    return ThreadBinaryTree;
}


/// 找到以某个结点为根的子树的中序遍历的第一个结点
ThreadBinaryTreeNode* ThreadedBinaryTree_FirstNode(ThreadBinaryTreeNode* ThreadBinaryTreeNode)
{
    // 当LeftChildTag为0时，说明该结点有左子树，需要找到左子树的中序遍历的第一个结点
    while (ThreadBinaryTreeNode->LeftChildTag == 0)
        ThreadBinaryTreeNode = ThreadBinaryTreeNode->LeftChild;

    // 返回找到的结点
    return ThreadBinaryTreeNode;
}

/// 在中序线索化的二叉树中找到某个结点的中序后继结点
ThreadBinaryTreeNode* ThreadedBinaryTree_FindNextNode(ThreadBinaryTreeNode* ThreadBinaryTreeNode)
{
    // 当RightChildTag为1时，说明该结点有右子树，直接返回右子树
    if (ThreadBinaryTreeNode->RightChildTag == 1)
        return ThreadBinaryTreeNode->RightChild;

    // 当RightChildTag为0时，说明该结点没有右子树，需要找到右子树的中序遍历的第一个结点
    else
        return ThreadedBinaryTree_FirstNode(ThreadBinaryTreeNode->RightChild);
}

///中序遍历的非递归算法（利用线索实现的非递归算法）
void ThreadedBinaryTree_InOrderTraverse(ThreadBinaryTree* ThreadBinaryTree)
{
    ThreadBinaryTreeNode* p = ThreadBinaryTree;
    ThreadBinaryTreeNode* Pre = NULL;
    for(p = ThreadedBinaryTree_FirstNode(ThreadBinaryTree); p != NULL; p = ThreadedBinaryTree_FindNextNode(p))
        ThreadedBinaryTree_Threading_Visit(p, Pre);
}
/// 找到以某个结点为根的子树的中序遍历的最后一个结点
ThreadBinaryTreeNode* ThreadedBinaryTree_LastNode(ThreadBinaryTreeNode* ThreadBinaryTreeNode)
{
    // 当RightChildTag为0时，说明该结点有右子树，需要找到右子树的中序遍历的最后一个结点
    while (ThreadBinaryTreeNode->RightChildTag == 0)
        ThreadBinaryTreeNode = ThreadBinaryTreeNode->RightChild;

    // 返回找到的结点
    return ThreadBinaryTreeNode;
}

/// 在中序线索化的二叉树中找到某个结点的中序前驱结点
ThreadBinaryTreeNode* ThreadedBinaryTree_FindPreNode(ThreadBinaryTreeNode* ThreadBinaryTreeNode)
{
    // 当LeftChildTag为1时，说明该结点有左孩子，其左孩子就是前驱结点
    if (ThreadBinaryTreeNode->LeftChildTag == 1)
        return ThreadBinaryTreeNode->LeftChild;
    else
    {
        // 当LeftChildTag为0时，说明该结点没有左孩子，需要找到左子树的中序遍历的最后一个结点
        return ThreadedBinaryTree_LastNode(ThreadBinaryTreeNode->LeftChild);
    }
}

///对中序线索化的二叉树进行逆向中序遍历
void ThreadedBinaryTree_InOrderReverseTraverse(ThreadBinaryTree* ThreadBinaryTree)
{
    ThreadBinaryTreeNode* p = ThreadBinaryTree;
    ThreadBinaryTreeNode* Pre = NULL;
    for(p = ThreadedBinaryTree_LastNode(ThreadBinaryTree); p!= NULL; p = ThreadedBinaryTree_FindPreNode(p))
        ThreadedBinaryTree_Threading_Visit(p, Pre);
}

/// 

#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_12_BINARYTREE_H
