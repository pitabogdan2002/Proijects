import sys
f = open(str(sys.argv[1]), "rb")
g = open(str(sys.argv[2]), "r")
i = 0
data1=f.read()
data2=g.read()
out=""
for i in range(len(data2)):
    t=data1[i] ^ ord(data2[i])
    print(chr(t), end="")
    i += 1

f.close()
