#include <bits/stdc++.h>
using namespace std;

// EXTRA QUES
//https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/description/

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        // subtracting 2^k from a number whose kth bit is set is equiv of unsetting that kth bit
        // we perform this opr in pairs
        // to make all elements equal to 0 -- means to unset every bit in a subarr
        // 1^1 = 0
        // hence to make all elements of a subarr = 0, the the set bits need to even in no -- this gives us the idea that any subarr with XOR = 0 is incl in ans
        
        // hence we find out the no of subarrays with XOR = 0

        // using map + prefix xor

        unordered_map<int,int> prexor;
        prexor[0] = 1; // for counting in the cases due to nums[i] = 0

        long long ans = 0;
        int xx = 0;

        for(int i=0;i<nums.size();i++) {
            xx ^= nums[i];
            ans += prexor.find(xx^0)!=prexor.end() ? prexor[xx]:0;
            prexor[xx]++;
        }
        return ans;
    }
};