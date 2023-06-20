#include <bits/stdc++.h>
using namespace std;

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // we can apply cell tranf -- i*n+j -- and transform this into a 1d array of len -- m*n
    // BS on this would have a TC of O(lg(m*n))

    int m = matrix.size(), n = matrix[0].size();

    int s = 0, e = m*n-1;

    while(s!=e) {
        int mid = (s+e)/2;

        if(matrix[mid/n][mid%n] < target) s = mid+1; 
        // this is simply the reverse of the cell transf done
        else e = mid;
    }

    return matrix[s/n][s%n] == target;
}