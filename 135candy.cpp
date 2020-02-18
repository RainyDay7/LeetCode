class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if(len == 0) return 0;
        vector<int> candy(len, 1);
        for(int i=1; i<len; i++){
            if(ratings[i-1]<ratings[i]) candy[i] = candy[i-1]+1;
        }
        int res=candy[len-1];
        for(int i=len-2; i>=0; i--){
            if(ratings[i]> ratings[i+1] && candy[i]<=candy[i+1]) candy[i]=candy[i+1]+1;
            res += candy[i];
        }
        return res;
    }
};

