//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        head = head->next;
    }
    cout << '\n';
}


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr) {
        next = curr->next;  // Save the next node
        curr->next = prev;  // Reverse the current node's pointer
        prev = curr;        // Move prev to the current node
        curr = next;        // Move curr to the next node
    }

    return prev;  // New head of the reversed list
}

    Node* subLinkedList(Node* head1, Node* head2) {
        
          
        
          Node* ori1=head1;
          Node* ori2=head2;
          
          head1=reverse(head1);
          head2=reverse(head2);
          
          int borrow=0;
          
          Node* newhead=new Node(0);
          Node* temp=newhead;
     
          Node* temp1=head1;
          Node* temp2=head2;
          
         
          while(temp1 && temp2){
             
               int diff=temp1->data - temp2->data -borrow;
               if(diff<0){ borrow=1;temp->next=new Node(10+diff); }
               else {  temp->next=new Node(diff);borrow=0; }
              
               temp=temp->next;
               temp1=temp1->next;
               temp2=temp2->next;
          }
          if((temp1==NULL && temp2) || (temp1==NULL && temp2==NULL && borrow)){
              return subLinkedList(reverse(head2),reverse(head1));
          }
          
          
          while(temp1!=NULL){
             
               int diff=temp1->data-borrow;
               if(diff<0){ borrow=1;temp->next=new Node(10+diff); }
               else {  temp->next=new Node(diff);borrow=0; }
        
               temp=temp->next;
               temp1=temp1->next;
          }
         
         
          Node* curr= reverse(newhead->next);
          while(curr&& curr->data==0){
               curr=curr->next;
          }
          if(curr){return curr;}
          return new Node(0);
          
    }
};

//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        cin >> input1 >> input2;
        for (char ch : input1) {
            int tmp = ch - '0';
            Node* new_node = new Node(tmp);
            if (!head1) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        for (char ch : input2) {
            int tmp = ch - '0';
            Node* new_node = new Node(tmp);
            if (!head2) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node* result = obj.subLinkedList(head1, head2);
        printList(result);
    }
    return 0;
}

// } Driver Code Ends