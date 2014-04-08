#ifndef GRAPH_H
#def GRAPH_H

template<typename T, typename E>
class Graph<T, E> {
friend istream &operator >> (istream &in, Graph<T, E> &G); // 输入
friend ostream &operator << (ostream &out, Graph<T, E> &G); // 输出
public:
	Graph();
	~Graph();
	T getValue(int i);
	E getWeight
};
#endif