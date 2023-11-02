#include <iostream>
#include <map>
#include <string>
#include <vector>

const char TERMINAL = '$';

class SuffixNode {
   public:
    int leftIndex, rightIndex;
    SuffixNode* suffixLink;
    std::map<char, SuffixNode> children;
};

class SuffixTree {
   public:
    SuffixTree(const std::string&);
    ~SuffixTree();

   public:
    void Build(const std::string&);
    void AddSuffix(const std::string&);
    bool Find(const std::string&);
    void PrintText();

   private:
    SuffixNode root;
    std::string text;
    size_t END;
};

SuffixTree::SuffixTree(const std::string& source_string) {
    text = source_string;
}

void SuffixTree::PrintText() { std::cout << text << std::endl; }

SuffixTree::~SuffixTree() {}

void SuffixTree::Build(const std::string& source_string) {
    text = source_string;
}

void SuffixTree::AddSuffix(const std::string& suffix) {}

void foo() {}

int main() {
    std::string s = "hello";
    SuffixTree tree = SuffixTree(s);
    tree.PrintText();
    return 0;
}
