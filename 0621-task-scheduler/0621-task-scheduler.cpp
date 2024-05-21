class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int freq[26] = {0};
        int len = tasks.size();
        for(int i=0; i<len; i++)
        {
            freq[tasks[i]-'A']++;
        }

        priority_queue<int>pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int time = 0;
        // Process tasks until the heap is empty
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> store;
            int taskCount = 0;
            // Execute tasks in each cycle
            while (cycle-- && !pq.empty()) {
                if (pq.top() > 1) {
                    store.push_back(pq.top() - 1);
                }
                pq.pop();
                taskCount++;
            }
            // Restore updated frequencies to the heap
            for (int &x : store) {
                pq.push(x);
            }
            // Add time for the completed cycle
            time += (pq.empty() ? taskCount : n + 1);
        }
        return time;
    }
};