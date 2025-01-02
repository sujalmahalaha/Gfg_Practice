//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     long subarrayXor(vector<int> &arr, int k) {
        long ans = 0;  // To store the count of subarrays with XOR = k
        map<int, int> mpp;  // Hashmap to store prefix XOR frequencies
        int xo = 0;  // Running XOR

        for (auto it : arr) {
            xo = xo ^ it;  // Update the running XOR

            // If the current XOR equals k, increment the answer
            if (xo == k) {
                ans++;
            }

            // Calculate the required XOR value
            int req = k ^ xo;

            // If the required XOR exists in the map, add its frequency to the answer
            if (mpp.find(req) != mpp.end()) {
                ans += mpp[req];
            }

            // Update the hashmap with the current XOR value
            mpp[xo]++;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends