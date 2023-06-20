#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n < 2) return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int j;

        for(int i=1;i<n;i++) {
            if(ans.size()) {
                // compare ans' last vector to int curr vector
                if(intervals[i][0] <= ans[j][1]) {
                    int s = ans[j][0];
                    int e = ans[j][1];
                    ans.pop_back();
                    ans.push_back({s, max(e,intervals[i][1])});
                }
                else {
                    ans.push_back(intervals[i]);
                    j++;
                }
            }

            else {
                j=0;
                if(intervals[i][0] <= intervals[i-1][1]) {
                    ans.push_back({intervals[i-1][0], max(intervals[i-1][1],intervals[i][1])});
                }
                else {
                    ans.push_back(intervals[i-1]);
                    ans.push_back(intervals[i]);
                    j++;
                }
            }
        }

        return ans;
    }
};