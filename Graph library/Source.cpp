#include <iostream>
#include <tuple>
#include "graph.h"

int main()
{
	heterogeneous::Graph<std::tuple<int, float>, int> s;

	for (size_t i = 0.; i < 10; i++)
	{
		s.addNode<std::tuple<int, float>, std::string, char, char, int>("Whatever this is", 'a', 'b', i);
	}




	system("pause");
}