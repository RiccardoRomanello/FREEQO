import numpy as np
import math as m

class Family:
    def __init__(self):
        self.family = {} # doubly indexed dictionary

    def set_matrix(self, matrix, name):
        n = matrix.shape[0]
        if n not in self.family.keys():
            self.family[n] = {}
        
        self.family[n][name] = np.array(matrix)

    def get_matrix(self, n, name):

        if not n in self.family.keys() or not name in self.family[n].keys():
            return self.default_matrix(n)
        
        return self.family[n][name]

    def default_matrix(self, n):
        i, j = np.meshgrid(np.arange(n), np.arange(n))
        omega = np.exp( - 2 * m.pi * 1J / n )
        W = np.power( omega, i * j ) / m.sqrt(n)
        return W
    
    def __str__(self):
        return str(self.family)

