#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){

    // optimal approach
    
    vector<int> arr = {2,4,1,7,5,0};
    
    int n = arr.size();

    int pivot = -1;
    for(int i = n-1; i>0 ; i--){
    
        if(arr[i-1]<arr[i]){
            pivot = i-1;
            break;
        }

    }

    if(pivot==-1){
        reverse(arr.begin(),arr.end());
    }

    // find the next greater element
    for(int i = n-1 ; i>pivot ; i--){
        if(arr[i]>arr[pivot]){
            swap(arr[pivot],arr[i]);
            break;
        }
    }
    // reverse from i to n-1
    reverse(arr.begin()+pivot+1,arr.end());


    for(int i = 0; i<n ; i++){
        cout<< arr[i] << " " ;
    }
}




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

    class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        
        //check if given array is last permutation
        
        int size = arr.size();
        int pivot = size-3;
        
        // condition if size <3
        
        if(size==2){
            swap(arr[0],arr[1]);
            return;
        }
        
        if (size<2){
            return;
        }
        
            bool isdesending = true;
          for( int i = 1; i<size ; i++){
            if (arr[i]>arr[i-1]){
             isdesending = false;
             break;
            }
          }
            
            
            if(isdesending){
                // asending order
               sort(arr.begin(),arr.end());
               return;
            }
            
             for( int i=size-2 ; i>=0 ; i--){
                 if(arr[i]<arr[i+1]){
                     next_permutation(i,size,arr);
                     return;
                 }
             }
    }
    
    // code for recursive function
    
    void next_permutation(int pivot, int size,vector<int>& arr){
        
        // asending
        
        if(arr[pivot]==arr[size-3] && arr[size-1]>arr[size-2]){
            // swap
            int temp;
            temp = arr[size-1];
            arr[size-1]=arr[size-2];
            arr[size-2]=temp;
        }
        
        // desending 
        else { 
            
            
            int store = INT_MAX;
            int index=-1 ;
            
            // to find largest element in remaining array
            
              for( int i = size-1 ; i>pivot ;i--){
                   if(store>arr[i] && arr[i]>arr[pivot]){
                    
                   store=arr[i]; // largest element
                   index = i;  // index of largest element
                    }
              }
              
              if(store>arr[pivot]){
              
                    // swap pivot to next greater element
                 swap(arr[pivot],arr[index]);
                    
                    // after pivot , sort them in ascending order
                 for(int l = pivot+1 ; l<size ; l++){
                    for(int k=pivot+1 ; k<size-1 ; k++){
                     if(arr[k]>arr[k+1]){
                        swap(arr[k],arr[k+1]);
                     }
                    }
                 }
                 
              }
              
              else {
                   pivot--;
            next_permutation(pivot,size,arr);
              }
         
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends