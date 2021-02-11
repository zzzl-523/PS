#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int height[10];
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}

	int num = sum - 100;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < i; j++) {
			if (height[i] + height[j] == num) {
				if (i == j) {
					break;
				}
				height[i] = -1;
				height[j] = -1;

				sort(height, height + 9); //이거 여기에 있는 거 중요

			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (height[i] != -1) {
			cout << height[i] << "\n";
		}
	}

	return 0;
	
}