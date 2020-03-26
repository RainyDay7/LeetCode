#include<bits/stdc++.h>
using namespace std;
string b = "31415926";
int xiaoshuwei = 7;
void multiply(long long int res ) {
	string a;
    ostringstream ss;
    ss<<res;
    istringstream is(ss.str());
    is>>a;
    cout<<a<<" "<<b<<endl;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int c=0;
	string temp(a.size()+b.size(),'0'); //将temp全部初始化为0字符  
	for(int i=0;i<a.size(); i++){
		int j=0;
		for( j=0; j<b.size(); j++){
			c+=temp[i+j]-'0'+(a[i]-'0')*(b[j]-'0');
			temp[i+j] = c%10+'0';
			c = c/10;
		}
		while(c){
			temp[i+j]+=c%10;
			c/=10;
			j++;
		}
	}
	//处理进位
	int i=2;
	if(temp[1]>=5 && i<temp.size()){
		temp[i]+=1;
		while(temp[i]-'0'>=10){
			temp[i] = 0;
			temp[i++] += 1;
		}
	}
	if(i==temp.size()) temp.append("1");
	for(int i=temp.size()-1; i>=0; i--){
		if(temp[i]=='0'){
			temp.erase(temp.end()-1);
		}
		else  break;
	}
	
	
	temp.insert(temp.begin()+7,'.');
	reverse(temp.begin(), temp.end());
	
	temp.erase(temp.end()-1);
	temp.erase(temp.end()-1);
	cout<<temp;
}


int main(){
	int n; scanf("%d",&n);
	int r[1001];
	long long int  res=0;
	r[0] = 0;
	for(int i=0; i<n; i++){
		scanf("%d",&r[i+1]);
	}
	while(n>0){
		res += (r[n]*r[n]-r[n-1]*r[n-1]);
		n-=2;
	}
	multiply(res);
}
