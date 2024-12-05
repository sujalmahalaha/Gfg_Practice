//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int mp[3] = {0};
        for(auto it : arr)
        {
            mp[it]++;
        }
        int ind = 0;
        for(int j=0; j<mp[0]; j++)
        {
            arr[ind] = 0;
            ind++;
        }
        for(int j=0; j<mp[1]; j++)
        {
            arr[ind] = 1;
            ind++;
        }
        for(int j=0; j<mp[2]; j++)
        {
            arr[ind] = 2;
            ind++;
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends