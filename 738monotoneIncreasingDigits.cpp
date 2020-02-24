class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int tem = N;
        if(N==0) return 0;
        if(N<=10) return N-1;
        vector<int> nums;
        while(N>0){ // ��N�ֽ�ţ�����ĸ������ַ���������
            nums.push_back(N%10);
            N/=10;
        }
        int i=0;
        reverse(nums.begin(), nums.end());//������v�еĸ�����ֽ��еߵ���1234->1234
        while (i + 1 < nums.size() && nums[i + 1] >= nums[i]) {
            ++i;
        }
        
        //�������
        if (i == nums.size()-1) {
            return tem; 
        }

         while (i > 0 && nums[i - 1] == nums[i]) --i;//3332 �ҵ���һ����ȵ��� ����һ��3

        int res = 0;
        for (int j = 0; j < i; ++j) {
            res = res * 10 + nums[j];
        }

         res = res * 10 + nums[i] - 1;
         for (int j = i + 1; j < nums.size(); ++j) {
            res = res * 10 + 9;
        }
        return res;






    }
};
