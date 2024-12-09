//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here 
        vector<vector<int>> res;
        
        int s=newInterval[0];
        int e=newInterval[1];
        int n=intervals.size();
        bool flag =true;
        
        for(int i=0;i<n;i++){
          
               if(intervals[i][1]<s){
                   res.push_back(intervals[i]);
                   continue;
               }
              
               if(intervals[i][0]>e){
                   if(flag){
                       res.push_back({s,e});
                       flag=false;
                   }
                   res.push_back(intervals[i]);
                   continue;
               }
               else{
                   s=min(s,intervals[i][0]);
                   e=max(e,intervals[i][1]);
               }
               
             
        }
        if(flag)res.push_back({s,e});
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends