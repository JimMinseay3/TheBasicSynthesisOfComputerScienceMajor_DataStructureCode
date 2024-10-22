// Filename:Definition.h
// FileType:Definition
// Beginning Time:9/15/2023
// Author:JimMinseay @CopyRight


#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_00_DEFINITION_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_00_DEFINITION_H


///include
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


///define 宏定义
#define ElementType int //将所有抽象元素类型替换为int
#define SequentialListMaxLength 100 //顺序表的最大长度
#define StaticLinkedListMaxLength 100 //静态链表的最大长度
#define SequentialStackMaxLength 100 //顺序栈的最大长度
#define SequentialQueueMaxLength 50 //顺序队列的最大长度
#define SequentialStringMaxLength 255 //串的最大长度
#define ChunkSize 255 //块链串的最大长度
#define BinaryTreeMaxSize 100 //二叉树的最大结点数
#define TreeMaxSize 100 //树的最大结点数
#define ParentTreeMaxSize 100 //双亲表示法中的最大结点数
#define ChildTreeMaxSize 100 //孩子表示法中的最大结点数
#define UnionFindMaxSize 100//并查集的最大元素个数
#define VertexMaxSize 100 //图的顶点数目最大个数
#define RecordCount 100 //在排序中待排序表中的记录数量

/* 表的存储结构定义 */
///顺序表
typedef struct SequentialList
{
    ElementType data[SequentialListMaxLength];//用于存储顺序表中元素的数组
    int SequentialListLength; //顺序表当前长度
}SequentialList;


///单链表（结点）
typedef struct SingleLinkedListNode
{
    ElementType data;//单链表结点的数据域
    struct SingleLinkedListNode* next;//单链表结点的指针域
}SingleLinkedListNode, SingleLinkedList;


///双链表（结点）
typedef struct DoubleLinkedListNode
{
    ElementType data;//双链表结点的数据域
    struct DoubleLinkedListNode *prior, *next;//双链表结点的前指针域和后指针域
}DoubleLinkedListNode, DoubleLinkedList;


///静态链表（结点）
typedef struct StaticLinkedListNode
{
    ElementType data;//静态链表的数据域
    int next;//指向下一个静态链表结点的标号
}StaticLinkedListNode[StaticLinkedListMaxLength];




/* 栈的存储结构定义 */
///栈的顺序存储结构
typedef struct SequentialStack
{
    ElementType data[SequentialStackMaxLength];//用于存储顺序栈元素的数组
    int top;//栈顶指针的标号
}SequentialStack;


///栈的链式存储结构（结点）
typedef struct LinkedStackNode
{
    ElementType data;
    struct LinkedStackNode* next;
}LinkedStackNode, LinkedStack;


/* 队列的存储结构定义 */
///顺序队列
typedef struct SequentialQueue
{
    ElementType data[SequentialQueueMaxLength]; //存放队列元素
    int front,rear; //队头指针和队尾指针
}SequentialQueue;


///队列的链式存储结构(结点)
typedef struct LinkedQueueNode
{
    ElementType Data;
    struct LinkedQueueNode* Next;
}LinkedQueueNode;


///链式队列
typedef struct LinkedQueue
{
    struct LinkedQueueNode* Front;
    struct LinkedQueueNode* Rear;
}LinkedQueue;





/* 串的存储结构定义 */
///串的定长顺序存储表示
typedef struct SequentialString
{
    char Character[SequentialStringMaxLength]; //每个分量存储串的一个字符
    int Length; //串的实际长度
}SequentialString;


///串的堆分配存储表示
typedef struct HeapString
{
    char* Character; //按照串长分配存储区，指针character指向串的基地址
    int Length; //串的实际长度
}HeapString;


///串的块链存储表示
typedef struct Chunk
{
    char Character[ChunkSize];
    struct Chunk* next;
}Chunk;

typedef struct LinkedString
{
    Chunk* Head;
    Chunk* Tail;
    int CurrentLength;
}LinkedString;





/* 树的存储结构定义 */
///二叉树的顺序存储结构
typedef struct SequentialBinaryTree
{
    ElementType SequentialBinaryTree[BinaryTreeMaxSize];
}SequentialBinaryTree;


///二叉树的链式存储结构
typedef struct BinaryTreeNode
{
    ElementType Data;
    struct BinaryTreeNode* LeftChild;
    struct BinaryTreeNode* RightChild;
}BinaryTreeNode, BinaryTree;


