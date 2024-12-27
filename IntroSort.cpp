#include "IntroSort.h"

void IntroSort::introSort(vector<int>& arr, int left, int right, int depthLimit) {
	if (left < right) {
		if (right - left < 16) {
			this->insertionSort.sort(arr, left, right);
		}
		else if (depthLimit == 0) {
			this->heapSort.sort(arr, left, right);
		}
		else {
			int pivot = quickSort(arr, left, right);

			introSort(arr, left, pivot - 1, depthLimit - 1);
			introSort(arr, pivot + 1, right, depthLimit - 1);
		}
	}
}

void IntroSort::reverseIntroSort(vector<int>& arr, int left, int right, int depthLimit) {
	if (left < right) {
		if (right - left < 16) {
			this->insertionSort.reverseSort(arr, left, right);
		}
		else if (depthLimit == 0) {
			this->heapSort.reverseSort(arr, left, right);
		}
		else {
			int pivot = reverseQuickSort(arr, left, right);

			reverseIntroSort(arr, left, pivot - 1, depthLimit - 1);
			reverseIntroSort(arr, pivot + 1, right, depthLimit - 1);
		}
	}
}

void IntroSort::sort(vector<int>& arr, int left, int right) {
	int depthLimit = 2 * log(arr.size());
	introSort(arr, 0, arr.size() - 1, depthLimit);
}

void IntroSort::reverseSort(vector<int>& arr, int left, int right) {
	int depthLimit = 2 * log(arr.size());
	reverseIntroSort(arr, 0, arr.size() - 1, depthLimit);
}