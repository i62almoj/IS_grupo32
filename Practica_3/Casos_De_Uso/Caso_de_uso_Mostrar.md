### Mostrar

**ID:** 6

**Breve descripción:** Se elegirá si la búsqueda es de uno o varios alumnos, o de un grupo.

**Actor principal:** Profesor.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. Deben existir alumnos en la base de datos.

**Flujo principal:**

1. El caso de uso empieza cuando el usuario necesita visualizar los datos de un alumno o de varios de la base de datos.
2. El sistema pide el tipo de búsqueda.

**Postcondiciones:**

* Dependiendo de lo que haya elegido el usuario, el sistema mostrará los datos de todos los alumnos o pedirá algún dato para una búsqueda concreta.

**Flujos alternativos:**

2. a. Si el usuario introduce una opción incorrecta, la aplicación muestra un mensaje de error y vuelve al menú principal.
