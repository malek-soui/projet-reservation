#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H
#include "structures.h"
#include <stdio.h>
#include <stdlib.h>

Salle* chargement_salle(const char* filename);
void sauvegarder_salles(Salle* head, const char* filename);
void liberer_salles(Salle* head);
Reservation* charger_reservations(const char* filename);
void sauvegarder_reservations(Reservation* head, const char* filename);
void liberer_reservations(Reservation* head);
void sauvegarder_salles_texte(Salle* head, const char* filename);
void sauvegarder_reservations_texte(Reservation* head, const char* filename);

#endif
