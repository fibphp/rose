// Example of using Qing's graph interface for an arbitrary graph.

#include "rose.h"
#include <GraphDotOutput.h>
#include <VirtualGraphCreate.h>
using namespace std;

class Node : public MultiGraphElem {
     public:
          std::string name;
          Node( std::string n ) : MultiGraphElem( NULL ), name( n ) {}
          virtual std::string toString() const { return name; }
   };

class Edge : public MultiGraphElem {
     public:
          std::string label;
          Edge ( std::string label = "default edge" ) : MultiGraphElem( NULL ), label( label ) {};
          void Dump() const { printf ("EDGE: label = %s \n",label.c_str()); }
          virtual std::string toString() const { return label;}
   };

template <class NodeType, class EdgeType>
class GraphBuilder : public VirtualGraphCreateTemplate<NodeType, EdgeType> {
     public:
          void addNode ( NodeType* node );
          void addEdge ( NodeType* src, NodeType* snk, EdgeType* edge );
          GraphBuilder () : VirtualGraphCreateTemplate<NodeType, EdgeType> (NULL) {}
         ~GraphBuilder() { printf ("Inside of ~GraphBuilder() \n"); }
   };

template <class NodeType, class EdgeType> 
void GraphBuilder<NodeType, EdgeType>::addNode ( NodeType* node )
   { VirtualGraphCreateTemplate<NodeType,EdgeType>::AddNode ( node ); }

template <class NodeType, class EdgeType> 
void GraphBuilder<NodeType, EdgeType>::addEdge ( NodeType* src, NodeType* snk, EdgeType* edge )
   { VirtualGraphCreateTemplate<NodeType,EdgeType>::AddEdge ( src, snk, edge ); }

int main( int argc, char * argv[] )
   {
     GraphBuilder<Node, Edge> graph;

     Node* rose                   = new Node("ROSE");                   graph.addNode(rose);
     Node* docs                   = new Node("docs");                   graph.addNode(docs);
     Node* scripts                = new Node("scripts");                graph.addNode(scripts);
     Node* src                    = new Node("src");                    graph.addNode(src);
     Node* tests                  = new Node("tests");                  graph.addNode(tests);
     Node* tools                  = new Node("tools");                  graph.addNode(tools);
     Node* tutorial               = new Node("tutorial");               graph.addNode(tutorial);
     Node* frontend               = new Node("frontend");               graph.addNode(frontend);
     Node* midend                 = new Node("midend");                 graph.addNode(midend);
     Node* backend                = new Node("backend");                graph.addNode(backend);
     Node* thirdPartyLibraries    = new Node("3rdPartyLibraries");      graph.addNode(thirdPartyLibraries);
     Node* roseExtensions         = new Node("RoseExtensions");         graph.addNode(roseExtensions);
     Node* roseIndependentSupport = new Node("RoseIndependentSupport"); graph.addNode(roseIndependentSupport);
     Node* rosetta                = new Node("ROSETTA");                graph.addNode(rosetta);
     Node* util                   = new Node("util");                   graph.addNode(util);

     graph.addEdge(rose,docs,                  new Edge("subdir1"));
     graph.addEdge(rose,scripts,               new Edge("subdir2"));
     graph.addEdge(rose,src,                   new Edge("subdir3"));
     graph.addEdge(rose,tests,                 new Edge("subdir4"));
     graph.addEdge(rose,tools,                 new Edge("subdir5"));
     graph.addEdge(rose,tutorial,              new Edge("subdir6"));
     graph.addEdge(src,frontend,               new Edge("subdirA"));
     graph.addEdge(src,midend,                 new Edge("subdirB"));
     graph.addEdge(src,backend,                new Edge("subdirC"));
     graph.addEdge(src,thirdPartyLibraries,    new Edge("subdirD"));
     graph.addEdge(src,roseExtensions,         new Edge("subdirE"));
     graph.addEdge(src,roseIndependentSupport, new Edge("subdirF"));
     graph.addEdge(src,rosetta,                new Edge("subdirG"));
     graph.addEdge(src,util,                   new Edge("subdirH"));

  // Build a wrapper for outputing DOT graph 
     GraphDotOutput<GraphBuilder<Node, Edge> > output(graph);

  // Write out the DOT graph
     output.writeToDOTFile("customGraph.dot", "custom graph");

     return 0;
   }

