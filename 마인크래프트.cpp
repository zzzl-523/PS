#include<iostream>
using namespace std;

int main() {
	int N, M, B;
	int list[505][505];
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];			
		}
	}

	int ans_time = 999999999, ans_layer = -1;
	int now_time = 0, now_inventory = 0;

	for (int now_layer = 256; now_layer >= 0; now_layer--) {

		now_time = 0;
		now_inventory = B;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (list[i][j] > now_layer) { //¸ñÇ¥Ãþº¸´Ù ³ôÀ¸¸é
					now_inventory += list[i][j] - now_layer;
					now_time += (list[i][j] - now_layer) * 2;
				}
				if (list[i][j] < now_layer) { //¸ñÇ¥Ãþº¸´Ù ³·À¸¸é
					now_inventory -= now_layer - list[i][j];
					now_time += now_layer - list[i][j];
				}
			}
		}
		
		if (now_inventory < 0) {
			continue;
		}
		if (now_time < ans_time) {
			ans_time = now_time;
			ans_layer = now_layer;
		}
		
	}

	cout << ans_time << " " << ans_layer;

	return 0;
}