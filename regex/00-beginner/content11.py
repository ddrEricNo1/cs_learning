import re
if __name__ == "__main__":
    source = '''a1b2c3d4e5'''
    p = re.compile(r'[^ \d]')
    print(p.findall(source))
