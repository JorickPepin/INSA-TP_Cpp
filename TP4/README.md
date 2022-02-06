# INSA C++ - TP n°4

## Sujet

Création d'un programme d'analyse de logs Apache permettant de générer le classement
des pages les plus demandées ainsi qu'un graphe de parcours en
[langage DOT](https://fr.wikipedia.org/wiki/DOT_(langage)) à partir d'un fichier de logs. 

## Configuration

Le projet nécessite un fichier de configuration à la racine (`.env` par défaut) contenant
les variables suivantes :

```bash
FORMAT_DATE=%d/%b/%Y:%H:%M:%S
DOMAINE=http://mon-domaine.fr
```

* `FORMAT_DATE` : le format de la date et de l'heure des logs
* `DOMAINE` : le nom de domaine de base à enlever des pages référentes pour construire
le graphe de parcours

## Exemples

TODO
