class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sa;

        for(int i=0; i<tokens.size(); i++){
            string s = tokens[i];
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                int a = sa.top();
                sa.pop();
                int b = sa.top();
                sa.pop();
                if(s=="+") sa.push(a+b);
                else if(s=="-")  sa.push(b-a);
                else if(s=="*")  sa.push(b*a); 
                else if(s=="/") sa.push(b/a); 
                }
            else{
                int flag=0;
                if(s[0]=='-') flag=1;
                int temp=0;
                for(int j=flag; j<s.length(); j++){
                    temp=(s[j]-'0') + temp*10;
                }
                if(flag==1) temp = -temp;
                sa.push(temp);
            }
                
        }
            return sa.top();
    }
};
