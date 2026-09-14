class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int>freqS;
        for( int ch : s ){
            freqS[ch]++;
        }
        map<char, int> freqT;
        for( int ch : t ){
            freqT[ch]++;
        }
        if( freqS == freqT ){
            return true;
        }
        return false;
    }
};
