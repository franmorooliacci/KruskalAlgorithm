# Kruskal's Algorithm

Kruskal's algorithm finds a minimum spanning tree of an undirected edge-weighted graph. A minimum spanning tree of a connected graph is a subset of the edges that forms a tree that includes every node, where the sum of the weights of all the edges in the tree is minimized.

## How to use it

1. Download the files.
  
2. Open the main.cpp file with a text editor.

3. In the main.cpp file:

   * Every call to the **insertNode()** function inserts a node in the graph which name is single character specified between the parenthesis with single quotation marks. Change the default nodes' names accordingly. You can increase or decrease the number of nodes by adding or deleting **insertNode()** function calls.

   * Every call to the **insertEdge()** function inserts an edge with weight that connects two nodes of the graph. The function receives three values separated by commas. The first two are the nodes' names, each one specified with single quotation marks. The third value is the edge's weight. Modify the default values as you need. You can increase or decrease the number of edges by adding or deleting **insertEdge()** function calls.

   * Once you are done, save the changes.

![Screenshot from 2023-10-19 09-45-57](https://github.com/franmorooliacci/Ford-FulkersonAlgorithm/assets/144138185/066e288d-5898-4de9-8b6e-e5a34a3dadb7)

4. Open the terminal in the same directory you have the three program's files and run the command:\
   `g++ -Wall main.cpp -o kruskal`

5. Use `./kruskal` to execute the program. The value of the minimum spanning tree will be displayed on the screen.
