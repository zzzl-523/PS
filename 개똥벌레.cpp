#include<iostream>
#include<algorithm>
using namespace std;

int suksun[100005];		//석순 리스트
int jongusuk[100005];	//종유석 리스트

int BS(int value, int L, int R,int list[]);	//그냥 찾는 함수
int binary_lower(int value, int L, int R,int list[]);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0,H=0;	//N은 장애물 개수, H는 높이(층)
	
	cin >> N >> H;
	for (int i = 0; i < N / 2; i++) {
		cin >> suksun[i];	//짝수, 석순
		cin >> jongusuk[i];	//홀수, 종유석
	}
	sort(suksun, suksun + N/2);
	sort(jongusuk, jongusuk + N / 2);

	int value = 0;
	int count = 0;
	int suk_num = 0, jong_num = 0;
	int min = 0;	
	for (int i = 1; i <= H; i++) {
		suk_num = N / 2 - binary_lower(i, 0, (N / 2) , suksun);	//석순
		jong_num = N / 2 - binary_lower(H - i + 1, 0, (N / 2), jongusuk);	//종유석
		
		if (count == 0) {
			min = suk_num + jong_num;
		}
		if (min > suk_num + jong_num) {
			count = 0;
			min = suk_num + jong_num;
			count++;
		}
		else if (min == suk_num + jong_num) {
			count++;
		}
	}

	cout << min << " " << count << "\n";
	return 0;
}
int BS(int value, int L, int R,int list[]) {	//그냥 찾는 함수
	int mid = (L + R) / 2;
	if (L > R) {//L>R이면 존재 X
		return 0;
	}

	if (value < list[mid]) {
		return BS(value, L, mid - 1,list);
	}
	else if (value > list[mid]) {
		return BS(value, mid + 1, R,list);
	}
	else {
		return 1;
	}
}

int binary_lower(int value, int L, int R,int list[] ) {
	while (L < R) {
		int mid = (L + R) / 2;

		if (value <= list[mid]) {
			R = mid;
		}
		else {
			L = mid + 1;
		}
	}
	return L;
}
