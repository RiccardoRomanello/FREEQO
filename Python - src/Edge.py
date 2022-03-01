class Edge:
    def __init__(self, source, target):
        self.source = source
        self.target = target

    def __hash__(self):
        return hash((self.source, self.target))
    
    def __eq__(self, other):
        return (self.source, self.target) == (other.source, other.target)

    def __str__(self):
        return "(" + str(self.source) + ", " + str(self.target) + ")"
    
    def __repr__(self):
        return "(" + str(self.source) + ", " + str(self.target) + ")"
