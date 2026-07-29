class Solution {
public:
    int findDuplicate(vector<int>& nums) {

    //   unordered_set<int>s;      // {  TC -- 0(n)  and SC -- 0(n)}

    //   for(int val : nums){
    //     if(s.find(val) != s.end()){
    //             return val;
    //     }
    //     s.insert(val);
    //   }
    //   return -1;
      

        int slow = nums[0];          // {  TC -- 0(n)  and SC -- 0(1)}
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = nums[0];

        while(slow != fast){

        slow = nums[slow];
        fast = nums[fast]; 
        }
        return slow;
    }
};