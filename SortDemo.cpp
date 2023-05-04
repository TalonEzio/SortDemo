#include <iostream>
using namespace std;
#define maxNumber 1000
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
typedef struct CustomArray
{
	int n;
	int* a;
	void Input(int n)
	{
		this->n = n;
		a = new int[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = rand() % maxNumber + 1;
		}
	}
	void output()
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << "\t";
			if ((i + 1) % 10 == 0)cout << endl;
		}
		cout << endl;
	}
	void InterchangeSort()
	{
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (a[i] > a[j])swap(a[i], a[j]);
			}
		}
	}
	void SelectionSort()
	{
		for (int i = 0; i < n - 1; ++i)
		{
			int minIndex = i;
			for (int j = i + 1; j < n; ++j)
			{
				if (a[minIndex] > a[j]) minIndex = j;
			}
			swap(a[i], a[minIndex]);
		}
	}
	void BubbleSort()
	{
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = n - 1; j > i; --j)
			{
				if (a[j] < a[j - 1])swap(a[j], a[j - 1]);
			}
		}
	}
	void QuickSort(int left, int right)
	{
		if (left >= right) return;
		int pivot = a[(left + right) / 2];
		int i = left, j = right;
		do
		{
			while (a[i] < pivot) i++;
			while (a[j] > pivot) j--;
			if (i <= j)
			{
				swap(a[i], a[j]);
				i++;j--;
			}
		} while (i < j);
		QuickSort(left, j);
		QuickSort(i, right);
	}
}Array;

int main()
{
	Array arr;
	arr.Input(120);

	//arr.BubbleSort();
	//arr.InterchangeSort();
	//arr.SelectionSort();

	arr.QuickSort(0, arr.n - 1);
	cout << "Sort completed!" << endl;
	arr.output();

	system("pause");
}
