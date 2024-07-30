//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
     vector<string> ans;
     vector<int>row= { 1 ,-1 , 0 , 0 };
     vector<int>col= { 0 , 0 , 1 ,-1 };
    vector<char>dir= {'D','U','R','L'};
    void solve(vector<vector<int>> &m,int n,int i,int j,string &s)
    {
        if(i<0 or j<0 or i==n or j==n or !m[i][j])
            return;
        if(i==n-1 and j==n-1)
        {
            ans.push_back(s);
            return;
        }
        m[i][j]=0;
        for(int l=0;l<4;l++)
        {
            s.push_back(dir[l]);
            solve(m,n,i+row[l],j+col[l],s);
            s.pop_back();
        }
        m[i][j]=1;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m) {
        // Your code goes here
        string s;
        int n=m.size();
        solve(m,n,0,0,s);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends