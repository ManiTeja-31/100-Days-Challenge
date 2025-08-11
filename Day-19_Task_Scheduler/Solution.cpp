//Brute Force Approach
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> remaining; // Remaining counts of each task
    unordered_map<char, int> cooldown;  // Time when task is next available
    for (char t : tasks) remaining[t]++;
    int time = 0;
    int done = 0;
    int totalTasks = tasks.size();
    while (done < totalTasks) {
        time++;
        char pick = '\0'; // No task picked yet
        // Brute force: scan all tasks to find an available one
        for (auto &task : remaining) {
            char t = task.first;
            if (task.second > 0 && cooldown[t] <= time) {
                if (pick == '\0' || remaining[t] > remaining[pick]) {
                    pick = t;
                }
            }
        }
        if (pick != '\0') {
            remaining[pick]--;
            cooldown[pick] = time + n + 1; // Next time this task can be done
            done++;
        }
        // else → idle
    }
    return time;
}

//Optimal Approach - Using Priority Queue
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int>mp(26,0);

        for(char i:tasks){
            mp[i-'A']++;  // count the number of times a task needs to be done
        }   
        for(int i=0;i<26;++i){
            if(mp[i]) 
            pq.push(mp[i]);
        }

        int time=0; // stores the total time taken 
        while(!pq.empty()){
            vector<int>remain;
            int cycle=n+1;  // n+1 is the CPU cycle length, if n is the cooldown period then after a task A there will be n more tasks. Hence n+1.

            while(cycle and !pq.empty()){
                int max_freq=pq.top(); // the task at the top should be first assigned the CPU as it has highest frequency
                pq.pop();
                if(max_freq>1){ // task with more than one occurrence, the next occurrence will be done in the next cycle 
                    remain.push_back(max_freq-1); // add it to remaining task list
                }
                ++time; 
                --cycle; 
            }

            for(int count:remain){
                pq.push(count); 
            }
            if(pq.empty())break; // if the priority queue is empty than all tasks are completed and we don't need to include the idle time
            time+=cycle; // this counts the idle time 
        }
        return time;
    }
};

//Optimal Approach - Using formula
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> Freq;
        int maxFreq = 0;
        for(auto c:tasks){
            Freq[c]++;
            maxFreq = max(maxFreq,Freq[c]);
        }
        int NumOfMaxFreq = 0;
        for(auto f:Freq){
            if(f.second == maxFreq){
                NumOfMaxFreq++;
            }
        }
        int ans = (maxFreq - 1) * (n+1) + NumOfMaxFreq;
        ans = max(ans,(int)tasks.size());
        return ans;
    }
};