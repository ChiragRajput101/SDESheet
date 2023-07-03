#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int ans = 0;
        int n = s.size();

        std::unordered_map<char, int> mp;

        for(int i=0,j=0;i<n;i++) {
            while(j<n && mp[s[j]] < 1) {
                mp[s[j++]]++;
            }

            ans = std::max(ans, j-i);
            mp[s[i]]--;
        } 

        return ans;
    }
};