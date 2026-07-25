class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int twoSum = (numbers[i] + numbers[j]);
            if(twoSum > target){
                j--;
            }
            else if(twoSum < target){
                i++;
            }
            else{
                ans.push_back(i);
                ans.push_back(j);
                return {i+1 , j+1};
            }
        }
        return ans;


//      vector<int> ans;
//      int n = numbers.size();
//      for(int i=1; i<n; i++){
//         for(int j=i+1; j<n; j++)
//         {
//             if((numbers[i] + numbers[j]) == target){
//                  ans.push_back(i);
//                  ans.push_back(j);
//                 return ans;
//             }
//         }
//      } 
// return ans;
    }
};