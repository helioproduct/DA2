
#include <chrono>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using namespace std::chrono;

int maxRectangleArea(vector<vector<int> >& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int> > height(n, vector<int>(m, 0));
    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) {
                height[i][j] = (i == 0) ? 1 : height[i - 1][j] + 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        stack<int> indices;
        int j = 0;
        while (j < m) {
            if (indices.empty() || height[i][indices.top()] <= height[i][j]) {
                indices.push(j++);
            } else {
                int tp = indices.top();
                indices.pop();
                int area = height[i][tp] *
                           (indices.empty() ? j : j - indices.top() - 1);

                maxArea = max(maxArea, area);
            }
        }

        while (!indices.empty()) {
            int tp = indices.top();
            indices.pop();
            int area =
                height[i][tp] * (indices.empty() ? m : m - indices.top() - 1);
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char ch;
            cin >> ch;
            matrix[i][j] = ch - '0';
        }
    }
    auto start = high_resolution_clock::now();
    cout << maxRectangleArea(matrix) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << endl;

    return 0;
}
