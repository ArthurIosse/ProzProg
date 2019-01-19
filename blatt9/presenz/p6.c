#include <stdio.h>
#include <string.h>

typedef struct konto
{
  char kontoinhaber[21];
  int kontonr;
  int bankleitzahl;
}konto;

int main (int argc, char * argv[])
{
  konto a;
  char ch[20];

  printf("Name des Kontoinhabers?\n");
  scanf("%s",ch);
  strcpy(a.kontoinhaber,ch);

  printf("Kontonr?\n");
  scanf("%d",&a.kontonr);
  
  printf("Bankleitzahl?\n");
  scanf("%d",&a.bankleitzahl);

  printf("\n%s\n",a.kontoinhaber);
  printf("%d\n",a.kontonr);
  printf("%d\n",a.bankleitzahl);

  return 0;
}
