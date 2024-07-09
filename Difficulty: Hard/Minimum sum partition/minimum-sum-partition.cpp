//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Initialize a boolean vector 'prev' to represent the previous row of the DP table
    vector<bool> prev(totSum + 1, false);

    // Base case: If no elements are selected (sum is 0), it's a valid subset
    prev[0] = true;

    // Initialize the first row based on the first element of the array
    if (arr[0] <= totSum)
        prev[arr[0]] = true;

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        // Create a boolean vector 'cur' to represent the current row of the DP table
        vector<bool> cur(totSum + 1, false);
        cur[0] = true;

        for (int target = 1; target <= totSum; target++) {
            // Exclude the current element
            bool notTaken = prev[target];

            // Include the current element if it doesn't exceed the target
            bool taken = false;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];

            cur[target] = notTaken || taken;
        }

        // Set 'cur' as the 'prev' for the next iteration
        prev = cur;
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++) {
        if (prev[i] == true) {
            // Calculate the absolute difference between two subset sums
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends