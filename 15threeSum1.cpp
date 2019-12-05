class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        int len = nums.size();
        if(len <3) return ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        int sum=-1;
        for(int i=0; i<len-2; i++){
            if(nums[i]<=0){
                v.push_back(nums[i]);
                if(sum == -nums[i]){
                    v.pop_back();
                    continue;
                }
                sum = -nums[i];
                int j=i+1, k=len-1;
                int d = nums[j]-1;
                while(j<k){
                    if(nums[j]+nums[k]==sum){
                        if(d!=nums[j]){
                            v.push_back(nums[j]);
                            v.push_back(nums[k]);
                            ans.push_back(v);
                            v.pop_back();
                            v.pop_back();
                            d = nums[j];
                        }
                        j++, k--;
                    }
                    else if(nums[j] + nums[k] < sum) j++;
                    else if(nums[j] + nums[k] > sum) k--;

                }
                v.pop_back();
            }
        }    
        return ans;
    }
};
