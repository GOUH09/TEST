```cpp
#include <LedControl.h>

int DIN = 12;
int CS = 11;
int CLK = 10;

int bouton1 = 6;
int bouton2 = 8;

// creation de la matrice
LedControl lc = LedControl(DIN, CLK, CS, 1);

// le smiley
byte smiley[8] = {
  0x00,
  0x00,
  0x36,
  0x36,
  0x00,
  0x41,
  0x3E,
  0x00
};

// la fleche vers le haut
byte haut[8] = {
  0x00,
  0x18,
  0x3C,
  0x7E,
  0x18,
  0x18,
  0x18,
  0x18
};

void setup() {

  // allume la matrice
  lc.shutdown(0, false);

  // luminosite
  lc.setIntensity(0, 15);

  // efface la matrice
  lc.clearDisplay(0);

  // reglage des boutons
  pinMode(bouton1, INPUT_PULLUP);
  pinMode(bouton2, INPUT_PULLUP);
}

void loop() {

  // si on appuie sur le bouton 1
  if (digitalRead(bouton1) == LOW) {
    afficher(smiley);
    delay(500);
  }

  // si on appuie sur le bouton 2
  if (digitalRead(bouton2) == LOW) {
    afficher(haut);
    delay(500);
  }
}

// fonction pour afficher un dessin
void afficher(byte dessin[]) {

  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, dessin[i]);
  }
}
```
