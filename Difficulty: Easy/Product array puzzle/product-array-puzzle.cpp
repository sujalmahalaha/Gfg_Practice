//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
   vector<long long int> productExceptSelf(vector<long long int>& nums) {

        vector<long long int>ans;
        
        long long int prefix =1;
        for(int i = 1;i<nums.size();i++) prefix *=nums[i];  // for first element
   
        ans.push_back(prefix);
        
        prefix =1;
        for(int i = 1;i<nums.size();i++)
        {
            prefix *=nums[i-1];
            long long int suffix =1;
            
            for(int  j = i+1;j<nums.size();j++)
            {
                suffix *=nums[j];
            }
            ans.push_back(prefix * suffix);
            
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends