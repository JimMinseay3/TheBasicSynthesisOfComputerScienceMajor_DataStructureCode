cmake_minimum_required(VERSION 3.26)
project(TheBasicSynthesisOfComputerScienceMajor_DataStructureCode C)

set(CMAKE_C_STANDARD 90)

add_executable(TheBasicSynthesisOfComputerScienceMajor_DataStructureCode main.c
        "00 Definition.h"
        "00 Function.h"
        "01 SequentialList.h"
        "02 SingleLinkedList.h"
        "03 DoubleLinkedList.h"
        "04 SequentialStack.h"
        "05 LinkedStack.h"
        "06 SequentialQueue.h"
        "07 LinkedQueue.h"
        "08 SequentialString.h"
        "09 HeapString.h"
        "10 LinkedString.h"
        "11 StringMatchingAlgorithm.h"
        "12 BinaryTree.h"
        "13 UnionFindSet.h"
        "14 AdjacentMatrixGrapg.h"
        "15 AdjacentListGraph.h"
        "16 BreadthFirstSearch.h"
        "17 DepthFirstSearch.h"
        "18 MinimumSpanningTree.h"
        "19 ShortestPath.h"
        "20 Search.h"
        "21 Sort.h"
)
