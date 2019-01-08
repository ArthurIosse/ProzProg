#include <stdio.h>
#include <string.h>


typedef struct student
{
  char vorname[51];
  char nachname[51];
  char adresse[51];
  int matrikel;
  int kurse;
}student;

void print(student * data)
{
  printf("%s, ",data->vorname);
  printf("%s, ",data->nachname);
  printf("%d, ",data->matrikel);
  printf("%s, ",data->adresse);
  printf("%d.\n",data->kurse);

}

int main(int argc, char * argv[])
{
  student studenten[3];

  student * stud = &studenten[0];
  strcpy(stud->vorname, "Anna");
  strcpy(stud->nachname, "Musterfrau");
  strcpy(stud->adresse, "Am Schwarzenberg-Campus 3");
  stud->kurse = 4;
  stud->matrikel = 22222;

  stud = &studenten[1];
  strcpy(stud->vorname, "Hans");
  strcpy(stud->nachname, "Peter");
  strcpy(stud->adresse, "Kasernenstrasse 12");
  stud->kurse = 2;
  stud->matrikel = 44444;

  stud = &studenten[2];
  strcpy(stud->vorname, "Lisa");
  strcpy(stud->nachname, "Lustig");
  strcpy(stud->adresse, "Denickestrasse 15");
  stud->kurse = 8;
  stud->matrikel = 66666;

  //ausgabe in schleife
  printf("\n");
    for (int i = 0 ; i<3 ; i++){
      print(&studenten[i]);
     }
  printf("\n");

  //1ste und 3te Studenten tauschen
  student  temp = studenten[0];
  studenten[0] = studenten[2];
  studenten[2] = temp;

  //ausgabe nach dem Tausche
  for (int i = 0 ; i<3 ; i++){
  print(&studenten[i]);
  }

  return 0;
}
