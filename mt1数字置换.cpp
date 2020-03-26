#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	char s1[9], ch;
	int flag=0;
	
	s.resize(10005);
	scanf("%c", &ch);
	if(ch=='-'){
		flag=1;
		scanf("%s",&s[0]);
	}
	else{
		s[0] = ch;
		scanf("%s",&s[1]);
	}
	//printf("%s\n",s.c_str());
	for(int i=0;i<9; i++){
		cin>>s1[i];
	}
	
	for(int i=0; s[i]!=0; i++){
		s[i] = s1[s[i]-1-'0'];
	}
	if(flag) printf("-");
	printf("%s",s.c_str());
	return 0;
} 
