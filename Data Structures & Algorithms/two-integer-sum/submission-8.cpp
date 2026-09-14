class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // int sum = 0;
        // int i= 0;
        // int j= n-1;
        // while( i<j ){
        //     sum = nums[i] + nums[j];
        //     if( sum == target ){
        //         return {i,j};
        //     }else if( sum > target ){
        //         j--;
        //     }else{
        //         i++;
        //     }
        // }
        //  return {i,j};
        int n = nums.size();
        unordered_map<int, int> mp;
        for( int i=0; i<n; i++ ){
            int need = target - nums[i];
            if( mp.find(need) != mp.end() ){
                return {mp[need], i};
            }
            mp[nums[i]] = i;
        }  
        return {};
    }
};
