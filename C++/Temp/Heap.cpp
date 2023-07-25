#include <stdio.h>

void Swap(int *heap, int len);        /* 交换根节点和数组末尾元素的值 */
void BuildMaxHeap(int *heap, int len);/* 构建大顶堆 */
void BuildMInHeap(int *heap, int len);/* 构建小顶堆 */

int main()
{
    int a[6] = {7, 3, 8, 5, 1, 2};
    int len = 6;    /* 数组长度 */
    int i;

    for (i = len; i > 0; i--)
    {
        BuildMaxHeap(a, i);
        Swap(a, i);
    }
    for (i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

/* Function: 构建大顶堆 */
void BuildMaxHeap(int *heap, int len)
{
    int i;
    int temp;

    for (i = len/2-1; i >= 0; i--)
    {
        if ((2*i+1) < len && heap[i] < heap[2*i+1])    /* 根节点大于左子树 */
        {
            temp = heap[i];
            heap[i] = heap[2*i+1];
            heap[2*i+1] = temp;
            /* 检查交换后的左子树是否满足大顶堆性质 如果不满足 则重新调整子树结构 */
            if ((2*(2*i+1)+1 < len && heap[2*i+1] < heap[2*(2*i+1)+1]) || (2*(2*i+1)+2 < len && heap[2*i+1] < heap[2*(2*i+1)+2]))
            {
                BuildMaxHeap(heap, len);
            }
        }
        if ((2*i+2) < len && heap[i] < heap[2*i+2])    /* 根节点大于右子树 */
        {
            temp = heap[i];
            heap[i] = heap[2*i+2];
            heap[2*i+2] = temp;
            /* 检查交换后的右子树是否满足大顶堆性质 如果不满足 则重新调整子树结构 */
            if ((2*(2*i+2)+1 < len && heap[2*i+2] < heap[2*(2*i+2)+1]) || (2*(2*i+2)+2 < len && heap[2*i+2] < heap[2*(2*i+2)+2]))
            {
                BuildMaxHeap(heap, len);
            }
        }
    }
}

/* Function: 构建小顶堆 */
void BuildMinHeap(int *heap, int len)
{
    int i;
    int temp;

    for (i = len/2-1; i >= 0; i--)
    {
        if ((2*i+1) < len && heap[i] < heap[2*i+1])    /* 根节点大于左子树 */
        {
            temp = heap[i];
            heap[i] = heap[2*i+1];
            heap[2*i+1] = temp;
            /* 检查交换后的左子树是否满足大顶堆性质 如果不满足 则重新调整子树结构 */
            if ((2*(2*i+1)+1 < len && heap[2*i+1] < heap[2*(2*i+1)+1]) || (2*(2*i+1)+2 < len && heap[2*i+1] < heap[2*(2*i+1)+2]))
            {
                BuildMaxHeap(heap, len);
            }
        }
        if ((2*i+2) < len && heap[i] < heap[2*i+2])    /* 根节点大于右子树 */
        {
            temp = heap[i];
            heap[i] = heap[2*i+2];
            heap[2*i+2] = temp;
            /* 检查交换后的右子树是否满足大顶堆性质 如果不满足 则重新调整子树结构 */
            if ((2*(2*i+2)+1 < len && heap[2*i+2] < heap[2*(2*i+2)+1]) || (2*(2*i+2)+2 < len && heap[2*i+2] < heap[2*(2*i+2)+2]))
            {
                BuildMaxHeap(heap, len);
            }
        }
    }
}

/* Function: 交换交换根节点和数组末尾元素的值*/
void Swap(int *heap, int len)
{
    int temp;

    temp = heap[0];
    heap[0] = heap[len-1];
    heap[len-1] = temp;
}