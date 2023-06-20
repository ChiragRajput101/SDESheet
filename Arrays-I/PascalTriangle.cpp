#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows, vector<int>());

    // If ever have to find out any combi: nCr use the code below for that, rather than implementing a factorial based function

    for(int i=0;i<numRows;i++) {
        ans[i].resize(i+1);
        ans[i][0] = ans[i][i] = 1; // nC0 and nCn = 1

        for(int j=1;j<i;j++) {
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }
    return ans;
}