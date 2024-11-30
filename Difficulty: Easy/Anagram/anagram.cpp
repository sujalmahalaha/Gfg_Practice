//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        map<char, int> mp1, mp2;
        for(auto it : s1)
        {
            mp1[it]++;
        }
        for(auto it : s2)
        {
            mp2[it]++;
        }
        if(mp1.size() != mp2.size())
        {
            return false;
        }
        for(auto it : mp1)
        {
            if(mp2[it.first] != it.second)
            {
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends