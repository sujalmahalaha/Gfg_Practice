//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
int perfectSum(int arr[], int n, int sum) {
        int mod = 1000000007;
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        
        // Initialize the dp array
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1; // There is always one way to make sum 0 (selecting no elements)
        }
        if (arr[0] <= sum) {
            dp[0][arr[0]] = 1; // If the first element is <= sum, include it
        }

        // If the first element is 0, it doubles the number of ways to get sum 0
        if (arr[0] == 0) {
            dp[0][0] = 2;
        }

        for (int index = 1; index < n; index++) {
            for (int target = 0; target <= sum; target++) {
                int notTaken = dp[index - 1][target];
                int taken = 0;
                if (arr[index] <= target) {
                    taken = dp[index - 1][target - arr[index]];
                }
                dp[index][target] = (notTaken + taken) % mod;
            }
        }

        return dp[n - 1][sum];
    }
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends