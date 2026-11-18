class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        /* BRUTE APPROACH :
                int maxArea = 0;
                for( int i=0; i<n; i++ ){
                    int left = i;
                    int right = i;

                    while( left>=0 && heights[left] >= heights[i] ){
                        left--;
                    }
                    while( right<n && heights[right] >= heights[i] ){
                        right++;
                    }

                    int width = right - left - 1;
                    int area = heights[i] * width;
                    maxArea = max(maxArea, area);
                }
                return maxArea;
        */

        // MONOTONIC STACK BETTER APPROACH USING PSE AND NSE
        vector<int> pse(n), nse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

/*
FORMULA:
Height = min(h1, h2, h3, ..., hn); // Minimum bar height
Width = number of consecutive bars;
Area = height * width;


*/