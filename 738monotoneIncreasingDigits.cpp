class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int tem = N;
        if(N==0) return 0;
        if(N<=10) return N-1;
        vector<int> nums;
        while(N>0){ // 把N分解放，将其的各个数字放入容器中
            nums.push_back(N%10);
            N/=10;
        }
        int i=0;
        reverse(nums.begin(), nums.end());//将容器v中的哥哥数字进行颠倒，1234->1234
        while (i + 1 < nums.size() && nums[i + 1] >= nums[i]) {
            ++i;
        }
        
        //无逆序的
        if (i == nums.size()-1) {
            return tem; 
        }

         while (i > 0 && nums[i - 1] == nums[i]) --i;//3332 找到第一个相等的数 即第一个3

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
