class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = nums[0];
        for(int i =0;i<nums.size();i++){
            if(nums[i]<=sum+nums[i]){
                sum=sum+nums[i];
            }else{
            	sum=nums[i];;
            }
            ans = max(ans, sum);
        }
		return ans;
    }
};
