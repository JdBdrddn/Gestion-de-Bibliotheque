/////////////////////////////////////////////////////////////////////////////
//Fichier Bibliotheque.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file Bibliotheque.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Bibliotheque
 * \author IFT-2008 & Jad Badreddine
 * \version 0.1
 * \date 4 fév. 2025
 *
 */

#include "Bibliotheque.h"
#include <fstream>
#include <sstream>
#include "ContratException.h"
#include <algorithm>
#include <iterator>

namespace tp1
{


    /**
    * \fn       Bibliotheque::Bibliotheque()
    * \brief    Constructeur avec paramètres de la classe Bibliotheque.
    * \post     Le vecteur m_livres instancié est vide
    * \post     Le vecteur m_emprunteurs instancié est vide
    */
    //Constructeur de la classe Bibliotheque.
    Bibliotheque::Bibliotheque() {
        POSTCONDITION(m_livres.empty());
        POSTCONDITION(m_emprunteurs.empty());
        INVARIANTS();
    }


    /**
    * \fn        Bibliotheque::Bibliotheque(const Bibliotheque& p_autre)
    * \brief     Constructeur de copie de la classe Bibliotheque.
    * \param[in] p_autre objet de la classe Bibliotheque à copier
    * \post      Les vecteur m_emprunteurs de l'objet courant et de l'objet copié doivent avoir la même taille
    * \post      Les vecteurs m_livres de l'objet et de l'objet copié doivent avoir la même taille
    * \post      Les attributs des livres dans m_livres sont identiques à ceux de l'objet copié.
    * \post      Les attributs des  emprunteurs dans m_emprunteurs sont identiques à ceux de l'objet copié.
    */
    Bibliotheque::Bibliotheque(const Bibliotheque& p_autre) {

        m_livres = p_autre.m_livres;
        m_emprunteurs = p_autre.m_emprunteurs;

        POSTCONDITION(m_livres.size() == p_autre.m_livres.size());
        POSTCONDITION(m_emprunteurs.size() == m_livres.size());

        for ( size_t i=0; i < m_livres.size(); i++ ) {
            POSTCONDITION(m_livres[i].reqAuteur() == m_livres[i].reqAuteur());
            POSTCONDITION(m_livres[i].reqId() == m_livres[i].reqId());
            POSTCONDITION(m_livres[i].reqTitre() == m_livres[i].reqTitre());
            POSTCONDITION(m_livres[i].reqEstDisponible() == m_livres[i].reqEstDisponible());
            POSTCONDITION(m_livres[i].reqDateRetour() == m_livres[i].reqDateRetour());

        }

        for ( size_t i=0; i < m_emprunteurs.size(); i++ ) {
            POSTCONDITION(m_emprunteurs[i].reqMatricule() == p_autre.m_emprunteurs[i].reqMatricule());
            POSTCONDITION(m_emprunteurs[i].reqPrenom() == p_autre.m_emprunteurs[i].reqPrenom());
            POSTCONDITION(m_emprunteurs[i].reqNom() == p_autre.m_emprunteurs[i].reqNom());
            POSTCONDITION(m_emprunteurs[i].reqNombreLivresEmpruntes() == p_autre.m_emprunteurs[i].reqNombreLivresEmpruntes());
        }
        INVARIANTS();
    }


    /**
     * \fn     Bibliotheque::~Bibliotheque()
     * \brief  Destructeur de la classe Bibliotheque.
     */
    Bibliotheque::~Bibliotheque() {}


    /**
   * \fn         Bibliotheque& Bibliotheque::operator=(const Bibliotheque& p_autre)
   * \brief      Surcharge de l'opérateur d'affectation.
   * \param[in]  p_autre Objet de la classe Bibliotheque à affecter.
   * \post      Les vecteur m_emprunteurs de l'objet courant et de l'objet copié doivent avoir la même taille
   * \post      Les vecteurs m_livres de l'objet et de l'objet copié doivent avoir la même taille
   * \post      Les attributs des livres dans m_livres sont identiques à ceux de l'objet copié.
   * \post      Les attributs des  emprunteurs dans m_emprunteurs sont identiques à ceux de l'objet copié.
   */
    Bibliotheque& Bibliotheque::operator=(const Bibliotheque& p_autre) {

        if (this != &p_autre) {
            m_livres = p_autre.m_livres;
            m_emprunteurs = p_autre.m_emprunteurs;
        }


        POSTCONDITION(m_livres.size() == p_autre.m_livres.size());
        POSTCONDITION(m_emprunteurs.size() == m_livres.size());

        for ( size_t i=0; i < m_livres.size(); i++ ) {
            POSTCONDITION(m_livres[i].reqAuteur() == m_livres[i].reqAuteur());
            POSTCONDITION(m_livres[i].reqId() == m_livres[i].reqId());
            POSTCONDITION(m_livres[i].reqTitre() == m_livres[i].reqTitre());
            POSTCONDITION(m_livres[i].reqEstDisponible() == m_livres[i].reqEstDisponible());
            POSTCONDITION(m_livres[i].reqDateRetour() == m_livres[i].reqDateRetour());

        }

        for ( size_t i=0; i < m_emprunteurs.size(); i++ ) {
            POSTCONDITION(m_emprunteurs[i].reqMatricule() == p_autre.m_emprunteurs[i].reqMatricule());
            POSTCONDITION(m_emprunteurs[i].reqPrenom() == p_autre.m_emprunteurs[i].reqPrenom());
            POSTCONDITION(m_emprunteurs[i].reqNom() == p_autre.m_emprunteurs[i].reqNom());
            POSTCONDITION(m_emprunteurs[i].reqNombreLivresEmpruntes() == p_autre.m_emprunteurs[i].reqNombreLivresEmpruntes());
        }


        return *this;
    }


     /**
     * \fn         void Bibliotheque::chargerDonnees(const std::string& p_nomFichier)
     * \brief      Charge les données de la bibliothèque à partir d'un fichier texte.
     * \param[in]  p_nomFichier Nom du fichier contenant les données.
     * \pre        Le fichier ne doit pas être vide
     * \post       Le fichier doit être fermé après fichier.close()
     * \post       Le nombre de livres après avoir chargé les livres doit être plus grand
     * \post       Le nombre d'dmprunteurs après avoir chargé les emprunteurs doit être plus grand
     */
    //Charge les données à partir d'un fichier texte.
    void Bibliotheque::chargerDonnees(const std::string& p_nomFichier) {

        std::ifstream fichier(p_nomFichier);
        if (!fichier.is_open()) {
            throw std::runtime_error("Erreur lors de l'ouverture du fichier.");
        }
        bool modeMembre = false;

        PRECONDITION(!p_nomFichier.empty());

        char ligne[256];


        while (fichier.getline(ligne, 256)){

            if (std::string(ligne) == "$") {
                modeMembre = true;
                continue;
            }


            if (modeMembre == false) {
                std::istringstream iss (ligne);
                int id;
                std::string titre, auteur;
                int disponibilite;
                iss >> id >> titre >> auteur >> disponibilite;
                Livre unLivre(id, titre, auteur, static_cast<bool>(disponibilite));
                ajouterLivre(unLivre);


            } else {
                std::istringstream iss (ligne);
                int matricule;
                std::string prenom, nom;
                iss >> matricule>> prenom >> nom;
                Emprunteur unEmprunteur(matricule, prenom, nom);
                ajouterEmprunteur(unEmprunteur);
            }
    }
        fichier.close();
        POSTCONDITION(!fichier.is_open());
        INVARIANTS();
    }


    /**
     * \fn          void Bibliotheque::ajouterLivre(const Livre& p_livre)
     * \brief       Ajoute un livre au vecteur m_livres de la bibliothèque.
     * \param[in]   p_livre Livre à ajouter au vecteur.
     * \post        Les livres ajoutés au vecteur m_livres ont le même m_id que celui entré en paramètre.
     * \post        La taille du vecteur de livres de la bibliothèque m_livres est plus grand après l'ajout
     */
    //Ajoute un livre à la bibliothèque.
    void Bibliotheque::ajouterLivre(const Livre& p_livre) {
        int tailleAvant = m_livres.size();
        m_livres.push_back(p_livre);
        int tailleApres = m_livres.size();

        POSTCONDITION(tailleApres>tailleAvant);
        INVARIANTS();
    }


     /**
     * \fn          void Bibliotheque::ajouterEmprunteur(const Emprunteur& p_emprunteur)
     * \brief       Ajoute un emprunteur à la bibliothèque.
     * \param[in]   p_emprunteur Emprunteur à ajouter.
     * \pre         La matricule doit etre un nombre positif
     * \post        La taille du vecteur d'emprunteurs est plus grand après l'ajout d'un emprunteur
     */
    //Ajoute un emprunteur à la bibliothèque.
    void Bibliotheque::ajouterEmprunteur(const Emprunteur& p_emprunteur) {
        PRECONDITION((p_emprunteur.reqMatricule())>0);

        int tailleAvant = m_emprunteurs.size();

        m_emprunteurs.push_back(p_emprunteur);
        int tailleApres = m_emprunteurs.size();
        POSTCONDITION(tailleApres>tailleAvant);
        INVARIANTS();
    }


    /**
    * \fn          void Bibliotheque::emprunterLivre(int p_idLivre, int p_matricule)
    * \brief       Permet à un emprunteur d'emprunter un livre.
    * \param[in]   p_idLivre identifiant du livre a emprunter.
    * \param[in]   p_matricule matricule de l'emprunteur.
    * \post        Les emprunteurs ajoutés au vecteur m_emprunteurs ont le même m_matricule que celui entré en paramètre.
    * \post        La taille du vecteur d'emprunteurs de la bibliothèque m_emprunteurs est plus grand après l'ajout
    */
    void Bibliotheque::emprunterLivre(int p_idLivre, int p_matricule) {
       PRECONDITION(p_idLivre>0);
       PRECONDITION(p_matricule>0);
        Livre& livre = reqLivreParId(p_idLivre);

        livre.emprunter(p_matricule);
        (reqEmprunteurParMatricule(p_matricule)).ajouterLivre(livre);

        INVARIANTS();
    }


    /**
    * \fn          void Bibliotheque::retournerLivre(int p_idLivre, int p_matricule)
    * \brief       Permet de retourner un livre à la bibliotheque.
    * \param[in]   p_idLivre identifiant du livre a retourner.
    * \post        Les emprunteurs ajoutés au vecteur m_emprunteurs ont le même m_matricule que celui entré en paramètre.
    * \post        La taille du vecteur d'emprunteurs de la bibliothèque m_emprunteurs est plus grand après l'ajout
    */
    void Bibliotheque::retournerLivre(int p_idLivre) {
        PRECONDITION(p_idLivre>0);


        Livre& livre = reqLivreParId(p_idLivre);
        livre.retourner();

        for (auto& emprunteur : m_emprunteurs) {
            int nbLivreEmprunteAvant = emprunteur.reqNombreLivresEmpruntes();

            emprunteur.retirerLivre(p_idLivre);

            int nbLivreEmprunteApres = emprunteur.reqNombreLivresEmpruntes();

            if (nbLivreEmprunteApres < nbLivreEmprunteAvant) {
                break;
            }
        }


        INVARIANTS();
    }


    /**
    * \fn          Livre& Bibliotheque::reqLivreParId(int p_id)
    * \brief       Retourne une référence au livre correspondant à l'ID donné
    * \param[in]   p_id identifiant d'un livre.
    * \pre         Le id du livre est positif
    * \pre         Le vecteur qui contient les livres de la bibliothèque ne devrait pas être vide
    * \post        Le vecteur qui contient les livres de la bibliothèque reste inchangé
    */
    Livre& Bibliotheque::reqLivreParId(int p_id) {
       PRECONDITION(p_id>0);
       PRECONDITION(!m_livres.empty());
       int nbLivresAvant = m_livres.size();
       for (auto it = m_livres.begin(); it != m_livres.end(); ++it) {
           if (it ->reqId() == p_id){
           int nbLivresApres = m_livres.size();
           POSTCONDITION(nbLivresAvant==nbLivresApres);
           return *it;
           }
           int nbLivresApres = m_livres.size();
           POSTCONDITION(nbLivresAvant==nbLivresApres);
       }
        throw std::runtime_error("Livre non trouvé");
    }


    /**
    * \fn          Livre& Bibliotheque::reqEmprunteurParMatricule(int p_matricule)
    * \brief       Retourne une référence à l'emprunteur correspondant à la matricule donné
    * \param[in]   p_matricule matricule d'un emprunteur.
    * \pre         La matricule du livre est positive
    * \pre         Le vecteur qui contient les emprunteurs de la bibliothèque ne devrait pas être vide
    * \post        Le vecteur qui contient les emprunteurs de la bibliothèque reste inchangé
    */
    Emprunteur& Bibliotheque::reqEmprunteurParMatricule( int p_matricule) {
        PRECONDITION(p_matricule>0);
        PRECONDITION(!m_emprunteurs.empty());
        int nbLivresAvant = m_emprunteurs.size();
        for (auto it = m_emprunteurs.begin(); it != m_emprunteurs.end(); ++it) {
            if (it ->reqMatricule() == p_matricule) {
                int nbLivresApres = m_emprunteurs.size();
                POSTCONDITION(nbLivresAvant==nbLivresApres);
                return *it;
            }
            int nbLivresApres = m_emprunteurs.size();
            POSTCONDITION(nbLivresAvant==nbLivresApres);
        }
        throw std::runtime_error("Emprunteur non trouvé");
    }


    /**
    * \fn        ostream& Bibliotheque::operator<< (ostream& p_os, const Bibliotheque& p_bibliotheque)
    * \brief     Surcharge de l'opérateur d'affichage de la classe Bibliotheque.
    */
    //Surcharge de l'opérateur d'affichage pour la classe Bibliotheque.
    //Ne pas toucher à cette méthode !
    std::ostream& operator<<(std::ostream& p_os, const Bibliotheque& p_bibliotheque) {
        p_os << "=== Liste des livres ===" << std::endl;
        for (const auto& livre : p_bibliotheque.m_livres) {
            p_os << livre << std::endl;
        }

        p_os << "\n=== Liste des emprunteurs ===" << std::endl;
        for (const auto& emprunteur : p_bibliotheque.m_emprunteurs) {
            p_os << emprunteur << std::endl;
        }

        return p_os;
    }

    void Bibliotheque::verifieInvariant() const {

    }

}