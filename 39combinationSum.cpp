class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size() == 0 || target < 0) {
            return res;
        }
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        BackTracking(res, curr, candidates, target, 0);
        return res;
    }
    void BackTracking(vector<vector<int>>& res, vector<int> curr, vector<int> candidates, int target, int level) {
        if(target == 0) {
            res.push_back(curr);
            return;
        } else if(target < 0) {
            return;
        }
        for(int i = level; i < candidates.size(); i++) {
            target -= candidates[i];
            curr.push_back(candidates[i]);
            BackTracking(res, curr, candidates, target, i);
            curr.pop_back();
            target += candidates[i];
        }
    }
};

