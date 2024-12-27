#include <iostream> 
#include "IntroSort.h"

int main() {
	cout << "오름 차순을 원하면 1, 내림차순을 원하면 2를 눌러주세요 :" << endl;
	int type{};
	cin >> type;
	vector<int> arr;
	while (!cin.fail()) {
		cout << "정렬할 숫자를 입력해 주세요(그만하고 싶으시면 숫자가 아닌값을 입력해주세요) :" << endl;
		int num{};
		cin >> num;
		arr.push_back(num);
	}
	Sort* sortMethod = new HeapSort();
	if (type == 1) {
		sortMethod->sort(arr, 0, arr.size() - 1);
	}
	else {
		sortMethod->reverseSort(arr, 0, arr.size() - 1);
	}

	cout << "정렬된 배열 : " << endl;

	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	delete sortMethod;
	return 0;
}