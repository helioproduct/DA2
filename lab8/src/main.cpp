#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

int main() {
    bool hasSolution = true;
    int m = 0, n = 0, cost = 0, numRow = 0;
    std::cin >> m >> n;
    cost = n;
    numRow = n + 1;

    std::vector<int> result;
    std::vector<std::vector<double> > matrix(m, std::vector<double>(n + 2));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            std::cin >> matrix[i][j];
        }
        matrix[i][numRow] = i + 1;
    }

    for (int col = 0; col < n; ++col) {
        int minRow = -1;
        int minCost = 51;
        for (int row = col; row < m; ++row) {
            if (matrix[row][col] != 0.0 && matrix[row][cost] < minCost) {
                minRow = row;
                minCost = matrix[row][cost];
            }
        }

        if (minRow == -1) {
            hasSolution = false;
            std::cout << "-1" << std::endl;
            break;
        }

        matrix[col].swap(matrix[minRow]);
        result.push_back(matrix[col][numRow]);
        for (int row = col + 1; row < m; ++row) {
            double c = matrix[row][col] / matrix[col][col];
            for (int i = col; i < n; ++i) {
                matrix[row][i] -= matrix[col][i] * c;
            }
        }
    }
    std::sort(result.begin(), result.end());

    if (hasSolution) {
        for (int i = 0; i < result.size(); ++i) {
            std::cout << result[i];
            if (i != result.size() - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}