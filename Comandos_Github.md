#GitHub no es Git

GitHub es un servicio de alojamiento que ofrece a los desarrolladores repositorios de software usando el sistema de control de versiones, Git.

Existen varios aspectos que hacen que GitHub sea una opción eficiente para el control y gestión de tus proyectos.

Estos son algunos de ellos:

* Permite que puedas compartir tus proyectos de una forma mucho más fácil.

* Te permite colaborar para mejorar los proyectos de otros y a otros mejorar o aportar a los tuyos.

* Ayuda reducir significativamente los errores humanos, a tener un mejor mantenimiento de distintos entornos y a detectar fallos de una forma más rápida y eficiente.

* Es la opción perfecta para poder trabajar en equipo en un mismo proyecto.

![Github](imagen/Github.png)

# Comandos GitHub I

#### Añadir repositorio remoto:

`git remote add origin url`

#### Ver repositorios remotos:

`git remote -v`

#### Eliminar repositorio remoto:

`git remote rm origin`

#### Añadir cambios del repositorio local al remoto:

`git push -u origin master`

#### Añadir cambios del repositorio remoto al local:

`git pull`


#Comandos GitHub II

#### Ver branches remotos:

`git branch -r`

#### Ver todos los branches:

`git branch -a`

#### Clonar un repositorio remoto:

`git clone url`


# Dar seguimiento a *branches* remotos:

* **LOCAL -> REMOTO**

 1. Cambios en el repositorio local.
 2. Commit de los cambios.
 3. Añadir cambios al repositorio remoto:

 `git push`

* **REMOTO -> LOCAL**

 * Sincronización y unión:

 `git fetch origin`

 `git merge/origin master`

 * En un solo paso:

 `git pull`


# Operaciones con *branches* remotos:

* **Creación**

 1. Crear branch local.

 2. Hacer cambios en dicho branch.
 3. Hacer commit.
 4. Copiar el branch al repositorio remoto:

 `git push -u origin branch_remoto`

* **Copia:**

 `git chekout -b local remoto`

* ** Eliminación:**

 `git push origin --delete branch_remoto`
