﻿#include <iostream>

using Compaison = bool (*)(int, int);

bool Ascending(int x, int y)
{
	return x > y; 
}

bool Descending(int x, int y)
{
	return x < y; 
}

//Sequential Sort
void SequentialSort(int numbers[], int count, Compaison f)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (f(numbers[i], numbers[j]))
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

void SelectionSort(int numbers[], int count, Compaison f)
{
	int min{};
	for (int i = 0; i < count; i++)
	{
		int minIndex = i;
		for (int j = i; j < count; j++)
		{
			if (numbers[minIndex] > numbers[j])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			int temp = numbers[minIndex];
			numbers[minIndex] = numbers[i];
			numbers[i] = temp;
		}
	}

}
void BubbleSort(int numbers[], int count, Compaison f)
{
	for (int phase = 0; phase < count - 1; phase++)
	{
		for (int k = 0; k > count - 1 - phase; k++)
		{
			if (numbers[k] > numbers[k + 1])
			{
				int temp = numbers[k];
				numbers[k] = numbers[k + 1];
				numbers[k + 1] = temp;
			}
		}
	}
}

void InsertionSort(int numbers[], int count)
{
	for (int i = 1; i < count; i++)
	{
		int j = i;
		int target = numbers[i];
		while (--j >= 0 && target < numbers[j])
		{
			numbers[j + 1] = numbers[j];
			numbers[j] = target;
		}
	}
}
//-----------------------------------------------------------------------

//MergeSort - 폰 노이만

void Merge(int numbers[], int start, int half, int end,int temp[])
{
	int i = start; //왼쪽 첫번째 원소
	int j = half + 1; // 오른쪽 첫번째 원소
	int tempIndex{};

	while (i <= half && j <= end)
	{
		if (numbers[i] < numbers[j])
		{
			temp[tempIndex++] = numbers[i++];
		}
		else
		{
			temp[tempIndex++] = numbers[j++];
		}
	}
	//왼쪽 남은 것
	while (i <= half)
	{
		temp[tempIndex++] = numbers[i++];
	}
	//오른쪽 남은 것
	while (j <= end)
	{
		temp[tempIndex++] = numbers[j++];
	}
	//복사
	tempIndex = 0;
	for (int i = start; i <= end; i++)
	{
		numbers[i] = temp[tempIndex++];
	}
}

void MergeSort(int numbers[], int start, int end, int temp[])
{
	//base case
	if (start >= end)
	{
		return;
	}

	int half = (start + end) / 2;
	//recursive case
	MergeSort(numbers, start, half, temp);
	MergeSort(numbers, half + 1, end, temp);

	// Merge
	Merge(numbers, start, half, end, temp);
}

// Quick Sort - Tony Hoare
// MergeSort의 단점(temp 메모리)을 보완하는 정도
void QuickSort(int numbers[], int start, int end)
{
	int i = start;
	int j = end;
	int pivot = numbers[(start + end) / 2];
	do
	{
		while (numbers[i] < pivot)
		{
			i++;
		}
		while (numbers[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			int temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
			i++;
			j--;
		}
	}while (i <= j);

	if (start < j)
	{
		QuickSort(numbers, start, j);
		
	}
	if (i < end)
	{
		QuickSort(numbers, i, end);
	}
}


void PrintArray(int numbers[], int count)
{

	for (int i = 0; i < count; i++)
	{
		std::cout << numbers[i] << " "; 
	}
	std::cout << std::endl;
}
int main()
{
	const int SIZE_ARRAY{ 10 };
	int scores[SIZE_ARRAY]{ 100,90,80,70,60,50,40,30,20,10 };
	int temp[SIZE_ARRAY]{};

	//SequentialSort(scores, SIZE_ARRAY, Ascending);
	//MergeSort(scores, 0, SIZE_ARRAY - 1, temp);

	QuickSort(scores, 0, 9);

	PrintArray(scores, SIZE_ARRAY);

}