class Solution {
public:

     void getAllCombination(vector<int>& candidates, int idx, int target,
                           vector<vector<int>>& ans, vector<int>& combine) {

        // Base Cases
        if (target == 0) {
            ans.push_back(combine);
            return;
        }

        if (idx == candidates.size() || target < 0) {
            return;
        }

        // Include current element
        combine.push_back(candidates[idx]);
        getAllCombination(candidates, idx, target - candidates[idx], ans, combine);

        // Backtrack
        combine.pop_back();

        // Exclude current element
        getAllCombination(candidates, idx + 1, target, ans, combine);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> combine;

        getAllCombination(candidates, 0, target, ans, combine);

        return ans;
    }
};