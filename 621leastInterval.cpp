class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> m;
        map<char, int>::iterator itr;
        int max_count = 0;
        int difference = 0;

        if(tasks.size() == 0) return 0;
        m.insert(pair<char, int>(tasks[0], 1));
        for(int i=1; i<tasks.size(); i++){
            itr = m.find(tasks[i]);
            if(itr!=m.end()){
                itr->second += 1;
                max_count = max(itr->second, max_count);
            }
            else m.insert(pair<char, int>(tasks[i],1));
        }
        
        for(itr=m.begin(); itr!=m.end(); itr++){
            if(itr->second == max_count) difference++;
        }

        int number1 = (n+1)*(max_count-1)+difference;
        int number2 = tasks.size();

        return max(number2, number1);
    }
};


