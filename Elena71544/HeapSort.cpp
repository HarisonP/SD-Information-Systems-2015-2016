#include <iostream>
using namespace std;

//heapSort

void print(int a[], int size){
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void heapify(int a[], int size, int position){
	int j = 2 * position + 1;
	while (j < size){
		if (j < size - 1 && a[j] < a[j + 1])
			j++;
		if (a[position] < a[j]){
			swap(a[position], a[j]);
			position = j;
			j = 2 * position + 1;
		}
		else break;
	}
}
void heapSort(int a[], unsigned size){
	for (int j = size/2-1; j >= 0; j--){
		heapify(a, size,j);
	}
	while (size > 1){
		swap(a[0], a[--size]);
		heapify(a, size,0);
	}
}

int main(){
  cout << "HeapSort: ";
	int arr[] = { 3, 32, 4, 1, 325, 0, -1, 3244 };
	print(arr, 8);
	heapSort(arr, 8);
	cout << "Sorted: ";
	print(arr, 8);


	return 0;
}
