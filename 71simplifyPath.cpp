class Solution {
public:
    string simplifyPath(string path) {
        stack<string> sa;
        for(int i=0; i<path.length();){
            if(path[i]=='/'){
                i++;
            }
            else{
                string temp;
                while(path[i]!='/'&& i<path.length()){
                    temp+=path[i];
                    i++;
                }
                
                if(temp==".."){
                    if(!sa.empty())  sa.pop();
                }
                else if(temp=="."){
                    continue;
                }
                else {
                    sa.push(temp);
                }
            }
        }
        string result;
        if(sa.empty()) result="/";
        while(!sa.empty()){
            result.insert(0,"/"+sa.top());
            sa.pop();
        }
        
        return result;
    }
};
