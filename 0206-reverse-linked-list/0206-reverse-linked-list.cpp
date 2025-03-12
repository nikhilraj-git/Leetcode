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
    ListNode* solve(ListNode* node){
        if(node -> next == nullptr) return node;

        ListNode* n = solve(node -> next);
        ListNode* temp = node -> next;
        temp -> next = node;
        node -> next = nullptr;
        return n;

    }
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
      ListNode*temp =head;
      return solve(head);
    }
};