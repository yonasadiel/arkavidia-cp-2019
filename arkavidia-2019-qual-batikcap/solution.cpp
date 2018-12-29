// by: Dicky Novanto

#include <bits/stdc++.h>

using namespace std;

bool isDivisible(const string& kata, int n) {
	int pjg = kata.length();
	if(pjg%n != 0){return false;}
	
	for(int i=n;i<pjg;i+=n){
		if(kata[i] != kata[i%n]) {return false;}
	}

	return true;
}

int main(){
	int tc;
	string kata1, kata2;

	scanf("%d",&tc);
	while(tc--){
		cin>>kata1>>kata2;
		int pjg1 = kata1.length(), pjg2 = kata2.length();
		int maks = __gcd(pjg1, pjg2);
		int pjgMaks = 0;
		string ans = "-";
		
		for(int i=1;i*i<=maks;i++){
			if(maks%i == 0){
				int angka1 = maks/i;
				int angka2 = i;
				
				if(angka1 == angka2){
					string str1 = kata1.substr(0, angka1);
					string str2 = kata2.substr(0, angka1);
					if(str1 == str2) {
						if(isDivisible(kata1, angka1) && isDivisible(kata2, angka1)){
							if(pjgMaks < angka1) {
								pjgMaks = angka1;
								ans = str1;
							}
						}	
					}
					
				}else{
					string str1 = kata1.substr(0, angka1);
					string str2 = kata2.substr(0, angka1);
					if(str1 == str2){
						if(isDivisible(kata1, angka1) && isDivisible(kata2, angka1)) {
							if(pjgMaks < angka1) {
								pjgMaks = angka1;
								ans = str1;
							}
						}	
					}
					str1 = kata1.substr(0, angka2);
					str2 = kata2.substr(0, angka2);
					if(str1 == str2) {
						if(isDivisible(kata1, angka2) && isDivisible(kata2, angka2)) {
							if(pjgMaks < angka2) {
								pjgMaks = angka2;
								ans = str1;
							}	
						}	
					}
					
				}	
			}
			
		}
		cout<<ans<<endl;
	}
	
	return 0;
};