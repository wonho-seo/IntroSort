// Sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <cmath> 

using namespace std;

void insertionSort(vector<int>& arr, int left, int right) {
	for (int firstIndex{ left + 1 }; firstIndex <= right; firstIndex++) {
		int tmp{ arr[firstIndex] };
		int secondIndex{ firstIndex - 1 };
		while (secondIndex >= left && arr[secondIndex] > tmp) {
			arr[secondIndex + 1] = arr[secondIndex];
			secondIndex--;
		}

		arr[secondIndex + 1] = tmp;
	}
}

void reverseInsertionSort(vector<int>& arr, int left, int right) {
	for (int firstIndex{ left + 1 }; firstIndex <= right; firstIndex++) {
		int tmp{ arr[firstIndex] };
		int secondIndex{ firstIndex - 1 };
		while (secondIndex >= left && arr[secondIndex] < tmp) {
			arr[secondIndex + 1] = arr[secondIndex];
			secondIndex--;
		}

		arr[secondIndex + 1] = tmp;
	}
}

void heapfy(vector<int>& arr, int size, int point) {
	int tmpPoint{ point };
	int left{ 2 * point + 1 };
	int right{ left + 1 };
	
	if (left < size && arr[left] > arr[tmpPoint]) {
		tmpPoint = left;
	}
	if (right < size && arr[right] > arr[tmpPoint]) {
		tmpPoint = right;
	}

	if (tmpPoint != point) {
		swap(arr[point], arr[tmpPoint]);
		heapfy(arr, size, tmpPoint);
	}
}

void reverseHeapfy(vector<int>& arr, int size, int point) {
	int tmpPoint{ point };
	int left{ 2 * point + 1 };
	int right{ left + 1 };

	if (left < size && arr[left] < arr[tmpPoint]) {
		tmpPoint = left;
	}
	if (right < size && arr[right] < arr[tmpPoint]) {
		tmpPoint = right;
	}

	if (tmpPoint != point) {
		swap(arr[point], arr[tmpPoint]);
		heapfy(arr, size, tmpPoint);
	}
}

void heapSort(vector<int>& arr, int size) {

	for (int point{ size / 2 - 1 }; point >= 0; point--) {
		heapfy(arr, size, point);
	}

	for (int point{ size - 1 }; point > 0; point--) {
		swap(arr[0], arr[point]);
		heapfy(arr, point, 0);
	}
}

void reverseHeapSort(vector<int>& arr, int size) {

	for (int point{ size / 2 - 1 }; point >= 0; point--) {
		reverseHeapfy(arr, size, point);
	}

	for (int point{ size - 1 }; point > 0; point--) {
		swap(arr[0], arr[point]);
		reverseHeapfy(arr, point, 0);
	}
}

int quickSort(vector<int>& arr, int left, int right) {
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

int reverseQuickSort(vector<int>& arr, int left, int right) {
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

void introSort(vector<int>& arr, int left, int right, int depthLimit, int type) {
	if (left < right) {
		if (right - left < 16) {
			if (type == 1) {
				insertionSort(arr, left, right);
			}
			else {
				reverseInsertionSort(arr, left, right);
			}
		}
		else if (depthLimit == 0) {
			if (type == 1) {
				heapSort(arr, right - left + 1);
			}
			else {
				reverseHeapSort(arr, right - left + 1);
			}
		}
		else {
			int pivot{};
			if (type == 1) {
				pivot = quickSort(arr, left, right);
			}
			else {
				pivot = reverseQuickSort(arr, left, right);
			}

			introSort(arr, left, pivot - 1, depthLimit - 1, type);
			introSort(arr, pivot + 1, right, depthLimit - 1, type);
		}
	}
}

void sort(vector<int>& arr, int type) {
	int depthLimit = 2 * log(arr.size());
	introSort(arr, 0, arr.size() - 1, depthLimit, type);
}


int main() {
	cout << "오름 차순을 원하면 1, 내림차순을 원하면 2를 눌러주세요 :" << endl;
	int type{};
	cin >> type ;
	vector<int> arr;
	while (!cin.fail()) {
		cout << "정렬할 숫자를 입력해 주세요(그만하고 싶으시면 숫자가 아닌값을 입력해주세요) :" << endl;
		int num{};
		cin >> num;
		arr.push_back(num);
	}
	sort(arr, type);

	cout << "정렬된 배열 : " << endl;

	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

		// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
		// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

		// 시작을 위한 팁: 
		//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
		//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
		//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
		//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
		//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
		//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
