
import tkinter as tk
import random

personnages = [
    "un petit dragon",
    "une licorne",
    "un robot rigolo",
    "un jeune pirate",
    "une exploratrice",
    "un chat aventurier",
    "un petit sorcier",
    "une fée",
    "un chevalier maladroit",
    "un extraterrestre"
]

lieux = [
    "dans une forêt magique",
    "sur une île mystérieuse",
    "dans un château",
    "dans l'espace",
    "au fond de l'océan",
    "dans un village enchanté",
    "sur une montagne",
    "dans un laboratoire secret",
    "dans un parc abandonné",
    "dans une ville futuriste"
]

objets = [
    "une clé dorée",
    "une carte mystérieuse",
    "une pierre magique",
    "un vieux livre",
    "un coffre étrange",
    "une montre spéciale",
    "une lampe magique",
    "un petit robot",
    "une plume brillante",
    "un cristal lumineux"
]

problemes = [
    "doit retrouver un trésor",
    "a perdu son meilleur ami",
    "doit résoudre une énigme",
    "doit sauver son village",
    "a découvert une porte secrète",
    "doit retrouver un objet disparu",
    "est poursuivi par une mystérieuse créature",
    "doit réussir une grande épreuve",
    "a trouvé un message étrange",
    "doit découvrir un secret"
]

fins = [
    "et découvre quelque chose d'incroyable.",
    "et devient le héros du village.",
    "et comprend enfin le mystère.",
    "et retrouve ses amis.",
    "et découvre que tout était lié depuis le début.",
    "et rentre chez lui avec un souvenir magique.",
    "et trouve une nouvelle aventure.",
    "et décide de garder le secret."
]

histoire = ""


def generer():
    global histoire

    personnage = random.choice(personnages)
    lieu = random.choice(lieux)
    objet = random.choice(objets)
    probleme = random.choice(problemes)
    fin = random.choice(fins)

    histoire = (
        personnage.capitalize() + " se trouve " + lieu + ". "+ "Il découvre " + objet + ". "+ "Mais il " + probleme + ". "+ "Finalement, " + fin)

    histoire_label.config(text=histoire)
    confirmation.config(text="")


def copier():
    fenetre.clipboard_clear()
    fenetre.clipboard_append(histoire)
    fenetre.update()

    confirmation.config(text="Histoire copiée !")


fenetre = tk.Tk()
fenetre.title("Générateur d'histoires")
fenetre.geometry("750x600")
fenetre.configure(bg="#111111")
fenetre.resizable(False, False)

titre = tk.Label(
    fenetre,
    text="GÉNÉRATEUR D'HISTOIRES",
    font=("Arial", 25, "bold"),
    fg="white",
    bg="#111111"
)
titre.pack(pady=(30, 5))

sous_titre = tk.Label(
    fenetre,
    text="Crée une nouvelle idée d'histoire aléatoire",
    font=("Arial", 11),
    fg="#888888",
    bg="#111111"
)
sous_titre.pack(pady=(0, 25))

cadre = tk.Frame(
    fenetre,
    bg="#1c1c1c",
    bd=1,
    relief="solid"
)
cadre.pack(padx=40, fill="both", expand=True)

tk.Label(
    cadre,
    text="TON HISTOIRE",
    font=("Arial", 11, "bold"),
    fg="#777777",
    bg="#1c1c1c"
).pack(pady=(25, 15))

histoire_label = tk.Label(
    cadre,
    text="Clique sur GÉNÉRER pour commencer !",
    font=("Arial", 15),
    fg="#4da6ff",
    bg="#1c1c1c",
    wraplength=580,
    justify="center"
)
histoire_label.pack(padx=30, pady=20)

bouton_generer = tk.Button(
    fenetre,
    text="Générer une idée d'histoire",
    command=generer,
    font=("Arial", 13, "bold"),
    fg="white",
    bg="#246bce",
    activebackground="#3d82e6",
    relief="flat",
    bd=0,
    padx=30,
    pady=10,
    cursor="hand2"
)
bouton_generer.pack(pady=(20, 10))

bouton_copier = tk.Button(
    fenetre,
    text=histoire+"📋",
    command=copier,
    font=("Arial", 11),
    fg="white",
    bg="#333333",
    activebackground="#444444",
    relief="flat",
    bd=0,
    width=8,
    cursor="hand2"
)
bouton_copier.pack()

confirmation = tk.Label(
    fenetre,
    text="",
    font=("Arial", 10),
    fg="#4da6ff",
    bg="#111111"
)
confirmation.pack(pady=8)

generer()

fenetre.mainloop()

