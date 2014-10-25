#include <iostream.h>

#define MAXN 100

int matrix[MAXN][MAXN];

int n;

int main(void){

	int i,j;
	int unCounted,possibleMax,currentMax;
	int left,right,row;

	cin >> n;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin >> matrix[i][j];
			if (j>0) matrix[i][j]+=matrix[i][j-1];
		}
	}

	for(currentMax=0,unCounted=1,left=0;left<n;left++){
		for(right=left;right<n;right++){
			for(row=0,possibleMax=0;row<n;row++){
				if (left>0) possibleMax+=matrix[row][right]-matrix[row][left-1];
				else possibleMax+=matrix[row][right];
				
				if (unCounted || possibleMax>currentMax){
					currentMax=possibleMax;
					unCounted=0;
				}

				if (possibleMax<0) possibleMax=0;
			}
		}
	}

	cout << currentMax << endl;

	return 0;
}

/*@ END_OF_SOURCE_FILE */
