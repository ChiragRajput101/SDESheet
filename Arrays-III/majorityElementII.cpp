#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    // Boyer-Moore Maj Voting Algo -- const space, linear time
    // only 2 distinct elements at max would exist that fulfills atleast n/3 + 1
    // the 3rd element would have a freq of at most n/3 - 2 (if any) -- this fails the given criteria for a majority el

    int y = -1, z = -1, cy = 0, cz = 0;

    for (auto &x: nums)  {
        if (x == y) cy++;
        else if (x == z) cz++;
        else if (! cy) y = x, cy = 1;
        else if (! cz) z = x, cz = 1;
        else cy--, cz--;
    }
    
    cy = cz = 0;
    for (auto &x: nums) {
        if (x == y) cy++;
        else if (x == z) cz++;
    }
    
    vector<int> r;
    if (cy > nums.size()/3) r.push_back(y);
    if (cz > nums.size()/3) r.push_back(z);
    return r;
}