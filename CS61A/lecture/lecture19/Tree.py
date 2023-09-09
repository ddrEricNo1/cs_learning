class Tree:
    def __init__(self, label, branches=[]):
        self.label = label 
        self.branches = list(branches)

    
    def is_leaf(self):
        return not self.branches
    

    def __repr__(self):
        return str([self.label] + self.branches)
    

def double(t):
    """Double every label in T, mutating T.
    >>> t = Tree(1, [Tree(3, [Tree(5)]), Tree(7)])
    >>> double(t)
    >>> t
    Tree(2, [Tree(6, [Tree(10)]), Tree(14)])
    """
    t.label = t.label * 2
    if not t.is_leaf():
        for b in t.branches:
            double(b)