class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        priority_queue<short> highest_prob;

        for (short i = 0; i < edges.size(); i++) {
            if (edges[i][0] == start_node) {
                if (edges[i][1] == end_node) {
                    highest_prob.push(succProb[i]);
                    continue;
                }

                // we want to check each 


            } else if (edge[1] == start_node) {

            }
        }


    }
};