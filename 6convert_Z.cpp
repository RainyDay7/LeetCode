class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
		if(len == 0 || numRows == 1)
		 	return s;
		int d = 2*numRows-2;
        int tem=0;
		string newstr;
		for(int i=0; i<numRows; i++){
			for(int j=i; j<len; j+=d){//j=i
                newstr+=s[j];
				tem = j+d-2*i;
			    if (i!=0 && i!=numRows-1 && tem<len)//不是第一行、最后一行
                    newstr += s[tem];
            }
		}
        return newstr;
    }
};