class Link:
    empty = ()


    def __init__(self, first, rest=empty):
        self.first = first
        self.rest = rest


def range_link(start, end):
    """Return a Link containing consecutive integers
    from START to END, not including END
    >>> range_link(3, 6)
    Link(3, Link(4, Link(5)))
    """
    if start >= end:
        return Link.empty
    return Link(start, range_link(start + 1, end))


# 依然是从左到右的递归
def map_link(f, ll):
    """Return a link that contains f(x) for each x in Link LL
    >>> square = lambda x: x*x
    >>> map_link(square, range_link(3, 6))
    Link(9, Link(16, Link(25)))
    """
    if ll.rest is Link.empty:
        return Link(f(ll.first))
    else:
        return Link(f(ll.first), map_link(ll.rest))


def insert_front(linked_list, new_val):
    """Inserts NEW_VAL in front of LINKED_LIST, 
    returning new linked list
    >>> ll = Link(1, Link(3, Link(5)))
    >>> insert_front(ll, 0)
    Link(0, Link(1, Link(3, Link(5))))
    """
    return Link(new_val, linked_list)


if __name__ == "__main__":
    l1 = Link("A", Link("B", Link("C")))
    print(l1) 