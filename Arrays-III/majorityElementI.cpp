#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    // bit manipulation -- TC: O(32n), Const Space

    int ans = 0;
    for(int i=0;i<32;i++) {
        // chk leftmost bit by masking all others then chk second last and so on
        int mask = 1;
        mask <<= i;

        int one = 0, zero = 0;
        for(auto &x : nums) {
            if(x & mask) one++;
            else zero++;
        }

        int maj = one>zero ? 1:0; // which ever 1 or 0 was the maj one it would be the part of the ans for sure
        ans |= maj<<i; // we OR that bit and that pos(postion of that bit is imp)
    }

    return ans;
}