struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int _key, int _val)
    {
        key=_key;
        val=_val;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
private:
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int capacity;
    map<int,Node*> mpp;
private:
    void InsertAfterHead(Node* node)
    {
        Node* currAfterHead = head->next;
        node->next=currAfterHead;
        currAfterHead->prev=node;
        head->next=node;
        node->prev=head;
    }
    void DeletionNode(Node* node)
    {
        Node* prevNode=node->prev;
        Node* nextNode=node->next;

        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end())
        {
            return -1;
        }
        Node* node=mpp[key];
        DeletionNode(node);
        InsertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end())
        {
            Node *node=mpp[key];
            DeletionNode(node);
            node->val=value;
            InsertAfterHead(node);
        }
        else
        {
            if(mpp.size()==capacity)
            {
                Node* node=tail->prev;
                mpp.erase(node->key);
                DeletionNode(node);
            }
            Node* node=new Node(key, value);
            mpp[key]=node;
            InsertAfterHead(node);
        }
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0";});
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 int main()
 {
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout<<obj->get(1)<<endl;
    obj->put(3,3);
    cout<<obj->get(2)<<endl;
    obj->put(4,4);
    cout<<obj->get(1)<<endl;
    cout<<obj->get(3)<<endl;
    cout<<obj->get(4)<<endl;

    return 0;
 }