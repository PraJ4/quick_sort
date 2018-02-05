#include <stdio.h>

int swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp; 
}

int display (int arr[], int n)
{
	printf ("Array elements: ");
	for (int i = 0; i < n; i++)
		printf ("%d ", arr[i]);
	printf ("\n");
}


int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high ; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap (&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;
}


int quick_sort (int arr[], int low, int high)
{
	int i, j;
	int pi;
	/*Find out pivot element position after sorting*/
	/*choosing default pivot at last element*/
	/*pi is pivot element new index*/
	if (low < high)
	{
		pi = partition (arr, low, high);
		quick_sort(arr, low, pi - 1);	
		quick_sort(arr, pi + 1, high);	
 	}
	return 0;
}


int main ()
{
	int arr[] = {21, 34, 54, 56, 23, 79, 12, 43, 67, 75,41};
	int n = sizeof (arr)/ sizeof (arr[0]);
	
	display (arr, n);
	quick_sort (arr, 0, n - 1);
	printf("Sorted array: \n");
	display (arr, n);
	return 0;	
}
