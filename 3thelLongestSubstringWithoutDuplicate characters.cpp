class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0;
        map<char,int> hash;
        for(int i=0, j=0; j<n; j++){
        	if(hash.find(s[j]) != hash.end()){
        		i = max(hash.find(j)->second+1,i);
			}
			ans = max(ans, j-i+1);
			hash[s[j]] = j;
        }
        return ans;
    }
};
