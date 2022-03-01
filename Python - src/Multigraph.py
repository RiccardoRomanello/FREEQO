from Edge import Edge
import numpy as np

class Multigraph: 

    def __init__(self):
        self.edges = 0
        self.adj_list = { }
        self.multiplicity = { }
        self.in_degree = { }
        self.out_degree = { }


    def indegree(self, n):
        return self.in_degree.get(n, 0)
    
    def outdegree(self, n):
        return self.out_degree.get(n, 0)

    def balance(self, n):
        return self.outdegree(n) - self.indegree(n)

    def edge_multiplicity(self, e):
        return self.multiplicity.get(e, 0)

    def edge_count(self):
        return self.edges

    def init_node(self, node):
        if not node in self.adj_list.keys():
            self.adj_list[node] = []
    
        if not node in self.in_degree.keys():
            self.in_degree[node] = 0
        
        if not node in self.out_degree.keys():
            self.out_degree[node] = 0
        

    def add_edge(self, source, target):

        self.init_node(source)
        self.init_node(target)

        if not Edge(source, target) in self.multiplicity.keys():
            self.multiplicity[Edge(source, target)] = 0 

        if target not in self.adj_list[source]:
            self.adj_list[source].append(target)

        self.edges += 1
        self.in_degree[target] += 1 
        self.out_degree[source] += 1 
        self.multiplicity[Edge(source, target)] += 1


    def pretty_print(self):
        for key in self.adj_list.keys():
            print(str(key) + ": " + str(self.adj_list[key]))

    def outgoing_edges(self, u):
        res = []
        for v in self.adj_list[u]:
            e = Edge(u, v)
            res += [(e, k) for k in range(self.edge_multiplicity(e))]
        return res

    def all_edges(self):
        res = []
        for u in self.adj_list.keys():
            res += self.outgoing_edges(u)

        return res

    def eulerify(self):
        B_plus = [u for u in self.adj_list.keys() if self.balance(u) > 0]
        B_minus = [u for u in self.adj_list.keys() if self.balance(u) < 0]
        E_bottom = []
        first = 0

        for u in B_minus:
            while self.balance(u) < 0:
                v = B_plus[first]
                self.add_edge(u, v)
                E_bottom.append((u, v))

                if self.balance(v) == 0:
                    first += 1

        return E_bottom

    def to_adjacency_matrix(self):
        adj_m = np.array([[self.edge_multiplicity(Edge(u, v)) for v in self.adj_list.keys()] for u in self.adj_list.keys()])

        return adj_m

    def line_graph(self):
        line = Multigraph()

        edges = self.all_edges()

        for i in edges:
            v = i[0].target
            for k in self.outgoing_edges(v):
                line.add_edge(i, k)

        return line