
#include "../include/structures.h"
Salle* chargement_salle(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Fichier %s non existant.\n", filename);
        return NULL;
    }

    Salle temp;
    Salle* head = NULL;

    while (fread(&temp, sizeof(Salle), 1, file) == 1) {
        Salle* nouveau = (Salle*)malloc(sizeof(Salle));
        if (!nouveau) {
            perror("Erreur ");
            break;
        }

        *nouveau = temp;
        nouveau->next = head;  
        head = nouveau;
    }

    fclose(file);
    printf("chargement salle avec succès.\n");
    return head;
}

void sauvegarder_salles(Salle* head, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Erreur ");
        return;
    }

    Salle* current = head;
    while (current != NULL) {
        Salle temp = *current;
        temp.next = NULL; 
        fwrite(&temp, sizeof(Salle), 1, file);
        current = current->next;
    }

    fclose(file);
    printf(" succès, salle bien sauvegardé.\n");
}

Reservation* charger_reservations(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Fichier %s non existant. Liste de réservations vide.\n", filename);
        return NULL;
    }

    Reservation temp;
    Reservation* head = NULL;

    while (fread(&temp, sizeof(Reservation), 1, file) == 1) {
        Reservation* nouveau = (Reservation*)malloc(sizeof(Reservation));
        if (!nouveau) {
            perror("erreur ");
            break;
        }

        *nouveau = temp;
        nouveau->next = head;
        head = nouveau;
    }

    fclose(file);
    printf("Réservations chargées avec succès.\n");
    return head;
}

void sauvegarder_reservations(Reservation* head, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("erreur");
        return;
    }

    Reservation* current = head;
    while (current != NULL) {
        Reservation temp = *current;
        temp.next = NULL; 
        fwrite(&temp, sizeof(Reservation), 1, file);
        current = current->next;
    }

    fclose(file);
    printf("Réservations sauvegardées avec succès.\n");
}

void liberer_salles(Salle* head) {
    Salle* current = head;
    while (current != NULL) {
        Salle* next = current->next;
        free(current);
        current = next;
    }
}

void liberer_reservations(Reservation* head) {
    Reservation* current = head;
    while (current != NULL) {
        Reservation* next = current->next;
        free(current);
        current = next;
    }
}
void sauvegarder_salles_texte(Salle* head, const char* filename) {
    FILE* file = fopen(filename, "w"); 
    if (!file) {
        perror("Erreur lors de la création du fichier salles.txt");
        return;
    }

    // En-tête du fichier
    fprintf(file, "# Fichier des salles - Format: ID;Nom;Capacité;TarifHoraire;Équipement\n");
    fprintf(file, "# Généré automatiquement le %s\n", __DATE__);
    fprintf(file, "# ================================================\n");
    
    if (head == NULL) {
        fprintf(file, "# Aucune salle enregistrée\n");
    } else {
        Salle* s = head;
        while (s != NULL) {
            fprintf(file, "%d;%s;%d;%.2f;%s\n", s->id, s->nom, s->capacite, s->tarif_horaire, s->equipement);
            s = s->next;
        }
    }

    fclose(file);
    printf("Salles sauvegardées en texte avec succès.\n");
}
void sauvegarder_reservations_texte(Reservation* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Erreur lors de la création du fichier reservations.txt");
        return;
    }

    // En-tête du fichier
    fprintf(file, "# Fichier des réservations - Format: ID;SalleID;Client;Début;Fin;Statut\n");
    fprintf(file, "# Généré automatiquement le %s\n", __DATE__);
    fprintf(file, "# ================================================\n");
    
    if (head == NULL) {
        fprintf(file, "# Aucune réservation enregistrée\n");
    } else {
        Reservation* r = head;
        char date_debut_str[20];
        char date_fin_str[20];

        while (r != NULL) {
            struct tm* tm_info;

            // Formatage date de début
            tm_info = localtime(&r->date_debut);
            strftime(date_debut_str, sizeof(date_debut_str), "%d/%m/%Y %H:%M", tm_info);

            // Formatage date de fin
            tm_info = localtime(&r->date_fin);
            strftime(date_fin_str, sizeof(date_fin_str), "%d/%m/%Y %H:%M", tm_info);

            fprintf(file, "%d;%d;%s;%s;%s;%s;%.2f;%d\n",
                    r->id, r->salle_id, r->nom_client,
                    date_debut_str, date_fin_str, r->statut,
                    r->cout_total, r->nombre_personnes);

            r = r->next;
        }
    }

    fclose(file);
    printf("Réservations sauvegardées en texte avec succès.\n");
}

