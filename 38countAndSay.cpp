class Solution {
public:
    string countAndSay(int n) {
        string n1 = "1";
        if(n==1) return "1";
        string res="1";
        for(int i=1; i<n; i++){
            char tem = res[0];
            string str;
            for(int j=0; j<res.length(); ){
                tem = res[j];
                int count = 0;
                while(res[j]==tem){
                    count++;
                    j++;
                }
                str.push_back(count+'0');
                str.push_back(tem);
                
            }
            res = str;
        }
        return res;

    }
};
