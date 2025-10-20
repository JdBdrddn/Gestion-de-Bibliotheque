/////////////////////////////////////////////////////////////////////////////
//Fichier Bibliotheque.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file Bibliotheque.cpp
 * \brief Ce fichier contient une définition de la classe Bibliotheque
 * \author IFT-2008 & Étudiant(e)
 * \version 0.1
 * \date fév. 2025
 *
 */

#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <iostream>
#include <vector>
#include "Livre.h"
#include "Emprunteur.h"
#include "ContratException.h"

namespace tp1
{

/**
 * @class Bibliotheque
 * @brief Classe représentant une bibliothèque.
 */
class Bibliotheque {
private:
    std::vector<Livre> m_livres;           ///< Liste des livres dans la bibliothèque.
    std::vector<Emprunteur> m_emprunteurs; ///< Liste des emprunteurs.

    Emprunteur& reqEmprunteurParMatricule(int p_matricule);
    void verifieInvariant() const;
public:
    //Constructeur de la classe Bibliotheque.
    Bibliotheque();

    //Constructeur de copie de la classe Bibliotheque.
    Bibliotheque(const Bibliotheque& p_autre);

    //Destructeur de la classe Bibliotheque.
    ~Bibliotheque();

    //Surcharge de l'opérateur d'affectation de la classe Bibliotheque.
    Bibliotheque& operator=(const Bibliotheque& p_autre);

    //Charge les données à partir d'un fichier texte.
    //Voir l'énoncé pour le formatage du fichier texte
    void chargerDonnees(const std::string& p_nomFichier);

    //Ajoute un livre à la bibliothèque.
    void ajouterLivre(const Livre& p_livre);

    //Ajoute un emprunteur à la bibliothèque.
    void ajouterEmprunteur(const Emprunteur& p_emprunteur);

    //Permet à un emprunteur d'emprunter un livre.
    //p_idLivre: Identifiant du livre à emprunter.
    //p_matricule: Matricule de l'emprunteur.
    void emprunterLivre(int p_idLivre, int p_matricule);

    //Permet de retourner un livre à la bibliothèque.
    //p_idLivre: Identifiant du livre à retourner.
    void retournerLivre(int p_idLivre);

    //Retourne une référence au livre correspondant à l'ID donné.
    //p_id: Identifiant du livre.
    Livre& reqLivreParId(int p_id);

    //Surcharge de l'opérateur d'affichage pour la classe Bibliotheque.
    //Ne pas toucher à cette méthode !
    friend std::ostream& operator<<(std::ostream& p_os, const Bibliotheque& p_bibliotheque);
};

}

#endif // BIBLIOTHEQUE_H