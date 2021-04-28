/*
 * Yesid Colmenares
 * ESTRUCTURAS
 Una empresa importadora que comercializa alumnos Apple, decide registrar de sus alumnos los siguientes datos:
 idProducto (numerico)
 descripcion (alfanumérico)
 nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
 tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
 precio (numérico decimal)
 Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
 ALTA Producto: Se ingresan los datos de UN solo alumno. Siempre y cuando haya espacio disponible en el array.
 BAJA Producto: A partir del ingreso del ID. Si existe el alumno desaparece de la lista, dejando espacio disponible para un nuevo alumno.
 MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
 LISTADO Productos.
 LISTADO ordenado por precio.
 LISTADO ordenado por descripción.
 */

#include "funcionesMenuPrincipal/funcionesStructEAlumno.h"

#define tamannoAlumno 12
#define tamannoCurso 5

int main(void)
{
	setbuf(stdout, NULL);
	eAlumno alumno[tamannoAlumno];
	eCurso curso[tamannoCurso];
	int opcionIngresada;
	int opcionIDIngresado;

	inicializarEstadosAlumnos(alumno, tamannoAlumno);
	inicializarEstadosCursos(curso, tamannoCurso);
	do
	{
		printf("\n-------------------Bienvenidos a nuestros sistema de datos--------------------");
		printf("\n1. Alta Estudiante");
		printf("\n2. Baja Estudiante");
		printf("\n3. Modificacion Estudiante");
		printf("\n4. Listado Estudiantes");
		printf("\n5. Listado ordenado por Nota 1");
		printf("\n6. Listado ordenado por Nombre");
		printf("\n7. Configurar Base Datos Cursos");
		printf("\n8. Salir");
		ingresarIntR(&opcionIngresada, "\nIngresa la opcion: ", "\nError, ingresa la opcion: ", 1, 8);

		switch (opcionIngresada)
		{
			case 1:
				system("cls");
				altaEstudiantes(alumno, tamannoAlumno);
				break;

			case 2:
				system("cls");
				ingresarIntR(&opcionIDIngresado, "\nIngrese el numero ID: ", "\nError, ingresa el numero ID: ", 0, tamannoAlumno);
				bajarEstudiante(opcionIDIngresado, alumno, tamannoAlumno);
				break;

			case 3:
				system("cls");
				ingresarIntR(&opcionIDIngresado, "Ingrese 1 si quieres modificar el nombre, \n ingrese 2 si quieres modificar la nota 1, ingrese 3 si quieres modificar la nota 3 ",
						"Error, Ingrese 1 si quieres modificar el nombre, \n ingrese 2 si quieres modificar la nota 1, \n ingrese 3 si quieres modificar la nota 3: ", 1, 3);
				if (opcionIDIngresado == 1)
				{
					system("cls");
					ingresarInt(&opcionIDIngresado, "\nIngresa el ID a modificar: ", "\nError, Ingresa el ID a modificar: ");
					modificarNombre(opcionIDIngresado, alumno, tamannoAlumno);
				}
				else
				{
					if (opcionIDIngresado == 2)
					{
						system("cls");
						ingresarInt(&opcionIDIngresado, "\nIngresa el ID a modificar: ", "\nError, Ingresa el ID a modificar: ");
						modificarNotaUno(opcionIDIngresado, alumno, tamannoAlumno);
					}
					else
					{
						system("cls");
						ingresarInt(&opcionIDIngresado, "\nIngresa el ID a modificar: ", "\nError, Ingresa el ID a modificar: ");
						modificarNotaDos(opcionIDIngresado, alumno, tamannoAlumno);
					}
				}
				break;

			case 4:
				system("cls");
				imprimirAlumnos(alumno, tamannoAlumno);
				break;

			case 5:
				system("cls");
				ordenarVector(alumno, tamannoAlumno, 1);
				imprimirAlumnos(alumno, tamannoAlumno);
				vectorOriginal(alumno, tamannoAlumno);
				break;

			case 6:
				system("cls");
				ordenarVector(alumno, tamannoAlumno, 2);
				imprimirAlumnos(alumno, tamannoAlumno);
				vectorOriginal(alumno, tamannoAlumno);
				break;

			case 7:
				system("cls");
				do
				{
					printf("\n----------------Configuracion de la base de datos del curso-------------------");
					printf("\n1. Alta curso");
					printf("\n2. Baja curso");
					printf("\n3. Modificacion curso");
					printf("\n4. Listado curso");
					printf("\n5. Listado ordenado por duracion de la carrera");
					printf("\n6. Listado ordenado por nombre de la carrera");
					printf("\n7. Volver al menu principal");
					ingresarIntR(&opcionIngresada, "\nIngresa la opcion: ", "\nError, ingresa la opcion: ", 1, 8);
					switch (opcionIngresada)
					{
						case 1:
							system("cls");
							altaCurso(curso, tamannoCurso);
							break;

						case 2:
							system("cls");
							ingresarIntR(&opcionIDIngresado, "\nIngrese el numero ID: ", "\nError, ingresa el numero ID: ", 0, tamannoAlumno);
							bajarCurso(opcionIDIngresado, curso, tamannoCurso);
							break;

						case 3:
							system("cls");
							ingresarIntR(&opcionIDIngresado, "Ingrese 1 si quieres modificar el nombre del curso, \n ingrese 2 si quieres modificar la duracion del curso: ",
									"Error, Ingrese 1 si quieres modificar el nombre del curso, \n ingrese 2 si quieres modificar la duracion del curso:  ", 1, 2);
							if (opcionIDIngresado == 1)
							{
								system("cls");
								ingresarInt(&opcionIDIngresado, "\nIngresa el ID a modificar: ", "\nError, Ingresa el ID a modificar: ");
								modificarNombreCurso(opcionIDIngresado, curso, tamannoCurso);
							}
							else
							{
								system("cls");
								ingresarInt(&opcionIDIngresado, "\nIngresa el ID a modificar: ", "\nError, Ingresa el ID a modificar: ");
								modificarDuracionCurso(opcionIDIngresado, curso, tamannoCurso);
							}
							break;

						case 4:
							system("cls");
							imprimirCursos(curso, tamannoCurso);
							break;

						case 5:
							system("cls");
							ordenarVectorCurso(curso, tamannoCurso, 1);
							imprimirCursos(curso, tamannoCurso);
							vectorOriginalCurso(curso, tamannoCurso);
							break;

						case 6:
							system("cls");
							ordenarVectorCurso(curso, tamannoCurso, 2);
							imprimirCursos(curso, tamannoCurso);
							vectorOriginalCurso(curso, tamannoCurso);
							break;

						case 7:
							system("cls");
							opcionIngresada = 7;
							break;
					}
				} while(opcionIngresada != 7);

				break;

			case 8:
				system("cls");
				opcionIngresada = 8;
				break;
		}
	} while (opcionIngresada != 8);
}
