#include<bits/stdc++.h>
using namespace std;
long long ga, gb;
set<int> v;
long long n, m, t;
long long tem;
int main(){
	int T; 	scanf("%d",&T);
	for(int j=0; j<T; j++){
		scanf("%lld%lld%lld",&n,&m,&t);
		v.clear();
		for(int i=0; i<m; i++){
			scanf("%lld",&tem);
			v.insert(tem);
		}
		for(int i=0; i<t && v.size()<n; i++){
			scanf("%lld%lld",&ga,&gb);
			if(v.find(ga)!=v.end()){
				v.insert(gb);
			}
			else if(v.find(gb)!=v.end()){
				v.insert(ga);
			}
		}
		printf("%d",v.size());
	}
	return 0;
} 
/*
1
5 2 5
1 2 
1 3
3 5
4 5
1 2 
2 3
*/
