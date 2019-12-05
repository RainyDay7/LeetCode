#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int **a=new int*[n];
	for(int i=0;i<n;i++)		
		a[i]=new int[m+1];	
	for(int i=0;i<n;i++)	
	{		
		for(int j=0;j<=m;j++)	
		{						
			cin>>a[i][j]; 	
		} 
	}

	long maxnum = 0;
	int flag=0;
	int zong=0;
	for(int i=0; i<n; i++){
		zong+=a[i][0];
		long temp=0;
		int j;
		for(j=1; j<=m; j++){
			zong+=a[i][j];
			temp+=a[i][j];
		}
		if(maxnum>temp) {
			maxnum=temp;
			flag = i;
		}
	}
	cout<<zong<<" "<<flag+1<<" "<<-maxnum;
	return 0;
} 
/*
3 3
73 -8 -6 -4
76 -5 -10 -8
80 -6 -15 0

2 2
10 -3 -1
15 -4 0
*/

