#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n,m;
	cin>>n;
	int c[1001]={0};
	vector<vector<long long> > a(n);
	long long a1=0;	
	for(int i=0;i<n;i++)	
	{		
		cin>>m;
		for(int j=0;j<m;j++)	
		{						
			cin>>a1; 	
			a[i].push_back(a1);
		} 
	}
    
	long long dnum=0;
	long long cnum=0;
	long long zong=0;
	for(int i=0; i<a.size(); i++){
		int ztem = a[i][0];//这一行的总数 
		int flag =0 ;//判断有没有掉果 
		
		for(int j=1; j<a[i].size(); j++){
			if(a[i][j] > 0) {
				if(ztem > a[i][j]) {
					flag=1;//记录掉果 
					ztem = a[i][j]; 
				} 
			}
			else{
				ztem+=a[i][j];
			}
		}
		dnum+=flag;
		zong += ztem;
		c[i] = flag;
	//	cout<<c[i]<<" ";
	}
	//cout<<endl;
	
	if(c[1] && c[0] && c[n-1]) cnum++;
	if(c[0] && c[n-1] && c[n-2] ) cnum++;
	for(int i=1; i<n-1; i++){
		if(c[i] && c[i+1] && c[i-1] ) 
			cnum++;
	}
	 cout<<zong<<" "<<dnum<<" "<<cnum;
	return 0;
}
/*
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0

5 
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0
*/
