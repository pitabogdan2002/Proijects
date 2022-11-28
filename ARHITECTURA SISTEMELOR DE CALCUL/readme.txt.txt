Nume echipa: Vigilantes
Nume echipa adversa: Bizonii
Cheia lor: bizosoferultau1


Pentru a rula cele doua scripturi, se va rula in terminal:
pentru encrypt: python3 encrypt.py <nume fisier input> <nume fisier output> <parola>
pentru decrypt: python3 decrypt.py <nume fisier output> <nume fisier recuperat> <parola>


PENTRU CRACK
cu input.txt: rulam in terminal  python3 crack.py <nume fisier output> <nume fisier input.txt> 
fara input.txt: rulam in terminal  python3 hack2.py <nume fisier output> 
in acest caz am incercat sa luam primele 10-15 caractere din output si sa verficam daca vreun caracter din cele posibile in parola xor-at cu fiecare din output va duce la obtinerea unui caracter posibil din cele din input.txt si daca da, atunci il adaugam la un sir creat de noi. Daca la final acest sir avea aceeasi lungime cu lungimea corespunzatoare 10-15 atunci acesta era cheia.

Documentație/surse de inspirație:
https://www.youtube.com/watch?v=jMZoZ1F7cZ8
https://www.youtube.com/watch?v=gULdbWqbTIE
https://www.kite.com/python/answers/how-to-encrypt-a-password-in-python
https://samsclass.info/124/proj14/VPxor.htm
