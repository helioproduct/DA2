#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int> > data(n, std::vector<int>(m));
    std::string row;
    for (int i = 0; i < n; i++) {
        std::cin >> row;
        for (int j = 0; j < row.size(); j++) {
            // data[i][j] = row[j] - '0';
        }
    }

    for (std::vector<int> vec : data) {
        for (int number : vec) {
            std::cout << number << " ";
        }
        std::cout << std::endl;
    }
}
