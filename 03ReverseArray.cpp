//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        
        int size = arr.size();
        
        for(int i = 0 ; i<size/2 ; i++){
            int temp;
            
            temp = arr[i];
            arr[i]=arr[size-i-1];
            arr[size-i-1] = temp;
            
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
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends