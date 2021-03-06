#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Structs for user data
struct colonia
{
	int cve_colonia;
	char colonia[15];
};
//pene
struct usuario
{
	int cve;
	int tipo;
	char nom[30];
	struct colonia dir;
	float consumo;
	float pago;
};

struct tarifas
{
	float tar[8];	
};

//declaracion de funciones
int validar(char aux[' ']);
float validar2(char aux[' ']);
void menu(int op);
void menuconsultas();
void menuconsultas2(int op);
void menuacceso();
//void menuacceso2(int op);
int login(char user[' '], char pass[' ']);
void admin();
void adminmenu();
void adminmenu2(int op);
void consulta(int op);
void adduser(struct usuario *pp);
int cveuser();
void rates();

int main()
{
    char aux[' '];
    int op, i;
    
    do
    {
        for(i=0; i<30; i++)
                 printf(" -");
        printf("\n\t\t\tWelcome\n\n");
        printf("\t\t1)Make a query\n\n");
        printf("\t\t2)Log In\n\n");
        printf("\t\t3)Exit\n\n");
        for(i=0; i<30; i++)
                 printf(" -");
        printf("\n");
                 
        gets(aux);
        op=validar(aux);
        
        if(op < 1 || op >3)
              printf("Try again\n");
        else
        	  menu(op);  
        
		system("cls");
        
		if(op == 3)
              printf("Thanks for your time\n");
        
            
        
     }while(op != 3);
    system("pause");
}

int validar(char aux[' '])
{
	int i, j, neg=0, n, u, len;
	

			u=0;
			
			len = strlen(aux);
			for(i=0; i<strlen(aux); i++)
			{
				if(isalpha(aux[i]))
				{
					u=1;
					return -1;
				}
				else
				{
					if(isdigit(aux[i]))
					{
						u=0;
					}
					else if( (aux[i] == 45 || aux[i] == 43) && i == 0 && len>1)
					{
						u=0;
					}
					else
					{
						u=1;
						return -1;
					}
				}
			}
			if(u == 0)
			{
				n=atoi(aux);
				return n;

			}
			else
			{
				return -1;
			}

}

float validar2(char aux[' '])
{
	int i, j, neg=0, u, len;
	float n;	

			u=0;
			
			len = strlen(aux);
			for(i=0; i<strlen(aux); i++)
			{
				if(isalpha(aux[i]))
				{
					u=1;
					return -1;
				}
				else
				{
					if(isdigit(aux[i]))
					{
						u=0;
					}
					else if( (aux[i] == 45 || aux[i] == 43) && i == 0 && len>1)
					{
						u=0;
					}
					else if (aux[i] == 46 && neg == 0) 
					{
						neg++;
						u=0;
					}
					else
					{
						u=1;
						return -1;
					}
				}
			}
			if(u == 0)
			{
				n=atof(aux);
				return n;

			}
			else
			{
				return -1;
			}

}


void menu(int op)
{
     switch(op)
     {
               case 1:
               			menuconsultas();
                     	break;
                case 2:
                		menuacceso();
                		break;
                default:
                		break;
     }
}

void menuconsultas()
{
	char aux[' '];
    int op, i;
    
    do
    {
    	system("cls");
        for(i=0; i<30; i++)
                 printf(" -");
        printf("\n\t\t\tQUERIES\n\n");
        printf("\t\t1)By Avenue Id\n\n");
        printf("\t\t2)By Avenue Name\n\n");
        printf("\t\t3)By User Id\n\n");
        printf("\t\t4)Exit Queries\n\n");
        for(i=0; i<30; i++)
                 printf(" -");
        printf("\n");
                 
        gets(aux);
        op=validar(aux);
        
        if(op < 1 || op >3)
              printf("Try again.\n");
        else
        	  menuconsultas2(op);  
			    
        system("cls");
    
     }while(op != 4);
}

void menuconsultas2(int op)
{
	switch(op)
	{
		case 1:
				consulta(op);
				break;
		case 2:
				consulta(op);
				break;
		case 3:
				consulta(op);
				break;
		case 4:
				consulta(op);
				break;
		default:
				break;
	}
}

