//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
          if (arr.empty()) {
        return "";
    }
    
    sort(arr.begin(), arr.end());

    string first = arr[0];
    string last = arr[arr.size() - 1];
    string ans = "";

    for (int i = 0; i < first.size(); i++) {
        char s = first[i];
        if (i >= last.size() || first[i] != last[i]) {
            break;
        }
        ans += s;
    }

    if (ans.empty()) {
        return "-1";
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
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends