// Brute Force

bool check(vector<int> &arr, int k, int pageLimit) {
    
    // starting from the first student
    int cnt = 1;
    int pageSum = 0;
    for(int i = 0; i < arr.size(); i++) {
        
        // if adding the current book exceeds the page 
        // limit, assign the book to the next student
        if(pageSum + arr[i] > pageLimit) {
            cnt++;
            pageSum = arr[i];
        }
        else {
            pageSum += arr[i];
        }
    }
    
  	// if books can assigned to less than k students then
    // it can be assigned to exactly k students as well
    return (cnt <= k);
}

int findPages(vector<int> &arr, int k) {
    
    // if number of students are more than total books
    // then allocation is not possible
    if(k > arr.size())
        return -1;
        
    // minimum and maximum possible page limits
    int minPageLimit = *max_element(arr.begin(), arr.end());
    int maxPageLimit = accumulate(arr.begin(), arr.end(), 0);
    
    // iterating over all possible page limits
    for(int i = minPageLimit; i <= maxPageLimit; i++) {
        
        // return the first page limit with we can
        // allocate books to all k students
        if(check(arr, k, i))
            return i;
    }
    
    return -1;
}

// Time Complexity: O(N * M) where N is the number of books and M is the sum of all pages in the books.
// Space Complexity: O(1)

// Optimal Approach: Binary Search

class Solution {
  public:
  
    bool check(vector<int> &arr, int pageLimit, int k){
        int pageSum = 0;
        int count = 1;
        
        for(int i = 0 ; i<arr.size() ; i++){
            
            if(pageSum + arr[i] > pageLimit){
                count++;
                pageSum = arr[i];
            }
            else{
                pageSum+=arr[i];
            }
        }
        
        return (count<=k);
        
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int ans = arr[0];
        if(arr.size() < k) return -1;
        
        int low = 0; // largest value in arr
        for(int i = 0 ; i<arr.size() ; i++){
            low = max(low,arr[i]);
        }
        
        int high = 0; // total sum of arr
        for(int i = 0 ; i<arr.size() ; i++){
            high+=arr[i];
        }
        
        while(low<=high){
            
            int mid = low + (high-low)/2;
            
            if(check(arr,mid,k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};

// Time Complexity: O(N log M) where N is the number of books and M is the sum of all pages in the books.