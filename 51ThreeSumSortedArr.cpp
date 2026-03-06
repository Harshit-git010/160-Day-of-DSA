class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int count = 0;
        
        for(int i = 0; i<arr.size()-2 ; i++){
            
            int left = i+1, right = arr.size()-1;
            while(left<right){
                
                int sum = arr[i] + arr[left] + arr[right];
                
                if(sum<target){
                    left++;
                }
                else if(sum>target){
                    right--;
                }
                else if(sum == target){
                    int cnt1 = 0, cnt2 = 0;
                    int ele1 = arr[left], ele2 = arr[right];
                    
                    while(left<=right && arr[left]==ele1){
                        cnt1++,left++;
                    }
                    while(left<=right && arr[right]==ele2){
                        cnt2++,right--;
                    }
                    
                    if(ele1==ele2){
                        count+=(cnt1*(cnt1-1))/2;
                    }
                    else count+=(cnt1*cnt2);
                }
            }
        }
        return count;
    }
};

// Time Complexity: O(n^2) where n is the number of elements in the array
// Space Complexity: O(1)