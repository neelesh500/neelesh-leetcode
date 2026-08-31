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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, prevCritical = -1;
        int minDist = INT_MAX, maxDist = -1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;
        while (curr && curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                if (first == -1) {
                    first = idx;
                } else {
                    minDist = min(minDist, idx - prevCritical);
                    maxDist = idx - first;
                }
                prevCritical = idx;
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }
        if (maxDist == -1) return {-1, -1};
        return {minDist, maxDist};
    }
};