class LFUCache {
    struct ListNode {
        int key;
        int val;
        int freq;
        ListNode* prev;
        ListNode* next;

        ListNode(int key, int val) : key(key), val(val), freq(1), prev(nullptr), next(nullptr) {}
    };

    struct LinkedList {
        ListNode* left;
        ListNode* right;
        int size;

        LinkedList() {
            left = new ListNode(0, 0);
            right = new ListNode(0, 0);
            left->next = right;
            right->prev = left;
            size = 0;
        }

        ~LinkedList() {
            delete left;
            delete right;
        }

        int length() {
            return size;
        }

        void pushRight(ListNode* node) {
            ListNode* prev = right->prev;
            prev->next = node;
            node->prev = prev;
            node->next = right;
            right->prev = node;
            size++;
        }

        void pop(ListNode* node) {
            ListNode* prev = node->prev;
            ListNode* next = node->next;
            prev->next = next;
            next->prev = prev;
            node->prev = nullptr;
            node->next = nullptr;
            size--;
        }

        ListNode* popLeft() {
            ListNode* node = left->next;
            pop(node);
            return node;
        }
    };

    int capacity;
    int lfuCount;
    unordered_map<int, ListNode*> nodeMap; // Map key -> node
    unordered_map<int, LinkedList*> listMap; // Map frequency -> linked list

    void counter(ListNode* node) {
        int count = node->freq;
        listMap[count]->pop(node);

        if (count == lfuCount && listMap[count]->length() == 0) {
            lfuCount++;
        }

        node->freq++;
        if (!listMap.count(node->freq)) {
            listMap[node->freq] = new LinkedList();
        }
        listMap[node->freq]->pushRight(node);
    }

public:
    LFUCache(int capacity) : capacity(capacity), lfuCount(0) {}

    ~LFUCache() {
        for (auto& pair : nodeMap) {
            delete pair.second;
        }
        for (auto& pair : listMap) {
            delete pair.second;
        }
    }

    int get(int key) {
        if (nodeMap.find(key) == nodeMap.end()) {
            return -1;
        }
        ListNode* node = nodeMap[key];
        counter(node);
        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        if (nodeMap.find(key) != nodeMap.end()) {
            ListNode* node = nodeMap[key];
            node->val = value;
            counter(node);
            return;
        }

        if (nodeMap.size() == capacity) {
            ListNode* toRemove = listMap[lfuCount]->popLeft();
            nodeMap.erase(toRemove->key);
            delete toRemove;
        }

        ListNode* node = new ListNode(key, value);
        nodeMap[key] = node;
        if (!listMap.count(1)) {
            listMap[1] = new LinkedList();
        }
        listMap[1]->pushRight(node);
        lfuCount = 1;
    }
};