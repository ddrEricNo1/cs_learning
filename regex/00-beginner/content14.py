content = '''苹果，苹果是绿色的
橙子，橙子是橙色的
香蕉，香蕉是黄色的
'''
import re
if __name__ == "__main__":
    p = re.compile(r'^(.*)，', re.M)
    for one in p.findall(content):
        print(one)
