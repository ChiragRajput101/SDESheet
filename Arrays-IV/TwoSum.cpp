#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveBy2Ptr(vector<int> &nums, int target) {
        
        vector<pair<int, int>> v(nums.size());
        
        for(int i=0;i<nums.size();i++) {
            v[i].first = nums[i]; v[i].second = i;
        }
        
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        
        while(i<j) {
            // int sum = v[i].first + v[j].first;
            if(v[i].first+v[j].first == target) return {v[i].second, v[j].second};
            else if(v[i].first+v[j].first > target) j--;
            else i++;
        }
        return {};
    }
    
    vector<int> solveByMap(vector<int> &nums, int target) {
        unordered_map<int, int> m;
        
        for(int i=0;i<nums.size();i++) {
            m[nums[i]] = i;
        }
        
        for(int i=0;i<nums.size();i++) {
            if(m.find(target - nums[i]) != m.end() && m[target-nums[i]] != i) return {i, m[target-nums[i]]};
        }
        
        return {};
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        // return solveBy2Ptr(nums, target);
        return solveByMap(nums, target);
    }
};