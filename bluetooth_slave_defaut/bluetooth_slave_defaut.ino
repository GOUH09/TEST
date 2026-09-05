/*
    //Branchement Arduino et HC05
    //  HC-05       Arduino Nano      Note
    //  VCC         5V                Alimentation
    //  GND         GND               Masse
    //  TXD         D10               Vers  RX logiciel
    //  RXD         D11               Vers  TX logiciel (via pont diviseur*)
    //  EN/KEY      D4 ou 5V          Doit être à l'état HAUT au démarrage
   
    //Configuration Arduino HC05 pour modification Code AT.#include <SoftwareSerial.h>
    //1.- Entrer en mode AT :
      //Débranchez le module.
      //Maintenez le petit bouton du HC-05 enfoncé.
      //Rebranchez l'alimentation. La LED du module doit clignoter lentement (toutes les 2 secondes environ).
    //2.- Réglages du Moniteur Série :
      //Ouvrez le moniteur série d'Arduino IDE.
      //Sélectionnez "Both NL & CR" (ou "NL et CR") en bas à droite.
      //Vitesse : 9600 baud.
    //3.- Commandes courantes à tester :
      //Tapez AT → Le module doit répondre OK.
      //Tapez AT+NAME=MonBluetooth → Change le nom.
      //Tapez AT+PSWD="1234" → Change le code PIN.
      //Tapez AT+UART=9600,0,0 → Fixe la vitesse de communication standard à 9600.
      //Une fois terminé, débranchez la broche EN/KEY (ou mettez-la à LOW) et redémarrez le module pour l'utiliser normalement.
     
    //Paramétrage pour autoconnexion
    //1. Configurer l'Esclave (Le module dont vous venez de lire l'adresse)
      //Assurez-vous que ce module est bien configuré ainsi (tapez ces commandes une par une) :
      //AT+ORGL (Réinitialisation par défaut, optionnel mais conseillé).
      //AT+ROLE=0 (Définit le module comme Esclave).
      //AT+POLAR=1,0 (Optionnel, assure que la LED clignote correctement).
      //AT+UART=9600,0,0 (Vitesse de communication).
    //2. Configurer le Maître (L'autre module)
      //Branchez votre deuxième module (le deuxième ZS-040) en mode AT et entrez ces commandes :
      //AT+ORGL (Réinitialisation).
      //AT+ROLE=1 (Passe en mode Maître).
      //AT+CMODE=0 (Force la connexion à une adresse unique et spécifique).
      //AT+BIND=0,13,1745C (On lui donne l'adresse de l'esclave. Attention : remplacez bien les : par des ,).
      //AT+UART=9600,0,0 (Doit être la même vitesse que l'esclave).
    //3. La suite : Test de connexion "Live"
      //Une fois les deux configurés :
      //Éteignez tout.
      //Remettez les deux modules sous tension (sans maintenir le bouton cette fois, pour rester en mode communication).
      //L'observation des LED :
      //Au début, les deux clignotent vite.
      //Après quelques secondes, elles devraient clignoter ensemble de façon synchronisée (généralement deux flashs rapides toutes les 2 ou 3 secondes). Cela signifie qu'ils sont appairés.
    //4. Code de test pour envoyer des données
      //Vous pouvez utiliser le même code sur les deux Arduino Nano pour tester l'envoi de messages :
          #include <SoftwareSerial.h>
          SoftwareSerial BTSerial(10, 11); // RX | TX
          void setup() {
            Serial.begin(9600);
            BTSerial.begin(9600);
            Serial.println("Liaison établie. Tapez un message pour l'envoyer :");
          }
          void loop() {
            // Envoi vers l'autre module
            if (Serial.available()) {
              BTSerial.write(Serial.read());
            }
           
            // Réception depuis l'autre module
            if (BTSerial.available()) {
              Serial.write(BTSerial.read());
            }
          }
    //Résumé de la "Checklist" de connexion
          //Si vos modules ne se connectent pas (les LED continuent de clignoter rapidement sans se synchroniser), vérifiez ces 3 points dans l'ordre :
          //Le MDP : Est-ce que AT+PSWD est identique sur les deux ?
          //Le Rôle : L'un est-il bien en AT+ROLE=1 (Maître) et l'autre en AT+ROLE=0 (Esclave) ?
          //L'Adresse : Le Maître a-t-il bien enregistré l'adresse de l'esclave avec AT+BIND=... ?
   
    //Une astuce pour le mode "Automatique"
          //Si vous ne voulez pas vous embêter avec l'adresse (BIND), vous pouvez configurer le Maître pour qu'il se connecte à n'importe quel module à proximité ayant le même mot de passe :
          //Sur le Maître, tapez : AT+CMODE=1 (Connexion à n'importe quelle adresse).
          //Assurez-vous que le mot de passe (AT+PSWD) est le même sur les deux.
          //Attention : Le CMODE=1 est plus simple, mais si vous avez d'autres modules Bluetooth allumés dans la pièce, le Maître risque de tenter de se connecter au mauvais appareil. Le CMODE=0 avec le BIND (ce qu'on a fait précédemment) reste la méthode la plus stable et "propre".
   
    ///////////////////////////////////////////////////////////////
    //A réactiver ici pour paramétrage des identifiants bleutooth//
    ///////////////////////////////////////////////////////////////

        #include <SoftwareSerial.h>
       
        // RX de l'Arduino sur 10, TX sur 11
        SoftwareSerial BTSerial(10, 11);

        void setup() {
          pinMode(4, OUTPUT);
          digitalWrite(4, HIGH); // Met la broche KEY à HIGH pour activer le mode AT
          Serial.begin(9600);
          BTSerial.begin(38400); // Vitesse standard pour le mode AT du HC-05
          Serial.println("Pret pour configurer le module.");
          Serial.println("Reglez le moniteur serie sur 'Les deux, NL et CR' et 9600 baud.");
          Serial.println("Entrez vos commandes AT :");
        }

        void loop() {
          if (Serial.available()) BTSerial.write(Serial.read());
          if (BTSerial.available()) Serial.write(BTSerial.read());
        }
    ///////////////////////////////////////////////////////////////////////
    //A désactiver ici pour fin de paramétrage des identifiants bleutooth//
    ///////////////////////////////////////////////////////////////////////
*/

//////////////////////////////////////////////////////////////
//Code pour liaison maitre esclave une fois module paramétré//
//////////////////////////////////////////////////////////////

#include <SoftwareSerial.h>
   
  // RX de l'Arduino sur 10, TX sur 11
  //TX module HC05 sur 10 de l'arduino
  //RX module HC05 sur 11 de l'arduino
  int joystick = 0;
  SoftwareSerial BTSerial(10, 11);
  const int statePin = 3; // Broche STATE du HC-05 reliée à D3
  const int stateBL = 0;
  void setup() {
  pinMode(statePin, INPUT);
  pinMode(13, OUTPUT); // LED de test
  Serial.begin(9600);
  BTSerial.begin(9600); // Vitesse fixée par AT+UART
  Serial.println("---       SYSTEME Esclave Démarré       ---");
  while (BTSerial.read() == "---      Connection Maitre établie      ---") {
    Serial.println("--- En attente connexion module Maitre  ---");
    }
  stateBL == 1;
  Serial.println("---     Connection Maitre établie       ---");
  }

void loop() {

  if (BTSerial.available()) {
    joystick = BTSerial.parseInt();

    if joystick> 600:{
    Serial.print("Joystick = ");
    Serial.print(joystick);
    Serial.println(↑)
    }



  }

  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
  }
