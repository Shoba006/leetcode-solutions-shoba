class Solution {
public:
    bool palindrome(string &s, int left, int right, bool deleted){

        if(left>=right){
            return true;
        } 
        if(s[left]==s[right]){
            return palindrome(s,left+1, right-1, deleted);
        }
        if(deleted == true){
            return false;
        }
        return palindrome(s, left+1, right,true) ||
        palindrome(s, left, right-1,true);
    }
    bool validPalindrome(string s) {
        return palindrome(s, 0, s.size()-1, false);
    }
};