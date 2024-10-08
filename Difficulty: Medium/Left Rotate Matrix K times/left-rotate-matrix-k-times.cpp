//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
         int rows=mat.size();
        if(rows == 0)
        return mat;
        int cols = mat[0].size();
        if(cols==0) return mat;
        
        k=k%cols;
        
        for(int i=0;i<rows;i++)
        {
            vector<int> newRow(cols);
            for(int j=0;j<cols;j++)
            {
                newRow[j]=mat[i][(j+k)%cols];
            }
            mat[i]=newRow;
        }
    return mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends