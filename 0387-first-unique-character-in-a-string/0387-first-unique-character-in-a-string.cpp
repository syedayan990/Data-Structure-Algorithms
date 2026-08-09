class Solution {
public:
    int firstUniqChar(string s) {

        int freq[26] = {0};

        // Frequency count
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        // Find first non-repeating character
        for (int i = 0; i < s.size(); i++) {

            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};