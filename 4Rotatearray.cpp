//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        
        int size = arr.size();
        
        // loop to reduce d size
        
        while(d>size){
            d=d-size;
        }
        
        if(d==size){
            //do nothing
        }
        else{
            // loop to assign value in second array
            int a[d];
            
            for( int i = 0 ; i<d ; i++){
                a[i]=arr[i];
            }
            
            // loop to shift values to the left
            
            for(int j = 0 ; j<size-d ; j++){
                arr[j]=arr[j+d];
            }
            
            // loop to assign values at last
            
            for(int k=0 ; k<d ;k++){
                arr[size-d+k] = a[k];
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        // calling rotateArr() function
        ob.rotateArr(arr, d);

        // printing the elements of the array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends