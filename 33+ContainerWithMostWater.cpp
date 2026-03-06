class Solution {
public:
    int maxArea(vector<int>& height) {

        int pil1 = 0, pil2 = height.size()-1;
        int maxCap = 0;

        while(pil1<pil2){

            int h = min(height[pil1],height[pil2]);
            maxCap = max(maxCap, (h*(pil2-pil1)) );

            if(height[pil1]<height[pil2]) pil1++;
            else pil2--;
        }
        return maxCap;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)