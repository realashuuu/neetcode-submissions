class Solution {
public:

    string encode(vector<string>& strs) {

            string encode = "";
            for( string s : strs ){
                encode  += to_string(s.size()) + '#' + s ;
                        // "5" + "#" + "Hello"
            }
            return encode;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
         while( i < s.size() ){
            int j = i;
            while( s[j] != '#' ){
                j++;
            }
            string lengthString = s.substr(i, j-i);
            int length = stoi(lengthString) ;
            string word = s.substr( j+1, length );
            ans.push_back(word);
            i = j + 1 + length;
         }
        return ans;
    }
};
