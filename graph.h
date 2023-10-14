#include <iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<pair<char,char>, int> edge;

typedef struct setC{
	map<char, pair<char, char>> names;
	map<char, pair<int, char>> components;
} setC;

class LessValue{
public:
	bool operator()(edge e1, edge e2){return e1.second > e2.second;}
};

typedef priority_queue<edge, vector<edge>, LessValue> tree;

class Graph {
	vector<char> V;
	vector<edge> E;
	tree orderedGraph;
	setC C;
	vector<edge> minimumSpanningTree;

public:
	Graph(){}
	~Graph(){}
	void insertNode(const char&);
	void insertEdge(const char&, const char&, const int&);
	void insertEdge();
	void initialSet(const char&, const char&);
	void combineSets(const char&, const char&);
	char findSet(const char&);
	void kruskal();
	void insert();

	friend ostream& operator <<(ostream&, Graph);
};