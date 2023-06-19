#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();

        // boundary 0s and non-boundary 0s are to be treated differently here

        map<pair<int,int>,bool> mp;

        // boundary zeros

        for(int j=0;j<n;j++) {
            if(A[0][j] == 0) mp[{0,j}] = true;
            if(A[m-1][j] == 0) mp[{m-1,j}] = true;
        }

        for(int i=0;i<m;i++) {
            if(A[i][0] == 0) mp[{i,0}] = true;
            if(A[i][n-1] == 0) mp[{i,n-1}] = true;
        }

        // non boundary zeros

        for(int i=1;i<m-1;i++) {
            for(int j=1;j<n-1;j++) {
                if(A[i][j] == 0) {
                    A[i][0] = A[0][j] = 0; // marking for transforming
                }
            }
        }

        for(int j=1;j<n-1;j++) {
            if(A[0][j] == 0) {
                for(int i=0;i<m;i++) {
                    A[i][j] = 0;
                }
            }
        }

        for(int i=1;i<m-1;i++) {
            if(A[i][0] == 0) {
                for(int j=0;j<n;j++) {
                    A[i][j] = 0;
                }
            }
        }


        // for boundary zeroes in the map

        for(int j=0;j<n;j++) {
            if(mp.find({0,j}) != mp.end()) {
                for(int j=0;j<n;j++) A[0][j] = 0;
                for(int i=0;i<m;i++) A[i][j] = 0;
                // break;
            }
        }

        for(int j=0;j<n;j++) {
            if(mp.find({m-1,j}) != mp.end()) {
                for(int j=0;j<n;j++) A[m-1][j] = 0;
                for(int i=0;i<m;i++) A[i][j] = 0;
                // break;
            }
        }

        for(int i=0;i<m;i++) {
            if(mp.find({i,0}) != mp.end()) {
                for(int j=0;j<n;j++) A[i][j] = 0;
                for(int i=0;i<m;i++) A[i][0] = 0;
                // break;
            }
        }

        for(int i=0;i<m;i++) {
            if(mp.find({i,n-1}) != mp.end()) {
                for(int j=0;j<n;j++) A[i][j] = 0;
                for(int i=0;i<m;i++) A[i][n-1] = 0;
                // break;
            }
        }

    }
};