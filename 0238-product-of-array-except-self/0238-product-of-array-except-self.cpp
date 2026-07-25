class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       // brute force approch   time compelxity = 0(n^2) for appropriate
        //   int n=nums.size();
        //   vector<int>ans(n , 1);
        //   for(int i=0; i<n; i++){
           
        //     for(int j=0; j<n; j++){
        //         if(i != j){
        //            ans[i] = ans[i]*nums[j];
        //         }
               

        //     }
        //   }  
        //   return ans;

        //optimal approch
        // int n = nums.size();
        // vector<int>ans(n , 1);
        // vector<int>prefix(n , 1);
        // vector<int>sufix(n , 1);

        // for(int i=1; i<n; i++){
        //     prefix[i] = prefix[i-1]*nums[i-1];
        // } 

        // for(int i=n-2; i>=0; i--){
        //     sufix[i] = sufix[i+1]*nums[i+1]; 
        // }

        // for(int i=0; i<n; i++){
        //     ans[i] =   prefix[i]*sufix[i];
        // }
        // return ans;

        //more optimal approch
         int n = nums.size();
        vector<int>ans(n , 1);
       

        for(int i=1; i<n; i++){
            ans[i] = ans[i-1]*nums[i-1];
        } 
                int suffix=1;
        for(int i=n-2; i>=0; i--){
           suffix *= nums[i+1]; 
           ans[i] = ans[i]*suffix;
        }

        return ans;
    }
};