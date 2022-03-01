import numpy as np
import math as m

class Family:
    def __init__(self):
        self.family = {}
        d = 1/np.sqrt(2)

    def set_matrix(self, matrix):
        self.family[matrix.size()] = matrix

    def get_matrix(self, n):
        if not n in self.family.keys():
            return self.default_matrix(n)
        
        return self.family[n]

    def default_matrix(self, n):
        i, j = np.meshgrid(np.arange(n), np.arange(n))
        omega = np.exp( - 2 * m.pi * 1J / n )
        W = np.power( omega, i * j ) / m.sqrt(n)
        return W