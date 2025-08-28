//Brute Force Approach
class Solution {
public:
    string simplifyPath(string path) {
        string result = "/";
        int n = path.size();
        
        for (int i = 0; i < n; i++) {
            if (path[i] == '/') continue; // Skip multiple slashes
            
            string dir = "";
            while (i < n && path[i] != '/') {
                dir += path[i];
                i++;
            }
            
            if (dir == ".") continue; // Ignore current directory
            if (dir == "..") {
                // Remove the last directory
                while (!result.empty() && result.back() != '/') {
                    result.pop_back();
                }
                if (!result.empty()) result.pop_back();
            } else {
                // Append valid directory name
                result += dir + "/";
            }
        }
        
        // Remove trailing slash, if any
        if (result.size() > 1 && result.back() == '/') result.pop_back();
        return result;
    }
};
//Recursion Approach
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> components = splitPath(path);
        vector<string> result;
        simplify(components, 0, result);
        return constructPath(result);
    }
    
private:
    // Helper function to split the path into components
    vector<string> splitPath(const string& path) {
        vector<string> components;
        string current = "";
        for (char c : path) {
            if (c == '/') {
                if (!current.empty()) {
                    components.push_back(current);
                    current.clear();
                }
            } else {
                current += c;
            }
        }
        if (!current.empty()) components.push_back(current);
        return components;
    }
    
    // Recursive function to simplify the path
    void simplify(const vector<string>& components, int index, vector<string>& result) {
        if (index == components.size()) return; // Base case
        
        string dir = components[index];
        if (dir == "." || dir.empty()) {
            simplify(components, index + 1, result); // Skip current directory
        } else if (dir == "..") {
            if (!result.empty()) result.pop_back(); // Go to parent directory
            simplify(components, index + 1, result);
        } else {
            result.push_back(dir); // Add valid directory
            simplify(components, index + 1, result);
        }
    }
    
    // Helper function to construct the simplified path
    string constructPath(const vector<string>& result) {
        string simplifiedPath = "/";
        for (int i = 0; i < result.size(); i++) {
            simplifiedPath += result[i];
            if (i != result.size() - 1) simplifiedPath += "/";
        }
        return simplifiedPath;
    }
};
//Optimal Approach
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack; // Stack to store valid directory names
        string currentDir;    // Temporary storage for the current directory name

        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/') {
                // If we encounter a '/', process the current directory name if it's valid
                if (!currentDir.empty()) {
                    if (currentDir == "..") {
                        // ".." means go up one directory (pop from stack)
                        if (!stack.empty()) stack.pop_back();
                    } else if (currentDir != ".") {
                        // Valid directory name, push it onto the stack
                        stack.push_back(currentDir);
                    }
                    currentDir.clear(); // Reset currentDir for the next component
                }
            } else {
                // Build the current directory name
                currentDir += path[i];
            }
        }

        // Process the last directory name (if any) at the end of the path
        if (!currentDir.empty()) {
            if (currentDir == "..") {
                if (!stack.empty()) stack.pop_back();
            } else if (currentDir != ".") {
                stack.push_back(currentDir);
            }
        }

        // Construct the simplified path from the stack
        string simplifiedPath = "/";
        for (int i = 0; i < stack.size(); i++) {
            simplifiedPath += stack[i];
            if (i != stack.size() - 1) simplifiedPath += "/";
        }

        return simplifiedPath;
    }
};