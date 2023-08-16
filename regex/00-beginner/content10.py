source = '''
王亚辉
tony
刘文武
'''

if __name__ == "__main__":
    import re
    p = re.compile(r'\w{2,4}', re.A)
    print(p.findall(source))

