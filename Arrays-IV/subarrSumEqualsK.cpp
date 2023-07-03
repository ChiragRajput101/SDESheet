#include <bits/stdc++.h>
using namespace std;

// IMP IDEA of combining preSum and map

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // using hashmap and concept of prefix sum
        unordered_map<long long, int> preSum; // sum:fre -- idx may be used instead of fre if the length of largest subarr with sum k is asked with a few mods in the below code
    
        int sum = 0;
        int ans = 0;
        int n = nums.size();
        preSum[sum]++;

        for(int i=0;i<n;i++) {
            sum += nums[i];
            ans += preSum.find(sum-k) != preSum.end() ? preSum[sum-k] : 0;
            preSum[sum]++;
        }

        return ans;
    }
};