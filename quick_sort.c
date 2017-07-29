#include <stdio.h>
void swap(int *x,int *y);
void quick_sort(int a[], int start, int end);


int main(int argc, char const *argv[])
{
	
	int sum = 0;
	int a[15] = {43, 23, 56, 78, 12, 78, 29, 90, 54, 76, 21, 92, 56, 37, 6};
	quick_sort(a, 0, 14);
	for (int i = 0; i < 15; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}

void swap(int *x,int *y){
	int t = *y;
	*y = *x;
	*x = t;
}
void quick_sort(int a[], int start, int end){
	if (start >= end)
		return;
	int mid = a[end];
	int left = start, right = end - 1;
	while(left < right){
		while(a[left] < mid && left < right)
			left++;
		while(a[right] >= mid && left < right)
			right--;
		swap(&a[left], &a[right]);
	}
	if (a[left] >= a[end])
		swap(&a[left], &a[end]);
	else 
		left++;

	if (left)
		quick_sort(a, start, left - 1);
	quick_sort(a, left + 1, end);
}