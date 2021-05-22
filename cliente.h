#include <stdio.h>
#include "utn.h"
#include <string.h>
#include "localidad.h"
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int codigo;
    char nombre[51];//Validar
    char apellido[51];//Validar
    char sexo;//Validar
    char telefono[21];//Validar
    int isEmpty;
    int idLocalidad;
}eCliente;

/** \brief  Ingresa los datos, valida y da de alta un cliente actualizando el proximo ID
 *
 * \param eCliente clientes[]
 * \param int tam
 * \param int* id
 * \param eLocalidad localidades[]
 * \param int tamL
 * \return int
 *
 */
int altaCliente(eCliente clientes[], int tam, int* id, eLocalidad localidades[], int tamL);

/** \brief  Inicializa el vector clientes poniendo isEmpty en verdadero (1)
 *
 * \param eCliente clientes[]
 * \param int tam
 * \return int
 *
 */
int initClientes(eCliente clientes[], int tam);

/** \brief  Devuelve la primera posicion libre (isEmpty en verdadero) de clientes
 *
 * \param eCliente clientes[]
 * \param int tam
 * \return int
 *
 */
int buscarLibreCliente(eCliente clientes[], int tam);

/** \brief  Muestra los clientes activos por pantalla
 *
 * \param eCliente clientes[]
 * \param int tam
 * \param eLocalidad localidades[]
 * \param int tamL
 * \return int
 *
 */
int mostrarClientes(eCliente clientes[], int tam, eLocalidad localidades[], int tamL);

/** \brief Modifica el cliente mostrando las opciones para modificar, validando y actualizando el cliente
 *
 * \param eCliente clientes[]
 * \param int tam
 * \return int
 *
 */
int modifCliente(eCliente clientes[], int tam);

/** \brief  Devuelve la posicion en el vector de un cliente usando su ID
 *
 * \param eCliente clientes[]
 * \param int tam
 * \return int
 *
 */
int buscarCliente(eCliente clientes[], int tam, int id);

/** \brief Realiza la baja de un cliente y de sus alquileres asociados
 *
 * \param eCliente clientes[]
 * \param int tam
 * \param eAlquiler alquileres[]
 * \param int tamA
 * \param eLocalidad localidades[]
 * \param int tamL
 * \return int
 *
 */
int bajaCliente(eCliente clientes[], int tam,int* idCliente, eLocalidad localidades[], int tamL);
#endif // CLIENTE_H_INCLUDED
