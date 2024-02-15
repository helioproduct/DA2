#include <iostream>
#include <vector>
#include <algorithm>

void dfs(std::vector<std::vector<int> > &graph, std::vector<bool> &used,
         std::vector<std::vector<int> > &components, int v) {
    if (used[v]) {
        return;
    }
    components.back().push_back(v);
    used[v] = true;
    for (int i = 0; i < graph[v].size(); i++) {
        dfs(graph, used, components, graph[v][i]);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int> > graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::vector<std::vector<int> > components;
    std::vector<bool> used(n);

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            std::vector<int> component;
            components.push_back(component);
            dfs(graph, used, components, i);
        }
    }

    for (int i = 0; i < components.size(); i++) {
        std::sort(components[i].begin(), components[i].end());
    }

    for (std::vector<int> component : components) {
        for (int i = 0; i < component.size(); i++) {
            std::cout << component[i] + 1 << " ";
        }
        std::cout << std::endl;
    }
}
