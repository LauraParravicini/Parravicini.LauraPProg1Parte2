#include "juego.h"
#include "categoria.h"
#include "alquiler.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


/** \brief Muestra los juegos de categoria Mesa
 *
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categoria[] eCategoria
 * \param tamC int
 * \return int
 *
 */
int mostrarJuegosMesa(eJuego juegos[], int tamJ, eCategoria categoria[], int tamC);


/** \brief Muestra los alquileres de un cliente
 *
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param clientes[] eCliente
 * \param tamC int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param localidades[] eLocalidad
 * \param tamL int
 * \return int
 *
 */
int mostrarAlquilerCliente(eAlquiler alquileres[], int tamA, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eLocalidad localidades[], int tamL);


/** \brief Muestra el total a pagar de un cliente
 *
 * \param clientes[] eCliente
 * \param tamC int
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param localidades[] eLocalidad
 * \param tamL int
 * \return int
 *
 */
int totalPagarCliente(eCliente clientes[], int tamC, eAlquiler alquileres[], int tamA, eJuego juegos[], int tamJ, eLocalidad localidades[], int tamL );


/** \brief Muestra los clientes que no alquilaron
 *
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param clientes[] eCliente
 * \param tamC int
 * \param localidades[] eLocalidad
 * \param tamL int
 * \return int
 *
 */
int mostrarClienteSinAlquilar(eAlquiler alquileres[], int tamA, eCliente clientes[], int tamC, eLocalidad localidades[], int tamL);

/** \brief Muestra los juegos sin alquilar
 *
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamC int
 * \return int
 *
 */
int mostrarJuegosSinAlquilar(eAlquiler alquileres[], int tamA,eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);

/** \brief Muestra los telefonos segun fecha de alquiler
 *
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param clientes[] eCliente
 * \param tamC int
 * \return int
 *
 */
int telefonosPorFecha(eAlquiler alquileres[], int tamA, eCliente clientes[], int tamC);

/** \brief Muestra los juegos jugados por mujeres
 *
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param clientes[] eCliente
 * \param tamC int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamCAT int
 * \return int
 *
 */
int mostrarJuegosMujeres(eAlquiler alquileres[], int tamA, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCAT);

/** \brief Muestra el juego favorito de los hombres
 *
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param clientes[] eCliente
 * \param tamCl int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamC int
 * \return int
 *
 */
int juegoFavoritoHombres(eAlquiler alquileres[], int tamA,eCliente clientes[], int tamCl, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);

/** \brief Muestra los clientes de un juego
 *
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param clientes[] eCliente
 * \param tamC int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamCat int
 * \param localidades[] eLocalidad
 * \param tamL int
 * \return int
 *
 */
int mostrarClientesJuego(eAlquiler alquileres[], int tamA,eCliente clientes[], int tamC, eJuego juegos[], int tamJ,eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamL);

/** \brief Muestra la recaudacion de una fecha especifica
 *
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param juegos[] eJuego
 * \param tamJ int
 * \return int
 *
 */
int recaudacionPorFecha(eAlquiler alquileres[], int tamA, eJuego juegos[], int tamJ);


/** \brief Muestra los clientes de una localidad
 *
 * \param clientes[] eCliente
 * \param tamC int
 * \param localidades[] eLocalidad
 * \param tamL int
 * \return int
 *
 */
int mostrarClientesLocalidad(eCliente clientes[], int tamC, eLocalidad localidades[], int tamL);

/** \brief Muestra los alquileres de una localidad
 *
 * \param clientes[] eCliente
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param tamC int
 * \param localidades[] eLocalidad
 * \param tamL int
 * \param juegos[] eJuego
 * \param tamJ int
 * \return int
 *
 */
int mostrarAlquilerLocalidad(eCliente clientes[],eAlquiler alquileres[], int tamA ,int tamC, eLocalidad localidades[], int tamL, eJuego juegos[], int tamJ);
#endif // INFORMES_H_INCLUDED
