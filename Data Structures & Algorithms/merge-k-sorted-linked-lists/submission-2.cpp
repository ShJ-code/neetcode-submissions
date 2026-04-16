/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        int interval = 1;
        while (interval < len) {
            for (int i = 0; i < len - interval; i += interval * 2) {
                lists[i] = merge2Lists(lists[i], lists[i+interval]);
            }
            interval *= 2;
        }
        return len > 0 ? lists[0] : nullptr;
    }

private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* curr = &head;
        while (l1 && l2) {
            if (l1 -> val <= l2 -> val) {
                curr -> next = l1;
                l1 = l1 -> next;
            } else {
                curr -> next = l2;
                l2 = l1;
                l1 = curr -> next -> next;
            }
            curr = curr -> next;
        }
        if (!l1) {
            curr -> next = l2;
        } else {
            curr -> next = l1;
        }
        return head.next;
    }
};
