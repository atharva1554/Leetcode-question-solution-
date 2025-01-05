//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> Smallestonleft(int arr[], int n);

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        int arr[n + 1];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> b;
        b = Smallestonleft(arr, n);
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";

        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n) {
    // Complete the function
    set<int> s;
    s.clear();
    auto it = s.begin();
    int min = INT_MAX;
    int k = 0;
    int ind = -1;

    
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            ind = i;
        }

        auto itr = s.insert(arr[i]);
        it = itr.first;
        auto f = s.begin();

        
        if (it != s.end() && *f < arr[i]) {
            it--;
            arr[k++] = *it;
        }
        // Otherwise, update the current element with -1
        else {
            arr[k++] = -1;
        }

        it = s.begin();
    }

    // Update the first element and the minimum element to -1
    arr[0] = -1;
    arr[ind] = -1;

    // Convert the array to a vector and return it
    vector<int> res;
    for (int i = 0; i < n; i++) {
        res.push_back(arr[i]);
    }
    return res;
}