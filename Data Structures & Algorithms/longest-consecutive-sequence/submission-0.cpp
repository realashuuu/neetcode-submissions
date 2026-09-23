class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 ) return 0;
        int longest =0;
        int cnt = 0;
        sort(nums.begin(), nums.end());
        int predecessor = INT_MAX;
        for( int i=0; i<n; i++ ){
            if( nums[i]-1 == predecessor ){
                cnt+=1;
                predecessor = nums[i];
            }else if( nums[i] !=  predecessor ){
                cnt= 1;
                predecessor = nums[i];
            }
            longest = max( cnt, longest );

        }
        return longest;
    }
};
