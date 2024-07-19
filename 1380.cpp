class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> result;
        int rows = matrix.size();
        if (rows == 0) return result;
        int cols = matrix[0].size();

        unordered_set<int> optimization;

        for (int i = 0; i < cols; ++i) {
            // Find the maximum in column i
            pair<int, int> colMax = make_pair(-1, INT_MIN); // (row index, value)
            for (int r = 0; r < rows; ++r) {
                if (matrix[r][i] > colMax.second) {
                    colMax.first = r;
                    colMax.second = matrix[r][i];
                }
            }

            if (optimization.find(colMax.first) != optimization.end()) {
                continue;
            }

            // Find the minimum in row colMax.first
            pair<int, int> rowMin = make_pair(-1, INT_MAX);
            for (int c = 0; c < cols; ++c) {
                if (matrix[colMax.first][c] < rowMin.second) {
                    rowMin.first = c;
                    rowMin.second = matrix[colMax.first][c];
                }
            }

            if (rowMin.first == i) {
                result.push_back(rowMin.second);
                optimization.insert(colMax.first);
            }
        }

        return result;
    }
};