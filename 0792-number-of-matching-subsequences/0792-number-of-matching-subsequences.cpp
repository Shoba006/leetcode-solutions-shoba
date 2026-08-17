class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // 26 boards (a-z), EACH entry = {wordIndex, matched}
        vector<vector<pair<int,int>>> boards(26);

        // each  word first  char in the  board 
        for (int i = 0; i < words.size(); i++) {
            boards[words[i][0] - 'a'].push_back({i, 0});
        }

        int count = 0;

        // s  scan
        for (char c : s) {
            int idx = c - 'a';
            vector<pair<int,int>> waiting = boards[idx];
            boards[idx].clear();               // empty board

            for (auto& entry : waiting) {
                int wordIdx = entry.first;
                int matched = entry.second + 1;

                if (matched == words[wordIdx].size()) {
                    count++;                    // word poora
                } else {
                    char next = words[wordIdx][matched];
                    boards[next - 'a'].push_back({wordIdx, matched});
                }
            }
        }

        return count;
    }
};