class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        
        int count = 0;
        for( int i = 0 ; i<arr.size() ; i++){
            if(arr[i]==target) count++;
        }
        
        return count;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)

// Better Approach 1

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        
        int count = 0;
        int left = 0 , right = arr.size()-1;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            
            if(arr[mid]==target){
                
                int i = mid;
                while(true){
                    if(arr[i]!=target || i<0) break;
                    count++;
                    i--;
                }
                int j = mid+1;
                while(true){
                    if(arr[j]!=target || j>arr.size()-1) break;
                    count++;
                    j++;
                }
                break;
            }
            else if(target<arr[mid]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return count;
    }
};
// Time complexity: O(log n) for binary search + O(k) where k is the number of occurrences of the target 
// OR O(n) in worst case when all elements are same as target
// Space complexity: O(1) as we are using only constant extra space

// Optimal approach 

class Solution {
public:
    int firstOccurrence(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                ans = mid;
                right = mid - 1;  // keep going left
            } 
            else if (target < arr[mid]) {
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int lastOccurrence(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                ans = mid;
                left = mid + 1;  // keep going right
            } 
            else if (target < arr[mid]) {
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int countFreq(vector<int>& arr, int target) {
        int first = firstOccurrence(arr, target);
        if (first == -1) return 0; // target not found
        int last = lastOccurrence(arr, target);
        return last - first + 1;
    }
};

