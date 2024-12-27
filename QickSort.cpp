#include "QuickSort.h"

void QuickSort::sort(vector<int>& arr, int left, int right) {
	int pivot =	quickSort(arr, left, right);
}

void QuickSort::reverseSort(vector<int>& arr, int left, int right) {
	quickSort(arr, left, right);
}

int QuickSort::quickSort(vector<int>& arr, int left, int right) {
	int pivot = arr[right];
	int i{ left };
	for (int j{ left }; j < right; j++) {
		if (arr[j] > pivot) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[right]);
	return i;
}

int QuickSort::reverseQuickSort(vector<int>& arr, int left, int right) {
	int pivot = arr[right];
	int i{ left };
	for (int j{ left }; j < right; j++) {
		if (arr[j] < pivot) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[right]);
	return i;
}