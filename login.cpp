#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void userlogin(void);

struct user{
    char username[10];
    char password[10];
}*usern;

int main()
{
    userlogin ( );

    return 0;
}

void userlogin(void){
    FILE *fp;
    char namet[10], pwd[10];int i;char c;

    usern=(struct user *)malloc(sizeof(struct user));

    printf("1. Ingresar con usuario existente\n2. Crear nuevo usuario y contraseña\n");
    scanf("%d",& i);
    
    switch(i){
        case 1:
            if ( ( fp=fopen("data.txt", "r+")) == NULL) {
                if ( ( fp=fopen("data.txt", "w+")) == NULL) {
                    printf ("No se pudo abrir el archivo\n");
                    exit ( 1);
                }
            }
            printf("Usuario: ");
            scanf("%s",namet);
            printf("contraseña: ");
            scanf("%s",pwd);
            while ( fread (usern, sizeof(struct user), 1, fp) == 1) {
                if( strcmp ( usern->username, namet) == 0) {
                    printf ("Usuario incorrecto\n");
                    if( strcmp ( usern->password, pwd) == 0) {
                        printf ("Contraseña incorrecta\n");
                    }
                }
            }
            break;

        case 2:
            do
            {
                if ( ( fp=fopen("data.txt", "a+")) == NULL) {
                    if ( ( fp=fopen("data.txt", "w+")) == NULL) {
                        printf ("No se pudo abrir el archivo\n");
                        exit ( 1);
                    }
                }
                printf("Elige un nombre de usuario: ");
                scanf("%s",usern->username);
                printf("Elige una contraseña: ");
                scanf("%s",usern->password);
                fwrite (usern, sizeof(struct user), 1, fp);
                printf("Ingresar otro usuario y contraseña (T/F): ");
                scanf(" %c",&c);
            }while(c=='T'||c=='F');
            break;
    }
    free ( usern);
    fclose(fp);
}
