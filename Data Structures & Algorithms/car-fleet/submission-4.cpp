class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector < pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());  // sort by position descending

        stack<double> st;
        // OR
        //  int fleets = 0;
        //  double previousTime = 0;

        for (int i = 0; i < n; i++) {
            
            double time = (double)(target - cars[i].first) / cars[i].second;

            // A new fleet is formed only if this car cannot catch the fleet ahead.
            // if (currentTime > previousTime) {
            //     fleets++;
            //     previousTime = currentTime;
            // }
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }
        // return fleets;
        return st.size();
    }
};

/*
Sort cars in descending order of position. Because we must process the car closest to the
destination first, followed by the cars behind it.

1.currentTime <= previousFleetTime: It joins the fleet ahead.
2.currentTime > previousFleetTime: It creates a new fleet.

Every time a car creates a new fleet, increment the answer and update the previous fleet’s arrival
time.

Time Complexity: O(n log n) because of sorting.
Space Complexity: O(n) for storing cars and fleet arrival times.
*/
