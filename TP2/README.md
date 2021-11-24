# INSA-TP2_Cpp

## Guide de style

Le projet suit le [guide de style C++ de Google](https://google.github.io/styleguide/cppguide.html)
et [celui de l'INSA](doc/GuideDeStyle_INSA.md), les deux étant compatibles.\
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

## Debug

Construire l'exécutable avec les affichages de debug définis dans la macro `MAP` :

```bash
$ make debug
```

Lancer l'exécutable :

```bash
$ ./main.out
```

## Tests

L'interface [acutest](https://github.com/mity/acutest) est utilisée pour améliorer l'affichage des tests unitaires.

Construire l'exécutable de test :

```bash
$ make test
```

Lancer les tests :

```bash
$ ./test.out -v
```
