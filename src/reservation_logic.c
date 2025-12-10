#include "../include/structures.h"
#include <math.h>
Salle* trouver_salle_par_id(Salle* head, int id) {
    while (head != NULL) {
        if (head->id == id) return head;
        head = head->next;
    }
    return NULL;
}

float calculer_cout_reservation(float tarif_horaire, time_t debut, time_t fin) {
    double duree_heures = difftime(fin, debut) / 3600.0;
    if (duree_heures <= 0) return 0.0f;
    return (float)(tarif_horaire * duree_heures);
}

int verifier_conflit_et_capacite(Reservation* res_head, Salle* sal_head, int salle_id,
                                 time_t debut, time_t fin, int nb_personnes) {

    Salle* salle = trouver_salle_par_id(sal_head, salle_id);
    if (!salle) {
        printf("Erreur : Salle ID %d introuvable.\n", salle_id);
        return 0;
    }

    if (nb_personnes > salle->capacite) {
        printf("Capacité insuffisante : max %d personnes.\n", salle->capacite);
        return 0;
    }

    Reservation* cur = res_head;
    while (cur != NULL) {
        if (cur->salle_id == salle_id && strcmp(cur->statut, "Annulee") != 0) {
            if (debut < cur->date_fin && fin > cur->date_debut) {
                printf("Conflit de réservation détecté.\n");
                return 0;
            }
        }
        cur = cur->next;
    }

    return 1;
}

Reservation* ajouter_reservation(Reservation* head, Reservation nouvelle) {
    Reservation* n = malloc(sizeof(Reservation));
    *n = nouvelle;
    n->next = head;
    return n;
}

Salle* ajouter_salle(Salle* head, Salle nouvelle) {
    Salle* n = malloc(sizeof(Salle));
    *n = nouvelle;
    n->next = head;
    return n;
}

void generer_facture(Reservation r, Salle* s) {
    char filename[100];
    snprintf(filename, sizeof(filename), "../output/facture_%d.txt", r.id);

    char buffer_debut[20], buffer_fin[20];
    strftime(buffer_debut, 20, "%Y-%m-%d %H:%M", localtime(&r.date_debut));
    strftime(buffer_fin, 20, "%Y-%m-%d %H:%M", localtime(&r.date_fin));

    FILE* f = fopen(filename, "w");
    if (!f) {
        perror("Impossible de générer la facture");
        return;
    }

    fprintf(f, "==========================================\n");
    fprintf(f, "              FACTURE N°%d\n", r.id);
    fprintf(f, "==========================================\n");
    fprintf(f, "Client : %s\n\n", r.nom_client);

    fprintf(f, "Salle Réservée : %s (ID: %d)\n", s->nom, s->id);
    fprintf(f, "Début : %s\n", buffer_debut);
    fprintf(f, "Fin   : %s\n\n", buffer_fin);

    fprintf(f, "Tarif Horaire : %.2f €\n", s->tarif_horaire);
    fprintf(f, "Coût Total    : %.2f €\n", r.cout_total);
    fprintf(f, "Statut        : %s\n", r.statut);
    fprintf(f, "==========================================\n");

    fclose(f);
    printf("Facture générée : %s\n", filename);
}


