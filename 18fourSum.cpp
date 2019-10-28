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
            //����ͷ����ͬԪ��
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=len-1; j>i+2; j--){
                //����β����ͬԪ��
                if(j<len-1 && nums[j]==nums[j+1]) continue;
                int left = i+1;
                int right = j-1;
                while(left<right){
                    int t = nums[i]+nums[j]+nums[left]+nums[right];
                    if(t<target) left++;
                    else if(t>target) right--;
                    else{//�õ�һ���
                        temp.clear();
                        temp.push_back(nums[i]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        temp.push_back(nums[j]);
                        res.push_back(temp);
                        //���left��left+1��ͬ�����Թ�
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
