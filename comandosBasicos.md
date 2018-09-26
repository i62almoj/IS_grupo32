

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
`git config --list``

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



