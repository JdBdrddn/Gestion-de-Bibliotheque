/////////////////////////////////////////////////////////////////////////////
//Fichier Principal.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file Principal.cpp
 * \brief Ce fichier contient un main permettant de tester le système
 * \author IFT-2008
 * \version 0.1
 * \date fév. 2025
 *
 * Ce fichier contient un main permettant de tester le système
 * de gestion d'une bibliothèque.
 */

#include "Bibliotheque.h"
#include <iostream>

/**
 * @brief Affiche le menu principal et retourne le choix de l'utilisateur.
 * @return Choix de l'utilisateur.
 */

int afficherMenu() {
    int choix;
    std::cout << "\n=== Menu Principal ===" << std::endl;
    std::cout << "1. Charger la bibliotheque" << std::endl;
    std::cout << "2. Afficher la liste des livres et des emprunteurs" << std::endl;
    std::cout << "3. Emprunter un livre" << std::endl;
    std::cout << "4. Retourner un livre" << std::endl;
    std::cout << "5. Verifier si un livre est en retard" << std::endl;
    std::cout << "6. Quitter" << std::endl;
    std::cout << "Votre choix : ";
    std::cin >> choix;
    return choix;
}

/**
 * @brief Fonction principale du programme.
 */


int main() {

    tp1::Bibliotheque bibliotheque;
    bool donneesChargees = false; // Indique si les données ont été chargées

    int choix;
    do {
        choix = afficherMenu();
        try {
            switch (choix) {
                case 1: { // Charger la bibliothèque
                    std::cout << "\n=== Chargement de la bibliotheque ===" << std::endl;
                    bibliotheque.chargerDonnees("../data.txt");
                    donneesChargees = true;
                    std::cout << "Donnees chargees avec succes !" << std::endl;
                    break;
                }
                case 2: { // Afficher la liste des livres et des emprunteurs
                    if (!donneesChargees) {
                        std::cout << "Veuillez d'abord charger la bibliotheque (choix 1)." << std::endl;
                        break;
                    }
                    std::cout << "\n=== Liste des livres et des emprunteurs ===" << std::endl;
                    std::cout << bibliotheque << std::endl;
                    break;
                }
                case 3: { // Emprunter un livre
                    if (!donneesChargees) {
                        std::cout << "Veuillez d'abord charger la bibliotheque (choix 1)." << std::endl;
                        break;
                    }
                    int idLivre, matricule;
                    std::cout << "\n=== Emprunter un livre ===" << std::endl;
                    std::cout << "Entrez l'ID du livre : ";
                    std::cin >> idLivre;
                    std::cout << "Entrez le matricule de l'emprunteur : ";
                    std::cin >> matricule;
                    bibliotheque.emprunterLivre(idLivre, matricule);
                    if (bibliotheque.reqLivreParId(idLivre).estEnAttente()) {
                        std::cout<< "Livre indisponible. Emprunteur ajoute a la file d'attente." << std::endl;
                        break;
                    }
                    std::cout << "Livre emprunte avec succes !" << std::endl;
                    break;
                }
                case 4: { // Retourner un livre
                    if (!donneesChargees) {
                        std::cout << "Veuillez d'abord charger la bibliotheque (choix 1)." << std::endl;
                        break;
                    }
                    int idLivre;
                    std::cout << "\n=== Retourner un livre ===" << std::endl;
                    std::cout << "Entrez l'ID du livre : ";
                    std::cin >> idLivre;
                    bibliotheque.retournerLivre(idLivre);
                    std::cout << "Livre retourne avec succes !" << std::endl;
                    break;
                }
                case 5: { // Vérifier si un livre est en retard
                    if (!donneesChargees) {
                        std::cout << "Veuillez d'abord charger la bibliotheque (choix 1)." << std::endl;
                        break;
                    }
                    int idLivre;
                    std::cout << "\n=== Verifier si un livre est en retard ===" << std::endl;
                    std::cout << "Entrez l'ID du livre : ";
                    std::cin >> idLivre;
                    try {
                        tp1::Livre& livre = bibliotheque.reqLivreParId(idLivre);
                        if (livre.estRetourDepasse()) {
                            std::cout << "Le livre est en retard !" << std::endl;
                        } else {
                            std::cout << "Le livre n'est pas en retard." << std::endl;
                        }
                    } catch (const std::runtime_error& e) {
                        std::cerr << "Erreur : " << e.what() << std::endl;
                    }
                    break;
                }
                case 6: { // Quitter
                    std::cout << "Merci d'avoir utilise le systeme de gestion de bibliotheque. Au revoir !" << std::endl;
                    break;
                }
                default: {
                    std::cout << "Choix invalide. Veuillez reessayer." << std::endl;
                    break;
                }
            }
        } catch (const std::runtime_error& e) {
            std::cerr << "Erreur : " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Une erreur inattendue s'est produite : " << e.what() << std::endl;
        }
    } while (choix != 6);




    return 0;
}