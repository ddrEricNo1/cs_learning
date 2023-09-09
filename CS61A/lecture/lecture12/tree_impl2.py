def tree(label, children=[]):
    return (label, children)

def label(tree):
    return tree[0]

def children(tree):
    return tree[1]

def is_leaf(tree):
    return len(children(tree)) == 0

def count_leaves(t):
    if is_leaf(t):
        return 1
    else:
        return sum([count_leaves(t) for t in children(tree)])

if __name__ == "__main__":
    t = tree(20, [tree(12, 
                       [tree(9, 
                        [tree(7), tree(2)]),
                        tree(3)]),
                  tree(8, 
                  [tree(4), tree(4)])])