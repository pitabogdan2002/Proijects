f=open("cfg_config_file.in")
lines=f.readlines()
i=0
variabile=[]
terminale=[]
start=[]
while i< len(lines):
    while lines[i][0] == '#':
        i+=1

    if "Variables" in lines[i]:
        i+=1
        while "End" not in lines[i]:
            variabile.append(lines[i].strip())
            i+=1

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
print(listaReguli)
for l in listaReguli:
    l[1] = l[1].split("|")
print(start)
print(variabile)
print(terminale)
print(listaReguli)

print()
print("USELESS REDUCTION")
print()
#######  "USELESS" REDUCTION

for lista in listaReguli:
    a = lista[0]
    nr = 0
    for cuv in lista[1]:
        if a in cuv:
            nr = nr+1
    if nr == len(lista[1]):
        variabile.remove(a)
        listaReguli.remove(lista)
        for l in listaReguli:
            for li in l[1]:
                if a in li:
                    l[1].remove(li)

print(start)
print(variabile)
print(terminale)
print(listaReguli)

for v in variabile:
    ok = 0
    if v != start[0]:
        for lista in listaReguli:
            if v != lista[0]:
                for cuv in lista[1]:
                    if v in cuv:
                        ok = 1
        if ok == 0:
            variabile.remove(v)
            for l in listaReguli:
                if v == l[0]:
                    listaReguli.remove(l)
                else:
                    for li in l[1]:
                        if v in li:
                            l[1].remove(li)

print(start)
print(variabile)
print(terminale)
print(listaReguli)


print()
print("NULL REDUCTION")
print()
######   "NULL" REDUCTION

nul=[]
for l in reversed(listaReguli):
    if '0' in l[1]:
        nul.append(l[0])
        l[1].remove('0')
    elif nul != []:
        for v in nul:
            for c in l[1]:
                if v in c and l[0] not in nul:
                    nul.append(l[0])

print(nul)
print(start)
print(variabile)
print(terminale)
print(listaReguli)


def subsetsUtil(index):
    global combinatii
    global caractere
    global subset
    if subset != "":
        combinatii.append(subset)
    for i in range(index, len(caractere)):
        subset = subset +caractere[i]
        subsetsUtil(i+1)
        subset = subset[:-1]
    return
for l in listaReguli:
    reguliNoi = []
    for x in l[1]:
        caractere = ""
        for c in x:
            if c in nul:
                caractere= caractere + c
        combinatii = []
        subset =""
        subsetsUtil(0)
        combinatii.append("")
        for s in combinatii:
            regula = ""
            for c in x:
                if c in s or c not in nul:
                    regula = regula + c
            if regula not in reguliNoi and regula != "":
                reguliNoi.append(regula)
    for regula in reguliNoi:
        if regula not in l[1]:
            l[1].append(regula)
print(start)
print(variabile)
print(terminale)
print(listaReguli)



print()
print("UNIT REDUCTION")
print()

#######   "UNIT" REDUCTION

print(listaReguli)
listaNonUnit = []
for lista in listaReguli:
    regula =[]
    regulile = []
    regula.append(lista[0])
    for l in lista[1]:
        if len(l)==1 and l in variabile:
            continue
        else:
            regulile.append(l)
    if len(regulile)>0:
        regula.append(regulile)
        listaNonUnit.append(regula)
print(listaNonUnit)
ok = 1


while ok == 1:
    ok = 0
    for i in range(len(listaReguli)):
        for l in listaReguli[i][1]:
            if len(l)==1 and l in variabile:
                for regula in listaNonUnit:
                    if l == regula[0]:
                        for r in regula[1]:
                            if r not in listaNonUnit[i][1]:
                                listaNonUnit[i][1].append(r)
                                ok = 1
print(listaNonUnit)
listaVariabile = []
listaVariabile.append(start[0])
for lista in listaNonUnit:
    for l in lista[1]:
        for caracter in l:
            if caracter not in listaVariabile and caracter in variabile and caracter!=lista[0]:
                listaVariabile.append(caracter)
print(listaVariabile)
for regula in listaNonUnit:
    if regula[0] not in listaVariabile:
        listaNonUnit.remove(regula)
        variabile.remove(regula[0])
print(start)
print(variabile)
print(terminale)
print(listaNonUnit)

