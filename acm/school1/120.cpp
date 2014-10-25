#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[600];
char buf[3000];

int FindMaxIndex(int max){
	int i;

	int tmp=0;

	for(i=1;i<=max;i++){
		if (a[i]>=a[tmp]) tmp=i;
	}
	return tmp;
}

void swap(int pos1,int pos2){

	int tmp=a[pos1];
	a[pos1]=a[pos2];
	a[pos2]=tmp;
}

void flip(int num){
	int i;

	for(i=0;i<=num/2;i++){
		swap(i,num-i);
	}
}

int main(void){


	char* x;

	int num=0;
	int k;
	int index;

	fgets(buf,3000,fi);

	while(!feof(stdin)){

	if (buf[strlen(buf)-1]=='\n') buf[strlen(buf)-1]=0;
	if (buf[0]>'9'|| buf[0]<'0') break;
	printf("%s\n",buf);

	x=strtok(buf," \t");
	while(x){
		a[num]=atoi(x);
		x=strtok(NULL," \t");
		num++;
	}
	k=num;
	while(num>1){

		num--;
		index=FindMaxIndex(num);
		if (index==0 ){
			flip(num);
			printf("%d ",k-num);
		}
		else if (index!=num){
			flip(index);
			flip(num);
			printf("%d %d ",k-index,k-num);
		}
	}
	printf("0\n");
	num=0;
	gets(buf);
	}

	return 0;
}

/* "@END_OF_SOURCE_CODE"*/
