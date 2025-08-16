> [Longest Repeating Character Replacement] - https://leetcode.com/problems/longest-repeating-character-replacement/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Sliding Window + MaxFrequency
--------------------------------------------------------------------------------------------------------------------------------------
# PsuedoCode
* For Brute force Approach
FUNCTION longestRepeatingCharacterReplacement(s, k):
    maxLength = 0  // Variable to track the maximum length of valid substring

    // Outer loop to pick the starting index of the substring
    FOR start FROM 0 TO length of s - 1:
        
        // Inner loop to pick the ending index of the substring
        FOR end FROM start TO length of s - 1:
            
            substring = s[start:end]  // Extract the substring
            
            // Count frequency of each character in the substring
            freq = [0] * 26  // Array to store frequency of each letter (A-Z)
            FOR char IN substring:
                freq[char - 'A'] += 1
            
            // Find the frequency of the most common character
            maxFreq = MAX(freq)
            
            // Calculate replacements needed
            replacements = (length of substring) - maxFreq
            
            // Check if replacements are within limit
            IF replacements <= k:
                maxLength = MAX(maxLength, length of substring)

    RETURN maxLength

* For Optimized Approach
Initialize left, right pointers = 0
Create freq array for 26 letters
Set maxFreq = 0, maxLen = 0
While right < string length:
  - Increase freq of s[right]
  - Update maxFreq
  - If (window size - maxFreq) > k:
   - Decrease freq of s[left]
   - Move left pointer
  - Update maxLen
  - Move right pointer
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

# 1. **Brute Force (O(n³))**

### Approach:

1. Iterate over all substrings `s[i...j]`.
2. For each substring:

   * Count the frequency of each character.
   * Find the maximum frequency `maxFreq`.
   * The number of replacements needed = `substring length - maxFreq`.
   * If replacements ≤ `k`, it’s a valid candidate.
3. Keep track of the maximum valid length.

### Intuition:

* We brute force by **trying every substring** and checking if it can be converted into a valid substring.
* Very slow, because for each substring we re-count frequencies from scratch.

### Complexity:

* Generating substrings: **O(n²)**
* Counting frequencies for each substring: **O(n)**
* Overall: **O(n³)**
* Space: **O(26) = O(1)**

✅ Works for small inputs, but not scalable.

---

# 2. **Improved Brute Force (O(n²))**

### Approach:

1. Fix the starting point `i`.
2. Maintain a frequency array as we extend the substring to the right (`j`).
3. At each step:

   * Update frequency of the new character.
   * Track `maxFreq`.
   * If `(length - maxFreq) <= k`, update the answer.
4. This avoids re-counting frequencies for every substring.

### Intuition:

* Instead of recalculating from scratch, we reuse frequency counts as we expand.
* Still quadratic, but much faster than the naive brute force.

### Complexity:

* Outer loop over `i`: **O(n)**
* Inner loop expanding `j`: **O(n)**
* Total: **O(n²)**
* Space: **O(26) = O(1)**

✅ Much better than O(n³), but still too slow for large strings (n up to 10⁵).

--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

### Approach:

1. Use a sliding window `[left, right]`.
2. Maintain a frequency map of characters inside the window.
3. Track the maximum frequency `maxFreq` in the window.
4. Condition:

   * Window size = `right - left + 1`
   * Replacements needed = `window size - maxFreq`
   * If replacements > k → shrink window from the left.
5. Keep updating the maximum valid window size.

### Intuition:

* Instead of checking all substrings, we **expand a window greedily**.
* If the window becomes invalid (too many replacements), we shrink it until valid again.
* Ensures linear time because each character enters and leaves the window at most once.

### Complexity:

* Each character processed at most twice → **O(n)**
* Space: **O(26) = O(1)**
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
340. Longest Substring with At Most K Distinct Characters - https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/
904. Fruit Into Baskets - https://leetcode.com/problems/fruit-into-baskets/description/
1016. Binary String With Substrings Representing 1 To N - https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Character compression, compression algorithms

