#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int val;
    int cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        cnt = 1;
        next = nullptr;
        prev = nullptr;
    }
};

struct List {
    int size;
    Node* head;
    Node* tail;
    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        size++;
    }
    void removeNode(Node* node) {
        Node* delprev = node->prev;
        Node* delnext = node->next;
        if (delprev) delprev->next = delnext;
        if (delnext) delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int currSize;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }

    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);

        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        int nextFreq = node->cnt + 1;
        List* nextHigherFreqList;
        if (freqListMap.find(nextFreq) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[nextFreq];
        } else {
            nextHigherFreqList = new List();
            freqListMap[nextFreq] = nextHigherFreqList;
        }

        node->cnt = nextFreq;
        nextHigherFreqList->addFront(node);
        keyNode[node->key] = node;
    }

    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int val = node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
        } else {
            if (currSize == maxSizeCache) {
                List* list = freqListMap[minFreq];
                Node* toRemove = list->tail->prev;
                keyNode.erase(toRemove->key);
                list->removeNode(toRemove);
                delete toRemove;
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List* listFreq;
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            } else {
                listFreq = new List();
                freqListMap[minFreq] = listFreq;
            }
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// /**
//  * Your LFUCache object will be instantiated and called as such:
//  * LFUCache* obj = new LFUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LFUCache* obj = new LFUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    obj->put(4, 4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;

    return 0;
}
