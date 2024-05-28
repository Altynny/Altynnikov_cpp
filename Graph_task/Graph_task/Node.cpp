#include "Node.h"

void Node::addNeighbour(Node* neighbour) {
	neighbours.insert(neighbour);
	//neighbour->neighbours.insert(this);
}

void Node::removeNeighbour(Node* neighbour) {
	neighbours.erase(neighbour);
	//neighbour->neighbours.erase(this);
}