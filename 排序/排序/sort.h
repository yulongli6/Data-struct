#pragma once


#include<stdio.h>
#include<stdlib.h>


//插入排序
//稳定
//最好/平均/最差  O(n)完全有序/o(n^2)/o(n^2)
//空间            o(1)

void InsertSort(int array[], int size)
{
	int key;
	int i, j;
	for (i = 1; i < size; i++)
	{
		key = array[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (key >= array[j])
			{
				break;
			}
			else
			{
				array[j + 1] = array[j];
			}
		}
		array[j + 1] = key;
	}
}


#if 0
void __InsertSort(int array[], int size, int gap)
{
	int g;
	for (g = 0; g < gap; g++)
	{
		int key;
		int i, j;
		for (i = gap + g; i < size; i += gap)
		{
			key = array[i];
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (key >= array[j])
				{
					break;
				}
				else
				{
					array[j + gap] = array[j];
				}
			}

			array[j + gap] = key;
		}
	}
}
#else
void _InsertSort(int array[], int size, int gap)
{
	int key;
	int i, j;
	for (i = gap; i < size; i++)
	{
		key = array[i];
		for (j = i - gap; j >= 0; j -= gap)
		{
			if (key >= array[j])
			{
				break;
			}
			else
			{
				array[j + gap] = array[j];
			}
		}

		array[j + gap] = key;
	}
}
#endif

//1.不稳定
//2.最好/平均/最差   o(n)/o(n^1.2~1.3)/O(n^2)
//3.空间复杂度       O(1)
void ShellSort(int array[], int size)
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;
		_InsertSort(array, size, gap);
		if (gap == 1)
		{
			break;
		}

	}
}


void Swap(int* a, int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}


//不稳定
//时间复杂度   O(n^2)
//空间复杂度   O（1）
void SelectSort(int array[], int size)
{
	int i, j;
	for (i = size; i > 1; i--)
	{
		int max = 0;
		for (j = 1; j < i; j++)
		{
			if (array[j] > array[max])
			{
				max = j;
			}
		}

		Swap(array + max, array + i - 1);
	}
}


void SelectSortOP(int array[], int size)
{
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		int max = left;
		int min = left;
		int i;
		for (i = left + 1; i <= right; i++)
		{
			if (array[i] > array[max])
			{
				max = i;
			}
			if (array[i] < array[min])
			{
				min = i;
			}

		}
		Swap(array + min, array + left);
		if (max == left)
		{
			max = min;
		}
		Swap(array + right, array + max);
		left++;
		right--;
	}
}


void AdjustDown(int array[], int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (left >= size)
	{
		return;
	}
	int max = left;
	if (right < size && array[right] > array[left])
	{
		max = right;
	}
	if (array[max] <= array[root])
	{
		return;
	}
	Swap(array + root, array + max);
	AdjustDown(array, size, max);

}


void CreateHeap(int array[], int size)
{
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}
}


//不稳定
//时间复杂度  O(N*logN)
//空间复杂度  O(1)
void HeapSort(int array[], int size)
{
	int i;
	CreateHeap(array, size);
	for (i = 0; i < size; i++)
	{
		Swap(&array[0], &array[size - 1 - i]);
		AdjustDown(array, size - i - 1, 0);
	}
}



// 冒泡排序
// 稳定
// 最好/平均/最差		O(n) 已经有序/O(n^2)/O(n^2)
// 空间复杂度			O(1)
void BubbleSort(int array[], int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		int isSorted = 1;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				Swap(array + j, array + j + 1);
				isSorted = 0;
			}
		}

		if (isSorted == 1)
		{
			break;
		}
	}
}



int Partition_01(int array[], int left, int right)
{
	int begin = left;
	int end = right;

	while (begin < end) {
		while (begin < end && array[begin] <= array[right]) {
			begin++;
		}

		while (begin < end && array[end] >= array[right]) {
			end--;
		}

		Swap(array + begin, array + end);
	}

	Swap(array + begin, array + right);

	return begin;
}

int Partition_02(int array[], int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = array[right];

	while (begin < end) {
		while (begin < end && array[begin] <= pivot) {
			begin++;
		}

		array[end] = array[begin];

		while (begin < end && array[end] >= pivot) {
			end--;
		}

		array[begin] = array[end];
	}

	array[begin] = pivot;

	return begin;
}


int Partition_03(int array[], int left, int right)
{
	int cur, div;

	for (cur = left, div = left; cur < right; cur++) {
		if (array[cur] < array[right]) {
			Swap(array + cur, array + div);
			div++;
		}
	}

	Swap(array + div, array + right);

	return div;
}


void __QuickSort(int array[], int left, int right)
{
	if (left == right) {

		return;
	}

	if (left > right) {
		return;
	}

	int div = Partition_01(array, left, right);

	__QuickSort(array, left, div - 1);
	__QuickSort(array, div + 1, right);
}


void QuickSort(int array[], int size)
{
	__QuickSort(array, 0, size - 1);
}



void PrintArray(int array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}


void Merge(int array[], int left, int mid, int right, int extra[])
{
	int left_i = left;
	int right_i = mid;
	int extra_i = left;

	while (left_i < mid && right_i < right) {
		if (array[left_i] <= array[right_i]) {
			extra[extra_i++] = array[left_i++];
		}
		else {
			extra[extra_i++] = array[right_i++];
		}
	}

	while (left_i < mid) {
		extra[extra_i++] = array[left_i++];
	}

	while (right_i < right) {
		extra[extra_i++] = array[right_i++];
	}
	int i;
	for (i = left; i < right; i++) {
		array[i] = extra[i];
	}
}


void __MergeSort(int array[], int left, int right, int extra[])
{

	if (left == right - 1) {

		return;
	}

	if (left >= right) {

		return;
	}

	int mid = left + (right - left) / 2;
	__MergeSort(array, left, mid, extra);
	__MergeSort(array, mid, right, extra);
	Merge(array, left, mid, right, extra);
}


void MergeSort(int array[], int size)
{
	int *extra = (int *)malloc(sizeof(int)* size);
	__MergeSort(array, 0, size, extra);
	free(extra);
}


void MergeSortLoop(int array[], int size)
{
	int i, j;
	int *extra = (int *)malloc(sizeof(int)* size);
	for (i = 1; i < size; i *= 2) {
		for (j = 0; j < size; j = j + 2 * i) {
			int left = j;
			int mid = j + i;
			int right = mid + i;

			if (mid >= size) {
				continue;
			}

			if (right > size) {
				right = size;
			}

			Merge(array, left, mid, right, extra);
		}
	}
	free(extra);
}


void CocktailSort(int array[], int size)
{
	int left = 0;                            // 初始化边界
	int right = size - 1;
	while (left < right)
	{
		for (int i = left; i < right; i++)   // 前半轮,将最大元素放到后面
		{
			if (array[i] > array[i + 1])
			{
				Swap(array + i, array + i + 1);
			}
		}
		right--;
		for (int i = right; i > left; i--)   // 后半轮,将最小元素放到前面
		{
			if (array[i - 1] > array[i])
			{
				Swap(array + i - 1, array + i);
			}
			
		}
		left++;

	}
}


void test()
{
	int array[] = { 3, 5, 1, 4, 7, 2, 6, 0, 9, 8, 8 };
	int size = sizeof(array) / sizeof(int);
	CocktailSort(array, size);
	PrintArray(array, size);
}
