#pragma once
#include <vector>

using namespace std;
class Sort {
public:
	virtual	void sort(vector<int>& arr, int left, int right) = 0;
	virtual void reverseSort(vector<int>& arr, int left, int right) = 0;

};