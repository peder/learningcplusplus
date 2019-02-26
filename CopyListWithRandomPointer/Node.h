#pragma once
#include "pch.h"
#include "Sequence.h"

class Node {
public:
	unsigned int uniqueId;

	int val;
	Node* next;
	Node* random;

	Node() { uniqueId = (new Sequence())->getNext(); }

	Node(int _val, Node* _next, Node* _random) {
		uniqueId = (new Sequence())->getNext();
		val = _val;
		next = _next;
		random = _random;
	}
};