//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int b_search(vector<int>& arr, int x) {
        int l = 0, r = arr.size()-1;
        int m;
        while(l < r) {
            m = l + (r-l-1)/2;
            if(arr[m] > x)
                r = m;
            else
                l = m+1;
        }
        if(arr[l] > x) return l;
        return (int) arr.size();
    }
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        sort(b.begin(), b.end());
        vector<int> ans;
        for(int i = 0; i < q; i++)
            ans.push_back(b_search(b, a[query[i]]));
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
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends