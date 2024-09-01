//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int i = arr1.size()-1, j = arr2.size()-1;
        
        int max_path = 0, arr1_path = 0, arr2_path = 0;
        
        while(i >= 0 && j >= 0)
            if(arr1[i] > arr2[j])
                arr1_path += arr1[i--];
            else if(arr1[i] < arr2[j])
                arr2_path += arr2[j--];
            else
            {
                max_path += max(arr1_path + arr1[i--], arr2_path + arr2[j--]);
                arr1_path = arr2_path = 0;
            }
        
        while(i >= 0)
            arr1_path += arr1[i--];
        while(j >= 0)
            arr2_path += arr2[j--];
        
        max_path += max(arr1_path, arr2_path);
        
        return max_path;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends