import sys
f=open(str(sys.argv[1]),"rb")
text="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-?!.:;,'"
parola="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"


data=f.read()
for lungime in range(10,16):
	sir=""
	for i in range (lungime):
		for c in parola:
			poz=i
			v=1
			if chr(ord(c) ^ data[poz]) not in text:
					v=0
			if v!=0:
				sir = sir + c
	sir=sir+'\n'
	if len(sir) == lungime :
		print(sir)
		i=16
				
			
