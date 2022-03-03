from Multigraph import Multigraph
from Family import Family
import numpy as np

class Driver: 
    def __init__(self, graph, family):
        self.graph = graph
        self.family = family

    def Unitarize(self):
        print("\tEulerifying the graph...")
        E_bot = self.graph.eulerify()
        print("\tDone!")

        print("\tComputing line graph...")
        overrightarrow_G = self.graph.line_graph()
        print("\tDone!")

        tilde_M = overrightarrow_G.to_adjacency_matrix()
        hat_M = np.zeros(tilde_M.shape)

        graph_nodes = list(self.graph.nodes())
        line_graph_nodes = list(overrightarrow_G.nodes())
        print("\tUnitarizing the matrix...")
        for node in graph_nodes:
            ingoing_of_node = self.graph.ingoing_edges(node)
            n = len(ingoing_of_node)
            U = self.family.get_matrix(n, node)
            c = 0
            for edge in ingoing_of_node:
                edge_to_number = line_graph_nodes.index(edge)
                hat_M[edge_to_number] = self.sparse_sub(tilde_M[edge_to_number], U[c])
                c += 1
        print("\tDone!")
        return hat_M


    def set_U_for_node(self, node, U):
        self.family.set_matrix(U, node)

    def set_U_for_nodes(self, nodes, U):
        for node in nodes:
            self.set_U_for_node(node, U)

    def set_U_for_all_nodes(self, U):
        self.set_U_for_nodes(self.graph.nodes(), U)

    def set_U_for_all_n_degree_nodes(self, U):
        degree = U.shape[0]
        degree_ok_nodes = [node for node in self.graph.nodes() if self.graph.indegree(node) == degree]
        self.set_u_for_nodes(degree_ok_nodes, U)

    def sparse_sub(self, r, rr):
        c = 0
        r = [float(k) for k in r]
        for k in range(len(r)):
            if r[k] != 0: 
                
                r[k] = rr[c]
                c += 1

        return r