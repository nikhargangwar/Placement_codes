There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

 

Example 1:


Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
Example 2:


Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
Example 3:

Input: n = 3, connections = [[1,0],[2,0]]
Output: 0


Based on the problem description, we have a tree, and node zero is the root.

However, the direction can point either from a parent to a child (positive), or from a child to its parent (negative).
To solve the problem, we traverse the tree and count edges that are directed from a parent to a child.
Direction of those edges need to be changed to arrive at zero node.

In the code below, I am using the adjacency list, and the sign indicates the direction. 
If the index is positive - the direction is from a parent to a child and we need to change it (change += (to > 0)).

Note that we cannot detect the direction for zero (-0 == 0), but it does not matter as we start our traversal from zero.





basic idea
consider whole graph as undirect graph and mark nodes which move away from 0 node as negative. Traverse complete graph as undirected graph and count the number of 
times the negative sign arrives. No of time negative sign arrives =  number of arrows whose direction is to be changed


solution

C++

int dfs(vector<vector<int>> &al, vector<bool> &visited, int from) {
    auto change = 0;
    visited[from] = true;
    for (auto to : al[from])
        if (!visited[abs(to)])
            change += dfs(al, visited, abs(to)) + (to > 0);
    return change;        
}
int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> al(n);
    for (auto &c : connections) {
        al[c[0]].push_back(c[1]);
        al[c[1]].push_back(-c[0]);
    }
    return dfs(al, vector<bool>(n) = {}, 0);
}