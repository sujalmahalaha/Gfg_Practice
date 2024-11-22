//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &p) {
        vector<int>v1,v2(p.size()); int ans=0;
        v1.push_back(p[0]); v2[p.size()-1]=p[p.size()-1];
        for(int i=1; i<p.size(); i++){
            v1.push_back(min(v1.back(),p[i]));
        }
        for(int i=p.size()-2; i>=0; i--){
            v2[i]=max(v2[i+1], p[i]);
        }
        for(int i=0; i<p.size(); i++){
            ans=max(ans, v2[i]-v1[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends