### Modificar alumno

**ID:** 2

**Breve descripción:** Se modifican los datos de un alumno de la base de datos.

**Actor principal:** Profesor.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El alumno debe existir en la base de datos.

**Flujo principal:**

1. El caso de uso empieza cuando el usuario necesita modificar un alumno de la base de datos.
2. El sistema pide los datos a cambiar del alumno.

**Postcondiciones:**

* El sistema guarda la nueva información del alumno.

**Flujos alternativos:**

2. a. Si el alumno no existe, la aplicación muestra un mensaje de error.
