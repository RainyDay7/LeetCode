class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
           return a[1]<b[1];
        });
        
        if(points.size() == 0) return 0;
        int res=1;
        int x_end = points[0][1];
        for(auto& e:points){
            if(e[0]>x_end) {
                x_end=e[1];
                res++;
            }
            
        }
        return res;

    }
};


