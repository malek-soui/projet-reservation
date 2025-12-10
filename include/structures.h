#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct Salle {
    int id;
    char nom[50];
    int capacite;
    float tarif_horaire; 
    char equipement[50];
    struct Salle* next;  
} Salle;
typedef struct Reservation {
    int id;
    char nom_client[50];
    int salle_id; 
    time_t date_debut;
    time_t date_fin;
    int nombre_personnes;
    float cout_total;
    char statut[20];
    struct Reservation* next; 
} Reservation;

Salle* charger_salles(const char* filename);
void sauvegarder_salles(Salle* head, const char* filename);
Reservation* charger_reservations(const char* filename);
void sauvegarder_reservations(Reservation* head, const char* filename);
void liberer_salles(Salle* head);
void liberer_reservations(Reservation* head);


Salle* trouver_salle_par_id(Salle* head, int id);
float calculer_cout_reservation(float tarif_horaire, time_t debut, time_t fin);
int verifier_conflit_et_capacite(Reservation* res_head, Salle* sal_head, int salle_id, 
                                 time_t debut, time_t fin, int nb_personnes);
Reservation* ajouter_reservation(Reservation* head, Reservation nouvelle);
Salle* ajouter_salle(Salle* head, Salle nouvelle);
void generer_facture(Reservation r, Salle* s);
void annuler_reservation();


#endif