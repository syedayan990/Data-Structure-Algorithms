class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        // vector<vector<int>> ans;     // TC is too hight so we need to solve this with iffernt approch 
        // set<vector<int>>s;
       
        // int n=nums.size();
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         for(int k=j+1; k<n; k++){
        //             if((nums[i] + nums[j] + nums[k]) == 0){
        //             vector<int>trip = {nums[i],nums[j],nums[k]};
        //             sort(trip.begin() , trip.end());

        //             if(s.find(trip) == s.end()){
        //                 s.insert(trip);
        //                 ans.push_back(trip);
        //             }
        //             }
                    
        //         }
           
        //     }
        // }
        //      return ans;


       //----------------------------------------------------------
        
        // set<vector<int>> uniqueTriplet;         // TC -- 0(n^2 logn)

        // int n=nums.size();
        
        // for(int i=0; i<n; i++){
        //     int tar = - nums[i];
        //     set<int>s;
        //     for(int j=i+1; j<n; j++){
        //         int toFind = tar - nums[j];
        //         if(s.find(toFind) != s.end()){
        //             vector<int> trip = {nums[i] , nums[j] , toFind};
        //             sort(trip.begin() , trip.end());
        //             uniqueTriplet.insert(trip);
        //         }
        //        s.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>>ans(uniqueTriplet.begin() , uniqueTriplet.end());
        // return ans;
        

         
        vector<vector<int>>ans;
        int n = nums.size();

       sort(nums.begin() , nums.end());

        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j=i+1; 
            int k=n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
               if(sum < 0) {j++;}
               else if(sum > 0) {k--;}
               else{
                ans.push_back({nums[i] , nums[j] , nums[k]});
                j++; 
                k--;

                while(j < k && nums[j] == nums[j-1]){
                    j++;
                }
               }
                
            }
        }
        return ans;
    }
};