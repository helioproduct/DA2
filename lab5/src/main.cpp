#include <iostream>
#include <vector>
#include <map>

const char TERMINAL = '$';

class SuffixNode {
public:
    int leftIndex, rightIndex;
    SuffixNode *suffixLink;
    std::map<char, SuffixNode> children;
};

class SuffixTree {
public:
    SuffixTree(const std::string &text);
    ~SuffixTree();

private:
    void Build(const std::string &text);
    void AddSuffix(const std::string &suffix);
    bool Find(const std::string &pattern);

private:
    SuffixNode root;
    std::string text;
};

void SuffixTree::Build(const std::string &text) {

}

void SuffixTree::AddSuffix(const std::string &suffix) {

}


int main() {
}
