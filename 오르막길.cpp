#include<stdio.h>
#include<iostream>
using namespace std;

int main() {
	int N;
	int Pi_list[1004] = { 0, };
	int bot = 0, top = 0;
	int gap_max = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &Pi_list[i]);
	}
	bot = Pi_list[0];
		for (int i = 0; i < N; i++) {
			if (Pi_list[i] < Pi_list[i + 1]) {
				top = Pi_list[i+1];					
			}
			else if (Pi_list[i] >= Pi_list[i + 1]) {				
				if (gap_max < top - bot) {
					gap_max = top - bot;
				}
				top = 0;
				bot = Pi_list[i+1];
			}	
		}
	cout << gap_max;
}