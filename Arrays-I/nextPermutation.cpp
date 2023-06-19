#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i=n-2;

        // arr of the form: .... d c b a , d >= c >= b >= a
        // we wont want to change this part of the arr -- already in mx poss state
        // we look at k where ...k, d, c, .. K<D

        // TRY OUT THE BELOW LOGIC ON FEW CASES TO GET IT:

        // maintaining the pointer at 'k' and another one traversing rightwards to find the last letter that is greater than 'k' and swap both of them

        // then - reverse(nums.begin()+i+1,nums.end());


        while(i>=0 && nums[i]>=nums[i+1]) {
            i--;
        }

        if(i<0) reverse(nums.begin(),nums.end()); // the arr already exists in its max poss form

        else {
            int j=i+1;
            while(j < n && nums[j]>nums[i]) j++;
            swap(nums[i],nums[--j]);
            reverse(nums.begin()+i+1,nums.end());
        }
    }
};