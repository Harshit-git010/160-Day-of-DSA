class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> max_left_height(n, 0);
        vector<int> max_right_height(n, 0);

        // Fill max_left_height
        for (int i = 1; i < n; i++) {
            max_left_height[i] = max(max_left_height[i - 1], height[i - 1]);
        }

        // Fill max_right_height
        for (int i = n - 2; i >= 0; i--) {
            max_right_height[i] = max(max_right_height[i + 1], height[i + 1]);
        }

        // Calculate trapped water
        int waterCap = 0;
        for (int i = 0; i < n; i++) {
            int temp = min(max_left_height[i], max_right_height[i]) - height[i];
            if (temp > 0) waterCap += temp;
        }

        return waterCap;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        if (n == 0) return 0;

        int low = 0, high = n-1;
        int lmax = 0, hmax = 0;

        int water = 0;

        while(low<high){

            lmax = max(lmax,height[low]);
            hmax = max(hmax,height[high]);

            if(lmax <= hmax){
                water += lmax - height[low];
                low++;
            }

            else{
                water += hmax - height[high];
                high--;
            }
            
        }

        return water;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)