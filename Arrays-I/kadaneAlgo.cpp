#include <bits/stdc++.h>
using namespace std;

// MAX SUBARR SUM IN O(N)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // for this to work for -ve numbers GLOBAL must be assigne -INF
        int local = 0, global = -1e9; 
        int prev = 0;

        for(auto &x : nums) {
            local += x;
            global = max(global, local);
            if(local < 0) local = 0;
        }
        return global;
    }
};