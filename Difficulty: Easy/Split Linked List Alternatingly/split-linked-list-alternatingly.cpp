//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) 
    {
        vector<Node*>ans;
        Node* a = head;
        
        if(head == NULL || head->next == NULL)
        {
            ans.push_back(a);
            return ans;
        }
        
        
        Node* b = head->next;
        Node* c = b;
        
        while(b->next != NULL)
        {
            a->next = b->next;
            a = a->next;
            
            if(a->next  == NULL)
            {
                break;
            }
            
            b->next = a->next;
            b = b->next;
        }
        
        a->next = NULL;
        b->next = NULL;
        
        ans.push_back(head);
        ans.push_back(c);
        
        return ans;
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends