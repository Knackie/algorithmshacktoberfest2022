// https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* tmp = head;
        while(tmp != NULL)
        {
            cnt++;
            tmp = tmp->next;
        }
        
        // cout<<cnt<<endl;
        int middu = cnt/2;
        // middu++;
        while(middu--){
            head = head->next;
        }
        return head;
    }
};
