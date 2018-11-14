### Eliminar alumno

**ID:** 4

**Breve descripción:** Se elimina un alumno de la base de datos.

**Actor principal:** Profesor.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El alumno debe existir en la base de datos.

**Flujo principal:**

1. El caso de uso empieza cuando el usuario necesita eliminar un alumno de la base de datos.
2. El sistema pide los datos del alumno a eliminar.

**Postcondiciones:**

* El sistema borra el alumno de la base de datos.

**Flujos alternativos:**

2. a. Si el alumno no existe, la aplicación muestra un mensaje de error y el sistema vuelve al menú principal.
