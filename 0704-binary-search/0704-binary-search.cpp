class Solution {
public:

    int binarySearch(vector<int>& nums, int target , int st , int end){
       if(st <= end){
       int mid = st + (end-st)/2;

       if(nums[mid] == target){
        return mid;
       } 
       else if(nums[mid] <= target){
        return binarySearch(nums , target , mid + 1 , end);
       }else{
        return binarySearch(nums , target , st , mid - 1);
       }

    }
    return -1;
    }

    int search(vector<int>& nums, int target) {
        // by binary search
        // int mid;
        // int start=0;
        // int n = nums.size();
        // int end = n-1;
        // while(start <= end){
        //   mid = start + (end-start)/2;
        //     if(target > nums[mid]){
        //         start= mid+1;
        //     }
        //     else if(target < nums[mid]){
        //         end=mid-1;
        //     }
        //     else{
        //         return mid;

        //     }

        // }
        // return -1;




    //    by recursive binary search--
    return binarySearch(nums,  target , 0 , nums.size()-1);
   
    }
};