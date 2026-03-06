#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int countPairs(vector<int> &arr, int target){
    // Complete the function
    int count = 0;
    
    int left = 0, right = arr.size()-1;
    
    while(left<right){
        
        int sum = arr[left] + arr[right];
        
        if(sum==target){
            
            if(arr[left]==arr[right]){
                int num = right-left;
            
                count+=(num*(num+1))/2;
                break;
            }
            
            else{
                int freq1 = 1, freq2 = 1;
                while(arr[left]==arr[left+1] && left<right){
                    left++, freq1++;
                } 
                while(arr[right]==arr[right-1] && left<right){
                    right--, freq2++;
                } 
                
                count+=(freq1*freq2);
            }
            
            left++,right--;
        }
        
        else if(sum>target){
            right--;
        }
        
        else if(sum<target){
            left++;
        }
    }
    
    
    return count;
}

int main(){

    vector<int> arr = {-17, -15, -13, -9, -4, 0, 0, 0, 1, 5, 9, 12, 18, 18};

    int ans = countPairs(arr,0);

    cout << ans  << " " ;
    
}

