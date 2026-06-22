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
ListNode* reverseList(ListNode* l){
    ListNode* curr = l;
    ListNode* prev = nullptr;
    while( curr ){
        ListNode* nex = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = nex;
    }return prev;
}
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while( fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(fast != nullptr )slow = slow -> next;
        ListNode* newHead1 = reverseList(slow);
        ListNode* newHead2 = head;
        ListNode* temp1 = newHead1;
        ListNode* temp2 = newHead2;
        while( temp1 && temp2 ){
            if( temp1 -> val != temp2 -> val)return false;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }return true;
    }
};