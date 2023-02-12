#pragma once
#include <vector>
#include <tuple>
#include <type_traits>
#include <utility>
/*
* Brainstorming:
* 1- Graphs could be useful for path tracking
* 2- Graphs could be useful to map a network topology
* 3- Useful for neural netwrork
* 4- Graphs could be used for 
*/

// there are two types of graphs directed, and undirected graphs
// each should have their own class repressentation, they both have common features so they
// can inherit from a base class Graph


// There are two possible implementations, two types of nodes, or one singular type


/*
* Here's what's gonna happen next:
*	1- Create the Graph, directedGraph, and undirectedGraph classes
*	2- Create all the features and stuff adj list and whatnot
*	3- Make the class accept input text files as 2 formats: .txt files and json formats
*	4- Use the OLC game engine to draw the graphs and circles (could be seperated or integrated)
*/
	/*
	* General functions which will be used across all types of Graphs
	*/
enum _Error
{
	_Errorno = 0
};
template <class _Type>
struct is_tuple : std::false_type {};

template <class... Args>
struct is_tuple<std::tuple<Args...>> : std::true_type {};

template <class _Type>
constexpr bool is_tuple_v = is_tuple<_Type>::value;


namespace heterogeneous {
	template <class _Neighbours, class... _Content>
	struct node {
		static_assert(is_tuple_v<_Neighbours>, "First argument of a heterogenous graph must be a tuple");
		std::vector<_Neighbours> neighbours;
		std::tuple<_Content...> data;
	};
	template<typename _FirstNeighbour, typename = std::enable_if_t<is_tuple_v<_FirstNeighbour>, void>>
	class Graph {
	private:
		void* head = nullptr;
	public:
		template<class _Neighbour, class ..._Content>
		_Error addNode(_Content... k)
		{
			static_assert(is_tuple_v<_Neighbour>, "Template first argument needs to be a tuple");
			if (head == nullptr)
			{
				bool _is_same = std::is_same_v<_Neighbour, _FirstNeighbour>;
				static_assert(std::is_same_v<_Neighbour, _FirstNeighbour>, "Incompatible template argument with the original declaration. Check your object declaration first argument");
				node<_Neighbour, _Content...>* s = new node<_Neighbour, _Content...>;
				s->data = std::make_tuple(k...);
				head = (node<_Neighbour, _Content...>*)s;
			}
			return _Error::_Errorno;
		}
		Graph() = default;
		~Graph() {
			delete head;
		}
	};
		
}

namespace homogeneous {
	template <class... _Content>
	struct node {
		std::vector<std::tuple<_Content...>*> neighbours;
		std::tuple<_Content...> data;
	};
	class Graph {
	private:
		int a = 20;
	public:
		template<class neighbour, class ..._Content>
		node<neighbour, _Content...> addNode(_Content... k)
		{
			node<neighbour, _Content...> s;
			s.data = std::make_tuple(k...);
			return s;
		}
		template<class ..._Content>
		node<_Content...> addNode(_Content... k)
		{
			node<_Content...> s;
			s.data = std::make_tuple(k...);
			return s;
		}
		Graph() = default;
		~Graph() {}
	};
}
