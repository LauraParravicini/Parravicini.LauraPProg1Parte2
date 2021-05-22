#include "informes.h"

int mostrarJuegosMesa(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC){
    int retorno = -1;
    char descripcion[21];
    if(juegos != NULL && tamJ > 0){
    for(int i = 0; i < tamJ ; i++){
        if(juegos[i].idCategoria == 100){
                printf("\n\n------ Juegos de tipo Mesa -----\n");
                printf("Codigo       Descripcion               Importe  Categoria \n");
                cargarDescripcionCateg(juegos[i].idCategoria,categorias,tamC,descripcion);
                printf(" %4d      %15s               %5.2f      %5s \n", juegos[i].codigo, juegos[i].descripcion,juegos[i].importe,descripcion);
                retorno = 1;
            }
        }
    }

    return retorno;
}

int mostrarAlquilerCliente(eAlquiler alquileres[], int tamA, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eLocalidad localidades[], int tamL){
    int cliente;
    int retorno = -1;
    char descripcion[21];
    if(alquileres != NULL && tamA > 0 && clientes != NULL && tamC > 0 && juegos != NULL  && tamJ > 0){
        retorno = 0;
        printf("\n\n--- Mostrar alquileres de un cliente ---\n");
        mostrarClientes(clientes,tamC,localidades,tamL);

        utn_getNumero(&cliente,"\n- Ingrese id de cliente: ", "\n-!- Invalido -!-",0,100,10);
        while( buscarCliente(clientes,tamC,cliente) == -1 ){
            utn_getNumero(&cliente,"\n- Ingrese id de cliente: ", "\n-!- Invalido -!-",0,100,10);
        }

        printf("\n\n------ Alquileres realizados -----\n");
        printf("\n-- Alquiler       Juego      Cliente   Fecha -------\n");

        for(int i = 0; i < tamA; i++){
            if(alquileres[i].isEmpty == 0 && alquileres[i].codCliente == cliente){
                cargarDescripcionJuego(alquileres[i].codJuego,juegos,tamJ,descripcion);
                printf(" %4d    %5d    %10s   %2d/%2d/%4d    \n", alquileres[i].codCliente, alquileres[i].codAlquiler, descripcion, alquileres[i].fecha.dia ,alquileres[i].fecha.mes,alquileres[i].fecha.anio);
                retorno = 1;
            }
        }
        if(retorno == 0){
            printf("\t-!- No tiene a alquileres cargados ese cliente -!-\n\n");
        }
    }
    return retorno;

}

int totalPagarCliente(eCliente clientes[], int tamC, eAlquiler alquileres[], int tamA, eJuego juegos[], int tamJ, eLocalidad localidades[], int tamL ){
    int cliente;
    int retorno = -1;

    float total = 0;
    if(alquileres != NULL && tamA > 0 && clientes != NULL && tamC > 0 && juegos != NULL  && tamJ > 0){
        retorno = 0;
        printf("\n\n--- Mostrar gasto de un cliente ---\n");
        mostrarClientes(clientes,tamC,localidades,tamL);

        utn_getNumero(&cliente,"\n- Ingrese id de cliente: ", "\n-!- Invalido -!-",0,100,10);
        while( buscarCliente(clientes,tamC,cliente) == -1 ){
            utn_getNumero(&cliente,"\n- Ingrese id de cliente: ", "\n-!- Invalido -!-",0,100,10);
        }

        for(int i = 0; i < tamA; i++){
            if(alquileres[i].isEmpty == 0 && alquileres[i].codCliente == cliente){
                for(int j = 0; j < tamJ; j++){
                    if(alquileres[i].codJuego == juegos[j].codigo){
                        total += juegos[j].importe;
                        retorno = 1;
                    }
                }
            }
        }
        if(retorno == -1){
            printf("\t-!- No tiene alquileres cargados ese cliente -!-\n\n");
        }else{
            printf("   Total a pagar por el cliente: %.2f\n",total);
        }
    }
    return retorno;
}


