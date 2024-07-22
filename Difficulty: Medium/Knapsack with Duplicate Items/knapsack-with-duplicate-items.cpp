//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

     int solve(int W, int *wt, int *val, int n , vector<vector<int>>&dp){
        if(n == 0){
            if(wt[0] <= W){
                int n = W/wt[0];
                return n*val[0];
            }
            else{
                return 0;
            }
        }
           if(dp[n][W]  != -1){
               return dp[n][W];
           }
            int notTake = solve(W , wt , val , n-1, dp);
            int Take = INT_MIN;
            if(wt[n] <= W){
                Take = val[n] + solve(W-wt[n] , wt , val , n, dp);
            }
            return dp[n][W]= max(notTake  , Take);
        
        
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
         // Your code here
         int n = N;
       vector<vector<int>>dp(n , vector<int>(W+1 , -1));
       return solve(W , wt , val , n-1, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends