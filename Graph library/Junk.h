#pragma once
typedef unsigned __int64 size_t;
template<Graph::size_t pos, typename _Ty>
class _vals
{
public:
	_Ty value;
};
template<Graph::size_t i, typename... Items>
class _valsProxy;

template<Graph::size_t i>
class _valsProxy<i> {};

template<Graph::size_t i, typename _first, typename... _Rest>
class _valsProxy<i, _first, _Rest...> : public _vals<i, _first>, _valsProxy<i + 1, _Rest...>
{	};

template<typename... Items>
using nodeData = _valsProxy<0, Items...>;

template<Graph::size_t i, typename _first, typename... _Rest>
_first& Get(_valsProxy<i, _first, _Rest...>& ARG) {
	return ARG._vals<i, _first>::value;
}