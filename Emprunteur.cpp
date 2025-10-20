/////////////////////////////////////////////////////////////////////////////
//Fichier Emprunteur.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file Emprunteur.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Emprunteur
 * \author IFT-2008 & Jad Badreddine
 * \version 0.1
 * \date fév. 2025
 *
 */

#include "Emprunteur.h"
#include "ContratException.h"
#include <algorithm>

namespace tp1
{


    /**
    * \fn        Emprunteur::Emprunteur(int p_matricule, const string& p_prenom, const string& p_nom)
    * \brief     Constructeur avec paramètres de la classe Livre.
    * \param[in] p_matricule entier qui représente la matricule de l'emprunteur
    * \param[in] p_prenom chaine de charactères qui représente le prenom de l'emprunteur
    * \param[in] p_nom chaine de charactères qui représente le nom de l'emprunteur
    * \pre       la matricule est un entier positif
    * \pre       La liste de livres empruntés doit être vide lors de la création de l'emprunteur
    * \post      La matricule correspond a celle passée en paramètre
    * \post      Le prenom de l'emprunteur correspond a celui passé en paramètre
    * \post      Le nom de l'emprunteur correspond a celui passé en paramètre
    */
    Emprunteur::Emprunteur(int p_matricule, const std::string& p_prenom, const std::string& p_nom) :
    m_matricule(p_matricule), m_prenom(p_prenom), m_nom(p_nom){
        PRECONDITION(p_matricule>=0);
        PRECONDITION(m_livresEmpruntes.empty());
        POSTCONDITION(m_matricule == p_matricule);
        POSTCONDITION(m_prenom == p_prenom);
        POSTCONDITION(m_nom == p_nom);
        INVARIANTS();

    }


    /**
    * \fn        Emprunteur::Emprunteur(const Emprunteur& p_autre)
    * \brief     Constructeur de copie de la classe Emprunteur.
    * \param[in] p_autre objet de la classe Emprunteur à copier
    * \pre       La matricule de la classe Emprunteur à copier est positive
    * \pre       La liste de livres empruntés doit être vide lors de la création de l'emprunteur
    * \post      La matricule correspond a celle de l'objet Emprunteur passée en paramètre
    * \post      Le prénom de l'emprunteur correspond a celui de l'objet Emprunteur passé en paramètre
    * \post      Le nom de l'emprunteur correspond a celui l'objet Emprunteur passé en paramètre
    */
    Emprunteur::Emprunteur(const Emprunteur& p_autre) :
    m_matricule(p_autre.m_matricule), m_prenom(p_autre.m_prenom), m_nom(p_autre.m_nom){
        PRECONDITION(p_autre.m_matricule>=0);
        PRECONDITION(m_livresEmpruntes.empty());
        m_livresEmpruntes = p_autre.m_livresEmpruntes;
        POSTCONDITION(m_prenom == p_autre.m_prenom);
        POSTCONDITION(m_nom == p_autre.m_nom);
        POSTCONDITION(m_matricule == p_autre.m_matricule);
        INVARIANTS();

    }


    /**
    * \fn    Emprunteur::~Emprunteur()
    * \brief destructeur de la classe Emprunteur.
    */
    //Destructeur de la classe Emprunteur.
    Emprunteur::~Emprunteur() {}



    /**
    * \fn        Emprunteur& Emprunteur::operator= (const Emprunteur& p_autre)
    * \brief     Opérateur d'affectation de la classe Emprunteur.
    * \param[in] p_autre objet la classe Emprunteur à copier.
    * \post      La matricule de l'emprunteur est identique a celui de l'opérande droite
    * \post      Le nom de l'emprunteur est identique a celle de l'opérande droite.
    * \post      Le prénom de l'emprunteur est identique a celle de l'opérande droite.
    * \post      La liste de livres emprunté a le même nombre d'éléments que celle de l'opérande droite.
    */
    Emprunteur& Emprunteur::operator=(const Emprunteur& p_autre) {
        if (this != &p_autre) {
            m_matricule = p_autre.m_matricule;
            m_prenom = p_autre.m_prenom;
            m_nom = p_autre.m_nom;
            m_livresEmpruntes = p_autre.m_livresEmpruntes;
        }
        POSTCONDITION(m_prenom == p_autre.m_prenom);
        POSTCONDITION(m_nom == p_autre.m_nom);
        POSTCONDITION(m_matricule == p_autre.m_matricule);
        POSTCONDITION(m_livresEmpruntes.size() == p_autre.m_livresEmpruntes.size());
        return *this;
    }


    /**
    * \fn   int Emprunteur::reqMatricule() const
    *\brief accesseur de m_matricule .
    */
    int Emprunteur::reqMatricule() const {
        return m_matricule;
    }


    /**
    * \fn   string Emprunteur::reqPrenom() const
    *\brief accesseur de m_prenom.
    */
    std::string Emprunteur::reqPrenom() const {
        return m_prenom;
    }


    /**
    * \fn   string Emprunteur::reqNom() const
    *\brief accesseur de m_nom .
    */
    std::string Emprunteur::reqNom() const {
        return m_nom;
    }


    /**
    *\fn        void Emprunteur::asgPrenom(string& p_prenom);
    *\brief     modificateur de m_prenom
    *\param[in] p_prenom chaine de charactere qui désigne le prenom de l'emprunteur
    *\post      m_prenom est identique a celui passé en paramètre
    */
    void Emprunteur::asgPrenom(const std::string& p_prenom) {
        m_prenom = p_prenom;
        POSTCONDITION(m_prenom == p_prenom);
        INVARIANTS();
    }


    /**
    *\fn        void Emprunteur::asgNom(string& p_nom);
    *\brief     modificateur de m_nom
    *\param[in] p_nom chaine de charactere qui désigne le nom de l'emprunteur
    *\post      m_nom est identique a celui passé en paramètre
    */
    void Emprunteur::asgNom(const std::string& p_nom) {
        m_nom = p_nom;
        POSTCONDITION(m_nom == p_nom);
        INVARIANTS();
    }


    /**
    * \fn   int Emprunteur::reqNombreLivresEmpruntes() const
    *\brief retourne le nombre de livres empruntés par l'emprunteur.
    */
    int Emprunteur::reqNombreLivresEmpruntes() const {
        return m_livresEmpruntes.size();
    }


    /**
    *\fn        int Emprunteur::ajouterLivre(const Livre& p_livre);
    *\brief     Ajoute un livre à la liste des livres empruntés
    *\param[in] p_livre une instance de la classe Livre
    *\post      Le nombre de livres empruntés augmente de un après l'ajout
    */
    void Emprunteur::ajouterLivre(const Livre& p_livre) {


        if (!p_livre.estEnAttente()) {
            int nbLivresEmprunteAvantAjout = m_livresEmpruntes.size();

            m_livresEmpruntes.push_back(p_livre);

            int nbLivresEmprunteApresAjout = m_livresEmpruntes.size();
            POSTCONDITION(nbLivresEmprunteApresAjout == (nbLivresEmprunteAvantAjout+1));
        }

        INVARIANTS();
    }


    /**
    * \fn        void Emprunteur::retirerLivre (int p_id)
    * \brief     Opérateur d'affectation de la classe Emprunteur.
    * \param[in] p_autre objet la classe Emprunteur à copier.

    */
    void Emprunteur::retirerLivre(int p_id) {

        for (auto iter = m_livresEmpruntes.begin(); iter != m_livresEmpruntes.end();) {
            if (iter->reqId() == p_id) {
               iter = m_livresEmpruntes.erase(iter);
            } else { ++iter; }
        }


        INVARIANTS();
    }


    /**
    * \fn        ostream& Emprunteur::operator<< (ostream& p_os, const Emprunteur& p_emprunteur)
    * \brief     Surcharge de l'opérateur d'affichage de la classe Emprunteur.
    */
    std::ostream& operator<<(std::ostream& p_os, const Emprunteur& p_emprunteur) {
        p_os << "Matricule: " << p_emprunteur.m_matricule << ", Prenom: " << p_emprunteur.m_prenom
             << ", Nom: " << p_emprunteur.m_nom << ", Nombre de livres empruntes: " << p_emprunteur.reqNombreLivresEmpruntes();
        if (p_emprunteur.reqNombreLivresEmpruntes() > 0) {
            p_os << ", Livres empruntes: ";
            for (const auto& livre : p_emprunteur.m_livresEmpruntes) {
                p_os << livre << "; ";
            }
        }
        return p_os;
    }


    /**
    * \fn        void Emprunteur::verifieInvariant() const
    * \brief     vérifie les invariants de la classe
    */
    void Emprunteur::verifieInvariant() const {
        INVARIANT(m_matricule>=0);

    }
}