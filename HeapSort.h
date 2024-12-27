#pragma once
#include "sort.h"

class HeapSort : public Sort{
public:
	void sort(vector<int>& arr, int left, int right) override;
	void reverseSort(vector<int>& arr, int left, int right) override;

private:
	void heapfy(vector<int>& arr, int size, int point, int offset);
	void reverseHeapfy(vector<int>& arr, int size, int point, int offset);
	void heapSort(vector<int>& arr, int left, int right);
	void reverseHeapSort(vector<int>& arr, int left, int right);
};