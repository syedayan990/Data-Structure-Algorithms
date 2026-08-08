class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        // nums2 ke elements ka next greater find karo
        for(int i = nums2.size() - 1; i >= 0; i--) {
            
            // Chhote elements ko remove karo
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // Stack empty hai -> koi greater element nahi
            if(st.empty()) {
                mp[nums2[i]] = -1;
            }
            else {
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        // nums1 ke answers
        vector<int> ans;

        for(int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};