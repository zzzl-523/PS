#include<iostream>
using namespace std;

void MergeSort(int list[], int tmp_list[], int, int);
void Merge(int list[], int tmp_list[], int, int, int);
int ans = 0;
int main() {
	int N;
	cin >> N;

	int list[50005];
	int ans = 0;

	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	int left = 0;
	int right = N - 1;
	int tmp_list[50005];

	MergeSort(list, tmp_list, left, right);

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N - i; j++) {
			if (list[j-1] > list[j]) {
				int temp = list[j-1];
				list[j-1] = list[j];
				list[j] = temp;
				ans++;
			}
		}
	}

	cout << ans;
}

void MergeSort(int list[], int tmp_list[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(list, tmp_list, left, mid);
		MergeSort(list, tmp_list, mid + 1, right);
		Merge(list, tmp_list, left, mid + 1, right);
	}
}

void Merge(int list[], int tmp_list[], int left_start, int right_start, int right_end){
	int i, left_end, num_elements, tmp_pos;
	left_end = right_start - 1;
	tmp_pos = left_start;
	num_elements = right_end - left_start + 1;

	while (left_start <= left_end && right_start <= right_end) { //both exist
		if (list[left_start] <= list[right_start]) {
			tmp_list[tmp_pos] = list[left_start];
			tmp_pos++;
			left_start++;
		}
		else {
			tmp_list[tmp_pos] = list[right_start];
			tmp_pos++;
			right_start++;
		}
	}
	while (left_start <= left_end) { //only left exists
		tmp_list[tmp_pos] = list[left_start];
		tmp_pos++;
		left_start++;
	}
	while (right_start <= right_end) { //only right exists
		tmp_list[tmp_pos] = list[right_start];
		tmp_pos++;
		right_start++;
	}

	for (int i = 0; i < num_elements; i++,right_end--) { //copy
		list[right_end] = tmp_list[right_end];
	}
}