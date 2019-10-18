
class Solution {

public:
    int maxArea(vector<int>& height) {
        int ret=0;
        int temp;
        for(int i=0,j=height.size()-1;i<j;)
        {
            temp=min(height[i],height[j])*(j-i);      //计算2个指针的height围成的面积
            ret=ret>temp?ret:temp;                    //更新最大面积
            if(height[i]>height[j])                   //依据左右指针的height大小移动左右指针
                j--;
            else
                i++;
        }
        return ret;
    }
};

