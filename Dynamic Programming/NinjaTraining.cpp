#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long
// Time Complexity: O(n*4*3);
// Space OCmplexity: O(n)+O(n*4);

int f(int day,int last,vector<vector<int>>& points,vector<vector<int>>& dp){
    if(day == 0){
        int maxi = 0;
        for(int task = 0;task<3;task++){
            if(task != last){
                maxi = max(maxi,points[0][task]);
            }
        }

        return maxi;
    }

    if(dp[day][last] != -1){
        return dp[day][last];
    }

    int maxi = 0;

    for(int task = 0;task<3;task++){
        int point = points[day][task]+f(day-1,task,points,dp);
        maxi = max(maxi,point);
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n,vector<vector<int>>& points){
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return f(n-1, 3, points,dp);
}
 
int main(){
    
    return 0;
}