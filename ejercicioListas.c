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
        printf("\nTareaID: %d, descripcion: %s, duracion %d",)
    }
    
}
int main(){
    start = CrearLista();
    int op = 0;
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
        
    } while (op != 0); 
   
   
    do
    {    
        printf("\nIngrese su duracion: ");
        scanf("%d", &tarea.Duracion);

    } while (tarea.Duracion >= 10 || tarea.Duracion <= 100);


    



    return 0;
}
