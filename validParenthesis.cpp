class Solution {
public:
    bool isValid(string s) {
        stack<int> sa;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i]=='[' || s[i]=='{'){
                sa.push(s[i]);
            }
            else{
                if(sa.empty()) return false;
                switch (sa.top()){
                    case '(': if(s[i]!=')') return false; else sa.pop();break;
                    case '[': if(s[i]!=']') return false; else sa.pop();break;
                    case '{': if(s[i]!='}') return false; else sa.pop();break;
                }
            }
        }
        if(sa.empty()) return true;
        else return false;
    }
};
