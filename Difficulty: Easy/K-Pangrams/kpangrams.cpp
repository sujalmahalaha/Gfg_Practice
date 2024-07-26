//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
       
       int cnt=0;
       for(int i=0;i<str.size();i++){
            if(str[i]!=' '){
               cnt++;
           }
       }
       

       if(cnt<26){
           return false;
       }
       int arr[26]={0};
       
       for(auto it:str){
           
          arr[it-'a']++;
       }
       
       for(int i=0;i<26;i++)
       {
           if(arr[i]==0){
              k--;
           }
       }
       
       return k>=0;
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends