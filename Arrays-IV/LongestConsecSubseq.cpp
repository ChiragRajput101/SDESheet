#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,int> parent, size;
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void UnionBySize(int u, int v) {
        int up = find(u);
        int vp = find(v);

        if(up == vp) return;

        if(size[up] < size[vp]) {
            parent[up] = vp;
            size[vp] += size[up];
        }
        else {
            parent[vp] = up;
            size[up] += size[vp];
        }
    }

public:
    int longestConsecutive(vector<int>& nums) {
        // i dont like the unordered_set appr
        // this problem has the flavour of union find

        parent.clear();
        size.clear();

        unordered_map<int, bool> mp; // check existence of "neighbors of a node"
        // using array requires a use of offset due to -ve nos

        for(int i=0;i<nums.size();i++) {
            mp[nums[i]] = true;
            parent[nums[i]] = nums[i];
            size[nums[i]] = 1;
        }

        for(int i=0;i<nums.size();i++) {
            if(mp[nums[i] - 1]) {
                // union those two
                UnionBySize(nums[i], nums[i]-1);
            }

            if(mp[nums[i]+1]) {
                UnionBySize(nums[i], nums[i]+1);
            }
        }

        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            int ulp = find(nums[i]);
            ans = max(ans, size[ulp]);
        }

        return ans;
    }
};