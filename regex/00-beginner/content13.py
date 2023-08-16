content = '''001-苹果价格-60
002-香蕉价格-40
003-葡萄价格-30
'''

import re

if __name__ == "__main__":
    p = re.compile(r'\d+$', re.M)
    for one in p.findall(content):
        print(one)
