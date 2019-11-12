class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowCount[10][9]={0};
        int columnCount[10][9]={0};
        int subBoardCount[10][9]={0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j <9; j++) {
                int num = board[i][j] - '0';
                if (board[i][j] != '.' &&
                    (++rowCount[num][i] == 2  //表示第 i 行数字 num 出现的次数
                        || ++columnCount[num][j] == 2  //表示第 j 列数字 num 出现的次数
                        || ++subBoardCount[num][i / 3 * 3 + j / 3] == 2)  //表示小9宫格 num 出现的次数
                    ) {
                    return false;
                }
            }
        }
        return true;
    }
};
