#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

int main(){
int i;
unsigned int ex;


//Criacao do Arquivo 01
printf("Gerando o Arquivo 01...\n");
FILE *txt;
if((txt = fopen("Arquivo01.txt", "w")) == NULL)    {
        printf("Erro ao abrir arquivo");
    }
 else {
       
	  	//Definindo a Semente Inicial do Gerador Aleat?rio
		ex = ((unsigned) time(NULL)) ; 
		
		srand(ex) ; 
		int c; 
	     i = 0;
         while(i < 1000000000)
         {
               c = rand() % 1000000;
               if (((c%7)==0) && ((c%14)==0) && ((c%42)==0)&& ((c%84)==0) && ((c%89)==0) && (c!=0)) 
               {
			      fprintf(txt, "%d\n",c);
			   }
               ++i;
          }
		fclose(txt);
      }

//Criacao do Arquivo 02
printf("Gerando o Arquivo 02...\n");
FILE *txt2;
if((txt2 = fopen("Arquivo02.txt", "w")) == NULL)    {
        printf("Erro ao abrir arquivo");
    }
 else {
       
	  	//Definindo a Semente Inicial do Gerador Aleat?rio
		ex = ((unsigned) time(NULL)) ; 
		
		srand(ex) ; 
		 int c;
	     i = 0;
         while(i < 1000000000)
         {
              c = rand() % 100000;
			  if (((c%3)==0) && ((c%6)==0) && ((c%31)==0) && ((c%99)==0) && ((c%12)==0)) 
			   {
			      fprintf(txt2, "%d\n",c);
           	   }	
			   ++i;
          }
		fclose(txt2);
      }
      

//Criacao do Arquivo 03
printf("Gerando o Arquivo 03...\n");
FILE *txt3;
if((txt3 = fopen("Arquivo03.txt", "w")) == NULL)    {
        printf("Erro ao abrir arquivo");
    }
 else {
       
	  	//Definindo a Semente Inicial do Gerador Aleat?rio
		ex = ((unsigned) time(NULL)) ; 
		
		srand(ex) ; 
		 int c;
	     i = 0;
         while(i < 1000000000)
         {
              c = rand() ;
			  if (((c%36)==0) && ((c%9)==0) && ((c%900)==0) && ((c%360)==0) && ((c%180)==0) && (c!=0) && (c<=8000)) 
			   {
			      fprintf(txt3, "%d\n",c);
           	   }	
			   ++i;
          }
		fclose(txt3);
      }

//Criacao do Arquivo 04
printf("Gerando o Arquivo 04...\n");
FILE *txt4;
if((txt4 = fopen("Arquivo04.txt", "w")) == NULL)    {
        printf("Erro ao abrir arquivo");
    }
 else {
       
	  	//Definindo a Semente Inicial do Gerador Aleat?rio
		ex = ((unsigned) time(NULL)) ; 
		
		srand(ex) ; 
		 int c;
	     i = 0;
         while(i < 1000000000)
         {
              c = rand() % 1000000;
			  if (((c%8)==0) && ((c%16)==0) && ((c%1024)==0) && ((c%256)==0) && ((c%512)==0) && (c<=3100)) 
			   {
			      fprintf(txt4, "%d\n",c);
           	   }	
			   ++i;
          }
		fclose(txt4);
      }
}
