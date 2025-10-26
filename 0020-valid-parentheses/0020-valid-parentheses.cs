using System;
using System.Collections.Generic;

public class Solution {
    public bool IsValid(string s) {
        if (s.Length % 2 != 0) {
            return false;
        }

        Dictionary<char, char> bracketMap = new Dictionary<char, char>() {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        Stack<char> stack = new Stack<char>();

        foreach (char c in s) {
            if (bracketMap.ContainsKey(c)) {
                // Closing bracket
                if (stack.Count == 0 || stack.Pop() != bracketMap[c]) {
                    return false;
                }
            } else {
                // Opening bracket
                stack.Push(c);
            }
        }

        return stack.Count == 0;
    }
}