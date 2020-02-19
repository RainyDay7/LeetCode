class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
           return a[1]<b[1];
        });
        
        if(intervals.size() <= 1) return 0;
        int res=-1;
        int x_end = intervals[0][1];
        for(auto& e:intervals){
            if(e[0]<x_end) res++;
            else x_end=e[1];
        }
        return res;

    }
};


