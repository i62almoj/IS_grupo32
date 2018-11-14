### Añadir alumno

**ID:** 1

**Breve descripción:** Se añade uno o varios alumnos a la base de datos.

**Actor principal:** Profesor.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El alumno no debe existir en la base de datos.
2. El número máximo de alumnos es 150.

**Flujo principal:**

1. El caso de uso empieza cuando el usuario necesita agregar un alumno a la base de datos.
2. El sistema pide los datos del alumno.

**Postcondiciones:**

* El sistema guarda la información obtenida del alumno.

**Flujos alternativos:**

2. a. Si el alumno ya existe, la aplicación muestra un mensaje de error y el sistema vuelve a pedir los datos.
2. b. Si ya hay 150 alumnos en la base de datos, la aplicación muestra un mensaje de error y el sistema vuelve al menú principal.
