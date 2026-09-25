class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // int n = numbers.size();
        // int l = 0;
        // int r = n-1;
        // while( l<r ){
        //     int sum = numbers[l] + numbers[r] ;
        //     if( sum == target ){
        //         return { l+1, r+1 };
        //     } else if( sum > target ){
        //         r--;
        //     }else{
        //         l++;
        //     }
        // }
        // return {};
        int n = numbers.size();
        unordered_map<int, int> mp;
        for( int i=0; i<n; i++ ){
            int more = target - numbers[i];
            if( mp.find(more) != mp.end() ){
                return {mp[more]+1, i+1};
            }
            mp[numbers[i]] = i ;
        } 
        return {};
    }
};