int mostrarClienteSinAlquilar(eAlquiler alquileres[], int tamA, eCliente clientes[], int tamC, eLocalidad localidades[], int tamL){
    int retorno = -1;
    int cantAlq[tamC];
    for(int i = 0; i < tamC; i ++){
        cantAlq[i] = 0;
    }
    if(alquileres != NULL && tamA > 0 && clientes != NULL && tamC > 0){
        retorno = 0;

        for(int i = 0; i < tamC; i++){
            for(int j = 0; j < tamA; j++){
                if(alquileres[j].isEmpty == 0 && alquileres[j].codCliente == clientes[i].codigo && clientes[i].isEmpty == 0){
                    cantAlq[i] += 1;
                }
            }
        }
        printf("\n\n------ Clientes que no alquilaron -----\n");
        printf("\n-- Codigo  Nombre Apellido  Sexo  Telefono -------\n");
        char descripLocal[21];
        for(int i = 0; i < tamC; i ++){
            if( !(cantAlq[i] > 0) && clientes[i].isEmpty == 0){
                cargarDescripcionLocat(clientes[i].codigo,localidades,tamL,descripLocal);
                printf(" %4d    %5s    %5s   %4c    %7s  %s \n", clientes[i].codigo, clientes[i].nombre, clientes[i].apellido, clientes[i].sexo,clientes[i].telefono, descripLocal);
                retorno = 1;
            }
        }
        if(retorno == 0){
            printf("-- Todos alquilaron :) ---\n\n");
        }

    }
    return retorno;

}

int mostrarJuegosSinAlquilar(eAlquiler alquileres[], int tamA,eJuego juegos[], int tamJ, eCategoria categorias[], int tamC){
    int retorno = -1;
    int cantAlq[tamJ];
    char descripcion[21];
    for(int i = 0; i < tamJ; i ++){
        cantAlq[i] = 0;
    }
    if(alquileres != NULL && tamA > 0 && juegos != NULL && tamJ > 0){
        retorno = 0;

        for(int i = 0; i < tamJ; i++){
            for(int j = 0; j < tamA; j++){
                if(alquileres[j].isEmpty == 0 && alquileres[j].codJuego == juegos[i].codigo){
                    cantAlq[i] += 1;
                }
            }
        }
        printf("\n\n------ Juegos que no alquilaron -----\n");
        printf("Codigo    Descripcion                  Importe  Categoria \n");

        for(int i = 0; i < tamJ; i ++){
            if( !(cantAlq[i] > 0) ){
                cargarDescripcionCateg(juegos[i].idCategoria,categorias,tamC,descripcion);
                printf(" %4d      %15s               %5.2f      %5s \n", juegos[i].codigo, juegos[i].descripcion,juegos[i].importe,descripcion);
                retorno = 1;
            }
        }
        if(retorno == 0){
            printf("-- Todos se alquilaron :) ---\n\n");
        }

    }
    return retorno;

}

int telefonosPorFecha(eAlquiler alquileres[], int tamA, eCliente clientes[], int tamC){
    int retorno = -1;
    eFecha fecha;
    if(clientes != NULL && tamC > 0 && alquileres != NULL && tamA > 0){
        printf("\n\n------- Mostrar telefonos de alquileres en fecha ---------- \n");

        utn_getFecha(&fecha.dia,&fecha.mes,&fecha.anio,"\n- Ingrese fecha de alquileres: ", "\n-!- Fecha invalida -!-",10);

        printf("- Nombre  Apellido  Telefono - \n");
        for(int i = 0; i < tamA; i ++){
            if( alquileres[i].isEmpty == 0 && (alquileres[i].fecha.dia == fecha.dia && alquileres[i].fecha.mes == fecha.mes && alquileres[i].fecha.anio == fecha.anio) ){
                for(int j = 0; j < tamC; j ++){
                    if(alquileres[i].codCliente == clientes[j].codigo){
                        printf("  %s  %s  %s   \n",clientes[j].nombre,clientes[j].apellido,clientes[j].telefono);
                        retorno = 1;
                    }
                }
            }
        }
    }
    return retorno;
}

