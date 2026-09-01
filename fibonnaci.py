nombre = int(input("Combien de nombres veux-tu afficher ? "))

a = 0
b = 1

for i in range(nombre):
    print(a)
    suivant = a + b
    a = b
    b = suivant