// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         deque<int> dq;
//         vector<int> res;

//         for(int i=0; i<k; i++){
//             while(dq.size() > && nums[dq.back()] <= nums[i]){
//                 dq.pop_back();
//             }
//             dq.push_back(i);
//         }

//         for(int i=k; i<nums.size(); i++){
//             res.push_back(nums[dq.front()]);
//             while(dq.size() > 0 && dq.front() <= i-k){
//                 dq.pop_front();
//             }

//               while(dq.size() > && nums[dq.back()] <= nums[i]){
//                 dq.pop_back();
//             }
//             dq.push_back(i);
//         }
//         res.push_back(nums[dq.front()]);
//     }
// };




class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> res;

        // First window
        for (int i = 0; i < k; i++) {

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // Remaining windows
        for (int i = k; i < nums.size(); i++) {

            // Current window ka maximum
            res.push_back(nums[dq.front()]);

            // Window se bahar ho chuka element remove karo
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Smaller elements ko remove karo
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // Last window
        res.push_back(nums[dq.front()]);

        return res;
    }
};