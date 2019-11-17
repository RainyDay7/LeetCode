class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end()); //先排列成最小的序列
        ans.push_back(nums);
        while(next_permutation(nums.begin(), nums.end())) //存在最小的序列，就返回true
        {
            ans.push_back(nums);
        }
        return ans;
    }
};
