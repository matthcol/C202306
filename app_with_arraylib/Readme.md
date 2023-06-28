# Compilation utilisant une librairie

# Compilation séparée
- -I DIR : répertoire include où chercher des fichiers headers
- -i PATH_HEADER : chemin vers un fichier header

# Edition des liens
- -L DIR : répertoire lib où chercher des librairies statitiques ou dynamiques
- -llibrary, -l library, -l:libarray.a : librairie à utiliser
- -static : inclut toutes les librairies dans le binaire (y compris glibc) ;
    force l'utilisation d'une librairie statique à la place d'une dynamique