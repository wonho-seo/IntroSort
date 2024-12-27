#include <iostream> 
#include "IntroSort.h"

int main() {
	cout << "���� ������ ���ϸ� 1, ���������� ���ϸ� 2�� �����ּ��� :" << endl;
	int type{};
	cin >> type;
	vector<int> arr;
	while (!cin.fail()) {
		cout << "������ ���ڸ� �Է��� �ּ���(�׸��ϰ� �����ø� ���ڰ� �ƴѰ��� �Է����ּ���) :" << endl;
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

	cout << "���ĵ� �迭 : " << endl;

	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	delete sortMethod;
	return 0;
}