class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int i = 0, j = 0;
        int count = 0;
         
        while(i<a.size() && j<b.size()){
            
            if(a[i]<b[j]){
                count++;
                if(count==k) return a[i];
                i++;
            }
            else{
                count++;
                if(count==k) return b[j];
                j++;
            }
        }
        
        while(i<a.size()){
            count++;
            if(count==k) return a[i];
            i++;
        }
        
        while(j<b.size()){
            count++;
            if(count==k) return b[j];
            j++;
        }
        
        return count;
    }
};
// Time Complexity: O(k)
// Space Complexity: O(1)

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n = a.size(), m = b.size();
        if(n>m) return kthElement(b, a, k);
        
        int low = max(0,k-m), high = min(k,n);
        
        while(low<=high){
            
            int mid1 = low + (high-low)/2;
            int mid2 = k-mid1;
            
            int l1 = (mid1 == 0 ? INT_MIN : a[mid1-1]);
            int r1 = (mid1 == n ? INT_MAX : a[mid1]);
            
            int l2 = (mid2 == 0 ? INT_MIN : b[mid2-1]);
            int r2 = (mid2 == m ? INT_MAX : b[mid2]);
            
            if(l1<=r2 && l2<=r1) return max(l1,l2);
            
            l1>r2 ? high = mid1-1 : low = mid1+1;
        }
        
        return 0; 
    }
};
// Time Complexity: O(log(min(n,m)))
// Space Complexity: O(1)