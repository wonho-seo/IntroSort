#include "InsertionSort.h"

void InsertionSort::sort(vector<int>& arr, int left, int right) {
	insertionSort(arr, 0, arr.size() - 1);
}

void InsertionSort::reverseSort(vector<int>& arr, int left, int right) {
	reverseInsertionSort(arr, 0, arr.size() - 1);
}

void InsertionSort::insertionSort(vector<int>& arr, int left, int right) {
	for (int firstIndex{ left + 1 }; firstIndex <= right; firstIndex++) {
		int tmp{ arr[firstIndex] };
		int secondIndex{ firstIndex - 1 };
		while (secondIndex >= left && arr[secondIndex] > tmp) {
			arr[secondIndex + 1] = arr[secondIndex];
			secondIndex--;
		}

		arr[secondIndex + 1] = tmp;
	}
}

void InsertionSort::reverseInsertionSort(vector<int>& arr, int left, int right) {
	for (int firstIndex{ left + 1 }; firstIndex <= right; firstIndex++) {
		int tmp{ arr[firstIndex] };
		int secondIndex{ firstIndex - 1 };
		while (secondIndex >= left && arr[secondIndex] < tmp) {
			arr[secondIndex + 1] = arr[secondIndex];
			secondIndex--;
		}

		arr[secondIndex + 1] = tmp;
	}
}