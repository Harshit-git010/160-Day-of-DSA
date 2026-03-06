#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){

    vector<int> arr = {100, 180, 260, 310, 40, 535, 695};
    
    int hold = 0, profit = 0;

    for(int i = 1; i<arr.size() ; i++){
        if(arr[i]>arr[i-1]){
            profit+= ( arr[i] - arr[i-1] );
        }
    }

    cout << profit << " " ;
    
}

