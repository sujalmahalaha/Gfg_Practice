//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     int isValid(string str) {
       string temp="";
       int count=0;
       for(int i=0;i<str.size();i++){
           if(str[i]=='.'){
               count++;
                if(temp.empty())
                return 0;
               int num=stoi(temp);
               if(temp.size()==1){
                   if(num<0 || num>9)
                    return 0;
               }
               else if(temp.size()==2){
                   if(num<=9 || num>=100)
                    return 0;
               }
               else if(temp.size()==3){
                   if(num<100)
                    return 0;
               }
               if(num<0 || num>255)
                return 0;
                temp="";
           }
           else
           temp+=str[i];
       }
      if(temp.empty())
                return 0;
               int num=stoi(temp);
               if(temp.size()==1){
                   if(num<0 || num>9)
                    return 0;
               }
               else if(temp.size()==2){
                   if(num<=9 || num>=100)
                    return 0;
               }
               else if(temp.size()==3){
                   if(num<100)
                    return 0;
               }
               if(num<0 || num>255)
                return 0;
       if(count<3 || count>3)
        return 0;
       return 1;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends