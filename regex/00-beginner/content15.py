content = '''张三，手机号码13913847300
李四，手机号码15380844135
王二，手机号码13665876613
'''

import re
if __name__ == "__main__":
    p = re.compile(r'^(.+)，.+(\d{11})', re.M)
    for one in p.findall(content):
        print(one)
