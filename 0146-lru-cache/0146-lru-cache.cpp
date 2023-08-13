class LRUCache {
public:
    class ListNode {
    public:
        int key;
        int val;
        ListNode* prev;
        ListNode* next;
        
        ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    int ms;
    int i;
    std::unordered_map<int, ListNode*> m;
    ListNode* head;
    ListNode* tail;

public:
    LRUCache(int capacity) : ms(capacity), i(0), head(nullptr), tail(nullptr) {}
    
    int get(int key) {
        if (m.find(key) == m.end() || head == nullptr) {
            return -1;
        }
        if (ms == 1 || i == 1) {
            return head->val;
        }
        ListNode* curr = m[key];
        if (curr != nullptr && curr != head) {
            ListNode* pr = curr->prev;
            ListNode* nx = curr->next;
            pr->next = nx;
            if (curr != tail) {
                nx->prev = pr;
            } else {
                tail = pr;
            }
            curr->next = head;
            head->prev = curr;
            curr->prev = nullptr;
            head = curr;
        }
        return head->val;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            ListNode* curr = m[key];
            curr->val = value;
            get(key);
            return;
        }
        
        ListNode* newnode = new ListNode(key, value);
        m[key] = newnode;
        if (i < ms) {
            if (head == nullptr) {
                head = newnode;
                tail = newnode;
            } else {
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
            }
            i++;
        } else {
            if (ms > 1) {
                ListNode* curr = tail->prev;
                curr->next = nullptr;
                m.erase(tail->key);
                delete tail;
                tail = curr;
                head->prev = newnode;
                newnode->next = head;
                head = newnode;
            } else {
                m.erase(tail->key);
                delete tail;
                head = newnode;
                tail = newnode;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */