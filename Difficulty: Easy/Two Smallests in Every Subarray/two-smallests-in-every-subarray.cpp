//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int pairWithMaxSum(vector<int>& arr) {
        int n=arr.size();
        if(n<2){
            return -1;
        }
        int sum =arr[0]+arr[1];
        int maxi=sum;
        for(int i=2;i<n;i++){
            sum+=(arr[i]-arr[i-2]);
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends