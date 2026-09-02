
import tkinter as tk
import random

# =========================
# VARIABLES
# =========================

taille = 20
vitesse = 150

snake = [[100, 100], [80, 100], [60, 100]]
direction = "droite"

pomme = [200, 200]

score = 0
mort = False


# =========================
# FENETRE
# =========================

fenetre = tk.Tk()
fenetre.title("Snake")

canvas = tk.Canvas(fenetre, width=400, height=400, bg="black")
canvas.pack()


# =========================
# TOUCHES
# =========================

def touche(event):

    global direction

    if event.keysym == "Up" and direction != "bas":
        direction = "haut"

    if event.keysym == "Down" and direction != "haut":
        direction = "bas"

    if event.keysym == "Left" and direction != "droite":
        direction = "gauche"

    if event.keysym == "Right" and direction != "gauche":
        direction = "droite"


fenetre.bind("<Key>", touche)


# =========================
# JEU
# =========================

def jeu():

    global score
    global mort

    if mort:
        return

    # position de la tete
    tete = snake[0].copy()

    if direction == "droite":
        tete[0] += taille

    if direction == "gauche":
        tete[0] -= taille

    if direction == "haut":
        tete[1] -= taille

    if direction == "bas":
        tete[1] += taille

    # =========================
    # COLLISION AVEC LE MUR
    # =========================

    if tete[0] < 0 or tete[0] >= 400:
        mort = True

    if tete[1] < 0 or tete[1] >= 400:
        mort = True

    # =========================
    # COLLISION AVEC LE CORPS
    # =========================

    if tete in snake:
        mort = True

    if mort:

        canvas.delete("all")

        canvas.create_text(
            200,
            180,
            text="GAME OVER",
            fill="red",
            font=("Arial", 30)
        )

        canvas.create_text(
            200,
            220,
            text="Score : " + str(score),
            fill="white",
            font=("Arial", 15)
        )

        return

    # ajoute la nouvelle tete
    snake.insert(0, tete)

    # =========================
    # POMME
    # =========================

    if tete == pomme:

        score += 1

        pomme[0] = random.randrange(0, 400, taille)
        pomme[1] = random.randrange(0, 400, taille)

    else:

        snake.pop()

    # =========================
    # AFFICHAGE
    # =========================

    canvas.delete("all")

    # serpent
    for morceau in snake:

        canvas.create_rectangle(
            morceau[0],
            morceau[1],
            morceau[0] + taille,
            morceau[1] + taille,
            fill="green"
        )

    # pomme
    canvas.create_rectangle(
        pomme[0],
        pomme[1],
        pomme[0] + taille,
        pomme[1] + taille,
        fill="red"
    )

    # score
    canvas.create_text(
        40,
        10,
        text="Score : " + str(score),
        fill="white"
    )

    fenetre.after(vitesse, jeu)


# =========================
# DEMARRAGE
# =========================

jeu()

fenetre.mainloop()

