class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // checking: [row number] -> existing char
        unordered_map<int, unordered_set<char>> rows;

        // checking: [col number] -> existing char
        unordered_map<int, unordered_set<char>> cols;

        // check all rows and cols
        for (int y = 0; y < 9; ++y) {
            for (int x = 0; x < 9; ++x) {
                if (board[y][x] != '.') {
                    // check whether num exists in y row
                    if (rows[y].find(board[y][x]) != rows[y].end()) {
                        return false;
                    }
                    // check whether num exists in x col
                    if (cols[x].find(board[y][x]) != cols[x].end()) {
                        return false;
                    }
                    
                    rows[y].insert(board[y][x]);
                    cols[x].insert(board[y][x]);
                }
            }

        }

        int y = 0;
        int x = 0;
        while (y < 9) {
             // checking: [row number] -> existing char
            unordered_map<int, unordered_set<char>> rows2;

            // checking: [col number] -> existing char
            unordered_map<int, unordered_set<char>> cols2;

            unordered_set<char> sqr;
            for (int i = y; i < y + 3; i++) {
                for (int k = x; k < x + 3; k++) {
                    if (board[i][k] != '.') {
                        if (sqr.find(board[i][k]) != sqr.end()) {
                            return false;
                        }                        
                        // check whether num exists in y row
                        if (rows2[i].find(board[i][k]) != rows2[i].end()) {
                            return false;
                        }
                        // check whether num exists in x col
                        if (cols2[k].find(board[i][k]) != cols2[i].end()) {
                            return false;
                        }
                        sqr.insert(board[i][k]);
                        rows2[y].insert(board[i][k]);
                        cols2[x].insert(board[i][k]);
                    }
                }
            }
            x += 3;
            if (x == 9) {
                x = 0;
                y += 3;
            }
        }

        return true;
    }
};