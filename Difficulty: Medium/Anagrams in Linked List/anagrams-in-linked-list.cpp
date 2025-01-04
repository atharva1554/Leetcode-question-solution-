//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    string input;
    getline(cin, input); // Read the entire line input

    stringstream ss(input);
    char ch;
    struct Node *head = NULL, *tail = NULL;

    while (ss >> ch) {
        // cout<< ch << " ";
        if (head == NULL) {
            head = new Node(ch);
            tail = head;

        } else {
            tail->next = new Node(ch);
            tail = tail->next;
        }
    }
    // cout<<endl;

    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(Node* head, string str) {
        // code here
        vector<Node*> ans;
        Node* start=head,*end=head;
        int n=str.length();
        
        // pattern string
        unordered_map<char,int> mp1;
        for(auto it:str) mp1[it]++;
        int count1=mp1.size();
        
        // traversing string
        unordered_map<char,int> mp2;
        int count2=0;
        while(end!=NULL)
        {
            mp2[end->data]++;
            if(mp1[end->data]==mp2[end->data]) count2++;
            
            while(mp2[end->data]>mp1[end->data])
            {
                if(mp2[start->data]==mp1[start->data]) count2--;
                mp2[start->data]--;
                start=start->next;
            }
        
            if(count2==count1)
            {
                ans.push_back(start);
                Node* ahead=end->next;
                end->next=NULL;
                start=ahead,end=ahead;
                mp2.clear();
                count2=0;
            }
            else
                end=end->next;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the number of test cases

    while (t--) {
        struct Node *head = inputList();

        string s;
        getline(cin, s); // Read the string for the anagram check
        // cout<< s << endl;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0)
            cout << "-1\n";
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends