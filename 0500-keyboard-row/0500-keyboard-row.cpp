class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;

        int row[26];

        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";

        for(char c : r1)
            row[c - 'a'] = 1;

        for(char c : r2)
            row[c - 'a'] = 2;

        for(char c : r3)
            row[c - 'a'] = 3;

        for(string word : words) {
            int firstRow = row[tolower(word[0]) - 'a'];
            bool valid = true;

            for(char c : word) {
                if(row[tolower(c) - 'a'] != firstRow) {
                    valid = false;
                    break;
                }
            }

            if(valid)
                ans.push_back(word);
        }

        return ans;
    }
};