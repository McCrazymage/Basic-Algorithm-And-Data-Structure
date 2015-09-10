#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
#include<iomanip>
using namespace std;

void insertion_sort(int *A, int n)
{
	int temp, j;
	for (int i = 1; i < n; i++)
	{
		temp = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > temp)  //care for with j >= 0 include ==
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = temp;  //easy to make mistakes
	}
	return;
}

void print_array(int *A, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}


int main(int argc, char **argv)
{
	int a[] = { 1, 7, 3, 6, 5, 8, 4, 2, 11, 100, 50 };
	int b[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int c[] = { 7, 6, 5, 4, 9, 8, 7, 1, 2 };

	insert_sort(a, sizeof(a) / sizeof(int));
	print_array(a, sizeof(a) / sizeof(int));
	insert_sort(b, sizeof(b) / sizeof(int));
	print_array(b, sizeof(b) / sizeof(int));
	insert_sort(c, sizeof(c) / sizeof(int));
	print_array(c, sizeof(c) / sizeof(int));
	return 0;
}
