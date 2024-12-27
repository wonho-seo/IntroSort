#pragma once
#include "sort.h"

class InsertionSort : public Sort {
public:
	void sort(vector<int>& arr, int left, int right) override;
	void reverseSort(vector<int>& arr, int left, int right) override;

	void insertionSort(vector<int>& arr, int left, int right);
	void reverseInsertionSort(vector<int>& arr, int left, int right);
};