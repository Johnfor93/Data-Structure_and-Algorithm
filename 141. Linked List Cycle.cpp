/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    Just implementation of Floyd's Turtle Hare Algorithm Cycle Detection

    Time Complexity: O(N)
    Space Complexity: O(1)
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