#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    // using max-subarr sum concept
    // Iamgine a math-wala graph and plot some points, the diff of consecutive prices mein kadane would be evident

    vector<int> diff;

    for(int i=1;i<prices.size();i++) {
        diff.push_back(prices[i]-prices[i-1]);
    }

    int mx = 0;
    int s = 0;

    for(auto x : diff) {
        s += x;
        mx = max(mx, s);
        if(s < 0) s = 0;
    }

    return mx;
}