#include "HeapSort.h"

void HeapSort::sort(vector<int>& arr, int left, int right) {
	heapSort(arr, left, right);
}
void HeapSort::reverseSort(vector<int>& arr, int left, int right) {
	reverseHeapSort(arr, left, right);
}

void HeapSort::heapfy(vector<int>& arr, int size, int point, int offset) {
	int tmpPoint{ point };
	int left{ 2 * point + 1 };
	int right{ left + 1 };

	if (left < size && arr[offset + left] > arr[offset + tmpPoint]) {
		tmpPoint = left;
	}
	if (right < size && arr[offset + right] > arr[offset + tmpPoint]) {
		tmpPoint = right;
	}

	if (tmpPoint != point) {
		swap(arr[offset + point], arr[offset + tmpPoint]);
		heapfy(arr, size, tmpPoint, offset);
	}
}

void  HeapSort::reverseHeapfy(vector<int>& arr, int size, int point, int offset) {
	int tmpPoint{ point };
	int left{ 2 * point + 1 };
	int right{ left + 1 };

	if (left < size && arr[offset + left] < arr[offset + tmpPoint]) {
		tmpPoint = left;
	}
	if (right < size && arr[offset + right] < arr[offset + tmpPoint]) {
		tmpPoint = right;
	}

	if (tmpPoint != point) {
		swap(arr[offset + point], arr[offset + tmpPoint]);
		reverseHeapfy(arr, size, tmpPoint, offset);
	}
}

void  HeapSort::heapSort(vector<int>& arr, int left, int right) {
	int size{ right - left + 1 };
	for (int point{ size / 2 - 1 }; point >= 0; point--) {
		heapfy(arr, size, point, left);
	}

	for (int point{ size - 1 }; point > 0; point--) {
		swap(arr[0], arr[point]);
		heapfy(arr, point, 0, left);
	}
}

void  HeapSort::reverseHeapSort(vector<int>& arr, int left, int right) {
	int size{ right - left };
	for (int point{ size / 2 - 1 }; point >= 0; point--) {
		reverseHeapfy(arr, size, point, left);
	}

	for (int point{ size - 1 }; point > 0; point--) {
		swap(arr[0], arr[point]);
		reverseHeapfy(arr, point, 0, left);
	}
}