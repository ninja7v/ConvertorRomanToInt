#include <stdio.h>
#include <string.h>
#define LMAX 5


int charToInt(char c)
{
    int result=0;
    switch(c)
    {
    case 'I' : result = 1; break;
	case 'V' : result = 5; break;
	case 'X' : result = 10; break;
	case 'L' : result = 50; break;
	case 'C' : result = 100; break;
	case 'D' : result = 500; break;
	case 'M' : result = 1000; break;
    }
    return result;
}


int romanToInt(char *nr)
{
    int result = 0;
    int taille = strlen(nr);
    for(int i = 0; i < taille; i++)
    {
	/*printf("%d",taille);*/
	if (i+1 >= LMAX || charToInt(nr[i+1]) <= charToInt(nr[i]))
	    result += charToInt(nr[i]);
	else
	    result -= charToInt(nr[i]);
    }
    return result;
}


int valide(char *nr)

{
/*initialisation*/
int i,test=1;
int taille=strlen(nr);
/*test 1*/
if (romanToInt(nr)==0) test=0;
/*test 2*/
if (taille==LMAX) test=0;
/*test 3*/
for (i=0;i<taille-3;i++) /*pas plus de 3 I consécutifs*/
    if ((nr[i]=='I') && (nr[i+1]=='I') && (nr[i+2]=='I') && (nr[i+3]=='I')) test=0;
for (i=0;i<taille-1;i++) /*pas plus de 1 V consécutif*/
    if ((nr[i]=='V') && (nr[i+1]=='V')) test=0;
for (i=0;i<taille-4;i++) /*pas plus de 4 X consécutifs*/
    if ((nr[i]=='X') && (nr[i+1]=='X') && (nr[i+2]=='X') && (nr[i+3]=='X') && (nr[i+4]=='X')) test=0;
for (i=0;i<taille-1;i++) /*pas plus de 1 L consécutif*/
    if ((nr[i]=='L') && (nr[i+1]=='L')) test=0;
for (i=0;i<taille-1;i++) /*pas plus de 1 D consécutif*/
    if ((nr[i]=='D') && (nr[i+1]=='D')) test=0;
for (i=0;i<taille-3;i++) /*pas plus de 3 M consécutifs*/
    if ((nr[i]=='M') && (nr[i+1]=='M') && (nr[i+2]=='M') && (nr[i+3]=='M')) test=0;
/*test 4*/
for (i=0;i<taille-2;i++) /*pas plus de 2 nombres consécutifs croissants*/
    if ((charToInt(nr[i])<charToInt(nr[i+1])) && (charToInt(nr[i+1])<charToInt(nr[i+2]))) test=0;
return test;
}


int main()
{
    char nr[LMAX]; /*nr pour Nombre Romain*/

    FILE* fichierD;
    FILE* fichierR;
    fichierD = fopen("données","r");
    fgets(nr,LMAX,fichierD);
    fclose(fichierD);

    fichierR=fopen("résultats","w");
    fprintf(fichierR,"%d",romanToInt(nr));
    fclose(fichierR);
    return 0;
}