void consulta(int op)
{
     int i;
     char aux[' '], query[' '];
     int val, exit;
     
	do
    {
        do{
            system("cls");

            for(i=0; i<30; i++)
                     printf(" -");
            printf("\n\t\tQUERIES\n\n");
            switch(op)
            {
            	case 1:	 
            	       printf("\t\t1)By Avenue Id\n\n");
                     printf("\tWrite the Avenue Id to query:\n\t\t");
            	       break;
            	 case 2:
        		        printf("\t\t2)By Avenue Name\n\n");
                    printf("\tWrite the Avenue Name to query:\n\t\t");
        		        break;
        		 case 3:
        		 		printf("\t\t3)By User Id\n\n");
                printf("\tWrite the User Id to query:\n\t\t");
        		 		break;
            }
                fflush(stdin);
                gets(query);

            printf("\tIs correct the information? (1=yes 2=no)\n\t\t");
            fflush(stdin);
            gets(aux);
            val = validar(aux);

          }while(val != 1);

            printf("\tWant to exit to Main Menu? (1=yes 2=no)\n\t\t");
            fflush(stdin);
            gets(aux);
            exit = validar(aux);

        for(i=0; i<30; i++)
                 printf(" -");
        printf("\n");     
        
     }while(exit != 1);
}

void menuacceso()
{
	 int i;
     char user[' '], aux[' '], pass[' '];
     int op=0;
     

     	do
     	{
     			system("cls");
		     	for(i=0; i<30; i++)
		           printf(" -");
		        printf("\n\t\t\tLOGIN\n\n");
		        printf("\t\tUsername: ");
		        fflush(stdin);         
		        gets(user);
				printf("\n\t\tPassword: ");
				fflush(stdin);
				gets(pass);
				
				//codigo que verifique usuario y contrasena
				if(login(user,pass) == 0)	
					adminmenu();
				else
				printf("\n\tUsername or password doesnt match or exist\n\n");
				
	            printf("\t\tDo you want to exit to Main Menu? (1=yes 2=no)\n\t\t");
	            fflush(stdin);
	            gets(aux);
				op=validar(aux);    
		        for(i=0; i<30; i++)
		                 printf(" -");
		        printf("\n");  
     		
     	}while(op != 1);
     	
	
}

void adminmenu()
{
	char aux[' '];
    int op, i;
    
    do
    {
    	system("cls");
        for(i=0; i<30; i++)
                 printf(" -");
        printf("\n\t\t\tADMIN\n\n");
        printf("\t\t1)Add User\n\n");
        printf("\t\t2)Delete User\n\n");
        printf("\t\t3)Modificate User\n\n");
        printf("\t\t4)Reports\n\n");
        printf("\t\t5)Modify rates for each user\n\n");
        printf("\t\t6)Exit\n\n");
        for(i=0; i<30; i++)
                 printf(" -");
        printf("\n");
                 
        gets(aux);
        op=validar(aux);
        
        if(op < 1 || op > 6)
              printf("Try again.\n");
        else
        	adminmenu2(op);	  
    
     }while(op != 6);
	
}

void adminmenu2(int op)
{
	struct usuario pp;
	
	switch(op)
	{
		case 1:
				adduser(&pp);
				break;
		case 2:
				
				break;
		case 3:
				
				break;
		case 4:
				
				break;
		case 5:
				rates();
				break;
				
		default:
				break;
	}
	
}

