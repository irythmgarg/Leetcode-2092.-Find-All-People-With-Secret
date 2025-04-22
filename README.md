# Leetcode-2092.-Find-All-People-With-Secret
/*
README.md

# 🕵️‍♂️ Secret Sharing Tracker

This project provides a solution to a problem where a secret is being shared among people through a series of meetings. The objective is to find all the people who will eventually learn the secret.

## 📘 Problem Statement

You are given:
- `n` people numbered from `0` to `n - 1`.
- A list of `meetings`, where each meeting is represented as `[person1, person2, time]`.
- Initially, person `0` and another given person `firstPerson` know a secret at time `0`.

The secret can only be shared **forward in time**, meaning a person can only share the secret in a meeting **at or after** the time they learn it.

Your task is to find **all the people who will eventually know the secret**.

## 🧠 Approach

This solution uses **Breadth-First Search (BFS)** to simulate the spread of the secret.

### ✅ Key Concepts:
- **Graph Representation:** Meetings are modeled as a graph where each person is a node and each meeting is an edge with a timestamp.
- **BFS Traversal:** Start from person `0` and `firstPerson`, and propagate the secret using a queue.
- **Condition for Propagation:** A person can only share the secret if the meeting time is **greater than or equal to** the time they learned it.
- **Visited Tracking:** Maintain a `visited` array and `whenknows` array to record when each person learns the secret.

---

💡 Optimization Notes
The algorithm ensures each person is visited only once with the earliest possible time.

Uses unordered_map for efficient graph building and queue for BFS traversal.

🧪 Time & Space Complexity
Time Complexity: O(M + N) where M is the number of meetings and N is the number of people.

Space Complexity: O(M + N) for the graph and auxiliary data structures.

🧩 Useful For
Graph traversal problems

Simulation-based questions

BFS on dynamic graphs

Competitive programming challenges

---
## 🛠 Example

```cpp
int n = 6;
vector<vector<int>> meetings = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}};
int firstPerson = 1;

Solution sol;
vector<int> result = sol.findAllPeople(n, meetings, firstPerson);
// Output: [0, 1, 2, 3, 5]
