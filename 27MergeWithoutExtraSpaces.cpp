class Solution {
  public:
  
    void merge(vector<int> &a, vector<int> &b){
        
        int i = 0 , j = 0;
        int n = a.size() , m = b.size();
        
        while(i<n && j<m){
            if(a[i]<=b[j]) i++;
            else{
                swap(a[i],b[j]);
                i++, j++;
            } 
        }
        
        if(j!=0) merge(a,b);
        else sort(b.begin(),b.end());
    }
    
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        merge(a,b);
    }
};
// Time Complexity: O((n+m)*log(n+m))
// Space Complexity: O(1)

// Optimal Solution : Using Gap Method

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        
        int n = a.size(), m = b.size();
        int gap = (n+m+1)/2;
        
        while(gap>0){
            
        int i = 0, j = gap;
            
            while(j<n+m){
                
                // if i and j are in a[]
                if(j<n && a[i]>a[j]){
                    swap(a[i],a[j]);
                }
                // if i is in a[] and j is in b[] 
                else if(i<n && j>=n && a[i]>b[j-n]){
                    swap(a[i],b[j-n]);
                }
                // if both i and j is in b[]
                else if(i>=n && b[i-n]>b[j-n]){
                    swap(b[i-n],b[j-n]);
                }
                
                i++, j++;
            }
            
            if(gap==1) break;
            gap = (gap+1)/2;
        }
    }
};
// Time Complexity: O((n+m)*log(n+m))
// Space Complexity: O(1)