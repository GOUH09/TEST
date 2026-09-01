nombre = int(input("Entre un nombre décimal : "))

binaire = ""

while nombre > 0:
    reste = nombre % 2
    binaire = str(reste) + binaire
    nombre = nombre // 2

print("Le nombre en binaire est :", binaire)