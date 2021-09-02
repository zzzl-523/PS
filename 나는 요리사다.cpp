#include<stdio.h>
int main() {
	int ply[5] = { 0, };
	int sco[4] = { 0, };
	int i, j;
	int rate=0;
	int rank =0 ;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 4; j++) {
			scanf("%d", &sco[j]);
			ply[i] += sco[j];
			
		}

		if (rate < ply[i]) {
			rate = ply[i];
			rank = i + 1;
		}
	}
	

	printf("%d %d",rank,rate);

}