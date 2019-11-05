class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i=n-1;
        for(;i>=1; i--){
            if(nums[i]>nums[i-1]) 
                break;
        }
        if(i>=1){
            int j=n-1;
            for(;j>=i; j--){
                if(nums[j]>nums[i-1]){
                    break;
                }
            }
            swap(i-1,j,nums);
            reverse(nums,i);
        }
        else{
            reverse(nums,0);
        }
    }
    
    void swap(int i, int j, vector<int>& nums){
        int tem = nums[i];
        nums[i] = nums[j];
        nums[j] = tem;
    }
    
    void reverse(vector<int>& nums, int index){
        int i=index;
        int j=nums.size()-1;
        while(i<j){
            swap(i,j,nums);
            i++;
            j--;
        }
    }
};
