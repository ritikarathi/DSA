class Node{
        public:
        int key,value;
        Node* prev;
        Node* next;

        Node(int k ,int v){
            key =k;
            value =v;
            
        }
    };

class LRUCache {
public:
    int limit;
    unordered_map<int,Node*>mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node *n){
        Node* temp =head->next;
        n->next =head->next;
        head->next=n;
        n->prev=head;
        temp->prev=n;
    }

    void deleteN(Node *n){
        Node* aage =n->next;
        Node* peeche =n->prev;
        peeche->next=aage;
        aage->prev=peeche;

    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node *res =mp[key];
        int v =res->value;
        deleteN(res);
        mp.erase(key);
        addNode(new Node(key,v));
        mp[key]=head->next;
        return v;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node *res =mp[key];
            mp.erase(key);
            deleteN(res);
        }
        if(mp.size()==limit){
            mp.erase(tail->prev->key);
            deleteN(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */