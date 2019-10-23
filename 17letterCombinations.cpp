class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int len = digits.size();
        if (digits.empty()) return res;
        map<char, string> numToStr;  
        numToStr['2']="abc";  
        numToStr['3']="def";  
        numToStr['4']="ghi";  
        numToStr['5']="jkl";  
        numToStr['6']="mno";  
        numToStr['7']="pqrs";  
        numToStr['8']="tuv";  
        numToStr['9']="wxyz"; 
        find(digits, 0, "", res, numToStr);
        return res;
    }
    void find(string digits, int idx, string s, vector<string> &res, map<char, string> numToStr){
        if(idx == digits.size())
            res.push_back(s);
        else
            for(int i = 0; i < numToStr[digits[idx]].size(); i++)
                find(digits, idx+1, s+numToStr[digits[idx]][i], res, numToStr);
    }
};
