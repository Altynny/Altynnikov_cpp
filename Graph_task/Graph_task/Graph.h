#pragma once
#include "Node.h"

typedef set<Node*>::const_iterator node_iterator;
class Graph {
	set<Node*> nodes;
public:
	void addNode(Node* node); // нужно проверять на имя
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end);
	void removeEdge(Node* begin, Node* end);
	//node_iterator begin() const { return nodes.begin(); }
	//node_iterator end() const { return nodes.end(); }
};