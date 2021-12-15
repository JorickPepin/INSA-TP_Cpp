# Guide de style INSA

Ce document contient une synthèse du guide de style présenté dans le
cours de programmation en C++.

## Présentation

### Général 

* Pour des problèmes d’impression et de facilité de lecture dans une
fenêtre, limiter la longueur des lignes (~ 80 caractères).

* Placer les `#` des directives du préprocesseur en première
colonne afin qu’ils soient nettement visibles (pas d’indentation).

* Déclarer une seule variable par ligne et en profiter pour expliciter
son rôle.

* Lorsqu’une instruction comme `if` ou `for` ne porte que sur une
seule instruction simple et non sur un bloc, placer des accolades même
si ce n’est pas nécessaire.

* N’écrire qu’une seule instruction par ligne. Ne pas utiliser
l’opérateur `,` pour exécuter plusieurs instructions.

* Mettre les imbrications des instructions en valeur par indentation
et aligner les ouvertures et fermetures de blocs.

* Signaler les instructions `for` qui ne comportent pas de bloc.

### Formes algorithmiques

* Les formes algorithmiques sont suffisamment riches : exclure
toute utilisation du branchement inconditionnel `goto`.

* Pour une boucle infinie, ne pas écrire `while(true)` mais
`for( ; ; )`.

* Placer une instruction `break` à la fin de chaque case, surtout du
dernier, en cas d’ajout ultérieur.
Il est également judicieux de commenter l’absence de `break` pour
distinguer l’omission involontaire de l’absence effectivement voulue.

* Dans le cas d’une sélection portant sur une variable de type
énuméré, traiter explicitement tous les cas.
Ne pas placer de cas `default` pour pouvoir contrôler que toutes les
valeurs possibles sont traitées correctement, en particulier lors de
l’ajout d’une nouvelle valeur dans le type.

## Noms et typographie

* Tous les objets doivent porter un nom rappelant leur signification.
Il n’est pas utile que le nom rappelle le type de l’objet.

* Ne pas donner à un objet le même nom qu’un autre objet du
même espace de nommage (attribut <-> paramètre).

* Ne pas commencer de nom par un blanc souligné ("_")
(recommandations ANSI).

* Dans les noms composés de plusieurs mots, mettre une
majuscule en tête de chaque mot pour faciliter la lecture.

* Écrire les noms de constantes et les valeurs de types énumérés
en lettres majuscules.

* Commencer les noms des objets publics et des types par une
majuscule, et les noms des objets protégés et privés par une
minuscule.

* Réserver les variables d’une seule lettre pour de simples indices
de boucle n’ayant pas de signification particulière ou pour des variables
de manœuvre temporaires.

* Convention d'écriture : 

|                       | Public          | Protégé - Privé |
|-----------------------|-----------------|-----------------|
| Constante             | NB_MAX          | NB_MAX          |
| Type (typedef, enum…) | CollectionTriee | CollectionTriee |
| Classe                | Noeud           | Noeud           |
| Variable / Attribut   | NombreElements  | nombreElements  |
| Fonction / Méthode    | IsolerMot       | isolerMot       |

## Commentaires

* Expliquer les passages de l’algorithme au code ne présentant
pas un caractère évident. Un commentaire doit expliquer et non
dupliquer.
La mise en page doit faciliter la lecture du code et des commentaires
associés. Les commentaires noyés dans le code sont de moindre
intérêt.

* Lorsque le `#endif` (ou le `#else`) est éloigné du `#if`, préciser la
correspondance par un commentaire.

## Longueur du code

* Ne pas s’acharner à écrire du code très court (illisible), mais ne
pas le décomposer sans fin non plus et ne pas introduire de code
inutile.

* Entre code élaboré et rustique, choisir la compréhensibilité et la
simplicité.

## Mise au point et test

* Tester séparément chacune des parties du programme en
réalisant si besoin un programme de test dédié, puis tester l’ensemble.
Apporter un maximum de soins à la construction du jeu d’essai.

## Constantes et macro-définitions

* Pour définir les constantes, préférer au préprocesseur
(`#define`) les formes `const` et `enum` dont la portée est plus facile à
contrôler.

* Ne pas utiliser les macro-définitions et les remplacer par des
méthodes en ligne (`inline`).

* Définir les constantes ayant un rapport entre elles dans un `enum`.

* Limiter la portée des constantes au strict nécessaire : mettre
dans la réalisation et non dans l’interface les constantes uniquement
utilisées dans la réalisation, et déclarer ces constantes `static`.

* Définir toutes les constantes du programme par des littéraux.

## Structures

* N’utiliser les structures (`struct`) que pour grouper des données, ce qui
est assez rare. Si ces données nécessitent des méthodes, ou si elles
doivent être initialisées, définir une classe.

## Expressions

* Programmer avec le type booléen et non le type entier pris comme
booléen (cas du C).

## Globaux

* Ne pas utiliser de global commun à plusieurs classes.

## Organisation

* Distinguer dans chaque classe la partie interface (.h)
qui est exportée de la partie réalisation (.cpp) qui est privée.

* Construire de petites classes bien ciblées et à la sémantique
cohérente plutôt qu’une grande classe qui fait tout.

## Constructeur

* Chaque constructeur doit initialiser tous les attributs de l’objet
-> état stable et connu pour un objet.

* Le constructeur doit allouer lui-même toutes les zones
dynamiques de l’objet.

* Une classe dont un attribut est alloué dynamiquement dans le
constructeur doit avoir un constructeur de copie et doit définir
l’opérateur d’affectation (cf. [Forme canonique](#forme-canonique)).

## Destructeur

* Le destructeur doit libérer toutes les zones allouées dans le
constructeur.

* La destruction de tous les objets créés est impérative pour que la
place mémoire soit récupérée. Pour s’en assurer, on pourra compter
les créations et les destructions de toutes les instances de la classe et
de ses descendantes.

* Pour autoriser les descendants à exécuter leur propre
destructeur, il faut toujours déclarer un destructeur et de plus il faut le
déclarer `virtual`.

## Attribut

* Ne pas déclarer d’attribut public.

* Ne pas initialiser un attribut par l’intermédiaire d’un autre attribut.

* Ne pas rendre systématiquement les attributs accessibles
publiquement et surtout ne pas fournir systématiquement de méthodes
pour les modifier (`Get` et `Set`).

## Forme canonique

* Définir au minimum les méthodes de la forme canonique afin de
pouvoir manipuler un objet d’une classe de façon similaire à un objet
d’un type de base.

* Toujours définir un constructeur de copie et un opérateur
d’affectation.

* Définir un constructeur de copie erroné lorsque son utilisation est
illicite (déclaration sans définition). La même chose peut être réalisée
pour l’opérateur d’affectation.

## Déclaration des méthodes

* L’en-tête de chaque méthode publique contient une description
de la fonction réalisée citant tous les paramètres de l’en-tête et
précisant les valeurs de retour.

* Déclarer les méthodes avec le statut `const` si elles ne modifient
pas les attributs de l’objet afin de permettre leur utilisation sur des
objets `const`.

* Ne pas utiliser le passage par valeur pour les classes sans
besoin justifié (problème de coût).

## Pointeur

* Dans une méthode ne pas écrire `this->attribut` ou
`this->méthode` puisque tout accès aux attributs et méthodes est
sous-entendu "de la classe".

* Une méthode ne doit pas détruire un objet passé en paramètre
sinon l’appelant se retrouve avec un objet inutilisable.
