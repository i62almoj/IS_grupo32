### Eliminar todos

**ID:** 5

**Breve descripción:** Se eliminan todos los alumnos de la base de datos.

**Actor principal:** Profesor.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. Debe existir la base de datos con la información.

**Flujo principal:**

1. El caso de uso empieza cuando el usuario necesita eliminar todos los alumnos de la base de datos.
2. El sistema carga la base de datos.

**Postcondiciones:**

* El sistema borra todos los alumnos de la base de datos.

**Flujos alternativos:**

2. a. Si la base de datos no existe o está vacía, la aplicación muestra un mensaje de error.
