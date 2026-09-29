class Solution {
public:
    int trap(vector<int>& height) {

        int l = 0;
        int r = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while(l < r) {

            if(height[l] <= height[r]) {

                // Left side ka maximum update karo
                if(height[l] >= leftMax)
                    leftMax = height[l];

                else
                    water += leftMax - height[l];

                l++;
            }

            else {

                // Right side ka maximum update karo
                if(height[r] >= rightMax)
                    rightMax = height[r];

                else
                    water += rightMax - height[r];

                r--;
            }
        }

        return water;
    }
};