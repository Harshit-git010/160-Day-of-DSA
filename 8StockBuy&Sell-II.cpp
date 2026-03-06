#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {


        int max = prices[0];
        int min = prices[0];

        int profit = 0;

        for(int i = 0 ; i<prices.size()-1 ; i++){

            if(prices[i+1]<prices[i] && i+1 == prices.size()-1){
                if(max-min > 0) profit += max-min;
                min = prices[i+1] , max = 0;
            }

            else if(prices[i+1]<prices[i]){
                if(max-min > 0) profit += max-min;
                min = prices[i+1] , max = 0;
            }

            else if(prices[i+1]>=prices[i] && i+1 == prices.size()-1){
                max = prices[i+1];
                profit+= max-min;
            }

            else if(prices[i+1]>prices[i]){
                max = prices[i+1];
            }
            
        }

    return profit;
    
    }
};