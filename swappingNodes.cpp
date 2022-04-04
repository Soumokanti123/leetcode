// Swapping Nodes in a Linked List
// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 


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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* l = head;
        ListNode* r = head;
        ListNode* curr = head;
        int cnt = 1;
        while(curr != NULL){
            if(cnt < k){
                l = l->next;
            }
            if(cnt > k){
                r = r->next;
            }
            curr = curr->next;
            cnt++;
        }
        
        int temp = l->val;
        l->val = r->val;
        r->val = temp;
        return head;
    }
};
