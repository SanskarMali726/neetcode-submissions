class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1:
        // Count how many times each task occurs.
        // Example: A A A B B C
        // freq = {A:3, B:2, C:1}
        unordered_map<char, int> freq;

        for (char task : tasks) {
            freq[task]++;
        }

        // Step 2:
        // Max heap stores tasks that are currently AVAILABLE.
        //
        // pair.first  = remaining frequency
        // pair.second = task
        //
        // We want the task with the highest frequency first,
        // so a normal priority_queue (max heap) is enough.
        priority_queue<pair<int, char>> pq;

        for (auto& [task, count] : freq) {
            pq.push({count, task});
        }

        // Step 3:
        // Store tasks that are currently in their cooldown period.
        //
        // tuple contains:
        // [0] = time when task becomes available again
        // [1] = remaining frequency
        // [2] = task character
        //
        // Example:
        // (3, 2, 'A')
        // means A has 2 copies left and can be used at time 3.
        vector<tuple<int, int, char>> cooldown;

        // Represents the current CPU time/interval.
        // Every executed task OR idle interval increases this by 1.
        int curr_time = 0;

        // Continue while:
        // 1. there are tasks available in pq, OR
        // 2. there are tasks still waiting in cooldown
        //
        // We cannot stop just because pq is empty,
        // because tasks may still be waiting for their cooldown.
        while (!pq.empty() || !cooldown.empty()) {

            // Step 4:
            // Check all tasks in cooldown.
            // If their cooldown is finished, move them back to pq.
            for (auto it = cooldown.begin(); it != cooldown.end(); ) {

                int available_time = get<0>(*it);
                int remaining_freq = get<1>(*it);
                char task = get<2>(*it);

                // The task is ready to be executed again.
                if (available_time <= curr_time) {

                    pq.push({remaining_freq, task});

                    // Remove it from cooldown because it is now available.
                    it = cooldown.erase(it);
                }
                else {
                    ++it;
                }
            }

            // Step 5:
            // If there is an available task, execute the one
            // with the highest remaining frequency.
            if (!pq.empty()) {

                auto curr = pq.top();
                pq.pop();

                int remaining_freq = curr.first - 1;
                char task = curr.second;

                // One copy of the task has been executed.
                //
                // If copies are still remaining, put the task
                // into cooldown. Otherwise we are completely done
                // with this task.
                if (remaining_freq > 0) {

                    // If task is executed at time t and cooldown = n,
                    // it can be executed again at:
                    //
                    // t + n + 1
                    //
                    // Example: n = 2
                    // time 0 -> A
                    // time 1 -> cannot A
                    // time 2 -> cannot A
                    // time 3 -> A
                    int available_time = curr_time + n + 1;

                    cooldown.push_back({
                        available_time,
                        remaining_freq,
                        task
                    });
                }
            }

            // Move to the next CPU interval.
            //
            // This is also incremented when no task is available,
            // which represents an idle interval.
            curr_time++;
        }

        // Total number of intervals needed.
        return curr_time;
    }
};