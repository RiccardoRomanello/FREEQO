from Multigraph import Multigraph
from Family import Family

class Driver: 
    def __init__(self, graph, family):
        self.graph = graph
        self.family = family

    def Unitarize(self):
        E_bot = self.graph.eulerify()
        # compute line graph 
        # compute adjacency matrix of line graph 
        # unitarize 