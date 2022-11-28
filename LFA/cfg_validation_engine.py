f=open("cfg_config_file.in")
lines=f.readlines()
i=0
variabile=[]
terminale=[]
start=[]
while i< len(lines):
    while lines[i][0] == '#':
        i+=1
      #  print("#")

    if "Variables" in lines[i]:
        i+=1
        while "End" not in lines[i]:
            variabile.append(lines[i].strip())
            i+=1
           # print("sigma")

    if "Terminals" in lines[i]:
        i+=1
        while "End" not in lines[i]:
            terminale.append(lines[i].strip())
            i+=1

    if "Start" in lines[i]:
        i+=1
        while "End" not in lines[i]:
            start.append(lines[i].strip())
            i+=1

    listaReguli=[]
    if "Rules" in lines[i]:
        i+=1
        while "End" not in lines[i]:
            l=lines[i].strip().split(',')
            listaReguli.append(l)
            i+=1
    i+=1
print(start)
print(variabile)
print(terminale)
print(listaReguli)
if len(start)>1 and start[0] in variabile:
    print("nu e cfg")
    exit()
for v in variabile:
    if v in terminale:
        print("nu e cfg")
        exit()
for lista in listaReguli:
    if lista[0] not in variabile:
        print("nu e cfg")
        exit()

print("e cfg")