int mostrarJuegosMujeres(eAlquiler alquileres[], int tamA, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCAT){
    int retorno = -1;
    char descripcion[21];
    if(alquileres != NULL && tamA > 0 && clientes != NULL && tamC > 0 && juegos != NULL  && tamJ > 0 && categorias != NULL && tamCAT > 0){
        retorno = 0;
        printf("\n\n--- Mostrar juegos alquilados por mujeres ---\n");
        printf("Codigo    Descripcion                  Importe  Categoria \n");

        for(int i = 0; i < tamC; i++){
           if(clientes[i].isEmpty == 0 && clientes[i].sexo == 'f'){
                for(int j= 0; j < tamA; j++){
                    if(alquileres[j].isEmpty == 0 && alquileres[j].codCliente == clientes[i].codigo){
                        for(int k = 0; k < tamJ; k++){
                            if(alquileres[j].codJuego == juegos[k].codigo){
                                cargarDescripcionCateg(juegos[i].idCategoria,categorias,tamC,descripcion);
                                printf(" %4d      %15s               %5.2f      %5s \n", juegos[i].codigo, juegos[i].descripcion,juegos[i].importe,descripcion);
                                retorno = 1;
                            }
                        }
                    }
                }
           }
        }
        if(retorno == 0){
            printf("\t-!- No tiene a alquileres de mujeres -!-\n\n");
        }
    }
    return retorno;

}

int juegoFavoritoHombres(eAlquiler alquileres[], int tamA,eCliente clientes[], int tamCl, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC){
    int retorno = -1;
    int cantAlq[tamJ];

    char descripcion[21];
    for(int i = 0; i < tamJ; i ++){
        cantAlq[i] = 0;
    }
    if(alquileres != NULL && tamA > 0 && juegos != NULL && tamJ > 0 && categorias != NULL && tamC > 0 && clientes != NULL && tamCl > 0){
        retorno = 0;

        for(int i = 0; i < tamCl; i++){
           if(clientes[i].isEmpty == 0 && clientes[i].sexo == 'm'){
                for(int j = 0; j < tamA; j++){
                    if(alquileres[j].isEmpty == 0 && alquileres[j].codCliente == clientes[i].codigo){
                        for(int k = 0; k < tamJ; k++){
                            if(alquileres[j].codJuego == juegos[k].codigo){
                                cantAlq[k] += 1;
                                retorno = 1;
                            }
                        }
                    }
                }
           }
        }

        printf("\n\n------ Juegos favorito de los varones -----\n");
        printf("Codigo      Descripcion                Importe    Categoria \n");

        int juegoPref = cantAlq[0];
        for(int i = 1; i < tamJ; i++){
            if(cantAlq[i] > juegoPref){
                juegoPref = cantAlq[i];
            }
        }

        for (int i = 0; i < tamJ; i++){
            if (cantAlq[i] == juegoPref && retorno > 0){
                cargarDescripcionCateg(juegos[i].idCategoria,categorias,tamC,descripcion);
                printf(" %4d      %15s               %5.2f      %5s \n", juegos[i].codigo, juegos[i].descripcion,juegos[i].importe,descripcion);
                retorno = 1;
            }
        }

        if(retorno == 0){
            printf("-- No hay alquiler de hombres ---\n\n");
        }

    }
    return retorno;

}

int mostrarClientesJuego(eAlquiler alquileres[], int tamA,eCliente clientes[], int tamC, eJuego juegos[], int tamJ,eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamL){
    int codJuego;
    int retorno = -1;

    if(alquileres != NULL && tamA > 0 && clientes != NULL && tamC > 0 && juegos != NULL  && tamJ > 0 && localidades != NULL && tamL > 0){
        retorno = 0;
        printf("\n\n--- Mostrar clientes de un juego ---\n");
        mostrarJuegos(juegos, tamJ,categorias,tamC);

        printf("\n- Ingrese Codigo de Juego: ");
        scanf(" %d", &codJuego);
        while( !validarJuego(codJuego,juegos,tamJ) ){
            printf("-!- Juego invalido -!- Reingrese codigo de juego: ");
            scanf(" %d", &codJuego);
        }
        printf("\n-- Codigo  Nombre Apellido  Sexo  Telefono Localidad -------\n");
        char descripLocal[21];
        for(int i = 0; i < tamA; i++){
           if( alquileres[i].isEmpty == 0 && alquileres[i].codJuego == codJuego){
                for(int j = 0; j < tamC; j++){
                    if(clientes[j].isEmpty == 0 && alquileres[i].codCliente == clientes[j].codigo){
                        cargarDescripcionLocat(clientes[j].codigo,localidades,tamL,descripLocal);
                        printf(" %4d    %5s    %5s   %4c    %7s  %s \n", clientes[j].codigo, clientes[j].nombre, clientes[j].apellido, clientes[j].sexo,clientes[j].telefono, descripLocal);
                        retorno = 1;
                    }
                }
           }
        }
        if(retorno == 0){
            printf("\t-!- No tiene alquileres cargados para ese juego -!-\n\n");
        }
    }
    return retorno;
}

