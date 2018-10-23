### Eliminar

**ID:** 3

**Breve descripción:** Se elegirá si la búsqueda es de uno o varios alumnos.

**Actor principal:** Profesor.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. Deben existir alumnos en la base de datos.

**Flujo principal:**

1. El caso de uso empieza cuando el usuario necesita eliminar los datos de un alumno o de todos de la base de datos.
2. El sistema pide el tipo de búsqueda.

**Postcondiciones:**

* Dependiendo de lo que haya elegido el usuario, el sistema eliminará los datos de todos los alumnos o pedirá algún dato para una eliminación concreta.

**Flujos alternativos:**

2. a. Si el usuario introduce una opción incorrecta, la aplicación muestra un mensaje de error.
