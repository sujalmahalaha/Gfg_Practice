//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
          // Code Here

       //n is the size of the matrix

        int n=arr.size();

        int count=0,i,j;

      //for row palindrome checking 

        for(i=0;i<n;i++)

        {

           for(j=0;j<n/2;j++)

           {

               if(arr[i][j]==arr[i][n-1-j])

               {

                   count++;

               }

           }

           if(count==n/2)

             return to_string(i)+" R";

            count=0;

        }

     //for coloumn palindrome         checking 

        for(i=0;i<n;i++)

        {

           for(j=0;j<n/2;j++)

           {

               if(arr[j][i]==arr[n-j-1][i])

               {

                   count++;

               }

           }

           if(count==n/2)

             return to_string(i)+" C";

           count=0;

        }

        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends