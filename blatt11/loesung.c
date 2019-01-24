/**
 * Prozedurale Programmierung
 *
 * Lineare Listen (hier doppelt verkettet)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3


// Stuktur Definition (lineare Liste [hier: doppelt verkettet])
struct student {
    char Vorname[51];
    char Nachname[51];
    int MatNr;
    char Adresse[51];
    int Kurse;
    struct student *prev; // Vorgaenger
    struct student *next; // Nachfolger
};


/**
 * Gibt eine Struktur in der Konsole aus
 */
void print_konsole(struct student *elem) {
    printf("Vorname: %s\n", elem->Vorname);
    printf("Nachname: %s\n", elem->Nachname);
    printf("Mat-Nr.: %d\n", elem->MatNr);
    printf("Adresse: %s\n", elem->Adresse);
    printf("belegte Kurse: %d\n\n", elem->Kurse);
}


/**
 * Loescht das uebergebene Element "elem" aus einer doppelt verkettete Liste
 * und gibt den neuen (ggf. unveraenderten) Listenanfang zurueck.
 */
struct student *delete(struct student *start, struct student *elem) {
    // 1. Zeiger der doppelt verkettete Liste korrigieren
    if (elem == start) {  // Wenn Listenanfang
        elem->next->prev = NULL;
        start = elem->next;
    } else if (elem->next == NULL) {  // Wenn Listenende
        elem->prev->next = NULL;
    } else {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
    }

    // 2. Speicher freigeben
    free(elem);

    return start;
}

/**
 * Dreht die doppelt verkettete Liste um und gibt den neuen Listenanfang
 * zurueck.
 */
struct student *reverse_list(struct student *list) {
    struct student *tmp = NULL;
    while (list != NULL) {
        list->prev = list->next;
        list->next = tmp;
        tmp = list;
        list = list->prev;
    }
    return tmp;
}

/**
 * Sortiert die Liste alphabetisch nach Nachname und gibt den neuen Listenanfang zurück.
 */

struct student * sort_list(struct student *list) {
    struct student *target_pos, *stud, *next;
    // Beginne mit dem 2. Element und vergleiche rück-iterierend zum Listenanfang
    stud = list->next;
    while (stud != NULL) {
        target_pos = stud;
        next = stud->next;
        while (target_pos != list && strcmp(stud->Nachname, (target_pos->prev)->Nachname) < 0)
            target_pos = target_pos->prev;
        if (target_pos != stud) {
            // Nachbar-Elemente des zu verschiebenen Elements verbinden
            (stud->prev)->next = next;
            if (next != NULL)  next->prev = stud->prev;
            // Element vor dem target_pos Element "einfügen"
            stud->next = target_pos;
            stud->prev = target_pos->prev;
            target_pos->prev = stud;
            if (stud->prev == NULL) list = stud;
            else (stud->prev)->next = stud;
        }
        stud = next;
    }
    return list;
}

/**
 * Hauptprogramm
 */
int main() {

    // Der Zeiger auf Listenanfang "studenten" sollte nicht fuer Iterationen
    // Verwendet werden, da sonst der Listenanfang ggf. "verloren" geht.
    struct student *studenten = NULL;

    // Hilfszeiger fuer Iterationen
    struct student *stud = NULL;

    // Erster Datensatz
    studenten = (struct student *) malloc(sizeof(struct student));
    stud = studenten;
    strcpy(stud->Vorname, "Anna");
    strcpy(stud->Nachname, "Musterfrau");
    stud->MatNr = 22222;
    strcpy(stud->Adresse, "Am Schwarzenberg-Campus 39");
    stud->Kurse = 4;
    stud->prev = NULL;  // Listenanfang
    stud->next = (struct student *) malloc(sizeof(struct student));
    stud->next->prev = stud;  // Mache Vorgaenger bekannt
    stud = stud->next;

    // Zweiter Datensatz
    strcpy(stud->Vorname, "Hans");
    strcpy(stud->Nachname, "Peter");
    stud->MatNr = 44444;
    strcpy(stud->Adresse, "Kasernenstrasse 12");
    stud->Kurse = 2;
    stud->next = (struct student *) malloc(sizeof(struct student));
    stud->next->prev = stud;
    stud = stud->next;

    // Dritter Datensatz
    strcpy(stud->Vorname, "Lisa");
    strcpy(stud->Nachname, "Lustig");
    stud->MatNr = 66666;
    strcpy(stud->Adresse, "Denickestrasse 15");
    stud->Kurse = 8;
    stud->next = (struct student *) malloc(sizeof(struct student));
    stud->next->prev = stud;
    stud = stud->next;

    // Vierter Datensatz
    strcpy(stud->Vorname, "Gabriele");
    strcpy(stud->Nachname, "Koenig");
    stud->MatNr = 12345;
    strcpy(stud->Adresse, "Waldstrasse 32");
    stud->Kurse = 3;
    stud->next = (struct student *) malloc(sizeof(struct student));
    stud->next->prev = stud;
    stud = stud->next;

    // Fuenfter Datensatz
    strcpy(stud->Vorname, "Otto");
    strcpy(stud->Nachname, "Mayer");
    stud->MatNr = 21545;
    strcpy(stud->Adresse, "Bahnhofstrasse 4");
    stud->Kurse = 5;
    stud->next = NULL;  // Listenende

    // Gebe Datensaetze in der Konsole aus
    for (stud = studenten; stud != NULL; stud = stud->next) {
        print_konsole(stud);
    }

    // Sortiere Studenten in der Liste nach Nachname
    studenten = sort_list(studenten);

    // Gebe Datensaetze in der Konsole aus
    printf("\n-------------------\n\n");
    for (stud = studenten; stud != NULL; stud = stud->next) {
        print_konsole(stud);
    }


    return 0;
}