int recaudacionPorFecha(eAlquiler alquileres[], int tamA, eJuego juegos[], int tamJ){
    int retorno = -1;
    eFecha fecha;
    float total = 0;
    if(alquileres != NULL && tamA > 0 && juegos != NULL && tamJ > 0){
        retorno = 0;
        printf("\n\n------- Mostrar recaudacion de alquileres en fecha ---------- \n");

        utn_getFecha(&fecha.dia,&fecha.mes,&fecha.anio,"\n- Ingrese fecha de alquileres: ", "\n-!- Fecha invalida -!-",10);

        for(int i = 0; i < tamA; i ++){
            if( alquileres[i].isEmpty == 0 && (alquileres[i].fecha.dia == fecha.dia && alquileres[i].fecha.mes == fecha.mes && alquileres[i].fecha.anio == fecha.anio) ){
                for(int j = 0; j < tamJ; j ++){
                    if(alquileres[i].codJuego == juegos[j].codigo){
                        total += juegos[j].importe;
                        retorno = 1;
                    }
                }
            }
        }
        if(retorno){
            printf("\n --- Total a pagar en fecha %2d/%2d/%4d es: $ %.2f\n\n",fecha.dia,fecha.mes,fecha.anio,total);
        }else{
            printf("\n -- No hay gastos en esa fecha --- \n\n");
        }
    }
    return retorno;
}

int mostrarClientesLocalidad(eCliente clientes[], int tamC, eLocalidad localidades[], int tamL){
    int retorno = 0;
    int id;
    if(clientes != NULL && tamC > 0 && localidades != NULL && tamL > 0 ){
        utn_getNumero(&id,"\nIngrese id de localidad: ","-!- Invalido -!-",1, 3,10);
        char descripLocal[21];
        printf("\n-- Clientes de la localidad ingresada --\n");
        for(int i = 0; i < tamC; i++){
            if(clientes[i].idLocalidad == id){
                cargarDescripcionLocat(clientes[i].codigo,localidades,tamL,descripLocal);
                printf(" %4d    %5s    %5s   %4c    %7s  %s \n", clientes[i].codigo, clientes[i].nombre, clientes[i].apellido, clientes[i].sexo,clientes[i].telefono, descripLocal);
                retorno = 1;
            }
        }
    }

    return retorno;
}

int mostrarAlquilerLocalidad(eCliente clientes[],eAlquiler alquileres[], int tamA ,int tamC, eLocalidad localidades[], int tamL, eJuego juegos[], int tamJ){
    int retorno = 0;
    int id;
    if(clientes != NULL && tamC > 0 && localidades != NULL && tamL > 0 ){
        utn_getNumero(&id,"\nIngrese id de localidad: ","-!- Invalido -!-",1, 3,10);
        printf("\n-- ALquiler de la localidad ingresada --\n");
        printf("\n-- Alquiler       Juego      Cliente   Fecha -------\n");
        char descripcion[21];
        for(int i = 0; i < tamC; i++){
            if(clientes[i].idLocalidad == id && clientes[i].isEmpty == 0){
                for(int k = 0; k < tamA; k++){
                  if(alquileres[k].codCliente == clientes[i].codigo && alquileres[k].isEmpty == 0){
                    cargarDescripcionJuego(alquileres[k].codJuego,juegos,tamJ,descripcion);
                    printf("   %4d       %10s     %4d   %2d/%2d/%4d    \n", alquileres[k].codAlquiler, descripcion, alquileres[k].codCliente, alquileres[k].fecha.dia, alquileres[k].fecha.mes, alquileres[k].fecha.anio);
                    retorno = 1;
                  }
                }
            }
        }
    }

    return retorno;
}


