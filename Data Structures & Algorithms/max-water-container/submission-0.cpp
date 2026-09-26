class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n - 1;
        int mostWater = 0;
        while (l < r) {
            int width = r - l;
            int height = min(heights[l], heights[r]);
            mostWater = max(mostWater, (width * height));
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return mostWater;
    }
};
// Left height = 1
// * Right height =6
// * Width = 7 - 1 = 6
// * Water height = min(1,6) = 1
// mostwater = 6*1 =6