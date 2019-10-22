class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) { 
        int len = nums.size();
        
        sort(nums.begin(), nums.end());
        int sum=nums[0]+nums[1]+nums[2];
        int d=sum;
        int close=abs(sum-target);
        for (int i=0; i<len-2; i++){
            int j=i+1, k=len-1;
            
            while(j<k){
                sum = nums[j]+nums[k]+nums[i];
                if( abs(sum-target) < close){
                     close = abs(sum-target);
                    d = sum;
                }
                   
                if( sum>target) k--;
                else if (sum<target)j++;
                else return target;
            }
        }
        return d;
    }
};
