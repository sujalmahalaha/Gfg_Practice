//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2) {
    int m = v2.size();
    int n = v1.size();
    int j = 0; // For index of v2

    // Traverse v1 and v2
    for (int i = 0; i < n && j < m; i++) {
        if (v1[i] == v2[j]) {
            j++;
        }
    }
    return (j == m);
}


// } Driver Code Ends
// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]]

class Solution {
  public:
   vector<int> find3Numbers(vector<int> &arr) {
    int n = arr.size();
    if (n < 3) return {}; // Not enough elements for a triplet
    
    vector<int> dp(n, 1);        // dp[i] will store the length of the LIS ending at index i
    vector<int> previous(n, -1); // previous[i] will store the index of the previous element in the subsequence
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                previous[i] = j;
                
                // If we found a subsequence of exactly length 3, extract it and return
                if (dp[i] == 3) {
                    vector<int> result;
                    int k = i;
                    while (k != -1) {
                        result.push_back(arr[k]);
                        k = previous[k];
                    }
                    reverse(result.begin(), result.end()); // Ensure the order is correct
                    return result;
                }
            }
        }
    }
    
    return {}; // No valid subsequence of length 3 found
}
};

//{ Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution obj;
        auto res = obj.find3Numbers(arr);
        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and isSubSequence(arr, res)) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends