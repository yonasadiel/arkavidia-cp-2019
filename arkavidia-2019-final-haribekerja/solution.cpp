//by: Dicky Novanto

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6;

int a[maxn + 2];

bool isValid(int bil){
	int curBil = 0;
	while(bil > 0){
		int angka = bil%10;
		bil /= 10;
		if(angka == 4){return false;}
		if(angka == 1 && curBil == 3){return false;}
		curBil = angka;
	}
	return true;
}

void precompute() {
	int i,j;
	int cnt = 1;
	for(i=1;i<=maxn;i++) {
		a[i] = (isValid(i) ? cnt++: -1);
	}
}

int main(){
	int tc,n,i,j;

	precompute();
	
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			if(i){printf(" ");}
			printf("%d",a[bil]);
		}
		printf("\n");
	}
	return 0;
};