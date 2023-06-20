#include <bits/stdc++.h>
using namespace std;

void rotateClockWise(vector<vector<int>>& matrix) {
    // clockwise rotation

    reverse(matrix.begin(),matrix.end());
    // j should be init with i+1 rather than 0 for every i
    // if j = 0, this swaps all the nos twice and hence returning only the reversed matrix
    
    for(int i=0;i<matrix.size();i++) {
        for(int j=i+1;j<matrix.size();j++) { 
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void rotateAntiClockWise(vector<vector<int>>& matrix) {
    // anti clockwise rotation

    for(auto &r : matrix) reverse(r.begin(),r.end());

    for(int i=0;i<matrix.size();i++) {
        for(int j=i+1;j<matrix.size();j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}