///线索二叉树的存储结构
typedef struct ThreadBinaryTreeNode
{
    ElementType data;
    struct ThreadBinaryTreeNode* LeftChild;
    struct ThreadBinaryTreeNode* RightChild;
    int LeftChildTag, RightChildTag;
}ThreadBinaryTreeNode, ThreadBinaryTree;


///树的双亲表示法存储结构
//双亲表示法的结点结构
typedef struct ParentTreeNode
{
    ElementType Data; //
    int Parent; //
}ParentTreeNode;

//双亲表示法的树结构
typedef struct ParentTree
{
    ParentTreeNode ParentTreeNode[ParentTreeMaxSize];
    int NodeCount; //结点数量
}ParentTree;


///孩子表示法
//孩子表示法的结点结构
typedef struct
{
    int ChildTreeNodeNumber; //记录该结点的在孩子表中的数组下标
    struct ChildNode* Next; //记录该结点的下一个孩子结点
}ChildTreeNode;

//孩子表示法的数组表结构
typedef struct
{
    ElementType Data;
    struct ChildNode* FirstChild;
}ChildTreeList;

typedef struct
{
    ChildTreeList ChildTreeList[ChildTreeMaxSize];
    int NodeCount; //记录结点数量
    int Root; //记录根结点的位置
}ChildTree;

///孩子兄弟表示法
typedef struct ChildSiblingNode
{
    ElementType Data; //记录该结点的数据
    struct ChildSiblingNod* FirstChild; //记录该结点的第一个孩子结点
    struct ChildSiblingNod* NextSibling; //记录该结点的下一个兄弟结点
}ChildSiblingTreeNode, ChildSiblingTree;





/* 并查集的存储结构定义 */
///并查集
typedef struct UnionFindSet
{
    ElementType UnionFindSet[UnionFindMaxSize];
}UnionFindSet;





/* 图的存储结构定义 */
typedef char VertexType;
typedef int EdgeType;

///图的邻接矩阵存储结构
typedef struct AdjacentMatrixGraph //由邻接矩阵存储结构构成的图
{
    VertexType Vertex[VertexMaxSize];
    EdgeType Edge[VertexMaxSize][VertexMaxSize];
    int VertexNumber;
    int ArcNumber;
}AdjacentMatrixGraph;


///图的邻接表存储结构
typedef struct AdjacentListArcNode //邻接表边表结点
{
    int AdjacentVertex; //该弧所指向顶点的位置
    struct AdjacentListArcNod* next; //指向下一条弧的指针
    //InformationType Information;
}AdjacentListArcNode;

typedef struct AdjacentListVertexNode //邻接表顶点表结点
{
    VertexType data; //顶点信息
    AdjacentListArcNode* first; //指向第一条依附该顶点的 弧的指针
}
AdjacentListVertexNode, //该注释表明这个别名是邻接表中单一结点的存储结构详情
AdjacentList[VertexMaxSize]; //该注释表明这个别名代表邻接表中的顶点结点是顺序存储在一个一维数组中的

typedef struct AdjacentListGraph //由邻接表存储结构所构成的图
{
    AdjacentList Vertices; //邻接表
    int VertexNumber; //邻接表的顶点数
    int ArcNumber; //邻接表的弧数
}AdjacentListGraph;


///图的十字链表存储结构
typedef struct OrthogonalLinkedListArcNode //十字链表弧结点
{
    int TailVertex; // 弧尾顶点编号
    int HeadVertex; // 弧头顶点编号
    struct ArcNode *HeadLink; // 弧头相同链表的下一个结点
    struct ArcNode *TailLink; // 弧尾相同链表的下一个结点
    // 其他信息域
}OrthogonalLinkedListArcNode;

typedef struct OrthogonalLinkedList //十字链表
{
    VertexType Data; // 顶点数据
    struct ArcNode *FirstIn; // 入度链表头指针
    struct ArcNode *FirstOut; // 出度链表头指针
}OrthogonalLinkedList;


///图的邻接多重表存储结构
typedef struct AdjacencyMultiListEdgeNode
{
    int FirstVertex; // 边的第一个顶点
    int SecondVertex; // 边的第二个顶点
    int Weight; // 边的权值
    struct AdjacencyMultiListEdgeNode *Link; // 下一个边结点
}AdjacencyMultiListEdgeNode;


typedef struct AdjacencyMultiListVertexNode //邻接多重表顶点结点
{
    VertexType Data; // 顶点数据
    struct AdjacencyMultiListEdgeNode *FirstEdge; // 边表头指针
}AdjacencyMultiListVertexNode;








#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_00_DEFINITION_H

