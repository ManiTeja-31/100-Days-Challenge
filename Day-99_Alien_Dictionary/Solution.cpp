//Topological Sort using Kahn's Algorithm
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;

        // Step 1: Initialize indegree for all characters
        for (auto& w : words) {
            for (auto& c : w) indegree[c] = 0;
        }

        // Step 2: Build graph (edges)
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool foundDiff = false;

            for (int j = 0; j < len; j++) {
                char c1 = w1[j], c2 = w2[j];
                if (c1 != c2) {
                    if (!graph[c1].count(c2)) {
                        graph[c1].insert(c2);
                        indegree[c2]++;
                    }
                    foundDiff = true;
                    break;
                }
            }

            // Invalid case: prefix situation ("abc", "ab")
            if (!foundDiff && w1.size() > w2.size()) return "";
        }

        // Step 3: BFS (Kahn's Algorithm)
        queue<char> q;
        for (auto& [c, deg] : indegree)
            if (deg == 0) q.push(c);

        string result;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            result += c;
            for (char nei : graph[c]) {
                if (--indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // Step 4: If not all characters used → cycle
        if (result.size() < indegree.size()) return "";

        return result;
    }
};

//Topological Sort using DFS
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        for (auto& w : words)
            for (auto& c : w) graph[c];

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool foundDiff = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].insert(w2[j]);
                    foundDiff = true;
                    break;
                }
            }

            if (!foundDiff && w1.size() > w2.size()) return "";
        }

        unordered_map<char, int> state; // 0=unvisited,1=visiting,2=done
        string order;
        for (auto& [c, _] : graph) {
            if (!dfs(c, graph, state, order)) return "";
        }
        reverse(order.begin(), order.end());
        return order;
    }

    bool dfs(char c, unordered_map<char, unordered_set<char>>& graph,
             unordered_map<char, int>& state, string& order) {
        if (state[c] == 1) return false; // cycle
        if (state[c] == 2) return true;

        state[c] = 1;
        for (auto& nei : graph[c]) {
            if (!dfs(nei, graph, state, order)) return false;
        }
        state[c] = 2;
        order += c;
        return true;
    }
};
