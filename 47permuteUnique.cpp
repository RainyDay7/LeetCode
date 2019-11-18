class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        help(nums, 0, res);
        return res;
    }

    void help(vector<int> nums, int start, vector<vector<int>> &res){
        if(start == nums.size()){
            res.push_back(nums);
            return ;
        }
        for(int i=start; i<nums.size(); i++){
            if(i>start && nums[start] == nums[i])
                continue;
            swap(nums[start], nums[i]);
            help(nums, start+1, res);
        }
    }
};
