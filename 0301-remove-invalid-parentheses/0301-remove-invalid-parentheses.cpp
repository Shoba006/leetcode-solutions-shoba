class Solution {
public:
    vector<string> ans;

    bool valid(string s) {
        int count = 0;

        for (char c : s) {
            if (c == '(')
                count++;
            else if (c == ')') {
                count--;

                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    void solve(string s, int index, int remove) {
        if (remove == 0) {
            if (valid(s))
                ans.push_back(s);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (i > index && s[i] == s[i - 1])
                continue;

            if (s[i] != '(' && s[i] != ')')
                continue;

            string temp = s;
            temp.erase(i, 1);

            solve(temp, i, remove - 1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0;
        int right = 0;

        for (char c : s) {
            if (c == '(') {
                left++;
            } 
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        solve(s, 0, left + right);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};