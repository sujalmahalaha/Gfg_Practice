//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     long long int gcd(long long int a, long long int b) {
        return b == 0 ? abs(a) : gcd(b, a % b);
    }

    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        // Extract coordinates
        long long int p1 = p[0], p2 = p[1];
        long long int q1 = q[0], q2 = q[1];
        long long int r1 = r[0], r2 = r[1];

        // Calculate the area using the determinant method
        long long int area = abs(p1 * (q2 - r2) + q1 * (r2 - p2) + r1 * (p2 - q2));

        // Calculate boundary points using gcd
        long long int boundaryPoints = gcd(abs(q1 - p1), abs(q2 - p2)) +
                                       gcd(abs(r1 - q1), abs(r2 - q2)) +
                                       gcd(abs(p1 - r1), abs(p2 - r2));

        // Apply Pick's theorem to find the number of integral points inside the triangle
        long long int interiorPoints = (area - boundaryPoints + 2) / 2;
        return interiorPoints;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends