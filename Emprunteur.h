/////////////////////////////////////////////////////////////////////////////
//Fichier Emprunteur.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file Emprunteur.cpp
 * \brief Ce fichier contient une définition de la classe Emprunteur
 * \author IFT-2008 & Étudiant(e)
 * \version 0.1
 * \date fév. 2025
 *
 */

#ifndef EMPRUNTEUR_H
#define EMPRUNTEUR_H

#include <iostream>
#include <string>
#include <list>
#include "Livre.h"
#include "ContratException.h"

namespace tp1
{

/**
 * @class Emprunteur
 * @brief Classe représentant un emprunteur dans la bibliothèque.
 */
class Emprunteur {
private:
    int m_matricule;                  // Numéro de matricule de l'emprunteur.
    std::string m_prenom;             // Prénom de l'emprunteur.
    std::string m_nom;                // Nom de famille de l'emprunteur.
    std::list<Livre> m_livresEmpruntes; // Liste des livres empruntés.
    void verifieInvariant() const;

public:
    //Constructeur de la classe Emprunteur.
    Emprunteur(int p_matricule = 0, const std::string& p_prenom = "", const std::string& p_nom = "");

    //Constructeur de copie de la classe Emprunteur.
    Emprunteur(const Emprunteur& p_autre);

    //Destructeur de la classe Emprunteur.
    ~Emprunteur();

    //Surcharge de l'opérateur d'affectation de la classe Emprunteur.
    Emprunteur& operator=(const Emprunteur& p_autre);

    //Accesseurs et modificateurs
    int reqMatricule() const;
    std::string reqPrenom() const;
    std::string reqNom() const;
    void asgPrenom(const std::string& p_prenom);
    void asgNom(const std::string& p_nom);
    int reqNombreLivresEmpruntes() const;  //Retourne le nombre de livres empruntés par l'emprunteur.

    //Ajoute un livre à la liste des livres empruntés.
    //p_livre: Livre à ajouter.
    void ajouterLivre(const Livre& p_livre);

    //Retire un livre de la liste des livres empruntés.
    //p_id: Identifiant du livre à retirer.
    void retirerLivre(int p_id);

    //Surcharge de l'opérateur d'affichage pour la classe Emprunteur.
    // Ne pas toucher à cette méthode
    friend std::ostream& operator<<(std::ostream& p_os, const Emprunteur& p_emprunteur);
};

}

#endif // EMPRUNTEUR_H