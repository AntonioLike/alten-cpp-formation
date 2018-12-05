#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
	char vertex[3];
	double weight;
};

bool compareEdges(Edge e1, Edge e2) {
	return e1.weight < e2.weight;
}

void krustalAlgorithm(std::vector<Edge> &graph) {
	//Remove loops
	for (unsigned int i = 0; i < graph.size(); i++) {
		if (graph[i].vertex[0] == graph[i].vertex[1])
			graph.erase(graph.begin() + i);
	}

	//Remove the non minimum edge
	for (unsigned int i = 0; i < graph.size(); i++) {
		for (unsigned int j = 0; j < graph.size(); j++) {
			//this "if" checks if the edges are the same by comparing the vertex. Need to see if the vertex aren't inverted
			if (j != i) {
				if (!strcmp(graph[i].vertex, graph[j].vertex)) {
					if (graph[i].weight > graph[j].weight)
						graph.erase(graph.begin() + i);
					else
						graph.erase(graph.begin() + j);
				}
				else if ((graph[i].vertex[0] == graph[j].vertex[1] && graph[i].vertex[1] == graph[j].vertex[0]))
				{
					if (graph[i].weight > graph[j].weight)
						graph.erase(graph.begin() + i);
					else
						graph.erase(graph.begin() + j);
				}
			}
		}
	}

	//Order the edges
	sort(graph.begin(), graph.end(), compareEdges);

	//Create the minimum spanning tree
	std::string vertexes;
	
	for (unsigned int i = 0; i < graph.size(); i++) {
		for (unsigned int j = 0; j < i; j++) {
			vertexes += graph[j].vertex;
		}
		if (vertexes.find(graph[i].vertex[0]) != std::string::npos && vertexes.find(graph[i].vertex[1]) != std::string::npos)
			graph.erase(graph.begin() + i);
	}
}

int main()
{
	Edge graph[8] = { {"AA",8},{"AB",2},{"BD",5},{"DD",4},{"DC",3},{"CA",2},{"CA",12},{"CB",1} };
	std::vector<Edge> graphV(graph,graph+sizeof(graph)/sizeof(graph[0]));

	std::cout << "my vector contains: ";
	for (unsigned int i = 0; i < graphV.size(); i++)
		std::cout << ' ' << graphV[i].vertex << "," << graphV[i].weight;
	std::cout << '\n';

	krustalAlgorithm(graphV); 

	std::cout << "my vector after krustalAlgorithm contains: ";
	for (std::vector<Edge>::iterator it = graphV.begin(); it != graphV.end(); ++it)
		std::cout << ' ' << (*it).vertex << "," << (*it).weight;
	std::cout << '\n';
}
