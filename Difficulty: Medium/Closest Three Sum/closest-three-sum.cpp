//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
   int threeSumClosest(vector<int> arr, int target) {
    // Initialize variables to store the smallest difference and the closest sum found
    int dif = INT_MAX, ans = INT_MAX;

    // Sort the array to facilitate the two-pointer approach
    sort(arr.begin(), arr.end());

    // Iterate through each element of the array, treating it as the first element of the triplet
    for (int i = 0; i < arr.size(); i++) {
        // Initialize two pointers, start (s) and end (e)
        int s = i + 1, e = arr.size() - 1;

        // Use the two-pointer approach to find the closest sum
        while (s < e) {
            // Calculate the sum of the current triplet
            int sum = arr[i] + arr[s] + arr[e];

            // If the sum equals the target, return the sum immediately
            if (sum == target) {
                return sum;
            } 
            // If the sum is greater than the target, decrement the end pointer to reduce the sum
            else if (sum > target) {
                e--;
            } 
            // If the sum is less than the target, increment the start pointer to increase the sum
            else {
                s++;
            }

            // Update the closest sum and the smallest difference if a closer sum is found
            if (abs(sum - target) < dif) {
                dif = abs(sum - target);
                ans = sum;
            } 
            // If the difference is the same but the sum is greater, update the closest sum
            else if (abs(sum - target) == dif) {
                ans = max(ans, sum);
            }
        }
    }

    // Return the closest sum found
    return ans;
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends