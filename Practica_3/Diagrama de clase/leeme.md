### EXPLICACIÓN DE DIAGRAMA DE CLASES

Un diagrama de clase muestra las clases, el sistema, atributos, métodos y relaciones entre ellos.
Una clase es una categoría o grupo de cosas que tienen unos atributos y realizan unas acciones.
En nuestro caso tenemos 3 clases:

1. Alumno
* Identifica a los alumnos registrados en el sistema.
* Se relaciona con Agenda mediante una agregación (Alumno forma parte de Agenda).
* Un alumno pertenece a una agenda.

2. Agenda
* Contiene a los alumnos del sistema.
* Se relaciona con Alumno mediante una agregación (Alumno forma parte de Agenda).
* Se relaciona con Profesor mediante una asociación (relación estática).
* Una agenda tiene 0 o varios alumnos.
* Una agenda pertenece a uno o varios profesores.

3. Profesor
* Identifica a los profesores.
* Se relaciona con Agenda mediante una asociación (relación estática).
* Un profesor tiene una única agenda.
