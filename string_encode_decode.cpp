class Solution {
public:
    string encode(vector<string>& strs) {
        string encoding = "";
        for (const string &str : strs) encoding += str + "/";
        return encoding;
    }

    vector<string> decode(string s) {
        vector<string> decoding;
        string str = ""; 
        for (const char &c : s) {
            reg = regex ("/./g")
            if (regex.find(c, reg)) str += c;
            else {
                decoding.push_back(str);
                str = "";
            }
        } 
    }
};