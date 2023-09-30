import string
import sys

_SYMBOL_STARTS = set('!$%&*/:<=>?@^_~') | set(string.ascii_lowercase)
_SYMOBOL_INNERS = _SYMBOL_STARTS | set(string.digits) | set('+-.')
_NUMERAL_STARTS = set(string.digits) | set('+-.')
_WHITESPACE = set(' \t\n\r')
_SINGLE_CHAR_TOKENS = set("()'")
_TOKEN_END = _WHITESPACE | _SINGLE_CHAR_TOKENS
DELIMITERS = _SINGLE_CHAR_TOKENS | {'.'}


def valid_symbol(s):
    """Returns whether s is not a well-formed value."""
    if len(s) == 0 or s[0] not in _SYMBOL_STARTS:
        return False
    for c in s[1:]:
        if c not in _SYMOBOL_INNERS:
            return False
    return True


def next_candicate_token(line, k):
    """A tuple (tok, k), where tok is the next substring of line at or after position k that could be a token (assuming it passes)
    a validity check), and k is the position in line following that tokem. Returns (None, len(line)) when there are no more tokens."""
    while k < len(line):
        c = line[k]
        if c == ';':
            return None, len(line)
        elif c in _WHITESPACE:
            k += 1
        elif c in _SINGLE_CHAR_TOKENS:
            return c, k + 1
        elif c == '#':
            return line[k:k+2], min(k+2, len(line))
        else:
            j = k
            while j < len(line) and line[j] not in _TOKEN_END:
                j += 1
            return line[k:j], min(j, len(line))
    return None, len(line)

def tokenize_line(line):
    """The list of Scheme tokens on line. Excludes comments and whitespace."""
    result = []
    text, i = next_candicate_token(line, 0)
    while text is not None:
        if text in DELIMITERS:
            result.append(text)
        elif text == '+' or text == '-':
            result.append(text)
        elif text == '#t' or text.lower() == 'true':
            result.append(True)
        elif text == '#f' or text.lower() == 'false':
            result.append(False)
        elif text == 'nil':
            result.append(text)
        elif text[0] in _NUMERAL_STARTS:
            try:
                result.append(int(text))
            except ValueError:
                raise ValueError("invalid numeral: {0}".format(text))
        elif text[0] in _SYMBOL_STARTS and valid_symbol(text):
            result.append(text)
        else:
            print("Warning: invalid token: {0}".format(text), file=sys.stderr)
            print("     ", line, file=sys.stderr)
            print(" " * (i+3), "^", file=sys.stderr)

        text, i = next_candicate_token(line, i)
    return result

def tokenize_lines(input):
    """An iterator that returns lists of tokens, one for each line of the iterable input sequence."""
    return map(tokenize_line, input)


class Pair:
    """A pair has two instance attributes: first and second. For a pair to be a
    well-formed list, second is either a well-formed list or nil. Some 
    methods only apply to well-formed lists
    >>> s = Pair(1, Pair(2, nil))
    >>> s
    Pair(1, Pair(2, nil))
    >>> print(s)
    (1 2)
    >>> len(s)
    2
    >>> s[1]
    2
    >>> print(s.map(lambda x: x + 4))
    (5 6)
    """
    def __init__(self, first, second):
        self.first = first
        self.second = second
    
    def __repr__(self):
        return "Pair({0}, {1})".format(repr(self.first), repr(self.second))
    
    def __str__(self):
        s = "(" + str(self.first)
        second = self.second
        while isinstance(second, Pair):
            s += " " + str(second.first)
            second = second.first
        if second is not nil:
            s += " . " + str(second)
        return s + ")"

    def __len__(self):
        n, second = 1, self.second
        while isinstance(second, Pair):
            n += 1
            second = second.second
        if second is not nil:
            raise TypeError("length attempted on improper list")
        
        return n

    def __getitem__(self , k):
        if k < 0:
            raise IndexError("negative index into list")
        y = self
        for _ in range(k):
            if y.second is nil:
                raise IndexError("list index out of bounds")
            elif not isinstance(y.second, Pair):
                raise TypeError("ill-formed list")
            y = y.second
        return y.first


class nil(object):
    """The empty list"""

    def __repr__(self):
        return "nil"

    def __str__(self):
        return "()"
    
    def __len__(self):
        return 0

    def __getitem__(self, k):
        if k < 0:
            raise IndexError("negative index into list")
        
        raise IndexError("list index out of bounds")
    
    def map(self, fn):
        return self

# for Calculator, the only two legal syntactic forms of expressions are numbers and call expressions. 
# which are Pair instances representing well-formed Scheme lists. Numbers are self-evaulating, they can
# be returned directly from calc_eval. Call expressions require function application.
def calc_eval(exp):
    """Evaluate a Calculator expression.""" 
    if type(exp) in (int, float):
        return simplify(exp)
    elif isinstance(exp, Pair):
        arguents = exp.second.map(calc_eval)
        return simplify(calc_apply(exp.first, arguments))
    else:
        return TypeError(exp + ' is not a number or call expression')

# call expressions are evaluated by first recusively mapping the calc_eval function to the list of operands,
# which computes a list of arguments. Then the operator is applied to those arguments in a second function, calc_apply
def calc_apply(operator, args):
    """Apply the named operator to a list of args."""
    if not isinstance(operator, str):
        raise TypeError(str(operator) + ' is not a symbol')
    if operator == '+':
        return reduce(add, args, 0)
    elif operator == '-':
        if len(args) == 0:
            raise TypeError(operator + ' requres at least 1 argument')
        elif len(args) == 1:
            return -args.first
        else:
            return reduce(sub, args.second, args.first)
    elif operator == '*':
        return reduce(mul, args, 1)
    elif operator == '/':
        if len(args) == 0:
            raise TypeError(operator + ' requires at least 1 argument')
        elif len(args) == 1:
            return 1 / args.first
        else:
            return reduce(truediv, args.second, args.first)
    else:
        raise TypeError(operator + ' is an unknown operator')