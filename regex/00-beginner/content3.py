content = '''
苹果是绿色的
橙子是橙色的
香蕉是黄色的
乌鸦是黑色的
'''

import re
if __name__ == "__main__":
    # p的类型是pattern
    p = re.compile(r'.色')
    print(type(p))
    for one in p.findall(content):
        print(type(one))
        print(one)
