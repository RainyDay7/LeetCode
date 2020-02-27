class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string res = strs[0];
        for(int i=1; i<strs.size(); i++){
            int j=0;
            for(;j<res.length() && j < strs[i].length();j++) {
                if(res[j] != strs[i][j])
                    break;
            }
            res = res.substr(0,j);
            if(res.length()==0) return "";
        }
        return res;
    }
};
