#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <assert.h>
#include <cmath>
#include<iomanip>
using namespace std;

void print_array(int *A, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

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

void merge(int *A, int p, int q, int r)
{
	int n1 = q - p + 1, n2 = r - q ,n3 = r - p + 1;
	int *L = new int[n1], *R = new int[n2];
	for (int i = p, j = 0; i <= q;i++, j++)
	{
		L[j] = A[i];
	}
	for (int i = q+1, j = 0; i <= r; i++, j++)
	{
		R[j] = A[i];
	}

	int i = 0, j = 0, k = p;
	while (k <= r)
	{
		if (i == n1)  //careful
		{
			while (j < n2)  
			{
				A[k++] = R[j++];
			}
			assert(k == r + 1);  //careful
			break;
		}
		if (j == n2)  //careful
		{
			while (i < n1)  
			{
				A[k++] = L[i++];
			}
			assert(k == r + 1);  //careful
			break;
		}
		if (L[i]<R[j])
		{
			A[k++] = L[i++];
		}
		else
		{
			A[k++] = R[j++];
		}
	}
	//print_array(A + p, r - p + 1);
}

void merge_sort(int *A, int p, int r)
{
	int q = (p + r) / 2;
	if (q > p)
	{
		merge_sort(A, p, q);
	}
	if (r > p + 1)
	{
		merge_sort(A, q + 1, r);
	}

	merge(A, p, q, r);

}




int main(int argc, char **argv)
{
	int a[] = { 1, 7, 3, 6, 5, 8, 4, 2, 11, 100, 50 };
	int b[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int c[] = { 7, 6, 5, 4, 9, 8, 7, 1, 2 };

	merge_sort(a, 0, sizeof(a) / sizeof(int) - 1);
	//insertion_sort(a, sizeof(a) / sizeof(int));
	print_array(a, sizeof(a) / sizeof(int));
	merge_sort(b, 0, sizeof(b) / sizeof(int) - 1);
	//insertion_sort(b, sizeof(b) / sizeof(int));
	print_array(b, sizeof(b) / sizeof(int));
	merge_sort(c, 0, sizeof(c) / sizeof(int) - 1);
	//insertion_sort(c, sizeof(c) / sizeof(int));
	print_array(c, sizeof(c) / sizeof(int));
	return 0;
}
