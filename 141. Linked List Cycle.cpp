/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *turtle = head;
        ListNode *hare = head;
        bool isCycle = false;
        bool isStart =  true;
        
        while(turtle && hare)
        {
            if(turtle == hare && !isStart){
                isCycle = true;
                break;
            }
            if(isStart) isStart = !isStart;
            turtle= turtle->next;
            hare = hare->next;
            if(!hare) break;
            hare = hare->next;
        }

        return isCycle;
    }
};