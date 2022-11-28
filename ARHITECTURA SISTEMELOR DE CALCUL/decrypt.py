import sys
import base64
if len(sys.argv) != 4:
	print ("Usage: encrypt.py infile outfile password")
	exit()
if (len(sys.argv[3])<10 or len(sys.argv[3])>15) or (sys.argv[3].isalnum()==0):
	print("Invalid password")
	exit()
f = open(str(sys.argv[1]), "rb")
g = open(str(sys.argv[2]), "w")
password="sys.argv[3]".encode("utf-8")
key=base64.b64encode(password)
data=f.read()
out=""
pozkey=0
for i in range (len(data)) :
    t = data[i]^ key[pozkey]
    out += chr(t)
    pozkey += 1
    if pozkey >= len(key):
            pozkey=0

g.write(out)  
