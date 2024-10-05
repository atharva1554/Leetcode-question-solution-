class Node
{
public:
    int k, v, f;
    Node *next, *prev;

    Node(int x, int y)
    {
        k = x;
        v = y;
        f = 1; // imp
        next = prev = NULL;
    }
};

class DLL
{
public:
    Node *head, *tail;
    int size;

    DLL()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void pluckNode(Node *curr)
    {
        cout << curr->v << endl;
        Node *prv, *nxt;
        nxt = curr->next;
        prv = curr->prev;
        prv->next = nxt;
        nxt->prev = prv;
        size--;
    }

    void addToHead(Node *curr)
    {
        curr->next = head->next;
        curr->prev = head;
        head->next->prev = curr;
        head->next = curr;
        size++;
    }
};

class LFUCache
{
private:
    int n, N, freq;
    unordered_map<int, Node *> keyNode;
    unordered_map<int, DLL *> freqList;

public:
    LFUCache(int capacity)
    {
        N = capacity;
        n = freq = 0;
    }

    void promoteFreq(Node *curr)
    {

        DLL *l = freqList[curr->f];

        if (l->size == 1 && curr->f == freq)
            freq++;
        l->pluckNode(curr);
        (curr->f)++;

        // init list if not
        if (freqList.find(curr->f) == freqList.end())
            freqList[curr->f] = new DLL();

        freqList[curr->f]->addToHead(curr);
    }

    int get(int key)
    {
        if (keyNode.find(key) == keyNode.end())
            return -1;
        Node *curr = keyNode[key];
        promoteFreq(curr);
        return curr->v;
    }

    void put(int key, int value)
    {
        // already present
        if (keyNode.find(key) != keyNode.end())
        {
            promoteFreq(keyNode[key]);
            // update
            keyNode[key]->v = value;
            return;
        }

        // present
        // if full
        if (n == N)
        {
            n--;
            // delete LFU (LRU)
            DLL *l = freqList[freq];
            Node *delN = (l->tail)->prev;
            l->pluckNode(delN);
            keyNode.erase(delN->k);
            delete delN;
            // delete entry from map
        }
        n++;
        Node *newN = new Node(key, value);
        // add to map
        keyNode[key] = newN;
        freq = 1; // due to new node
        if (freqList.find(freq) == freqList.end())
            freqList[freq] = new DLL();
        freqList[freq]->addToHead(newN);
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */