//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int lcs(string str1, string str2, int i, int j,  vector<vector<int>>& dp ){
        if(str1.length() == i) return 0;
        if(str2.length() == j) return 0;
       
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        if(str1[i] == str2[j])
            ans += 1 + lcs(str1, str2, i+1, j+1, dp);
        
        else
           ans += max(lcs(str1, str2, i+1, j, dp), lcs(str1, str2, i, j+1, dp));
        return dp[i][j] = ans;  
    }
   
    int countMin(string str){
        vector<vector<int>> dp(str.length(), vector<int>(str.length(), -1));
        string str1 = str;
        string str2 ;
        reverse(str.begin(), str.end());
        str2 = str;
        int ans = 0;
        
        ans = lcs(str1, str2, 0, 0, dp);

    //subtract subsequence length to string length
        return str.length() - ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends