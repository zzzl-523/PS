#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct conference {
	int start;
	int finish;
	conference(int a, int b) : start(a), finish(b){}
};
bool operator<(conference a, conference b) { //이렇게 하면 sort도 이렇게!
	if (a.finish == b.finish) {
		return a.start < b.start;
	}
	return a.finish < b.finish;
}

vector<conference>v;

int main() {
	int N;
	int start, fin;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> start >> fin;
		v.push_back(conference(start, fin));
	}

	sort(v.begin(), v.end());

	int ans = 1;
	int prev = 0;
	for (int i = 1; i < N; i++) {
		if (v[prev].finish <= v[i].start) {
			ans++;
			prev = i;
		}
	}

	cout << ans;

	return 0;
}