class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> cwd;

        for (const string &log : logs) {
            if (log == "../") {
                if (cwd.empty()) continue;

                cwd.pop();
            } 
            else if (log == "./") {
                continue;
            } 
            else {
                cwd.push(log);
            }
        }


        return cwd.size();
    }
};