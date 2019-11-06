class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty() || target < nums.front() || target > nums.back()) //�������
            return {-1, -1};
        int l = 0, r = nums.size() - 1, mid;
        int res1 , res2;
        //���ֲ���,�ֱ������ұ�Ե
        //ע�ⲻ���ҵ����Ե��ѭ���������ұ�Ե����Ϊ�����������鶼����������������ӶȾ��Ǳ��n+logn��
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if(nums[l] != target)//û����������������ֵ
            return{-1, -1};
        res1 = l;
        //�����Ե�����ʼ���������ҵ��ұ�Ե
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
