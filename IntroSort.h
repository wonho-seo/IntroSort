#pragma once
#include "HeapSort.h"
#include "QuickSort.h"
#include "InsertionSort.h"

class IntroSort : public QuickSort {
public:
	void sort(vector<int>& arr, int left, int right) override ;
	void reverseSort(vector<int>& arr, int left, int right) override;

private:
	void introSort(vector<int>& arr, int left, int right, int depthLimit);
	void reverseIntroSort(vector<int>& arr, int left, int right, int depthLimit);
	InsertionSort insertionSort{ InsertionSort() };
	HeapSort heapSort{ HeapSort() };
};