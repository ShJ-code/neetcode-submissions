class LFUCache {
private:
    struct ListNode {
        ListNode* prev;
        ListNode* next;
        pair<int, int> kvpair;
        size_t freq;

        ListNode(): prev(nullptr), next(nullptr), kvpair(make_pair(0, 0)), freq(1UL) {}

        ListNode(ListNode* prv, ListNode* nxt, int key, int value)
            : prev(prv), next(nxt), kvpair(make_pair(key, value)), freq(1UL) {}
    };

    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> llmap;
    size_t size;
    size_t capacity;

    void restore_pos(ListNode* cur, ListNode* tail) {
        while (cur->next != tail && cur->freq >= cur->next->freq) {
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            cur->prev = cur->next;
            cur->next = cur->next->next;
            cur->next->prev = cur;
            cur->prev->next = cur;
        }
    }

public:
    LFUCache(int capacity) {
        this->capacity = (size_t)capacity;
        size = 0UL;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (auto it = llmap.find(key); it != llmap.end()) {
            it->second->freq++;
            restore_pos(it->second, tail);
            return it->second->kvpair.second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (auto it = llmap.find(key); it != llmap.end()) {
            it->second->freq++;
            it->second->kvpair.second = value;
            restore_pos(it->second, tail);
        } else {
            if (size < capacity) {
                ListNode* node = new ListNode(head, head->next, key, value);
                head->next = node;
                node->next->prev = node;
                restore_pos(node, tail);
                llmap.insert({key, node});
                size++;
            } else {
                llmap.erase(head->next->kvpair.first);
                head->next->kvpair = make_pair(key, value);
                head->next->freq = 1UL;
                llmap.insert({key, head->next});
                restore_pos(head->next, tail);
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */