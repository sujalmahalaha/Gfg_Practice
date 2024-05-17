//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int findPair(int n, int x, vector<int>& arr) {
    if (n < 2) return -1; // If there are less than 2 elements, no pair can exist

    // Sort the array to use the two-pointer technique
    sort(arr.begin(), arr.end());

    int i = 0, j = 1;

    while (j < n) {
        int diff = arr[j] - arr[i];
        
        // Ensure i is always less than j
        if (i == j) {
            j++;
            continue;
        }

        if (diff == x) {
            return 1;
        } else if (diff < x) {
            j++;
        } else {
            i++;
        }
    }

    return -1;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends