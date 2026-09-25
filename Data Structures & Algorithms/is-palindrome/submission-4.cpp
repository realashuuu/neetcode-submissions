class Solution {
   public:
   bool isvalid( char ch){
    return ( ch>='a' && ch<='z' ||
             ch>='A' && ch<='Z' ||
             ch>='0' && ch<='9');
   }
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {

            if (!isvalid(s[l])) {
                l++;
                continue;
            } 
            if (!isvalid(s[r])) {
                r--;
                continue;
            } 
            //tolower make the captial to samller alph so it can check smotohly 
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
