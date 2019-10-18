class Solution {  
public:  
    int maxArea(vector<int>& height) {  
        int n=height.size();  
        int i=0,j=n-1;  
        int max=0;  
        while(i!=j){  
            if(height[i]<height[j]){  
                int valid_height=height[i];  
                int temp_area=valid_height*(j-i);  
                max=max>temp_area?max:temp_area;  
                i++;  
            }  
            else{  
                int valid_height=height[j];  
                int temp_area=valid_height*(j-i);  
                max=max>temp_area?max:temp_area;  
                j--;  
            }           
        }  
        return max;  
    }  
};
