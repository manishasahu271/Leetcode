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
struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // smaller value = higher priority
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       // Step 2: Create the min heap that stores ListNode pointers
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        
        // Step 3: Push the head of each non-empty list into the heap
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                minHeap.push(lists[i]);
            }
        }
        
        // Step 4: Create a dummy node to simplify building the result
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;  // tail points to the last node in result
        
        // Step 5: Keep pulling the smallest node out of the heap
        while (!minHeap.empty()) {
            // Get the smallest node
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            // Attach it to the end of our result list
            tail->next = smallest;
            tail = tail->next;  // move tail forward
            
            // If this node has a next node, push it into the heap
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        
        // Step 6: Return the merged list (skip the dummy node)
        return dummy->next;
    }
};

