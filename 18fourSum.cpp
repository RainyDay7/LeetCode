class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (len<4) return res;
        if(nums[0]+nums[1]+nums[2]+nums[3] > target || nums[len-1]+nums[len-2]+nums[len-3]+nums[len-4] < target) return res; 
        for(int i=0; i<len; i++){
            //跳过头部相同元素
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=len-1; j>i+2; j--){
                //跳过尾部相同元素
                if(j<len-1 && nums[j]==nums[j+1]) continue;
                int left = i+1;
                int right = j-1;
                while(left<right){
                    int t = nums[i]+nums[j]+nums[left]+nums[right];
                    if(t<target) left++;
                    else if(t>target) right--;
                    else{//得到一组解
                        temp.clear();
                        temp.push_back(nums[i]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        temp.push_back(nums[j]);
                        res.push_back(temp);
                        //如果left和left+1相同，则略过
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            --right;
                        ++left;
                        --right;
                    }
                }
            }
        }
        return res;
    }
};
