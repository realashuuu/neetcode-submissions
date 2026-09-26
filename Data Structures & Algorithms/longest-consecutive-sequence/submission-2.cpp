class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        // int n = nums.size();
        // if (n == 0) return 0;
        int longest = 0;
        int cnt = 0;
        // sort(nums.begin(), nums.end());
        // int predecessor = INT_MAX;
        // for( int i=0; i<n; i++ ){
        //     if( nums[i]-1 == predecessor ){
        //         cnt+=1;
        //         predecessor = nums[i];
        //     }else if( nums[i] !=  predecessor ){
        //         cnt= 1;
        //         predecessor = nums[i];
        //     }

        unordered_set<int> st(nums.begin(), nums.end());
        for (int i : st) {
            // this condition means it will check in the set that i-1 is present or not is this make
            // true means not present then it will start from i so it will make current element to
            // start to i nd cnt++
            if (st.find(i - 1) == st.end()) {
                int current = i;
                cnt = 1;
                while (st.find(current + 1) != st.end()) {
                    current++;
                    cnt++;
                }
        longest = max(cnt, longest);
            }
        }
    return longest;
    }

};
