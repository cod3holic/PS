with open('./output1') as o1:
    with open('./output2') as o2:
        for (a, b) in zip(o1.readlines(), o2.readlines()):
            a=a.rstrip()
            b=b.rstrip()
            if(a != b):
                print(f"[!] o1: {a} o2: {b}")