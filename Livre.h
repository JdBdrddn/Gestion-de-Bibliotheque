/////////////////////////////////////////////////////////////////////////////
//Fichier Livre.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file Livre.cpp
 * \brief Ce fichier contient une définition de la classe Livre
 * \author IFT-2008 & Étudiant(e)
 * \version 0.1
 * \date fév. 2025
 *
 */

#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
#include <string>
#include <queue>
#include <chrono> // Pour la gestion des dates
#include "ContratException.h"

namespace tp1
{
/**
 * @class Livre
 * @brief Classe représentant un livre dans la bibliothèque.
 */
class Livre {
private:
    int m_id;               // Identifiant unique du livre.
    std::string m_titre;    // Titre du livre.
    std::string m_auteur;   // Auteur du livre.
    bool m_estDisponible;   // Disponibilité du livre.
    std::chrono::system_clock::time_point m_dateEmprunt; // Date d'emprunt du livre.
    std::chrono::system_clock::time_point m_dateRetour;  // Date de retour prévue.
    std::queue<int> m_fileAttente; // File d'attente des emprunteurs (matricules).
    void verifieInvariant() const;

public:
    // Constructeur de la classe Livre.
    Livre(int p_id = 0, const std::string& p_titre = "", const std::string& p_auteur = "", bool p_estDisponible = true);

    //Constructeur de copie de la classe Livre.
    Livre(const Livre& p_autre);

    //Destructeur de la classe Livre.
    ~Livre();

    //Surchage de l'opérateur d'affectation de la classe Livre.
    Livre& operator=(const Livre& p_autre);

    //Modificateurs
    int reqId() const;
    std::string reqTitre() const;
    std::string reqAuteur() const;
    bool reqEstDisponible() const;

    //Retourne la date de retour sous forme de chaîne.
    //La date de retour au format "AAAA-MM-JJ".
    std::string reqDateRetour() const;

    //Vérifie si la date de retour est dépassée.
    bool estRetourDepasse() const;

    //Permet à un emprunteur d'emprunter le livre.
    //p_matricule: Matricule de l'emprunteur (14 jours pour retourner)
    void emprunter(int p_matricule);

    //Permet de retourner le livre.
    //Il faut réinitialiser la date.
    void retourner();

    ///Ajoute un emprunteur à la file d'attente du livre.
    //p_matricule: Matricule de l'emprunteur.
    void ajouterEmprunteurEnAttente(int p_matricule);

    //Retire et retourne le prochain emprunteur en attente.
    //Matricule de l'emprunteur en tête de la file.
    int retirerEmprunteurEnAttente();

    //Vérifie si des emprunteurs sont en attente pour ce livre.
    //retourne `true` si la file d'attente n'est pas vide, `false` sinon.
    bool estEnAttente() const;

    //Surcharge de l'opérateur d'affichage pour la classe Livre.
    //Ne pas toucher à cette méthode !
    friend std::ostream& operator<<(std::ostream& p_os, const Livre& p_livre);
};

}

#endif // LIVRE_H