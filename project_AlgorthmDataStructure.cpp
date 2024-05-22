#include <iostream>
#include <chrono>
using Compaison = bool (*)(int, int);

bool Ascending(int x, int y)
{
	return x > y; 
}

bool Descending(int x, int y)
{
	return x < y; 
}

void Sort(int numbers[], int count, Compaison f)
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
int main()
{
	const int SIZE_ARRAY{ 10 };
	int scores[SIZE_ARRAY]{ 20,10,30,50,40,60,70,90,80,100 };
	
	Sort(scores, SIZE_ARRAY, Ascending);

	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		std::cout << scores[i] << std::endl;
	}
}

