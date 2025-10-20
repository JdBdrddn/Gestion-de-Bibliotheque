# Gestion de bibliothèque (C++ / CMake)

Ce projet implémente un système console permettant de gérer une bibliothèque contenant des livres et des emprunteurs.  
Il s’agit d’un projet académique développé dans le cadre du cours IFT-2008.  
L’objectif principal est d’appliquer les principes de la programmation orientée objet en C++ et le concept de "Design by Contract".

---

## 1. Fonctionnalités principales

- Chargement des données de la bibliothèque à partir d’un fichier texte (`data.txt`)
- Ajout et gestion des livres et des emprunteurs
- Emprunt et retour de livres
- Gestion automatique de la disponibilité et des files d’attente
- Détection des retards à l’aide des fonctions temporelles (`std::chrono`)
- Validation des contraintes logiques (préconditions, postconditions, invariants)

---

## 2. Structure du projet

| Fichier | Description |
|----------|-------------|
| **Livre.h / Livre.cpp** | Définit la classe `Livre`, ses attributs (ID, titre, auteur, disponibilité, dates d’emprunt/retour) et ses opérations. |
| **Emprunteur.h / Emprunteur.cpp** | Définit la classe `Emprunteur`, gère l’identité d’un emprunteur et la liste de ses livres empruntés. |
| **Bibliotheque.h / Bibliotheque.cpp** | Gère l’ensemble des livres et emprunteurs. Fournit les opérations d’emprunt, de retour et de recherche. |
| **ContratException.h / ContratException.cpp** | Implémente les exceptions utilisées pour la vérification de contrat (pré/post/invariant). |
| **Principal.cpp** | Contient le programme principal et le menu d’interaction console. |
| **data.txt** | Fichier texte d’exemple contenant la liste initiale des livres et des emprunteurs. |

---

## 3. Compilation et exécution

### Prérequis
- CMake 3.22 ou plus
- Compilateur C++14 ou supérieur

### Étapes
```bash
mkdir build
cd build
cmake ..
cmake --build .
./CodeTP1

##Exemple d'execution (Menu console)
=== Menu Principal ===
1. Charger la bibliotheque
2. Afficher la liste des livres et des emprunteurs
3. Emprunter un livre
4. Retourner un livre
5. Verifier si un livre est en retard
6. Quitter
