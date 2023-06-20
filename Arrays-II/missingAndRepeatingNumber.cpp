#include <bits/stdc++.h>
using namespace std;

// Linear time and Const space solution -- BIT MANIPULATION -- ** IMP perspective of looking at things where there is repition
// [1,n] leading to use of indexes didn't come to fruition while thinking of a linear time and constv space soln
 
vector<int> findTwoElement(vector<int>arr, int n) {
    // repeating no exists 3 times and the missing number exists 1 time in xor of arr[] with (1^2..^n)
    
    int commonxx = 0;
    
    for(int i=0;i<n;i++) {
        commonxx ^= arr[i]^(i+1);
    }
    
    // this now contains r^m
    // checking which bit is set in commonxx which indicates the bit at which both r and m differs the first time
    

    int differ = commonxx & ~(commonxx-1);
    // the above code works the same way
    /*
    int chk = 1;
    int differ = 0;
    
    for(int i=0;i<32;i++) {
        if(commonxx & (chk<<i)) {
            differ = i;
            break;
        }
    }
    */
    
    // seprating and xoring the nos of arr based on the differ bit -- 0 or 1
    int zero = 0, one = 0;
    
    for(int i=0;i<n;i++) {
        if(arr[i] & (1<<differ)) one ^= arr[i];
        else zero ^= arr[i];
    }
    
    for(int i=1;i<=n;i++) {
        if(i & (1<<differ)) one ^= i;
        else zero ^= i;
    }
    
    // now one and zero contain r and m but we don't know yet which one contains which
    
    int c = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] == one) c++;
    }
    
    if(c == 2) return {one,zero};
    return {zero,one};
} 
