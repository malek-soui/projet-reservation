#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/structures.h"
#include "../include/data_manager.h"
Salle* head_salles = NULL;
Reservation* head_reservations = NULL;
int next_salle_id = 1;
int next_reservation_id = 1;
time_t lire_date_heure() {
    int an, mois, jour, heure, min;
    struct tm t = {0};
    
    printf("Annee (AAAA): "); scanf("%d", &an);
    printf("Mois (1-12): "); scanf("%d", &mois);
    printf("Jour (1-31): "); scanf("%d", &jour);
    printf("Heure (0-23): "); scanf("%d", &heure);
    printf("Minute (0-59): "); scanf("%d", &min);
    t.tm_year = an - 1900;
    t.tm_mon = mois - 1;
    t.tm_mday = jour;
    t.tm_hour = heure;
    t.tm_min = min;
    t.tm_isdst = -1; 

    return mktime(&t);
    

}
void initialiser_ids() {
    Salle* s = head_salles;
    while(s != NULL) {
        if (s->id >= next_salle_id) {
            next_salle_id = s->id + 1;
        }
        s = s->next;
    }

    Reservation* r = head_reservations;
    while(r != NULL) {
        if (r->id >= next_reservation_id) {
            next_reservation_id = r->id + 1;
        }
        r = r->next;
    }
}


void creer_salle() {
    Salle nouvelle_salle;
    
    nouvelle_salle.id = next_salle_id++;
    printf("Nom de la salle : "); 
    scanf("%s", nouvelle_salle.nom);
    printf("Capacite : "); 
    scanf("%d", &nouvelle_salle.capacite);
    printf("Tarif horaire : "); 
    scanf("%f", &nouvelle_salle.tarif_horaire);
    printf("equipements:");
    scanf("%s", nouvelle_salle.equipement);

    
    head_salles = ajouter_salle(head_salles, nouvelle_salle);
    
    // Sauvegarder immédiatement en binaire et texte
    sauvegarder_salles(head_salles, "../data/salles.dat");
    sauvegarder_salles_texte(head_salles, "../output/salles.txt");
    printf("\nSalle %s ajoutee (ID: %d) et enregistree.\n", nouvelle_salle.nom, nouvelle_salle.id);
}
void creer_reservation() {
    Reservation nouvelle_res;
    int salle_id, nb_personnes;
    time_t debut, fin;

    printf("\n--- Nouvelle Reservation ---\n");
    nouvelle_res.id = next_reservation_id++;
    
    printf("Nom du client : "); scanf("%s", nouvelle_res.nom_client);
    
    printf("ID de la salle a reserver : "); scanf("%d", &salle_id);
    printf("Nombre de personnes : "); scanf("%d", &nb_personnes);
    printf("Date et heure de DEBUT :\n"); debut = lire_date_heure(); 
    printf("Date et heure de FIN :\n"); fin = lire_date_heure();


    

    
    nouvelle_res.salle_id = salle_id;
    nouvelle_res.nombre_personnes = nb_personnes;
    nouvelle_res.date_debut = debut;
    nouvelle_res.date_fin = fin;

    
    if (verifier_conflit_et_capacite(head_reservations, head_salles, salle_id, debut, fin, nb_personnes)) {
        
        
        Salle* salle = trouver_salle_par_id(head_salles, salle_id);
        nouvelle_res.cout_total = calculer_cout_reservation(salle->tarif_horaire, debut, fin);
        
        strcpy(nouvelle_res.statut, "Validee");
        
        
        head_reservations = ajouter_reservation(head_reservations, nouvelle_res);
        
        // Sauvegarder immédiatement en binaire et texte
        sauvegarder_reservations(head_reservations, "../data/reservations.dat");
        sauvegarder_reservations_texte(head_reservations, "../output/reservations.txt");

        printf("\nReservation ID %d VALIDE, ajoutee et enregistree.\n", nouvelle_res.id);
        
        
        generer_facture(nouvelle_res, salle);

    } else {
        printf("\nReservation ANNULEE : Conflit ou capacite insuffisante.\n");
        next_reservation_id--; 
    }
}
void annuler_reservation() {
    int id;
    printf("\nID de la reservation à annuler : ");
    scanf("%d", &id);

    Reservation* cur = head_reservations;

    while (cur != NULL) {
        if (cur->id == id) {

            if (strcmp(cur->statut, "Annulee") == 0) {
                printf("Cette reservation est deja annulee.\n");
                return;
            }

            strcpy(cur->statut, "Annulee");
            // Sauvegarder immédiatement en binaire et texte
            sauvegarder_reservations(head_reservations, "../data/reservations.dat");
            sauvegarder_reservations_texte(head_reservations, "../output/reservations.txt");

            printf("Reservation %d ANNULEE avec succes et mise a jour enregistree.\n", id);
            return;
        }
        cur = cur->next;
    }

    printf("Reservation ID %d introuvable.\n", id);
}



void afficher_stats() {
    printf("\n~~~~les  Statistiques ~~~~\n");

    
    Salle* s = head_salles;
    while(s != NULL) {
        float ca = 0.0;
        int nb_res = 0;
        Reservation* r = head_reservations;
        
        while(r != NULL) {
            if (r->salle_id == s->id && strcmp(r->statut, "Validee") == 0) {
                ca += r->cout_total;
                nb_res++;
            }
            r = r->next;
        }
        printf("\nSalle %s (ID %d) :\n", s->nom, s->id);
        printf("  - Chiffre d'affaires : %.2f Euros\n", ca);
        printf("  - Nombre de reservations : %d\n", nb_res);
        
        s = s->next;
    }
}


int main() {
    int choix;

    
    head_salles = chargement_salle("../data/salles.dat");
    head_reservations = charger_reservations("../data/reservations.dat");
    initialiser_ids();
    
    // Créer les fichiers txt au démarrage
    sauvegarder_salles_texte(head_salles, "../output/salles.txt");
    sauvegarder_reservations_texte(head_reservations, "../output/reservations.txt");

    do {
        printf("\n\n ___ MENU GESTION DE RESERVATIONs ___\n");
        printf("1. Ajouter une Salle \n");
        printf("2. Creer une Reservation \n");
        printf("3. Afficher Statistiques \n");
        printf("4. supprimer réservation \n");
        printf("0. Quitter et Sauvegarder \n");
        printf("Votre choix : ");
        if (scanf("%d", &choix) != 1) {
            
            while(getchar() != '\n');
            choix = -1; 
        }

        switch (choix) {
            case 1: creer_salle(); break;
            case 2: creer_reservation(); break;
            case 3: afficher_stats(); break;
            case 4: annuler_reservation(); break;
            case 0: break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 0);

    
    // Sauvegarde finale de sécurité
    sauvegarder_salles(head_salles, "../data/salles.dat");
    sauvegarder_reservations(head_reservations, "../data/reservations.dat");
    sauvegarder_salles_texte(head_salles, "../output/salles.txt");
    sauvegarder_reservations_texte(head_reservations, "../output/reservations.txt");
    
    liberer_salles(head_salles);
    liberer_reservations(head_reservations);
    
    printf("\nProgramme termine. Toutes les donnees sont sauvegardees.\n");

    return 0;
}


