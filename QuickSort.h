#pragma once
#include "sort.h"

class QuickSort :public Sort {
public:
	void sort(vector<int>& arr, int left, int right) override;
	void reverseSort(vector<int>& arr, int left, int right) override;

protected:
	int quickSort(vector<int>& arr, int left, int right);
	int reverseQuickSort(vector<int>& arr, int left, int right);
};