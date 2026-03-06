// Brute force

class Solution {
  public:
    bool isTriangle(int a, int b, int c){
        if(a+b > c) return true;
        else return false;
    }
    
    int countTriangles(vector<int>& arr) {
        // code here
        int ans = 0;
        sort(arr.begin(),arr.end());
        
        for(int i = 0 ; i<arr.size(); i++){
            for(int j = i+1 ; j<arr.size()-1 ; j++){
                
                int right = j+1;
                
                while(isTriangle (arr[i],arr[j],arr[right]) == true && right<arr.size()){
                    right++;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

// Complexity n^3 & O(1)

// Optimal Solution

class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int ans = 0;
        sort(arr.begin(),arr.end());
        
        // we here are taking the largest length size 
        // and comparing if triangle are possible with this 
        for(int i = 2; i<arr.size() ; i++){
            
            int left = 0, right = i-1;
            
            while(left<right){
                
                if(arr[left]+arr[right] > arr[i]){
                    
                    // if arr[left]+arr[right] > arr[i] is true 
                    // then it is true for all (x,right)
                    // where left <= x < right
                    
                    ans+=(right-left);
                    right--;
                }
                else{
                    left++;
                }
                
            }
        }
        
        return ans;
    }
};

// Complexity of n^2 and O(1)