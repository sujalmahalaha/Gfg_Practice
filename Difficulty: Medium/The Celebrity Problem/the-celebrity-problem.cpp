//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        
        int n = mat.size();
        int m = mat[0].size();
        int KnowMe[n] = {0};
        int IKnow[n] = {0};
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(mat[i][j] == 1){
                    KnowMe[j]++;
                    IKnow[i]++;
                }
            }
        }
        
        for(int i = 0 ; i<n ; i++){
            if(IKnow[i] == 0 && KnowMe[i] == n-1){
                return i;
                break;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends