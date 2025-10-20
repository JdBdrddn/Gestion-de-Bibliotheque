/////////////////////////////////////////////////////////////////////////////
//Fichier Livre.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file Livre.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Livre
 * \author IFT-2008 & Jad Badreddine
 * \version 0.1
 * \date fév. 2025
 *
 */

#include "Livre.h"
#include "ContratException.h"
#include <sstream>
#include <iomanip>

namespace tp1
{

    /**
    * \fn    Livre::Livre(int p_id, const std::string& p_titre, const std::string& p_auteur, bool p_estDisponible)
    * \brief    Constructeur avec paramètres de la classe Livre.
    * \param[in] p_id entier qui représente le numéro d'identification du livre
    * \param[in] p_titre chaine de charactères qui représente le titre du livre
    * \param[in] p_auteur chaine de charactères qui représente le nom de l'auteur
    * \param[in] p_estDisponible booléen qui représente la disponibilité du livre
    * \pre    L'identifiant (p_id) du livre est  positif
    * \pre    La file d'attente m_fileAttente est vide
    * \post   Le titre du livre correspond a celui passé en paramètre
    * \post   Le nom de l'auteur correspond a celui passé en paramètre
    * \post   Le numéro d'identification du livre correspond a celui passé en paramètre
    * \post   La disponibilité du livre correspond a celui passé en paramètre.
    */
    Livre::Livre(int p_id, const std::string& p_titre, const std::string& p_auteur, bool p_estDisponible):
    m_id(p_id), m_titre(p_titre), m_auteur(p_auteur), m_estDisponible(p_estDisponible)
    {

        PRECONDITION(p_id>=0);
        PRECONDITION(m_fileAttente.empty());
        POSTCONDITION(p_titre == m_titre);
        POSTCONDITION(p_auteur==m_auteur);
        POSTCONDITION(p_id==m_id);
        POSTCONDITION(p_estDisponible==m_estDisponible);
        INVARIANTS();

    }


    /**
    * \fn    Livre::Livre(const Livre& p_autre)
    * \brief    Constructeur de copie de la classe Livre.
    * \param[in] p_autre objet de la classe Livre à copier
    * \pre   La file d'attente du livre est vide avant le copiage
    * \post   Le titre du livre correspond a celui de l'objet à copier
    * \post   Le nom de l'auteur correspond a celui de l'objet à copier
    * \post   Le numéro d'identification du livre correspond a celui de l'objet à copier
    * \post   La disponibilité du livre correspond a celui de l'objet à copier
    * \post   La date d'emprunt est identique a celle de l'objet à copier
    * \post   La date de retour est identique a celle de l'objet à copier
    * \post   La file d'attente est identique a celle de l'objet passée en paramètre.
    */
    Livre::Livre(const Livre& p_autre) :
    m_id(p_autre.m_id),
    m_titre(p_autre.m_titre),
    m_auteur(p_autre.m_auteur),
    m_estDisponible(p_autre.m_estDisponible),
    m_dateEmprunt(p_autre.m_dateEmprunt),
    m_dateRetour(p_autre.m_dateRetour){

        PRECONDITION(m_fileAttente.empty());

        m_fileAttente = p_autre.m_fileAttente;

        POSTCONDITION(m_id==p_autre.m_id);
        POSTCONDITION(m_titre == p_autre.m_titre);
        POSTCONDITION(m_auteur == p_autre.m_auteur);
        POSTCONDITION(m_estDisponible == p_autre.m_estDisponible);
        POSTCONDITION(m_dateEmprunt==p_autre.m_dateEmprunt);
        POSTCONDITION(m_dateRetour==p_autre.m_dateRetour);
        POSTCONDITION(m_fileAttente == p_autre.m_fileAttente);
        INVARIANTS();
    }


    /**
    * \fn    Livre::~Livre()
    * \brief destructeur de la classe Livre.
    */
    Livre::~Livre() {}


    /**
    * \fn    Livre::operator= (const Livre& p_autre)
    * \brief   Opérateur d'affectation de la classe Livre.
    * \param[in] p_autre objet Livre à copier.
    * \post   Le titre du livre est identique a celui de l'objet passé en paramètre
    * \post   Le nom de l'auteur est identique a celui de l'objet passé en paramètre
    * \post   Le numéro d'identification du livre est identique a celui de l'objet passé en paramètre
    * \post   La disponibilité du livre est identique a celui de l'objet passé en paramètre.
    * \post   La date d'emprunt est identique a celle de l'objet passée en paramètre.
    * \post   La date de retour est identique a celle de l'objet passée en paramètre.
    * \post   La file d'attente est identique a celle de l'objet passée en paramètre.
    */
    Livre& Livre::operator=(const Livre& p_autre) {
        if (this != &p_autre) {

            m_auteur=p_autre.m_auteur;
            m_titre=p_autre.m_titre;
            m_id=p_autre.m_id;
            m_estDisponible=p_autre.m_estDisponible;
            m_dateEmprunt=p_autre.m_dateEmprunt;
            m_dateRetour=p_autre.m_dateRetour;

            m_fileAttente=p_autre.m_fileAttente;
        }

        POSTCONDITION(m_id==p_autre.m_id);
        POSTCONDITION(m_titre == p_autre.m_titre);
        POSTCONDITION(m_auteur == p_autre.m_auteur);
        POSTCONDITION(m_estDisponible == p_autre.m_estDisponible);
        POSTCONDITION(m_dateEmprunt==p_autre.m_dateEmprunt);
        POSTCONDITION(m_dateRetour==p_autre.m_dateRetour);
        POSTCONDITION(m_fileAttente == p_autre.m_fileAttente);
        INVARIANTS();
        return *this;
    }


    /**
    * \fn   int Livre::reqID() const
    * \brief accesseur de m_id .
    */
    int Livre::reqId() const {
        return m_id;
    }


    /**
    * \fn   string Livre::reqTitre() const
    * \brief accesseur de m_titre .
    */
    std::string Livre::reqTitre() const {
        return m_titre;
    }


     /**
     * \fn   string Livre::reqAuteur() const
     * \brief accesseur de m_auteur .
     */
    std::string Livre::reqAuteur() const {
        return m_auteur;
    }


     /**
     * \fn   bool Livre::reqEstDisponible() const
     * \brief accesseur de m_estDisponible .
     */
    bool Livre::reqEstDisponible() const {
        return m_estDisponible;
    }


     /**
     * \fn      string Livre::reqDateRetour() const
     * \brief   Accesseur du membre m_dateRetour qui retourne un string formaté
     */

    std::string Livre::reqDateRetour() const {

        if (m_estDisponible ==  false) {
            std::ostringstream os;
            std::time_t dateRetour = std::chrono::system_clock::to_time_t(m_dateRetour);
            std::tm* ptr_date = std::localtime(&dateRetour);
            os << std::put_time(ptr_date, "%Y-%m-%d");

            return os.str();
        }

        return "Le livre n'est pas emprunté.";

    }


    /**
    * \fn      bool Livre::estRetourDepasse() const
    * \brief   vérifie si la date de retour est depassée
    */
    bool Livre::estRetourDepasse() const {
        return m_dateRetour < std::chrono::system_clock::now();
    }


    /**
    * \fn      void Livre::emprunter(int p_matricule)
    * \brief   permet d'emprunter le livre et le rendre indisponible.
    * \param[in] p_matricule matricule d'un emprunteur.
    * \pre    p_matricule est un entier positif
    */
    void Livre::emprunter(int p_matricule) {

        PRECONDITION(p_matricule >=0);

        if (m_estDisponible == true ) {
            if (m_fileAttente.empty()) {
                m_estDisponible = false;
                m_dateEmprunt = std::chrono::system_clock::now();
                m_dateRetour = m_dateEmprunt + std::chrono::hours(336);
            }
        } else {
                ajouterEmprunteurEnAttente(p_matricule);
            }


        INVARIANTS();
    }


