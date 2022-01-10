#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isoperator (char c)
{
  if ('+'==c) return true;
  if ('-'==c) return true;
  if ('*'==c) return true;
  if ('/'==c) return true;
  return false;
}  
  
int main ()
{
 double memory = 0.0;
 double visor, temp;
 char op = 0;
 printf ("Digite um número: ");
 if (scanf ("%lf",&visor)!=1)
 {
  printf ("Número inválido.\n");
  return EXIT_FAILURE;
 }
 getchar();
 printf ("Os operadores basicos são '+' '-' '*' '/'.\n");
 printf ("Para raiz quadrada use 'v'.\n");
 printf ("Para raiz cúbica use 'w'.\n");
 printf ("Para operações com memoría use 'm+' 'm-' 'mr' 'mc' .\n");
 printf ("Para limpar o visor use 'c'.\n");
 while (1)
 {
  op = 0;
  while (!isoperator(op))
  {
   printf ("Digite o operador: ");
   op = getchar();
   if (EOF==op) return EXIT_SUCCESS;
   if ((op == 'v')||(op == 'V'))
   {
     visor = sqrt (visor);
     printf ("Agora o visor é %lf .\n", visor);
   }
   else if ((op == 'w')||(op == 'W'))
   {
     visor = cbrt (visor);
     printf ("Agora o visor e %lf .\n", visor);
   }  
   else if ((op == 'c')||(op == 'C'))
   {
     op = '+';
     visor = 0.0;
     printf ("O visor foi zerado.\n");
   }
   else if ((op == 'm')||(op=='M'))
   {
    char aux = getchar();
    if ('+'==aux)
    {
     memory+=visor; 
     printf ("O novo conteúdo da memória é %lf .\n", memory);
    }
    else if ('-'==aux)
    {
     memory-=visor;
     printf ("O novo conteúdo da memória é %lf .\n", memory);
    }
    else if (('r'==aux)||('R'==aux))
    {
     visor = memory;
     printf ("O novo conteúdo do visor é %lf .\n", visor);
    }
    else if (('c'==aux)||('C'==aux))
    {
     memory = 0.0;
     printf ("Memória zerada.\n");
    }
    else
    {
      fprintf (stderr, "Não entendi o caractere após o m .\n");
    }
   }
   while ((getchar()!='\n')&&(!feof(stdin)));
  }
  printf ("Digite outro número: ");
  temp = 0.0;
  char buffer [80];
  if (fgets (buffer, 80, stdin)==NULL)
  {
   perror("fgets");
   return EXIT_FAILURE;    
  }
  if ((buffer[0] == 'v')||(buffer[0] == 'V'))
  {
   temp = sqrt (visor);
   printf ("Agora o temp é %lf .\n", temp);
  }
  else if ((buffer[0] == 'w')||(buffer[0] == 'W'))
  {
    temp = cbrt (visor);
    printf ("Agora o temp é %lf .\n", temp);
  }
  else if ((buffer[0] == 'c')||(buffer[0] == 'C'))
  {
    op = '+';
    visor = 0.0;
    printf ("O visor foi zerado.\n");
  }
  else if ((buffer[0] == 'm')||(buffer[0] == 'M'))
  {
   char aux = buffer[1];
   if (aux == '+')
   {
    memory+=visor; 
    printf ("O novo conteúdo da memória é %lf .\n", memory);
   }
   else if (aux == '-')
   {
    memory-=visor;
    printf ("O novo conteúdo da memória é %lf .\n", memory);
   }
   else if ((aux == 'r')||(aux == 'R'))
   {
    temp = memory;
    printf ("O novo conteúdo do temp é %lf .\n", temp);
   }
   else if ((aux == 'c')||(aux == 'C'))
   {
    memory = 0.0;
    printf ("Memória zerada.\n");
   }
   else
   {
     fprintf (stderr, "O caractere '%c' não é reconhecido após o 'm'.\n", aux);
   }
  }
  else if (sscanf (buffer, "%lf", &temp) != 1)
  {
   printf ("Número inválido.\n");
   return EXIT_FAILURE;
  }
  if (op == '+')
  {
   visor+=temp;
  }
   else if (op == '-')
  {   
   visor-=temp;
  }  
   else if (op == '*')
  { 
   visor*=temp;
  }
   else if (op == '/')
  {
   visor/=temp;
  }
  else
  {
   printf ("O operador %c é inválido.\n",op);
   return EXIT_FAILURE;
  }
  printf("O resultado é %f\n",visor);
 }
 return EXIT_SUCCESS;
}
