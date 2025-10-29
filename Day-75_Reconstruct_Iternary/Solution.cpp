//DFS Approach
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        map<string,multiset<string>> graph;
        int n=tickets.size();
        for(int i=0;i<n;i++){
            graph[tickets[i][0]].insert(tickets[i][1]);
        }
        dfs("JFK",graph,res);
        reverse(res.begin(),res.end());
        return res;
    }
    void dfs(string src,map<string,multiset<string>> &graph,vector<string> &res){
        auto &curr=graph[src];
        while(!curr.empty()){
            string dest = *curr.begin();
            graph[src].erase(curr.begin());
            dfs(dest,graph,res);
        }
        res.push_back(src);
    }
};

//Stack Approach
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (auto& t : tickets) graph[t[0]].push(t[1]);

        vector<string> result;
        stack<string> st;
        st.push("JFK");

        while (!st.empty()) {
            string curr = st.top();
            if (graph[curr].empty()) {
                result.push_back(curr);
                st.pop();
            } else {
                string next = graph[curr].top();
                graph[curr].pop();
                st.push(next);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

