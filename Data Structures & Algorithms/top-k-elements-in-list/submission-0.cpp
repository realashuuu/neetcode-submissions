class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        for( int i : nums){
            freq[i]++; //count frequency 
        }
        priority_queue<
                pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>
            > pq;
        for( auto it : freq ){
            pq.push({it.second, it.first});

            if( pq.size() > k ){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
/*pair → what?
vector → storage
greater → min-heap
pq.top() → smallest frequency
pq.pop() → remove smallest frequency*/