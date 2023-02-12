#include <iostream>
#include <tuple>
#include "graph.h"

int main()
{
	heterogeneous::Graph<std::tuple<int, float>, int> s;
	s.addNode<std::tuple<int, float>, std::string, char, char, int>("Whatever this is", 'a', 'b', 0);
}