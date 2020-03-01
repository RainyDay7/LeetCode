class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        multimap<string,int> m;
        vector<string> tem = strs;
        for(int i=0; i<strs.size(); i++){
            sort(strs[i].begin(), strs[i].end());
            m.insert(make_pair(strs[i], i));
        }

        vector<vector<string>> res;
        vector<string> temres;
        multimap<string,int>::iterator itr=m.begin();
        for(itr = m.begin(); itr != m.end();){
            string str = itr->first;
            temres.push_back(tem[itr->second]);
            itr++;
            while(itr!=m.end() && itr->first==str ){
                temres.push_back(tem[itr->second]);
                itr++;
            }
            res.push_back(temres);
            temres.clear();
        }
        return res;
    }
};

