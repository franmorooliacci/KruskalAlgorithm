#include "graph.h"

ostream& operator <<(ostream& os, Graph G){

	os << "Graph: \n";
	for(auto x: G.E)
		os << x.first.first << " - " << x.first.second << ": weight = " << x.second << endl;

	return os;
}

void Graph::insertNode(const char& v){
	
	if(!(find(V.begin(), V.end(), v) != V.end())){
		V.push_back(v);
	}
}

void Graph::insertEdge(const char& v1, const char& v2, const int& weight){
	
	E.push_back(make_pair(make_pair(v1, v2), weight));
}

void Graph::insertEdge(){
	
	char v1,v2;
	int weight;
	
	cout<<"Enter node 1: ";
	cin>>v1;
	cout<<"Enter node 2: ";
	cin>>v2;
	cout<<"Enter weight: ";
	cin>>weight;
	
	this->insertEdge(v1, v2, weight);
}

void Graph::initialSet(const char& set, const char& node){
	
	C.names.insert({node, make_pair(set,'0')});
	C.components.insert({set, make_pair(1,node)});
}

void Graph::insert(){
	for(edge x: E){
		orderedGraph.push(x);
	}
}

char Graph::findSet(const char& x){
	return C.names[x].first;
}

void Graph::combineSets(const char& A, const char& B){
	
	int i;

	if(C.components[A].first > C.components[B].first){
		
		i = C.components[B].second;
		
		while(C.names[i].second != '0'){
			C.names[i].first = A;
			i = C.names[i].second;
		}

		C.names[i].first = A;
		
		if(C.names[A].second != '0'){

			i = C.names[A].second;

			while(C.names[i].second != '0'){
				i = C.names[i].second;	
			}
			
			C.names[i].second = B;

		} else {

			C.names[A].second = C.components[i].second;
		}
		
		C.components[B].second = '0';
		C.components[A].first += C.components[B].first;
		C.components[B].first = 0;
	
	} else {

		i = C.components[A].second;
		
		while(C.names[i].second != '0'){
			C.names[i].first = B;
			i = C.names[i].second;
		}

		C.names[i].first = B;

		if(C.names[B].second != '0'){

			i = C.names[B].second;
			
			while(C.names[i].second != '0'){
				i = C.names[i].second;	
			}

			C.names[i].second = A;

		} else {

			C.names[B].second = C.components[i].second;
		}

		C.components[A].second = '0';
		C.components[B].first += C.components[A].first;
		C.components[A].first = 0;
	}
}

void Graph::kruskal(){

	for(char x: V){
		this->initialSet(x,x);
	}
	this->insert();
	int n = V.size();

	while(n > 1){

		edge a = orderedGraph.top();
		orderedGraph.pop();
		char u = this->findSet(a.first.first);
		char v = this->findSet(a.first.second);

		if(u != v){
			this->combineSets(u, v);
			minimumSpanningTree.push_back(a);
			n--;
		}
	}

	int valueMinSpanningTree = 0;
	for(edge x: minimumSpanningTree){
		valueMinSpanningTree += x.second;
	}
	cout << "Minimum spanning tree: " << valueMinSpanningTree << endl;
}