class Solution {
public:
    bool isPalindrome(string s) {

        string ans = "";
        for(int i=0; i<s.size(); i++){
            s[i] = tolower(s[i]);
            if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9'){
                ans += s[i];            
            }
        }
        int left = 0;
        int right = ans.size()-1;

        while(left<right){
            if(ans[left]!=ans[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};