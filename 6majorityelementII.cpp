#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){

    vector<int> arr = {-5, 3, -5};
    
    vector<int> ans;

    // There are only atmost two elements which appear more than n/3 times
    // finding out which two elements will be the majority

    int ele1 = arr[0], ele2 = arr[0];
    int freq1 = 0, freq2 = 0;

    for(int i = 0; i<arr.size() ; i++){

        if(arr[i]==ele1){
            freq1++;
        }
        else if(arr[i]==ele2){
            freq2++;
        }
        else if (freq1==0){
            ele1 = arr[i];
            freq1++;
        }
        else if(freq2==0){
            ele2 = arr[i];
            freq2++;
        }
        else{
            freq1--, freq2--;
        }
        
    }

    // counting occurences of both the elements

    freq1 = 0, freq2 = 0;

    for(int ele : arr){
        if(ele = ele1) freq1++;
        else if(ele = ele2) freq2++;
    }

    if(freq1 > arr.size()/3) ans.push_back(ele1);
    if(freq2 > arr.size()/3) ans.push_back(ele2);


    if(ele1>ele2 && ans.size()==2){
        swap(ans[0],ans[1]);
    }
    
    for(int ele : ans){
        cout << ele << " " ;
    }
}

