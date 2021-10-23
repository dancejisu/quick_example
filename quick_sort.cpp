#include <iostream>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };


void print_data()
{
	for (int i = 0; i < SIZE; i++)
		cout << " " << L[i] << " ";
	cout << endl;
}

int Partition(int from, int to)
{
	int Pivot_Value = from;
	int Store_Index = Pivot_Value;

	for (int i = from + 1; i <= to; i++)
	{
		if (L[Pivot_Value] > L[i])
		{
			Store_Index++;
			swap(L[i], L[Store_Index]);
		}
	}
	swap(L[Pivot_Value], L[Store_Index]);
	Pivot_Value = Store_Index;
	return Pivot_Value;

}
void quick_sort(int from, int to)
{
	if (from < to)
	{
		int Pivot = Partition(from, to);
		quick_sort(from, Pivot - 1);
		quick_sort(Pivot + 1, to);
	}

}

void main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	quick_sort(0, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();

}
