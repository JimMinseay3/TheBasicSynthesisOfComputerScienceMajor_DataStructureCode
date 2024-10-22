// Filename:Sort.h
// FileType:Algorithm
// Beginning Time:
// Author:JimMinseay @CopyRight

#ifndef THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_21_SORT_H
#define THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_21_SORT_H

///
#include "00 Definition.h"
#include "00 Function.h"

///插入排序
//直接插入排序
void InsertSort(ElementType A[], int n)
{
    int i,j; //设置哨兵

    /* 哨兵从2开始，因为1号元素已经有序,所以从2开始*/
    for (i = 2; i <= n; i++)
    {
       if (A[i] < A[i-1])
       {
           A[0] = A[i]; //将最小的元素存放在哨兵中
           for (j = i-1; A[0] < A[j]; --j)
           {
               A[j+1] = A[j]; //将大于哨兵的元素向后移动
           }
           A[j+1] = A[0]; //将哨兵放到正确的位置
       }
    }
}

//折半插入排序
void BinaryInsertSort(ElementType A[], int n)
{
    int i,j,low,high,mid;

    for (i = 2; i <= n; i++)
    {
        A[0] = A[i];
        low = 1;
        high = i-1;
        while (low <= high)
        {
            mid = (low + high) / 2;

            if (A[mid] > A[0])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        for (j = i-1; j >= high+1; --j)
        {
            A[j+1] = A[j];
        }

        A[high+1] = A[0];
    }
}


//希尔排序
void ShellSort(ElementType A[], int n)
{
    //A[0]只是暂存器，并不是哨兵
    int i,j,Increment;

    for (Increment = n / 2; Increment > 0; Increment /= 2)
    {
        for (i = Increment + 1; i <= n; ++i)
        {
            if (A[i] < A[i-Increment])
            {
                A[0] = A[i];
                for (j = i - Increment; j > 0 && A[j] > A[0]; j -= Increment)
                {
                    A[j + Increment] = A[j];
                }
                A[j + Increment] = A[0];
            }
        }
    }
}

///交换排序
//冒泡排序
void BubbleSort(ElementType A[], int n)
{
    int i,j;
    for (i = 0; i < n-1; i++)
    {
        bool flag = false;
        for(j = n-1; j > i; j--)
        {
            if (A[j] < A[j-1])
            {
                Swap(A[j], A[j-1]);
                flag = true;
            }
            else
            {
                printf("The table is already in order.");
            }
        }
    }
}

//双向冒泡排序
void BidirectionalBubbleSort(ElementType A[], int n)
{
    int low=0, high=n-1;
    bool flag = true;

    while (low < high && flag) {
        flag = false;

        int i;

        for (i = low; i < high; i++) {
            if (A[i] > A[i + 1]) {
                Swap(A[i], A[i + 1]);
                flag = true;
            }
        }
        high--;

        for (i = high; i > low; i--) {
            if (A[i] < A[i - 1]) {
                Swap(A[i], A[i - 1]);
                flag = true;
            }
        }
        low++;

    }
}



//快速排序
void QuickSort(ElementType A[], int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = Partition(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }
}


///选择排序
//简单选择排序
void SelectSort(ElementType A[], int n)
{
    int i,j,min;

    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }

        if (min!= i)
        {
            Swap(A[i], A[min]);
        }
    }
}

//堆排序
//调整堆
void AdjustDown(ElementType A[], int k, int len)
{
    A[0] = A[k];
    for (int i = 2 * k; i <= len; i *= 2)
    {
        if (i < len && A[i] < A[i+1])
        {
            i++;
        }

        if (A[0] >= A[i])
        {
            break;
        }
        else
        {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

//建立大根堆
void BuildMaxHeap(ElementType A[], int len)
{
    int i;
    for (i = len / 2; i > 0; i--)
    {
        AdjustDown(A, i, len);
    }
}

///归并排序
ElementType B[RecordCount];

void Merge(ElementType A[], int low, int mid, int high)
{
    int i,j,k;

    for (k = low; k <= high; k++)
    {
        B[k] = A[k];
    }

    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j])
        {
            A[k] = B[i++];
        }
        else
        {
            A[k] = B[j++];
        }
    }

    while (i <= mid)
    {
        A[k++] = B[i++];
    }

    while (j <= high)
    {
        A[k++] = B[j++];
    }
}

void MergeSort(ElementType A[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }
}

#endif //THEBASICSYNTHESISOFCOMPUTERSCIENCEMAJOR_DATASTRUCTURECODE_21_SORT_H
