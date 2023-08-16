# 默认是单行模式，需要切换到多行模式
content = '''001-苹果价格-60,
002-橙子价格-70,
003-香蕉价格-80,
'''

import re
if __name__ == "__main__":
    # re.M表示声明multiple line
    p = re.compile(r'^\d+', re.M)
    for one in p.findall(content):
        print(one)
