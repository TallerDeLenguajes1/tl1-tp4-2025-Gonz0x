#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;
typedef struct{
Tarea T;
Nodo *Siguiente;
}Nodo;

Nodo *start;
Nodo * CrearLista(){
    return NULL;
}

Nodo *crearNodo(Tarea tarea)
{
    Nodo *Nnodo = (Nodo *)malloc(sizeof(Nodo));
    Nnodo->T = tarea;
    Nnodo->Siguiente = NULL;
    return Nnodo;
}

void InsertarNodo(Nodo **start, Nodo *Nodo){
    Nodo-> Siguiente = *start;
    *start = Nodo;
}

void mostrarLista(){
    Nodo *actual;
    while (actual != NULL)
    {
        printf("\nTareaID: %d, descripcion: %s, duracion %d", actual->T.Duracion, actual->T.Descripcion, actual->T.Duracion);
        actual = actual->Siguiente;
    }
}

int main(){
    start = CrearLista();
    int op = 0;
    //*tareasPendientes;
    //*tareasRealizadas;
    
    do
    {

        printf("\nDesea ingresar nueva tarea o carga?");
        printf("\n1.SI - 0.No: ");
        scanf("%d", &op); 
        Tarea tarea;
        int i = 1000;
        tarea.TareaID = i++;
        tarea.Descripcion = (char *)malloc(strlen(tarea.Descripcion) * sizeof(char));
        printf("\nIngrese la descripcion de tarea: ");
        gets(tarea.Descripcion);
        do
        {    
            printf("\nIngrese su duracion: ");
            scanf("%d", &tarea.Duracion);

        } while (tarea.Duracion >= 10 || tarea.Duracion <= 100);

        


        int buscar = 0;

        if (buscar == 0)
        {
            int id;
            printf("\nIngrese id:");
            scanf("%d", &id);    
            char *tareaBuscada = BuscaNombrePorId(nombres, id);
            if (tareaBuscada != NULL)
            {
                printf("\nNombre buscado: %s", tareaBuscada);      
            }else{
                printf("\nEl id no pertenece al arreglo.");
            }
        }else if(buscar == 1)
        {
            char subcadena[15];
            printf("\nIngrese una palabra para buscar nombre:");
            fflush(stdin);
            gets(subcadena);
            fflush(stdin);
            char *tareaBuscada2 = BuscaNombrePorPalabra(nombres, subcadena);
            if (tareaBuscada2)
            {
                printf("La subcadena se encuentra en: %s\n", tareaBuscada2);
            }else{
                printf("La subcadena no encontrada.\n");
            }
        }


    } while (op != 0); 
   
   



    



    return 0;
}
