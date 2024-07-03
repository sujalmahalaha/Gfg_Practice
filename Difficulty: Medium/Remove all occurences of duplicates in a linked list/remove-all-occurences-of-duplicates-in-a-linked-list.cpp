//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        
        if (!head || !head->next) return head;
    
    Node* dummy = new Node(0); // Dummy node to handle edge cases
    dummy->next = head;
    Node* prev = dummy; // Pointer to the node before the current node
    
    while (head) {
        // Check if the current node has duplicates
        if (head->next && head->data == head->next->data) {
            // Skip all nodes that have the same value
            while (head->next && head->data == head->next->data) {
                head = head->next;
            }
            // Connect the previous node to the node after the duplicates
            prev->next = head->next;
        } else {
            // Move the prev pointer
            prev = prev->next;
        }
        // Move the head pointer
        head = head->next;
    }
    
    head = dummy->next; // Update head to the new head of the list
    delete dummy; // Free the dummy node
    return head;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends