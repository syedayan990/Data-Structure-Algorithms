class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //using brute force method
    //     int n=nums.size();
    //     for(int val : nums){
    //         int freq=0;
    //         for(int element: nums ){
    //             if(element == val){
    //                 freq++;
    //             }
    //         }
    //         if(freq > n/2){
    //             return val;
    //         }
    //     }
    //    return -1; 

    //using sorting mathod 
      
    // sort(nums.begin() , nums.end());
    // int ans;
    //  int freq=1;
    //   ans=nums[0];
    //   int n = nums.size();
    //   for(int i=1; i<n; i++){
    //      if(nums[i]==nums[i-1]){
    //         freq++;
    //      }
    //      else{
    //         freq=1;
    //         ans=nums[i];
    //      }
    //      if(freq > n/2){
    //         return ans;
    //      }
    //   }
    //   return ans;
      
    
    //using moore's voting method
    int n = nums.size();
    int ans=nums[0];
    int freq = 0;

    for(int i=0; i<n; i++){
        if(freq==0){
            ans=nums[i];
        }
        if(ans==nums[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    return ans;
    }
};