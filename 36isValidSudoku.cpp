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
                    (++rowCount[num][i] == 2  //��ʾ�� i ������ num ���ֵĴ���
                        || ++columnCount[num][j] == 2  //��ʾ�� j ������ num ���ֵĴ���
                        || ++subBoardCount[num][i / 3 * 3 + j / 3] == 2)  //��ʾС9���� num ���ֵĴ���
                    ) {
                    return false;
                }
            }
        }
        return true;
    }
};
