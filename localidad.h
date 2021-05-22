#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct{
    int id;
    char descripcion[21];
}eLocalidad;

/** \brief Muestra por pantalla las localidades
 *
 * \param localidades[] eLocalidad
 * \param tamL int
 * \return int
 *
 */
int mostrarLocalidades(eLocalidad localidades[], int tamL);


/** \brief Carga en descripcion la descripcion de la localidad pasada por id
 *
 * \param id int
 * \param localidades[] eLocalidad
 * \param tam int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionLocat(int id , eLocalidad localidades[], int tam, char descripcion[]);
#endif // LOCALIDAD_H_INCLUDED
