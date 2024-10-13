#include <compare>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

class Node {
public:
  std::string name;
  Node *parent;
  std::vector<Node> children;

  Node() : name(""), parent(nullptr) {}
  Node(std::string name) : name(name), parent(nullptr) {}
  Node(std::string name, Node *parent) : name(name), parent(parent) {}

  void add_child(Node child) const {
    const_cast<std::vector<Node> &>(children).push_back(child);
  }

  int descendants() const {
    int count = 0;
    for (Node child : children) {
      count += 1 + child.descendants();
    }
    return count;
  }

  int generation() {
    int count = 0;
    Node *current = this;
    while (current->parent != nullptr) {
      count++;
      current = current->parent;
    }
    return count;
  }

  std::strong_ordering operator<=>(const Node &other) const {
    return name <=> other.name;
  }

  auto operator==(const Node &other) const -> bool {
    return name == other.name;
  }
};

template <> struct std::hash<Node> {
  std::size_t operator()(const Node &node) const {
    return std::hash<std::string>{}(node.name);
  }
};

int main() {
  std::string input_buffer{};
  std::unordered_set<Node> nodes{};

  while (input_buffer != "***") {
    std::string child;
    std::string parent;
    std::cin >> child;
    if (child == "***") {
      break;
    }
    std::cin >> parent;
    if (parent == "***") {
      break;
    }

    Node child_node{child};
    Node parent_node{parent};

    if (nodes.find(parent_node) == nodes.end()) {
      parent_node.add_child(child_node);
      child_node.parent = &parent_node;
      nodes.insert(parent_node);
      nodes.insert(child_node);
    } else {
      auto it = nodes.find(parent_node);
      it->add_child(child_node);
      child_node.parent = const_cast<Node *>(&(*it));
      nodes.insert(child_node);
    }
  }

  for (Node node : nodes) {
    if (node.parent == nullptr) {
      std::cout << node.name << " " << node.descendants() << std::endl;
    }
  }

  return 0;
}