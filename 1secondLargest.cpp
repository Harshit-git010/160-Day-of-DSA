//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
      
      // to find the largest
      
      int largest=arr[0];
      int size = arr.size();
      for(int i = 0; i<size ; i++){
          if(arr[i]>largest){
              largest=arr[i];
          }
      }
      
      // to find the second largest
      
      // initialise temp
      
      int temp = largest;
      
      for(int j=0 ; j<size ; j++){
          if(arr[j]<largest){
              temp=arr[j];
              break;
          }
       }
       
       
       if(temp == largest){
           return -1;
       }
       else{
            for(int k=0 ; k<size ; k++){
              if( arr[k]<largest && arr[k]>temp){
                  temp = arr[k];
              }
            }
            return temp;
       }
      
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends