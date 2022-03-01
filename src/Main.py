from Multigraph import Multigraph

g = Multigraph()

g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(2, 1)
g.add_edge(1, 3)
g.add_edge(1, 3)
g.add_edge(3, 4)
g.add_edge(4, 0)

print("Graph: ")
g.pretty_print()

print("Line graph: ")
g.line_graph().pretty_print()
