class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int n = nums.size();       // TC - 0(n^2);
        // int count = 0;

        // for(int i=0; i<n; i++){
        //     int sum = 0;
        //     for(int j=i; j<n; j++){
        //         sum += nums[j];
        //         if(sum == k){
        //             count++;
        //         }
        //     }
        // }
        // return count;


        int n = nums.size();
        vector<int>prifixSum(n , 0);
        int count = 0;

         prifixSum[0] = nums[0];
        for(int i=1; i<n; i++){
           prifixSum[i] = prifixSum[i-1] + nums[i];
        }

        unordered_map<int , int>m;  // PS , freq
        for(int j=0; j<n; j++){
            if(prifixSum[j] == k){
                count++;
            }
            int val = prifixSum[j] - k;
            if(m.find(val) != m.end()){
                count += m[val];
            }
            if(m.find(prifixSum[j]) == m.end()){
                m[prifixSum[j]] = 0;
            }
               m[prifixSum[j]]++;
        } 
        return count;
    }
};