class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int n = nums.size();
        // for(int i=0; i<n-1; i++){
        //     for(int j=0; j<n-i-1; j++){
        //         if(nums[j] > nums[j+1]){
        //             swap(nums[j] , nums[j+1]);
        //         }
        //     }
        // }

        // int n = nums.size();
        // for(int i=0; i<n-1; i++){
        //     int smallestIndex = i;
        //     for(int j=i+1; j<n; j++){
        //         if(nums[j] < nums[smallestIndex]){
        //             smallestIndex = j;
        //         }
        //     }
        //     swap(nums[i] , nums[smallestIndex]);
        // }

        int n = nums.size();
        for(int i=1; i<n; i++){
            int curr = nums[i];
            int prev = i-1;
            while(prev >= 0 && nums[prev] > curr){
                nums[prev + 1] = nums[prev];
                prev--;
            }
            nums[prev + 1] = curr;
        }
    }
};