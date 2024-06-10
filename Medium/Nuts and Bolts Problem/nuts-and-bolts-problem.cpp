//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        unordered_map<char,char> seq,revseq;
        seq['!']='a',
        seq['#']='b',
        seq['$']='c',
        seq['%']='d',
        seq['&']='e',
        seq['*']='f',
        seq['?']='g',
        seq['@']='h',
        seq['^']='i';
       
        revseq['a']='!',
        revseq['b']='#',
        revseq['c']='$',
        revseq['d']='%',
        revseq['e']='&',
        revseq['f']='*',
        revseq['g']='?',
        revseq['h']='@',
        revseq['i']='^';


        for(int i=0;i<n;i++){
            nuts[i]=seq[nuts[i]];
        }
        sort(nuts,nuts+n);
        for(int i=0;i<n;i++){
            bolts[i]=seq[bolts[i]];
        }
        sort(bolts,bolts+n);

        for(int i=0;i<n;i++){
            nuts[i]=revseq[nuts[i]];
        }
        for(int i=0;i<n;i++){
            bolts[i]=revseq[bolts[i]];
        }

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends