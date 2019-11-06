class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty() || target < nums.front() || target > nums.back()) //特殊情况
            return {-1, -1};
        int l = 0, r = nums.size() - 1, mid;
        int res1 , res2;
        //二分查找,分别找左右边缘
        //注意不能找到左边缘再循环遍历到右边缘，因为可能整个数组都是这个数，这样复杂度就是变成n+logn了
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if(nums[l] != target)//没有瞒足条件的数组值
            return{-1, -1};
        res1 = l;
        //从左边缘到最后开始继续二分找到右边缘
        r = nums.size() - 1;
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] <= target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        res2 = r;
        return {res1, res2};
    }
};
