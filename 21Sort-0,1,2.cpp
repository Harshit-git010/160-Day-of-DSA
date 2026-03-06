class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int num0=0, num1=0, num2=0;
        
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i]==0) num0++;
            else if(arr[i]==1) num1++;
            else if(arr[i]==2) num2++;
        }
        
        arr.clear();
        
        while(true){
            
            if(num0!=0) arr.push_back(0),num0--;
            else if(num1!=0) arr.push_back(1),num1--;
            else if(num2!=0) arr.push_back(2),num2--;
            
            if(num0==0 && num1==0 && num2==0) break;
            
        }
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {

        int left = 0 , mid = 0 , high = nums.size()-1;

        while(mid<=high){

            if(nums[mid]==0){
                swap(nums[left],nums[mid]);
                left++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[high],nums[mid]);
                high--;
            }
            else mid++;
        }
    }
};
    