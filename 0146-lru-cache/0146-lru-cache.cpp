class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            Node* resNode = mpp[key];
            int res = resNode->val;
            deleteNode(resNode); 
            addNode(resNode);    
            mpp[key] = head->next; 
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* existingNode = mpp[key];
            mpp.erase(key);      
            deleteNode(existingNode); 
        }
        if (mpp.size() == cap) {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev); 
        }
        addNode(new Node(key, value)); 
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */