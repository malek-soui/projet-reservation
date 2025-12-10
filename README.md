# Système de Gestion de Réservations de Salles

## Description
Application console en C pour la gestion des réservations de salles avec interface utilisateur, sauvegarde de données et génération de factures.

## Architecture du Projet

```
projetC/
├── src/
│   ├── main.c
│   ├── data_manager.c
│   └── reservation_logic.c
├── include/
│   ├── structures.h
│   └── data_manager.h
├── data/
│   ├── salles.dat
│   └── reservations.dat
├── output/
│   ├── salles.txt
│   ├── reservations.txt
│   └── facture_*.txt
├── build/
│   └── gestion_reservations.exe
├── compile.bat
├── run.bat
└── README.md
```

## Fonctionnalités

### Gestion des Salles
- Ajout de nouvelles salles avec nom, capacité, tarif et équipements
- Attribution automatique d'ID unique
- Sauvegarde immédiate

### Système de Réservations
- Création de réservations avec vérification de conflits
- Validation de la capacité de la salle
- Calcul automatique des coûts
- Gestion des statuts (Validée/Annulée)

### Fonctionnalités Supplémentaires
- Génération automatique de factures
- Statistiques par salle
- Annulation de réservations

### Sauvegarde des Données
- Sauvegarde en temps réel
- Format binaire pour les performances
- Format texte pour la lisibilité
- Mise à jour immédiate à chaque modification

## Installation et Utilisation

### Prérequis
- Windows avec PowerShell
- GCC (MinGW recommandé)

### Compilation
```batch
./compile.bat
```

### Exécution
```batch
./run.bat
```

## Guide d'Utilisation

### Menu Principal
```
___ MENU GESTION DE RESERVATIONs ___
1. Ajouter une Salle
2. Créer une Réservation  
3. Afficher Statistiques
4. Supprimer réservation
0. Quitter et Sauvegarder
```

### Ajout d'une Salle
1. Sélectionner option 1
2. Saisir nom, capacité, tarif horaire, équipements
3. Sauvegarde automatique

### Création de Réservation
1. Sélectionner option 2
2. Saisir nom client, ID salle, nombre de personnes
3. Définir date/heure début et fin
4. Validation automatique des conflits
5. Génération facture automatique

### Statistiques
- Chiffre d'affaires par salle
- Nombre de réservations
- Vue d'ensemble

## 📁 Formats de Données

### 💾 Fichiers Binaires (.dat)
- **Performance** : Chargement ultra-rapide
- **Intégrité** : Aucune corruption de format
- **Efficacité** : Stockage optimisé

### 📄 Fichiers Texte (.txt)
- **Lisibilité** : Format humain avec en-têtes descriptifs
- **Interopérabilité** : Compatible autres logiciels
## Formats de Données

### Fichiers Binaires (.dat)
- Chargement rapide
- Stockage optimisé

### Fichiers Texte (.txt)
- Format lisible
- Compatible avec d'autres logiciels
- Exemple format :
```
# Fichier des salles - Format: ID;Nom;Capacité;TarifHoraire;Équipement
1;SalleA;24;14.00;Projecteur
```

### Factures
- Génération au format texte
- Informations complètes
- Nommage automatique

## Développement

### Structure Modulaire
- main.c : Interface utilisateur
- data_manager.c : Gestion fichiers
- reservation_logic.c : Logique métier
- structures.h : Définitions de données
- data_manager.h : Interface de gestion

### Compilation
```bash
gcc -Wall -Wextra -std=c99 -Iinclude src/*.c -o build/gestion_reservations.exe
```

## Caractéristiques

- Sauvegarde en temps réel
- Validation des conflits
- Interface simple
- Calculs automatiques
- Statistiques intégrées
- Architecture modulaire

Système de gestion de réservations développé en C.