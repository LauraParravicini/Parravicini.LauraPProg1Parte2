#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "cliente.h"
#include "alquiler.h"
#include "informes.h"
#define SALIR 21
#define TAMC 10
#define TAMA 20
#define TAMJ 6
#define TAMCAT 5
#define TAMLOC 3

int main()
{
    eJuego juegos[TAMJ] = {  {1, "Tateti" , 50, 100} , {2, "Starcraft" , 400, 300} , {3, "Conejo Galera" , 700, 500} , {4, "Poker" , 200, 200} , {5, "Ruleta" , 2000, 400}, {6, "Hanoi" , 500, 100} };
    eCategoria categorias[TAMCAT] = { {100, "Mesa"},{200, "Azar"} , {300, "Estrategia"} , {400, "Salon" } , {500, "Magia"} };
    eLocalidad localidades[TAMLOC] = { {1,"GrandBourg"} , {2,"Polvorines"} , {3,"Nogues"} };

    eCliente clientes[TAMC];
    eAlquiler alquileres[TAMA];

    initClientes(clientes,TAMC);
    initAlquileres(alquileres,TAMA);

    int nextId = 1;
    int nextIdAlquiler = 1;
    int opcion;
    int status;
    int flagAlta = 0;
    int idBorrarAlq = -1;
    do{
            printf("-----------*-*-*--- Alquiler de Juegos ---*-*-*---------------\n\n");
            printf("--- Menu ---\n 1) Alta cliente \n ");
            if(flagAlta){
                printf("2) Modificar cliente \n 3) Baja cliente \n 4) Listar Cliente \n 5) Alta alquiler \n 6) Listar alquileres \n 7) Mostrar Juegos de Mesa \n 8) Mostrar alquileres de cliente \n");
                printf(" 9) Total a pagar de Cliente \n 10) Clientes que no alquilaron \n 11) Juegos que no alquilaron \n 12) Telefonos por fecha \n 13) Mostrar Juegos alq por Mujeres \n 14) Juego favorito de hombres \n");
                printf(" 15) Mostrar clientes de un juego \n 16) Mostrar recaudacion por fecha \n 17) Mostrar clientes de una localidad \n 18) Mostrar alquileres de una localidad \n");
            }
            printf(" \n 21) Salir del sistema \n");
            utn_getNumero(&opcion,"\n--- Ingrese opcion: ", "\n-!- Dato Invalido -!-\n",1,21,10);
            switch(opcion){
                case 1:
                    status = altaCliente(clientes,TAMC,&nextId,localidades,TAMLOC);
                    status != -1 ? printf("\n--- Cliente Agregado ---\n\n") : printf("\n-!- Hubo error al cargar Cliente -!-\n") ;
                    flagAlta++;
                    break;
                case 2:
                    status = modifCliente(clientes,TAMC);
                    status != -1 ? printf("\n--- Operacion exitosa ---\n\n") : printf("\n-!- Hubo error al modificar Cliente -!-\n") ;
                    break;
                case 3:
                    status = bajaCliente(clientes,TAMC,&idBorrarAlq,localidades,TAMLOC);
                    status = bajaAlquileresCliente(idBorrarAlq,alquileres,TAMA);
                    status != -1 ? printf("\n--- Operacion exitosa ---\n\n") : printf("\n-!- Hubo error al borrar Cliente -!-\n") ;
                    break;
                case 4:
                    status = mostrarClientes(clientes,TAMC,localidades,TAMLOC);
                    status != -1 ? printf("\n\n") : printf("\n-!- Hubo error al mostrar -!-\n\n") ;
                    break;
                case 5:
                    status = altaAlquiler(alquileres,TAMA,&nextIdAlquiler,clientes,TAMC,juegos,TAMJ,categorias,TAMCAT,localidades,TAMLOC);
                    status != -1 ? printf("\n ---- Alquiler cargado -----\n\n") : printf("\n-!- Hubo error al cargar -!-\n") ;
                    break;
                case 6:
                    status = mostrarAlquileres(alquileres,TAMA,juegos,TAMJ);
                    status != -1 ? printf("\n\n") : printf("\n-!- Hubo error al mostrar -!-\n") ;
                    break;
                case 7:
                    status = mostrarJuegosMesa(juegos,TAMJ,categorias,TAMC);
                    status != -1 ? printf("\n\n") : printf("\n-!- No hay juegos de mesa -!-\n") ;
                    break;
                case 8:
                    status = mostrarAlquilerCliente(alquileres,TAMA,clientes,TAMC,juegos,TAMJ,localidades,TAMLOC);
                    status != -1 ? printf("\n\n") : printf("\n-!- Hubo error al mostrar -!-\n") ;
                    break;
                case 9:
                    status = totalPagarCliente(clientes,TAMC,alquileres,TAMA,juegos,TAMJ,localidades,TAMLOC);
                    status != -1 ? printf("\n\n") : printf("\n-!- Hubo error al mostrar -!-\n") ;
                    break;
                case 10:
                    status = mostrarClienteSinAlquilar(alquileres,TAMA,clientes,TAMC,localidades,TAMLOC);
                    status != -1 ? printf("\n\n") : printf("\n-!- Hubo error al mostrar -!-\n") ;
                    break;
                case 11:
                    status = mostrarJuegosSinAlquilar(alquileres,TAMA,juegos,TAMJ,categorias,TAMCAT);
                    status != -1 ? printf("\n\n") : printf("\n-!- Hubo error al mostrar -!-\n") ;
                    break;
                case 12:
                    status = telefonosPorFecha(alquileres,TAMA,clientes,TAMC);
                    status != -1 ? printf("\n\n") : printf("\n-- No hay alquileres en esa fecha ---\n\n") ;
                    break;
                case 13:
                    status = mostrarJuegosMujeres(alquileres,TAMA,clientes,TAMC,juegos,TAMJ,categorias,TAMCAT);
                    status != -1 ? printf("\n\n") : printf("\n-- Hubo error al mostrar ---\n") ;
                    break;
                case 14:
                    status = juegoFavoritoHombres(alquileres,TAMA,clientes,TAMC,juegos,TAMJ,categorias,TAMCAT);
                    status != -1 ? printf("\n\n") : printf("\n-- Hubo error al mostrar ---\n") ;
                    break;
                case 15:
                    status = mostrarClientesJuego(alquileres,TAMA,clientes,TAMC,juegos,TAMJ,categorias,TAMCAT,localidades,TAMLOC);
                    status != -1 ? printf("\n\n") : printf("\n-- Hubo error al mostrar ---\n") ;
                    break;
                case 16:
                    status = recaudacionPorFecha(alquileres,TAMA,juegos,TAMJ);
                    status != -1 ? printf("\n\n") : printf("\n-- Hubo error al mostrar ---\n") ;
                    break;
                case 17:
                    status = mostrarClientesLocalidad(clientes,TAMC,localidades,TAMLOC);
                    status != -1 ? printf("\n\n") : printf("\n-- Hubo error al mostrar ---\n") ;
                    break;
                 case 18:
                    status = mostrarAlquilerLocalidad(clientes,alquileres,TAMA,TAMC,localidades,TAMLOC,juegos,TAMJ);
                    status != -1 ? printf("\n\n") : printf("\n-- Hubo error al mostrar ---\n") ;
                    break;
                case 21:
                    break;
            }

    }while(opcion != SALIR);


    return EXIT_SUCCESS;
}

