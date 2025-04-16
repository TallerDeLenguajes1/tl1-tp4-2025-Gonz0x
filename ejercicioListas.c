#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;
typedef struct Nodo{
Tarea T;
Nodo *Siguiente;
}Nodo;

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

int moverLista(Nodo **pendientes, Nodo **realizadas, int id){
    Nodo *actual = *pendientes;  
    Nodo *anterior = NULL; 
    while (actual != NULL)
    {
        if (actual->T.TareaID == id) //si encontramos a la tarea
        {
            if (anterior == NULL) //es para el caso que la tarea sea la primera de la lista
            {
                *pendientes = actual->Siguiente; //me desplazo hacia la siguiente tarea para borrar actual
            }else
            {
                anterior->Siguiente = actual->Siguiente; //para el caso tarea no es la primera de la lista, me la salteo mediante punteros
            }

            InsertarNodo(realizadas, actual); //cambio de lista las tareas
            
        }
        anterior = actual; //me desplazo por la lista
        actual = actual->Siguiente;
    }
    

}

int main(){
    Nodo *pendientes = CrearLista();
    Nodo *realizadas = CrearLista();
    int i = 1000;
    int op = 0;
    //*tareasPendientes;
    //*tareasRealizadas;
    
    do
    {

        printf("\nDesea ingresar nueva tarea o carga?");
        printf("\n1.SI - 0.No: ");
        scanf("%d", &op); 
        if (op == 1)
        {
            Tarea tarea;
            tarea.TareaID = i++;
            tarea.Descripcion = (char *)malloc(strlen(tarea.Descripcion) * sizeof(char));
            printf("\nIngrese la descripcion de tarea: ");
            gets(tarea.Descripcion);
            do
            {    
                printf("\nIngrese su duracion: ");
                scanf("%d", &tarea.Duracion);

            } while (tarea.Duracion <= 10 || tarea.Duracion >= 100);

            InsertarNodo(&pendientes, crearNodo(tarea));
            printf("\nSe agrego la tarea!");

        }

        if (pendientes != NULL)
        {
            printf("\nTareas pendientes: ");
            mostrarLista(pendientes);
        }else
        {
            printf("\nNo hay tareas pendientes.");
        }
        

        if (realizadas != NULL)
        {
            printf("\nTareas realizadas: ");
            mostrarLista(realizadas);
        }else
        {
            printf("\nNo hay tareas realizadas.");
        }


        char x;
        printf("\nSi desea cambiar una tarea pendiente a realizada, presione x");
        scanf("%c", &x);
        if (x)
        {
            int id;
            printf("\nIngrese ID de la tarea que desea eliminar: ");
            scanf("%d", &id);
            moverLista(&pendientes, &realizadas, id);
            printf("\nTarea movida exitosamente!");
            
        }
        
        
        
        

        
        




    } while (op != 0); 
   
   



    



    return 0;
}
