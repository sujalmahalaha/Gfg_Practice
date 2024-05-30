//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int countWays(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int mod = 1e9+7;
        vector<int> prev(m + 1), curr(m + 1);
        
        prev[0] = curr[0] = 1;
            
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int count = 0;
                
                if(s1[i - 1] == s2[j - 1])
                    count = (count + prev[j - 1] + prev[j]) % mod;
                else
                    count = (count + prev[j]) % mod;
                    
                curr[j] = count % mod;
            }
            
            prev = curr;
        }
        
        return prev[m];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends