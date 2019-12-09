#include<bits/stdc++.h>
using namespace std;

int main(){
	long r, y, g;
	cin>>r>>y>>g;
	int n; cin>>n;
	long long res=0;
	for(int i=0; i<n; i++){
		int c, time;
		cin>>c;
		cin>>time;
		switch(c){
			case 0:
				res+=time;
				break;
			case 1://ºì 
				res+=time; break;
			case 2://»Æ 
				res+=time; res+=r; break;
			case 3:
				 break;
		}
	}
	cout<<res;
	return 0;
} 
