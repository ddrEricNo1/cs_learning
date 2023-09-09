def tree(label, children=None):
    """Create a tree whose root node is labeled LABEL and 
    optionally has CHILDREN, a list of trees,"""
    return (label, list(children or []))

def label(tree):
    """Return the label of the root node of TREE"""
    return tree[0]

def children(tree):
    """Return a list of children of TREE"""
    return tree[1]

def is_leaf(t):
    return len(children(t)) == 0


def double(t):
    """Return a tree identical to T, but with all labels doubled"""
    if is_leaf(t):
        return tree(label(t) * 2)
    else:
        # double_children = []
        # for c in children(t):
        #     double_children.append(double(c))
        #    return tree(label(t) * 2, double_children)
        return tree(label(t) * 2, [double(c) for c in children(t)])