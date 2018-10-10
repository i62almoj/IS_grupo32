# Problema a resolver

El profesorado de la asignatura de Ingeniería del Software quiere informatizar los datos de contacto de los alumnos en un programa informático que guarde esta información.

### PARTES INTERESADAS

**Profesor**

**Alumnos**


### DATOS DE LA APLICACIÓN

* DNI
* NOMBRE
* APELLIDOS
* TELÉFONO
* EMAIL CORPORATIVO
* DIRECCIÓN
* CURSO MÁS ALTO MATRICULADO
* FECHA DE NACIMIENTO
* GRUPO DE TRABAJO
* LÍDER
* NOTAS

### REQUISITOS FUNCIONALES

1. Añadir un alumno.
2. Modificar alumno.
3. Eliminar alumno.
4. Buscar alumno.
5. Mostrar todos los alumnos.
6. Mostrar alumnos de un grupo.


### REQUISITOS NO FUNCIONALES

** El formato del fichero de la base de datos será binario. **
** El lenguaje de programación usado será C++. **

##### Añadir Alumno
* Todos los datos de la aplicación son obligatorios, excepto ** líder ** y ** notas **
* Solo puede haber un líder por grupo.
* Número máximo de alumnos: 150.
* Manualmente o cargar de una base de datos.

##### Modificar Alumno
* Usar DNI o apellidos

##### Eliminar Alumno
* Usar DNI o apellidos.
* Si la búsqueda es por apellido y hay alumnos con el mismo, se muestran ambos y solicitamos al usuario el DNI del alumno que desea borrar.

##### Buscar Alumno
* Usar DNI, apellido o email.
* Si la búsqueda es por apellido y hay alumnos con el mismo, se muestran ambos.

##### Mostrar todos los alumnos

** Ordenar: **

* Alfabéticamente
 * Por nombre
 * Por apellido

* Por DNI (sin letra)

* Por curso más alto

* Por grupo

** Mostrar: **

* Al mostrar el líder de un equipo se verá de forma especial.

* Por línea de comandos (obligatorio)

* Generar un fichero HTML

*Todo esto se podrá ordenar de forma ascendente o descendente*


