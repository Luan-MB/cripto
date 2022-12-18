import string

DIMENSION = 6

key = input("Entre com a chave: ").upper()

table = []

for char in key:
    if not char in table:
       table.append(char)

for char in list(string.ascii_uppercase) + list(str(i) for i in range(10)):
    if not char in table:
        table.append(char)

phrase = input("Frase para criptografar: ").upper().replace(' ', '')
if len(phrase) % 2:
    phrase += 'X'

print("--- Frase Formatada ---")
print(phrase)

encrypted_phrase = ""

for i in range(len(phrase) // 2):
    


