#include <stdio.h>
#include <stdlib.h>

// crear e inicializar lista
// agregar_Nodo elemento
// obtener largo de la lista
// obtener un elemento N
// elimintar un elemento N
// imprimir lista

typedef struct Nodo { /* lista simple enlazada */
    struct Nodo *siguiente;
    char datos;
}Nodo;

Nodo *iniciar_crear(){
    return NULL;
}

Nodo *agregar_Nodo (Nodo *lista ,char datos){
    Nodo *nuevoNodo = malloc(sizeof(Nodo));
    nuevoNodo->datos = datos;
    nuevoNodo->siguiente = NULL;
    if(lista != NULL){
        Nodo *nodoAux = lista;
        while(nodoAux->siguiente != NULL){
            nodoAux = nodoAux->siguiente;
        }
        nodoAux->siguiente = nuevoNodo;
        return lista;
    }
    return nuevoNodo;
}

int largo_lista(Nodo *lista){
    int largo = 0;
    while( lista != NULL){
        largo++;
        lista = lista->siguiente;
    }
    return largo;
}

/*funcion para obtener un elemento N de la lista, la misma devuelve el elemento.
 * en caso contrario imprime un mensaje diciendo que no se encuentra el elemento y devuelve null*/
char obtener_elemento(Nodo *lista, char dato){

    while( lista != NULL) {

        if (lista->datos == dato) {
            return dato;
        }
        lista = lista->siguiente;
    }
    printf("El elemento no se encuentra en la lista");
    return NULL;
}

Nodo *eliminar_Nodo (Nodo *lista, char datos){
    if(lista != NULL){
        Nodo *nodoAux = lista;
        while(nodoAux->datos != datos){
            if(nodoAux->siguiente->datos == datos){
                nodoAux->siguiente = nodoAux->siguiente->siguiente;
                return lista;
            }else if (nodoAux->siguiente->siguiente != NULL){
                nodoAux = nodoAux->siguiente;
            } else{
                printf("El dato '%c' que se quiere eliminar no se encuentra en la lista.\n",datos);
                return lista;
            }
        }
        lista = nodoAux->siguiente;
        return lista;
    }
    printf("La lista esta vacia\n");
    return lista;
}

void imprimir_lista(Nodo *lista){
    while(lista!= NULL){
        printf("%c \n", lista->datos);
        lista = lista->siguiente;
    }
}


int main() {
    Nodo *lista1 = iniciar_crear();
    lista1 = eliminar_Nodo(lista1, 'A');
    lista1 = agregar_Nodo(lista1,'A');
    lista1 = agregar_Nodo(lista1,'B');
    lista1 = agregar_Nodo(lista1,'C');
    lista1 = agregar_Nodo(lista1,'D');
    lista1 = agregar_Nodo(lista1,'X');
    lista1 = agregar_Nodo(lista1,'Y');
    imprimir_lista(lista1);
    printf("\nEl largo de la lista es: %d\n", largo_lista(lista1));
    lista1 = eliminar_Nodo(lista1, 'C');
    lista1 = eliminar_Nodo(lista1, 'J');
    lista1 = eliminar_Nodo(lista1, 'a');
    imprimir_lista(lista1);
    printf("\nEl largo de la lista es: %d\n", largo_lista(lista1));
    return 0;
}
