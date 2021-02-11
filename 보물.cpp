#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a[55];
	int b[55];
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}

	sort(a, a + N);
	sort(b, b + N, greater<>());

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += a[i] * b[i];
	}

	cout << ans;
	
	return 0;
}