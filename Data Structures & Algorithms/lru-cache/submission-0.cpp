class LRUCache {
public:

    class Node{
    public:
        int key;int val;
        Node* prev;Node* next;
        Node(int key1,int val1){
            key=key1;val=val1;
        }
    };
    int cap;
    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);
    unordered_map<int,Node*>m;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node* newnode){
        Node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
      void deleteNode(Node* delnode){
        Node* prevv = delnode -> prev;
        Node* nextt = delnode -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }

    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* temp=m[key];
            deleteNode(m[key]);
            addNode(temp);
            return temp->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* temp=m[key];
            m.erase(key);
            deleteNode(temp);  
            delete temp;      
        }
        if(m.size()>=cap){
                int x=tail->prev->key;
                m.erase(x);
                deleteNode(tail->prev);
             
        }
        addNode(new Node(key, value));
        m[key] = head -> next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */