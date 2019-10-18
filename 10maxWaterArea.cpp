
class Solution {

public:
    int maxArea(vector<int>& height) {
        int ret=0;
        int temp;
        for(int i=0,j=height.size()-1;i<j;)
        {
            temp=min(height[i],height[j])*(j-i);      //����2��ָ���heightΧ�ɵ����
            ret=ret>temp?ret:temp;                    //����������
            if(height[i]>height[j])                   //��������ָ���height��С�ƶ�����ָ��
                j--;
            else
                i++;
        }
        return ret;
    }
};