void adduser(struct usuario *pp)
{
	char aux[' '];
	int correct=0;
	
	do
	{
	  system("cls");
	  // lectura de datos del empleado
	  printf("\n\t\t Reading the user data\n\n");
	  do
	  {
		  printf("\t\t Id of the user:\n \t\t  ");
		  fflush(stdin);
		  gets(aux);
		  pp->cve=validar(aux); 
		  
		  if(pp->cve < 1)
		  	printf("\t\tTry Again\n");
		   
	  }while(pp->cve < 1);
	  
	  do
	  {
		  printf("\t\t Type of user(1-8):\n \t\t  ");
		  fflush(stdin);
		  gets(aux);
		  pp->tipo=validar(aux);
		  
		  if(pp->tipo < 1 || pp->tipo > 8)
		  	printf("\t\tTry Again\n");
		   
	  }while(pp->tipo < 1 || pp->tipo > 8);	
	  
	  printf("\t\t Add name of the user:\n\t\t  ");
	  fflush(stdin);
	  gets(pp->nom);
	  
	  do
	  {
	  	printf("\t\t Id of Avenue:  \n\t\t  ");
	  	fflush(stdin);
	  	gets(aux);
	   	pp->dir.cve_colonia = validar(aux);
	   	
	   	if(pp->dir.cve_colonia < 1)
	   		printf("\t\tTry Again\n");
	   		
	  }while(pp->dir.cve_colonia < 1);
	  
	  printf("\t\t Add Name of the Avenue:\n\t\t  ");
	  fflush(stdin);
	  gets(pp->dir.colonia);
	  
	  do
	  {
	  	printf("\t\t Add usage of the user:\n\t\t  ");
	  	fflush(stdin);
	  	gets(aux);
	   	pp->consumo = validar2(aux);
	   	
	   	if(pp->consumo < 1)
	   		printf("\t\tTry Again\n");
	   		
	  }while(pp->consumo < 1);
	  
	  do
	  {
	  	printf("\t\t Add pay of the user:\n\t\t  ");
	  	fflush(stdin);
	  	gets(aux);
	   	pp->pago = validar2(aux);
	   	
	   	if(pp->pago < 1)
	   		printf("\t\tTry Again\n");
	  }while(pp->pago < 1);
	  
	  printf("\t\t Is it correct all of this information? (1=yes 2=no)\n\t\t  ");
	  fflush(stdin);
	  gets(aux);
	  correct = validar(aux);

	}while(correct != 1);
	
	//Add to textfile
	FILE *ptr_file;

		ptr_file =fopen("usuarios.txt", "a");
		
		if (!ptr_file)
			printf("\t\tNo se encontro el archivo\n");
		else
		{
			fprintf(ptr_file,"%d\t", pp->cve);
			fprintf(ptr_file,"%d\t", pp->tipo);
			fprintf(ptr_file,"%s\t", pp->nom);
			fprintf(ptr_file,"%d\t", pp->dir.cve_colonia);
			fprintf(ptr_file,"%s\t", pp->dir.colonia);
			fprintf(ptr_file,"%.2f\t", pp->consumo);
			fprintf(ptr_file,"%.2f\t\n", pp->pago);			
		}
		
		fclose(ptr_file);

	
}

int login(char user[' '], char pass[' '])
{
	FILE *ptr_file;
	char aux[' '], aux2[' '];	
		
		
		ptr_file =fopen("login.txt", "r");
	//	fprintf(ptr_file,"%s\t%s", "ADMIN", "ADMIN");
		fscanf(ptr_file, "%s\t%s", &aux, &aux2 );
	//	printf("%s \t %s", aux, aux2);
	if((strcmp(user,aux) == 0) && (strcmp(pass,aux2) == 0))
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
		fclose(ptr_file);
}

//EXPERIMENTAL STUFF
int cveuser()
{
	int cve=0;
	FILE *ptr_file;
	
	ptr_file = fopen("cve.txt", "r");
	
	//Stuff para dar clave de usuario automaticamente prioridad baja
	
	//do
	//{
	//	fscanf(ptr_file, "%d\n", cve );
	//}while(cve != NULL);
	fclose(ptr_file);
	
	//ptr_file=fopen("cve.txt", "a");
}

void rates()
{
	int i, op;
	char aux[' '];
	float rate;
	FILE *ptr_file;

	do
	{	
		ptr_file=fopen("tarifas.txt", "r");
		
		system("cls");
		printf("\t\tCurrent User Rates:\n\n\t\tUser Type\tRate\n\n");
		for(i=0; i<8; i++)
		{
			fscanf(ptr_file, "%f\n", &rate);
			printf("\t\t\t%d\t%.2f\n\n", i+1, rate);
		}
		fclose(ptr_file);
		
	
			printf("\t\tDo you want to change them? (1=yes, 2=no)\n\n\t\t  ");	
			gets(aux);
			op=validar(aux);
			
			if(op == 1)
			{
				//Stuff para cambiar las tarifas de los usuarios
			}
			else if(op < 1 || op > 2)
			{
				printf("\t\tPlease enter a valid option.\n\n");
			}
	}while(op !=2);	
}

