class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> v;
        int temp=0;
        for(int i=0; i<gas.size(); i++){
            v.push_back(gas[i]-cost[i]);
            temp += gas[i]-cost[i];
        }
        if(temp<0) return -1;
        for(int i=0; i<gas.size(); i++){
            if(v[i]<0) continue;
            temp=v[i];
            int j;
            for(j=(i+1)%gas.size(); j!=i;j=(j+1)%gas.size()){
                temp += v[j];
                if(temp<0) break;
            }
            if(j==i) return i;
        }
        return -1;
    }
};
