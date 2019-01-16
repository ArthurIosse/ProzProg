#include <stdio.h>
#include <stdlib.h> //memory allocation
#include <string.h>



typedef struct student
{
    char vorname[51];
    char nachname[51];
    char adresse[51];
    int matrikel;
    int kurse;
    struct student * next;
    struct student * prev;
}student;


void print(student * data)
{
    printf("%s, ",data->vorname);
    printf("%s, ",data->nachname);
    printf("%d, ",data->matrikel);
    printf("%s, ",data->adresse);
    printf("%d.\n",data->kurse);
}

student *reverse(struct student *list) {
  student *tmp = NULL;
  while (list != NULL) {
    list->prev = list->next;
    list->next = tmp;
    tmp = list;
    list = list->prev;
  }
  return tmp;
}


int main(int argc, char * argv[])
{
    student * studenten = NULL;
    student * stud = NULL;
    studenten = (student*)malloc(sizeof(student));
    //student bulbulim[3] = {{"anna","muster","am berg",4,22222},{"buba","huba","kaser",2,44444},{"perda","4ello","deni",8,66666}};

    //erste Student
    stud = studenten;
    strcpy(stud->vorname, "Anna");
    strcpy(stud->nachname, "Musterfrau");
    strcpy(stud->adresse, "Am Schwarzenberg-Campus 3");
    stud->kurse = 4;
    stud->matrikel = 22222;
    stud->prev = NULL;
    stud->next = (student*)malloc(sizeof(student));
    stud->next->prev = stud;

    //zweite Student
    stud = stud->next;
    strcpy(stud->vorname, "Hans");
    strcpy(stud->nachname, "Peter");
    strcpy(stud->adresse, "Kasernenstrasse 12");
    stud->kurse = 2;
    stud->matrikel = 44444;
    stud->next = (student*)malloc(sizeof(student));
    stud->next->prev = stud;

    //dritte Student
    stud = stud->next;
    strcpy(stud->vorname, "Lisa");
    strcpy(stud->nachname, "Lustig");
    strcpy(stud->adresse, "Denickestrasse 15");
    stud->kurse = 8;
    stud->matrikel = 66666;
    stud->next = (student*)malloc(sizeof(student));
    stud->next->prev = stud;

    //vierte Student
    stud = stud->next;
    strcpy(stud->vorname, "Ivan");
    strcpy(stud->nachname, "Ivanov");
    strcpy(stud->adresse, "Monetastr. 2");
    stud->kurse = 1;
    stud->matrikel = 77777;
    stud->next = (student*)malloc(sizeof(student));
    stud->next->prev = stud;

    //fuenfte Student
    stud = stud->next;
    strcpy(stud->vorname, "Pedro");
    strcpy(stud->nachname, "Podolski");
    strcpy(stud->adresse, "Papphausweg 1");
    stud->kurse = 3;
    stud->matrikel = 88888;
    stud->next = NULL;

    //Ausgabe in schleife
    printf("\n");
    for (stud = studenten ; stud!=NULL ; stud = stud->next){
        print(stud);
    }
    printf("\n");

    //dritte Student loeschen
        studenten -> next ->next = studenten->next->next->next;
        studenten -> next -> next -> next -> prev = studenten -> next;


    //Ausgabe nach dem Tausch
    printf("dritte Student geloescht:\n");
    for (stud = studenten ; stud!=NULL ; stud = stud->next){
        print(stud);
    }
    printf("\n");

    //liste umdrehen
    studenten = reverse(studenten);

    //Ausgabe nach Umdrehung
    printf("umgedrehte Liste:\n");
    for (stud = studenten ; stud!=NULL ; stud = stud->next){
        print(stud);
    }
    printf("\n");



    return 0;
}
