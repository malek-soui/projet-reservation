# 🏢 Système de Gestion de Réservations de Salles

## 📋 Description
Application console en C pour la gestion complète des réservations de salles avec interface utilisateur intuitive, sauvegarde en temps réel et génération automatique de factures.

## 🏗️ Architecture du Projet

```
📁 Gestion-Reservations/
├── 📁 src/                    # 💻 Code source
│   ├── main.c                 # Interface utilisateur et menu principal
│   ├── data_manager.c         # Gestion fichiers et persistance de données
│   └── reservation_logic.c    # Logique métier et algorithmes de réservation
├── 📁 include/                # 📂 Fichiers d'en-tête
│   ├── structures.h           # Définitions des structures Salle et Reservation
│   └── data_manager.h         # Déclarations des fonctions de gestion de données
├── 📁 data/                   # 💾 Données binaires (performance)
│   ├── salles.dat             # Base de données binaire des salles
│   └── reservations.dat       # Base de données binaire des réservations
├── 📁 output/                 # 📄 Fichiers de sortie lisibles
│   ├── salles.txt             # Export texte des salles avec en-têtes
│   ├── reservations.txt       # Export texte des réservations avec formatage
│   └── facture_*.txt          # Factures générées automatiquement
├── 📁 build/                  # 🔧 Fichiers compilés
│   └── gestion_reservations.exe
├── 📄 compile.bat             # Script de compilation Windows
├── 📄 run.bat                # Script d'exécution simplifié
└── 📄 README.md              # Documentation complète
```

## ✨ Fonctionnalités

### 🏛️ Gestion des Salles
- ✅ Ajout de nouvelles salles (nom, capacité, tarif, équipements)
- ✅ Attribution automatique d'ID unique
- ✅ Sauvegarde immédiate à chaque ajout

### 📅 Système de Réservations
- ✅ Création de réservations avec vérification de conflits
- ✅ Validation de la capacité de la salle
- ✅ Calcul automatique des coûts basé sur la durée
- ✅ Gestion des statuts (Validée/Annulée)

### 💰 Fonctionnalités Avancées
- ✅ Génération automatique de factures détaillées
- ✅ Statistiques par salle (chiffre d'affaires, nombre de réservations)
- ✅ Annulation de réservations avec mise à jour immédiate

### 💾 Sauvegarde Intelligente
- ✅ **Sauvegarde en temps réel** (plus besoin d'attendre la fermeture)
- ✅ **Double format** : binaire pour performance + texte pour lisibilité
- ✅ **Fichiers txt créés dès le démarrage** avec en-têtes informatifs
- ✅ **Mise à jour immédiate** à chaque modification

## 🔄 Comportement de Sauvegarde (Nouveau)

### Sauvegarde en Temps Réel
- **🚀 Au démarrage** : Fichiers `.txt` créés automatiquement avec en-têtes
- **➕ Ajout de salle** : Sauvegarde immédiate en `.dat` + `.txt`
- **📝 Nouvelle réservation** : Sauvegarde immédiate en `.dat` + `.txt`
- **❌ Annulation** : Mise à jour instantanée des deux formats
- **🔒 À la fermeture** : Sauvegarde finale de sécurité

## 🚀 Installation et Utilisation

### ⚙️ Prérequis
- **Windows** avec PowerShell
- **GCC** (MinGW recommandé)
- **Git** (optionnel pour clonage)

### 🔨 Compilation Rapide
```batch
# Méthode recommandée
./compile.bat

# Ou compilation manuelle
gcc -Wall -Wextra -std=c99 -Iinclude src/*.c -o build/gestion_reservations.exe
```

### ▶️ Exécution
```batch
# Lancement simple
./run.bat

# Ou manuel
cd data
../build/gestion_reservations.exe
```

## 🎯 Guide d'Utilisation

### Menu Principal
```
___ MENU GESTION DE RESERVATIONs ___
1. Ajouter une Salle
2. Créer une Réservation  
3. Afficher Statistiques
4. Supprimer réservation
0. Quitter et Sauvegarder
```

### 🏛️ Ajout d'une Salle
1. Choisir option `1`
2. Saisir : nom, capacité, tarif horaire, équipements
3. ✅ **Sauvegarde automatique immédiate**

### 📅 Création de Réservation
1. Choisir option `2`
2. Saisir : nom client, ID salle, nombre de personnes
3. Définir : date/heure début et fin
4. ✅ **Validation automatique** (conflits + capacité)
5. ✅ **Génération facture + sauvegarde immédiate**

### 📊 Statistiques
- Chiffre d'affaires par salle
- Nombre de réservations actives
- Vue d'ensemble en temps réel

## 📁 Formats de Données

### 💾 Fichiers Binaires (.dat)
- **Performance** : Chargement ultra-rapide
- **Intégrité** : Aucune corruption de format
- **Efficacité** : Stockage optimisé

### 📄 Fichiers Texte (.txt)
- **Lisibilité** : Format humain avec en-têtes descriptifs
- **Interopérabilité** : Compatible autres logiciels
- **Sauvegarde** : Archive facilement lisible
- **Exemple format** :
```
# Fichier des salles - Format: ID;Nom;Capacité;TarifHoraire;Équipement
# Généré automatiquement le Dec 10 2025
# ================================================
1;SalleA;24;14.00;Projecteur
```

### 🧾 Factures Automatiques
- Génération au format `.txt`
- Informations complètes (client, salle, durée, coût)
- Nommage automatique `facture_[ID].txt`

## 🛠️ Développement

### Structure Modulaire
- **`main.c`** : Interface utilisateur et orchestration
- **`data_manager.c`** : Persistance et gestion fichiers
- **`reservation_logic.c`** : Algorithmes métier et validations
- **`structures.h`** : Définitions de données
- **`data_manager.h`** : Interface de gestion de données

### Compilation Avancée
```bash
# Debug mode
gcc -Wall -Wextra -g -std=c99 -Iinclude src/*.c -o build/debug.exe

# Release optimisé
gcc -Wall -Wextra -O2 -std=c99 -Iinclude src/*.c -o build/release.exe
```

## 🎉 Points Forts du Système

- 🔄 **Sauvegarde en temps réel** - Plus de perte de données
- 🛡️ **Validation robuste** - Prévention des conflits automatique
- 📱 **Interface intuitive** - Menu simple et efficace
- 💰 **Calculs automatiques** - Coûts précis basés sur durée
- 📊 **Reporting intégré** - Statistiques en temps réel
- 🔧 **Architecture modulaire** - Code maintenable et extensible

---

**Développé en C** avec architecture professionnelle pour la gestion efficace des réservations de salles.