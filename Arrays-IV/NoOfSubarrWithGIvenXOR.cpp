#include <bits/stdc++.h>
using namespace std;

// ....sum..
// if for a sum in the prefix sum, a sum equal to sum-target existed then we count the no of ways 
// ....|.....
// sum-t  sum if yes then we increase the count

// simi we mod the expression for XOR if curr_xor ^ target was present at some time then we increase the count BY THE AMOUNT OF WAYS WE CAN REACH curr_xor ^ t

int subarraysXor(vector<int> &arr, int k) {
    unordered_map<int,int> preXor; // xor:i

    int n = arr.size();
    preXor[0] = 1; // this is for handling the element 0 which would increase the no of ways

    int xx = 0;
    int ans = 0;

    for(int i=0;i<n;i++) {
        xx ^= arr[i];
        ans += (preXor.find(xx^k) != preXor.end()) ? preXor[xx^k] : 0;
        preXor[xx]++;
    }

    return ans;
}