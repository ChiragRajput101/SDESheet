#include <bits/stdc++.h>
using namespace std;

// VERY IMPORTANT --> totally exploits the fact that all nos from [1,n] occur only once except one
// n+1 numbers will exist
// This is generally a clue which leads to "using the indexes" >--^

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // linked list cycle detection

        int slow = 0, fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = 0;

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};