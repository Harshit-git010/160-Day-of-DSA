class Solution {
  public:
  
    int merge(vector<int> &arr , int st , int mid , int end){
        
        int i = st, j = mid+1;
        
        vector<int> temp;
        
        int ans = 0;
        
        // left size = mid-st+1
        // right size = end-mid
        
        while(i<=mid && j<=end){
            
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                ans += ( (mid+1) - i);
                j++;
            }
        }
        
        while(i<=mid){
            temp.push_back(arr[i]);
                i++;
        }
        while(j<=end){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int i = 0 ; i<temp.size() ; i++){
            arr[st+i] = temp[i];
        }
        
        return ans;
    }
  
    int merge_sort(vector<int> &arr , int st , int end){
        
        int ans = 0;
        if(st<end){
            int mid = st + (end-st)/2;
            
            ans += merge_sort(arr , st , mid);
            ans += merge_sort(arr , mid+1 , end);
            
            ans += merge(arr , st , mid , end);
            
        }
        
        return ans;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        
        return merge_sort(arr , 0 , arr.size()-1);
    }
};
// Time Complexity: O(n log n)
// Space Complexity: O(n) due to the temporary array used in merge function