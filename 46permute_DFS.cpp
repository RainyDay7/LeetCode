class Solution {
public:
    void dfs(int cur,vector<int>& nums,vector<vector<int>>& ans){
        if( cur == nums.size() - 1 ){
            ans.push_back(nums);
            return ;
        }
        for(int i = cur; i < nums.size(); i++){
            swap( nums[cur], nums[i] );
            dfs( cur + 1,nums, ans );
            swap( nums[cur], nums[i] );
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs( 0, nums, res );
        return res;
    }
};