     /**
     * \fn    void Livre::retourner()
     * \brief   méthode qui permet de retourner un livre préalablement emprunté.
     * \pre     m_estDisponible est false donc le livre est emprunté
     * \post    m_estDisponible est true donc le livre est disponible
     * \post    m_dateEmprunt et m_dateRetour sont réinitialisé
     */
    void Livre::retourner() {
        PRECONDITION(m_estDisponible==false);
        m_estDisponible = true;
        m_dateEmprunt = std::chrono::system_clock::time_point();
        m_dateRetour = std::chrono::system_clock::time_point();

        POSTCONDITION(m_estDisponible==true);
        POSTCONDITION(m_dateEmprunt==m_dateRetour);

        INVARIANTS();
    }


    /**
    * \fn    void Livre::ajouterEmprunteurEnAttente()
    * \brief   Ajoute un emprunteur dans la file d'attente.
    * \pre     La matricule existe.
    * \post    La taille de la fille d'attente augmente d'une personne.
    */
    void Livre::ajouterEmprunteurEnAttente(int p_matricule) {
        PRECONDITION(p_matricule>=0);

        int nbPersonnesFileAttenteAvantAjout = m_fileAttente.size();

        m_fileAttente.push(p_matricule);

        int nbPersonnesFileAttenteApresAjout = m_fileAttente.size();

        POSTCONDITION(nbPersonnesFileAttenteApresAjout == (nbPersonnesFileAttenteAvantAjout+1));
        INVARIANTS();
    }


     /**
     * \fn    void Livre::retirerEmprunteurEnAttente()
     * \brief   Retourne le premier emprunteur dans la file d'attente et le retire du file.
     * \pre     La file d'attente m_fileAttente ne peut être vide.
     * \post    La taille de la fille d'attente diminue d'une personne.
     */
    int Livre::retirerEmprunteurEnAttente() {
        PRECONDITION(!m_fileAttente.empty());
        int nbPersonnesEnAttenteAvant = m_fileAttente.size();
        int prochain;
        prochain = m_fileAttente.front();
        m_fileAttente.pop();
        int nbPersonnesEnAttenteApres = m_fileAttente.size();
        POSTCONDITION(nbPersonnesEnAttenteApres == (nbPersonnesEnAttenteAvant-1));
        INVARIANTS();
        return prochain;
    }


    /**
    * \fn    bool Livre::estEnAttente() const
    * \brief   retourne true si la file d'attente contient au moin un emprunteur, false sinon.
    */
    //Vérifie si des emprunteurs sont en attente pour ce livre.
    //retourne `true` si la file d'attente n'est pas vide, `false` sinon.
    bool Livre::estEnAttente() const {
        return !m_fileAttente.empty();
    }


    /**
    * \fn    ostream& Livre::operator<<(ostream& p_os, const Livre& p_livre)
    * \brief   Surcharge  de l'opérateur d'affichage. Retourne les informations formatés du livre.
    */
    std::ostream& operator<<(std::ostream& p_os, const Livre& p_livre) {
        p_os << "ID: " << p_livre.m_id << ", Titre: " << p_livre.m_titre << ", Auteur: " << p_livre.m_auteur
             << ", Disponible: " << (p_livre.m_estDisponible ? "Oui" : "Non");
        if (!p_livre.m_estDisponible) {
            p_os << ", Date de retour: " << p_livre.reqDateRetour();
        }
        if (!p_livre.m_fileAttente.empty()) {
            p_os << ", En attente: ";
            std::queue<int> file = p_livre.m_fileAttente;
            while (!file.empty()) {
                p_os << file.front() << " ";
                file.pop();
            }
        }
        return p_os;
    }


    /**
    * \fn    void Livre::verifieInvariant() const
    * \brief vérifie que les membres de la classe livre restent cohérent tout au long de l'éxecution du programme.
    */
    void Livre::verifieInvariant() const {
        INVARIANT(m_id>=0);
        INVARIANT(m_estDisponible == true || m_estDisponible == false);
        INVARIANT(m_fileAttente.empty() == !estEnAttente());
        if (m_estDisponible == false) {
            INVARIANT(m_dateEmprunt < m_dateRetour);
        }

        if (m_estDisponible == true) {
            INVARIANT(m_dateRetour==m_dateEmprunt);
        }

        if (estEnAttente() == false) {
            INVARIANT(m_fileAttente.empty());
        }

    }

}