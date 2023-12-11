class Jeu {
public:
    Jeu(int nbJoueurs) {
        this->nbJoueurs = nbJoueurs;
        this->joueurs = new Joueur[nbJoueurs];
        this->ob = new FinDeJeu();
    }

    void initialiser() {
        for (int i = 0; i < nbJoueurs; i++) {
            this->joueurs[i].initialiser();
        }
    }

    void executer() {
        while (!ob->estArrivee()) {
            for (int i = 0; i < nbJoueurs; i++) {
                this->joueurs[i].executer();
            }
        }
    }

    void determinerGagnant() {
        int gagnant = 0;
        for (int i = 1; i < nbJoueurs; i++) {
            if (this->joueurs[i].getScore() > this->joueurs[gagnant].getScore()) {
                gagnant = i;
            }
        }
        this->ob->setGagnant(gagnant);
    }

    void afficherGagnant() {
        cout << "Le gagnant est : " << this->ob->getGagnant() << endl;
    }

private:
    int nbJoueurs;
    Joueur* joueurs;
    FinDeJeu* ob;
};

class FinDeJeu {
public:
    FinDeJeu() {
        this->gagnant = -1;
    }

    void setGagnant(int gagnant) {
        this->gagnant = gagnant;
    }

    int getGagnant() {
        return this->gagnant;
    }

    bool estArrivee() {
        return this->gagnant != -1;
    }

private:
    int gagnant;
};
