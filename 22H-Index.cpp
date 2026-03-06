class Solution {
public:
    int hIndex(vector<int>& citations) {

        int count = 0;
        
        sort(citations.begin(),citations.end());

        reverse(citations.begin(),citations.end());

        int i = 0;
        while(citations[i]>=i+1){
            count = i+1;
            i++;
            if(i==citations.size()) break;
        }

        return count;
    }
};

// Time Complexity: O(nlogn) due to sorting
// Space Complexity: O(1) as we are using constant space

class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        
        int n = citations.size();
        vector<int> arr(n+1,0);
        
        int i = 0;
        
        while(i<n){
            
            citations[i]>=n ? arr[n]+=1 : arr[citations[i]]+=1;
            i++;
        }
        
        i = n;
        int count = 0;
        
        while(i>=0){
            count+=arr[i];
            if(count>=i) return i;
            i--;
        }
        
        return count;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n) due to the additional array used for counting citations