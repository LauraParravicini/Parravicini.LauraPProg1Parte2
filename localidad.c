#include "localidad.h"

int mostrarLocalidades(eLocalidad localidades[], int tamL){
    int retorno = -1;
    if(localidades != NULL && tamL > 0){
        printf("\n\n------ Localidades -----\n");
        printf("Codigo   Descripcion \n");
        for(int i = 0; i < tamL ; i++){
            printf(" %4d      %15s         \n", localidades[i].id ,localidades[i].descripcion);
            retorno = 1;
        }
    }
    return retorno;
}

int cargarDescripcionLocat(int id , eLocalidad localidades[], int tam, char descripcion[]){
	int retorno = -1;
	if(id >= 1 && id <= 3 && localidades != NULL && tam > 0 && descripcion != NULL){
		for(int i = 0; i < tam; i++){
			if(localidades[i].id == id){
				strcpy(descripcion, localidades[i].descripcion);
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
