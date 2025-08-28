> [Simplify Path] - https://leetcode.com/problems/simplify-path/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

- A single period '.' represents the current directory.
- A double period '..' represents the previous/parent directory.
- Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
- Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' - and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

- The path must start with a single slash '/'.
- Directories within the path must be separated by exactly one slash '/'.
- The path must not end with a slash '/', unless it is the root directory.
- The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
- Return the simplified canonical path.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
Stack – Path Resolution
--------------------------------------------------------------------------------------------------------------------------------------
# PsuedoCode

--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

1. Traverse the input path character by character.
2. Skip multiple slashes (`////`).
3. Extract each directory name between slashes.
4. If the name is `"."` → ignore (current directory).
5. If the name is `".."` → remove the last added directory from result.
6. Otherwise → append the directory to the result string.
7. At the end, remove any trailing slash.
8. Return the simplified path.

⏱ **Time Complexity:** O(N²) (string operations + backtracking).
📦 **Space Complexity:** O(N).
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

### 🔹 Recursive Approach

1. Split the path into components (using `/` as delimiter).
2. Recursively process components one by one:

   * If `"."` → skip.
   * If `".."` → pop the last valid directory from result (if exists).
   * Else → add the directory to the result.
3. Recurse until all components are processed.
4. Construct final path from the result vector.

⏱ **Time Complexity:** O(N) (but recursion adds overhead).
📦 **Space Complexity:** O(N) (stack + recursion depth).

---

### 🔹 (Stack-based)

1. Use a stack to store valid directory names.
2. Traverse the path and build directory names between `/`.
3. When a directory is complete:

   * If `".."` → pop from stack (if not empty).
   * If `"."` → ignore.
   * Else → push directory into stack.
4. After traversal, construct path from stack elements.
5. Return simplified path starting with `/`.

⏱ **Time Complexity:** O(N)
📦 **Space Complexity:** O(N)
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
402. Remove K Digits - https://leetcode.com/problems/remove-k-digits/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
File system navigation, Linux path resolution (cd ..)

