

## Que es git

*Sistema para el control distribuido de versiones
de coodigo. Fundamentalmente permite:*
1. Dar seguimiento a los cambios realizados sobre un 		archivo.

2. Almacenar una copia de los cambios

## Configuracion Basica

##### Nombre del administrador
`git config -- global user . name " Juan Manuel Álvarez Morales"`

##### Correo electronico
`git config -- global user . email i62almoj@uco .es`

##### Editor de texto
`git config -- global core . editor " gedit "`

##### Color de la interfaz:
`git config -- global color .ui true`

##### Listado de la configuración:
`git config --list`

## Comandos básicos 1

##### Iniciar repositorio en un directorio:
`git init`

##### Agregar cambios al area de staging :
`git add`

##### Validar cambios en el repositorio:
`git commit -m " Mensaje "`

##### Hacer los dos pasos anteriores en uno:
`git commit -am " Mensaje "`

##### Historial de commits:
`git log`

## Comandos básicos 2

##### Ayuda del listado anterior:
`git help log`

##### Listar los 5 commits mas recientes:
`git log -n 5`

##### Listar los commits desde una fecha:
`git log --since =2018 -09 -18`

##### Listar los commits por autor:
`git log -- author =" Juanma"`

##### Ver cambios en el directorio:
`git status`

## Ver Comandos Basicos 3

##### ver diferencia entre ficheros en el directorio y el repositorio de git
`git diff`

##### ver diferencia entre los ficheros en el staging y el repositorio
`gis diff --staged`

##### Eliminar archivos
`git rm archivo`
`git commit -m "mensaje"

##### mover o renombrar archivos
`git mv antiguo nuevo`
`git commit -m "mensaje"`

## Comandos Basicos 4

##### Deshacer cambios con git
`git checkout --nombre_fichero`

##### Retirar archivos del staging
`git reset HEAD nombre_fichero`

##### Complementar ultimo commit
`git commit --amend -m "mensaje`

##### Recuperar version de un fichero de commit antiguo
`git checkout <id_commit> -- nombre_archivo'

##### Revertir un commit
`git revert <id_commit>`

## Comandos Basicos 5

##### Listar el contenido del repositorio de git
`git ls-tree master`
`git ls-tree master^^^`
`git ls-tree master~3`

##### Log en una linea
`git log --oneline`

##### Log con los tres ultimos commit en una linea
`git log --oneline -3`

###### Para mas opciones consultar documentacion de git.

## Comandos basicos 6

##### Deshacer multiples cambios en el repositorio
`git reset --soft <id_commit>`
`git reset --mixed <id_commit>`
`git reset -- hard < id_commit>`

##### Listar archivos que git no controla
`git clean -n`

##### Eliminar archivos que git no controla
`git clean -f`

## Comandos basicos 7

##### Examinar el contenido de un commit
`git show <id>`
##### Comparar un commit con el actual
'git diff <id> nombre_archivo`

##### Comparar dos commits
`git diff id..id nombre_archivo`
###### Ignora archivos en el repositorio .gitignore
