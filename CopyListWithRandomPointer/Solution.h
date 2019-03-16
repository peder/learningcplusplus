#pragma once
#include "pch.h"
#include "Node.h"

class Solution {
public:
	Node* copyRandomList(Node* head)
	{
		auto test = std::make_optional(1);
		std::unordered_set<int> nodesToBuild;
		std::unordered_map<int,
			std::tuple<
				std::optional<int>,
				std::optional<int>>> nodeDetails;
		std::unordered_map<int, Node*> nodes;

		buildNodeStackRecursive(head, nodesToBuild, nodeDetails);

		for(auto nodeVal : nodesToBuild)
		{
			auto node = new Node();
			node->val = nodeVal;

			nodes[nodeVal] = node;
		}

		for (auto nodeDetail : nodeDetails)
		{
			auto val = nodeDetail.first;
			auto nextVal = std::get<0>(nodeDetail.second);
			auto randomVal = std::get<1>(nodeDetail.second);

			auto* node = nodes[val];

			if (nextVal.has_value())
			{
				node->next = nodes[nextVal.value()];
			}

			if (randomVal.has_value())
			{
				node->random = nodes[randomVal.value()];
			}
		}

		return nodes[head->val];
	}

	void buildNodeStackRecursive(
		Node* node,
		std::unordered_set<int>& nodesToBuild,
		std::unordered_map<int, std::tuple<std::optional<int>, std::optional<int>>>& nodeDetails)
	{
		if (nodeDetails.count(node->val) > 0) return;

		nodesToBuild.insert(node->val);
		nodeDetails[node->val] = std::make_tuple(
			node->next ? std::make_optional(node->next->val) : std::nullopt,
			node->random ? std::make_optional(node->random->val) : std::nullopt);

		if (node->next)
		{
			buildNodeStackRecursive(node->next, nodesToBuild, nodeDetails);
		}

		if (node->random)
		{
			buildNodeStackRecursive(node->random, nodesToBuild, nodeDetails);
		}
	}
};