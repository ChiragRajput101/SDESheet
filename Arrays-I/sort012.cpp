#include <bits/stdc++.h>
using namespace std;

// Const space TWO-PASS solution: more intuitive

void sortColors(vector<int>& nums) { 
    unordered_map<int,int> mp;
    for(auto x:nums) {
        mp[x]++;
    }
    int x = 0;
    for(int i=0;i<nums.size();i++) {
        if(mp[x]>0) {
            nums[i] = x;
            mp[x]--;
        }
        else {
            x++;
            i--;
        }
    }
}

// Const space ONE-PASS algo -- DUTCH NATIONAL FLAG
// We try to maintain all 0s at the left side of a pointer mid and all the 2s at its right side

void sortColors(vector<int>& nums) { 
    int low = 0, mid = 0, high = nums.size()-1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}