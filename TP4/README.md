# INSA C++ - TP n°4

## Sujet

Création d'un programme d'analyse de logs Apache permettant de générer le classement
des pages les plus demandées ainsi qu'un graphe de parcours en
[langage DOT](https://fr.wikipedia.org/wiki/DOT_(langage)).

## Configuration

Le projet nécessite un fichier de configuration à la racine (`.env` par défaut) contenant
les variables suivantes :

```bash
FORMAT_DATE=%d/%b/%Y:%H:%M:%S
DOMAINE=http://mon-domaine.fr
```

* `FORMAT_DATE` : le format de la date et de l'heure des logs
([liste des paramètres](https://en.cppreference.com/w/cpp/io/manip/get_time#Parameters))
* `DOMAINE` : le nom de domaine à enlever des pages référentes pour construire
le graphe de parcours

## Compilation

Construire et lancer l'exécutable du programme :

```bash
make
./analog fichier.log
```

## Debug

### Programme

Construire l'exécutable avec les affichages de debug définis dans la macro `MAP` :

```bash
make clean
make debug
./analog fichier.log
```

### Mémoire

Utilisation de [Valgrind](https://en.wikipedia.org/wiki/Valgrind) :

```bash
make
valgrind ./analog fichier.log
```

## Utilisation

```bash
./analog [-e] [-g fichier.dot] [-t heure] fichier.log
```

| Option | Description                                                            | Type   |
|--------|------------------------------------------------------------------------|--------|
| -e     | exclut les documents qui ont une extension de type image, CSS ou JS    |        |
| -t     | exclut les logs n'étant pas dans l’intervalle horaire [heure, heure+1[ | int    |
| -g     | produit un fichier au format DOT du graphe de parcours des logs        | string |

Le fichier d'entrée doit contenir un log par ligne au format suivant :

```
127.0.0.0 - - [08/Sep/2012:11:16:07 +0200] "GET /temps/4IF20.html HTTP/1.1" 200 5185 "http://intranet-if.insa-lyon.fr/temps/4IF19.html" "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1"
```

## Exemples

```bash
# affiche dans la console les 10 ressources les plus demandées
./analog meslogs.log

# affiche dans la console les 10 ressources les plus demandées n'étant pas des images, du CSS ou du JS
./analog -e meslogs.log

# affiche dans la console les 10 ressources les plus demandées n'étant pas des images, du CSS ou du JS
# et ayant été demandées entre 15h et 16h
./analog -e -t 15 meslogs.log

# génère un fichier contenant le graphe de parcours au format DOT des ressources n'étant pas des images,
# du CSS ou du JS et affiche les 10 plus demandées dans la console
./analog -g sortie.dot -e meslogs.log
```

## Guide de style

Le projet suit le [guide de style C++ de Google](https://google.github.io/styleguide/cppguide.html)
et [celui de l'INSA](https://github.com/JorickPepin/INSA-TP_Cpp/blob/main/TP2/doc/GuideDeStyle_INSA.md),
les deux étant compatibles.\
Il est préférable d'utiliser un linter comme [cpplint](https://github.com/cpplint/cpplint) pour
vérifier si le code suit ces conventions.

Installation de cpplint avec pip :

```bash
$ pip install cpplint
```

Exemples d'utilisation :

```bash
$ cpplint src/main.cpp
$ cpplint --recursive src/
```
