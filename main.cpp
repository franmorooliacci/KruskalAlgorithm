#include "graph.cpp"

int main(){
	
	Graph G;

	G.insertNode('1');
	G.insertNode('2');
	G.insertNode('3');
	G.insertNode('4');
	G.insertNode('5');
	G.insertNode('6');

	G.insertEdge('1','2',6);
	G.insertEdge('1','3',1);
	G.insertEdge('1','4',5);
	G.insertEdge('2','3',5);
	G.insertEdge('2','5',3);
	G.insertEdge('3','4',5);
	G.insertEdge('3','5',6);
	G.insertEdge('3','6',4);
	G.insertEdge('4','6',2);
	G.insertEdge('5','6',6);

	G.kruskal();
	
	return 0;
}