//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
       long long ExtractNumber(string sentence) {
        long long count=0,n=0;
        bool indicate=false;
        for(char x:sentence)
        {
            if(x>='0' && x<='9')
            {
                n=n*10+(x-'0');
                if(x=='9')
                indicate=true;
            }
            else if(x==' ')
            {
                if(!indicate)
                count=max(count,n);
                indicate=false;
                n=0;
            }
        }
        if(indicate==false)
        count=max(count,n);
        return count==0?-1:count;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends