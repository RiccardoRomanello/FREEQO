from Multigraph import Multigraph
from Family import Family
from Driver import Driver
import numpy as np

# Input format

# N 
# node_1 : comma_separated_adj_1
# node_2 : comma_separated_adj_2 
# ...
# node_N : comma_separated_adj_N
# R 
# [nodes_1] : unitary for nodes_1 in matlab syntax 
# [nodes_2] : unitary for nodes_2 in matlab syntax 
# ... 
# [nodes_R] : unitary for nodes_R in matlab syntax

class InputReader:
    def __init__(self, file_name):
        self.file_name = file_name

    def read_input(self):

        g = Multigraph()
        mathcal_U = Family()
        
        with open(self.file_name) as input_file:
            node_count = int(input_file.readline())
            # read adjacencies
            for _ in range(node_count):
                adj = input_file.readline() # of the form: u: v, w, .... -> (u, v), (u, w), ecc
                source = adj.split(":")[0]
                adj_source = adj.split(":")[1].split(",")
                for target in adj_source:
                    g.add_edge(str(source), target.strip())
            
            rows_number = int(input_file.readline())
            driver = Driver(g, mathcal_U)

            # set of rows_number rows where there is [nodes]: matrix (matrix described by rows in classical matlab sintax)
            # for each node in nodes the matrix associated is matrix

            for _ in range(rows_number):
                matrix_row = input_file.readline()
                nodes, matrix_values = matrix_row.split(":")[0], matrix_row.split(":")[1]
                nodes = nodes[1:-1] # removing surrounding brackets
                nodes = nodes.split(",")
                for node in nodes:
                    driver.set_U_for_node(node.strip(), np.matrix(matrix_values.strip()))



        return driver
