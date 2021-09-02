#include<bits/stdc++.h>
using namespace std;
stack < int > st;
vector<stack<int>>v(300000);

int main() {
	int N, P;
	cin >> N >> P;
	int count = 0;
	int check = 0;

	int line, fret;
	cin >> line >> fret;
	v[line].push(fret);
	count++;
	for (int i = 0; i < N-1; i++) {
		cin >> line >> fret;

		if (v[line].empty() == 1) {
			v[line].push(fret);
			count++;
			continue;
		}

		if (fret > v[line].top()) {}
		else if (fret == v[line].top()) {	continue; }
		else {
			while (1) {
				if (v[line].empty() == 1) {
					break;
				}
				if (fret < v[line].top()) {
					count++;//뗴고
					v[line].pop();
					continue;
				}
				break;
			}
			if (v[line].empty() == 0) {
				if (fret == v[line].top()) {
					continue;
				}
			}
		}
		
		v[line].push(fret);
		count++;
	}
	cout << count;
	return 0;
}