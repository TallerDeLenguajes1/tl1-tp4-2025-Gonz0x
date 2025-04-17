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
struct Nodo *Siguiente;
}Nodo;

Nodo * CrearLista(){
    return NULL;
}

Nodo *crearNodo(Tarea tarea)
{
    Nodo *Nnodo = (Nodo *)malloc(sizeof(Nodo)); //asignacion dinamica de memoria nuevonodo
    Nnodo->T = tarea;
    Nnodo->Siguiente = NULL;
    return Nnodo;
}

void InsertarNodo(Nodo **start, Nodo *NuevoNodo){
    NuevoNodo-> Siguiente = *start;
    *start = NuevoNodo;
}

void mostrarLista(Nodo *lista){
    Nodo *actual = lista;
    while (actual != NULL)
    {
        printf("\nTareaID: %d, descripcion: %s, duracion %d", actual->T.TareaID, actual->T.Descripcion, actual->T.Duracion);
        actual = actual->Siguiente;
    }
}



void moverLista(Nodo **pendientes, Nodo **realizadas, int id){
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

void buscaTarea(Nodo **pendientes, Nodo **realizadas){
    Nodo *actual, *actual2;
    actual = *pendientes;
    actual2 = *realizadas;
    int seleccion = 0;        
    int encontrada = 0;
    printf("\nSi desea buscar la tarea por ID presione 0, si desea buscarla por un nombre presione 1: ");
    scanf("%d", &seleccion);
    if (seleccion == 0)
    {
        int id = 0;
        printf("\nIngrese ID de tarea: ");
        scanf("%d", &id);
        while (actual != NULL)
        {
            if (actual->T.TareaID == id) //si encontramos a la tarea
            {
                printf("\nTareaID: %d, descripcion: %s, duracion %d", actual->T.TareaID, actual->T.Descripcion, actual->T.Duracion);
                encontrada = 1;
            }
            actual = actual->Siguiente;
        }

        while (actual2 != NULL)
        {
            if (actual2->T.TareaID == id) //si encontramos a la tarea
            {
                printf("\nTareaID: %d, descripcion: %s, duracion %d", actual2->T.TareaID, actual2->T.Descripcion, actual2->T.Duracion);
                encontrada = 1;
            }
            actual2 = actual2->Siguiente;
        }

        if (!encontrada)
        {
            printf("\nNo se encontro la tarea.");
        }
        
    }else
    {
        char subcadena[15]; 
        printf("\nIngrese el nombre de la tarea: ");
        fflush(stdin);
        gets(subcadena);
        fflush(stdin);

        while (actual != NULL)
        {
            if (strstr(actual->T.Descripcion, subcadena))
            {
                printf("\nTareaID: %d, descripcion: %s, duracion %d", actual->T.TareaID, actual->T.Descripcion, actual->T.Duracion);
                encontrada = 1;
            }
            actual = actual->Siguiente;
            
        }
        while (actual2 != NULL)
        {
            if (strstr(actual2->T.Descripcion, subcadena))
            {
                printf("\nTareaID: %d, descripcion: %s, duracion %d", actual2->T.TareaID, actual2->T.Descripcion, actual2->T.Duracion);
                encontrada = 1;
            }
            actual2 = actual2->Siguiente;
            
        }
        if (!encontrada)
        {
            printf("\nNo se encontro la tarea.");
        }
        
    }
}

int main(){
    Nodo *pendientes = CrearLista();
    Nodo *realizadas = CrearLista();
    int i = 1000;
    int op = 0;
    Tarea tarea;
    do
    {

        printf("\nDesea ingresar nueva tarea o carga?");
        printf("\n1.SI - 0.No: ");
        scanf("%d", &op); 
        if (op == 1)
        {
            tarea.TareaID = i++;          
            char descripcionTarea[100]; // arreglo aux 
            printf("\nIngrese la descripcion de tarea: ");
            fflush(stdin);
            gets(descripcionTarea);
            tarea.Descripcion = (char *)malloc(strlen(descripcionTarea) * sizeof(char));
            strcpy(tarea.Descripcion, descripcionTarea); //copio lo del arreglo aux a tarea.descripcion
  
            do
            {    
                printf("\nIngrese su duracion > 10 y < 100: ");
                scanf("%d", &tarea.Duracion);
            } while (tarea.Duracion <= 10 || tarea.Duracion >= 100);

            InsertarNodo(&pendientes, crearNodo(tarea));
            printf("\nSe agrego la tarea!");

        }else{
            op = 0;
            printf("\nFIN");
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


        int cambiar = 0;
        printf("\nSi desea cambiar una tarea pendiente a realizada, presione 1, sino 0: ");
        scanf(" %d", &cambiar);
        if (cambiar == 1)
        {
            int id;
            printf("\nIngrese ID de la tarea que desea eliminar: ");
            scanf("%d", &id);
            moverLista(&pendientes, &realizadas, id);
            printf("\nTarea movida exitosamente!");
            
        }
        
        int buscar = 0;
        printf("\nSi desea buscar una tarea pendiente o realizada, presione 1, sino 0: ");
        scanf(" %d", &buscar);
        if (buscar == 1)
        {
            buscaTarea(&pendientes, &realizadas);
        }

    } while (scanf("%d", &op) != 0); 

    return 0;
}
