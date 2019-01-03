#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <libconfig.h>

void betterfgets(char *str, int size)
{
    fgets(str, size, stdin);
    str[strcspn(str,"\n")] = '\0';
}

int deleteFic(FILE *file){
    if(file != NULL)
    {
        fclose(file);
        fopen("fic.txt", "w+b");
        fclose(file);
        return 1;
    }
    fclose(file);
    return 0;
}

//saisie de resultat
int addResult(FILE *file)
{
    char name[10];
    int error;
    char *position;
    memset(name, '\0', 10);
    fseek(file, 0, SEEK_END);
    printf("Saisie d\'un résultat\n");
    printf("résultat : ");
    fflush(stdin);
    betterfgets(name,10);
    error = fwrite(&name, sizeof(char), 10, file);
    fclose(file);
    return error;
}

//code function1
void function1()
{
    config_t cfg;/*Returns all parameters in this structure */
    config_setting_t *setting;
    const char *str1, *str2;
    int tmp;

    char *config_file_name = "config.txt";

    /*Initialization */
    config_init(&cfg);

    /* Read the file. If there is an error, report it and exit. */
    if (!config_read_file(&cfg, config_file_name))
    {
        printf("\n%s:%d - %s", config_error_file(&cfg), config_error_line(&cfg), config_error_text(&cfg));
        config_destroy(&cfg);
        return -1;
    }

    /* Get the configuration file name. */
    if (config_lookup_string(&cfg, "filename", &str1))
        printf("\nFile Type: %s", str1);
    else
        printf("\nNo 'filename' setting in configuration file.");

    /*Read the parameter group*/
    setting = config_lookup(&cfg, "params");
    if (setting != NULL)
    {
        /*Read the string*/
        if (config_setting_lookup_string(setting, "param1", &str2))
        {
            printf("\nParam1: %s", str2);
        }
        else
            printf("\nNo 'param1' setting in configuration file.");

        /*Read the integer*/
        if (config_setting_lookup_int(setting, "param2", &tmp))
        {
            printf("\nParam2: %d", tmp);
        }
        else
            printf("\nNo 'param2' setting in configuration file.");

        printf("\n");
    }

    config_destroy(&cfg);
}

//code function2
void function2()
{
    char result;
 printf("Vous avez demandé de rendre le fichier vide.\n");

  printf("ATTENTION PAS DE RETOUR POSSIBLE, VOULEZ-VOUS CONTINIUER ?\n");
  fflush(stdin);
  printf("choix [y/n]: ");
  scanf("%c", &result);
  if (result == 'y'){
     int error;
    FILE *pf;
    pf = fopen("fic.txt", "r+b");
    if (pf == NULL){
        pf = fopen("fic.txt", "w+b");
    }
    error = deleteFic(pf);
    if (error != 0){
         printf("\nEnregistrement effectue\n");
    }
    else {
         printf("\nErreur a l\'enregistrement\n");
    }
  }
}

//code function3
void function3()
{
    //JAI PAS FINIE LA FONCTION
    printf("Vous voulez determiner si un programme de numero donne a ete resolu.\n");
    int error;
    FILE *pf;
    pf = fopen("fic.txt", "r+b");
    if (pf == NULL){
        pf = fopen("fic.txt", "w+b");
    }
    error = solve(pf);
    if (error != 0){
         printf("\nEnregistrement effectue\n");
    }
    else {
         printf("\nErreur a l\'enregistrement\n");
    }

}

//code function4
void function4()
{
}

//code function5
void function5()
{
}

//code function6
void function6()
{
}

//code function7
void function7()
{
}

//code function8
void function8()
{
}

//code function9
void function9()
{
}

//code function10
void function10()
{
}

