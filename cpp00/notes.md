# Notes

## ex00

### String

Le type *std::string* est un type qui est fournit pas la bibliothèque *string*. Cette classe permet de gérer les strings beaucoup plus facilement qu'en C.

Il existe plein de méthode que nous pouvons utiliser sur les strings. Par exemple, dans la fonction *strToUpper()* utilise la méthode *length().* de la classe *string*.

Nous pouvons aussi remarquer que nous n'avons pas eu besoin de gérer la mémoire pour la *string*. Nous n'avons ni réservé de mémoire, ni libérer la mémoire utilisée par la string. C'est la magie de C++ ! Ce travail est fait pour nous par la bibliothèque *string*. Elle se charge de réservé la mémoire lors de la création de la *string* puis elle elle la libère à la fin du scoop quand la string est détruite.

Voici ce que dit *valgrind* lorsque j'appel le binaire avec aucun argument. On peu voir que 3 allocations ont été faite et qu'elle ont toute été frees. Ce travail a été fait pour moi.

```text
==29577== Memcheck, a memory error detector
==29577== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29577== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==29577== Command: ./megaphone
==29577==
* LOUD AND UNBEARABLE FEEDBACK NOISE *
==29577==
==29577== HEAP SUMMARY:
==29577==     in use at exit: 0 bytes in 0 blocks
==29577==   total heap usage: 3 allocs, 3 frees, 73,767 bytes allocated
==29577==
==29577== All heap blocks were freed -- no leaks are possible
==29577==
==29577== For lists of detected and suppressed errors, rerun with: -s
==29577== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### String stream

Afin de réunir tous les membres de *argv* en une seul *string*, j'ai utilisé un *stringstream*. Un *string stream* est un *stream* que nous pouvons manipuler et que nous pouvons infine transformer en *string*. Cela est très utile pour cette exercice, car il nous permet de créer un *stream*, de parcourir *argv* et mettre chacun de ces élément dans le *stream* avec l'opérateur *<<*. Une fois que tous les éléments de *argv* ont été ajouté dans le stream, nous pouvons stocker la string qui le compose grace à la méthode *str()*.

Maintenant que nous avons tous les éléments de *argv* dans une seule string, il ne reste plus qu'a la mettre en majuscule. Pour ce faire, j'ai créer une fonction *strToUpper()* qui parcoure tous le message caractère par caractère et qui ajoute le caractère en majuscule à la string.

Pour utiliser les *stream string*, nous devons inclure la bibliothèque *sstream*.

### cout

*cout* qui est définit pas la bibliothèque *iostream* représente la sortie standard. *cout* est un *stream* nous pouvons donc utiliser les opérateur *<<* et *>>* pour interagir avec, cela veux aussi dire que nous pouvons chainer les opération. Vu que *cout* représente la sortie standard, tout se que nous mettrons dans ce *stream* sera affiché à l'écran.

A la fin d'une ligne, il m'arrive d'utiliser *std::endl*. *endl* ajoute une *\n* pour revenir à la ligne. En plus de cela il flush le buffer. C'est à dire, qu'il affiche à l'écran tout ce qu il y a dans le buffer de sortie.

## ex01

Cette exercie est le premier dans le quel je sépare la définition (fichier .hpp) et l implémentation (fichier .cpp) de mes classe. Nous allons maintenant appliquer cette structure pour toute nos classe. Cela permet de separer et de parcourir le code de façon plus claire.

Nous ne devons jamais implementer de code dans les fichier header. Son but est de contenir le prototype de la classe ainsi que les prototypes des methodes de la classe.

### getline

L utilisateur doit pouvoir entrer des commande. Pour se faire, nous devons interagir avec *std::cin*. Afin de pouvoir gerer facilement la saisie d une ligne complete par l utilisateur, *iostream* nous mette a disposition la methode *getline()*. En utilsant cette fonction, nous n avons pas besoin de reflechir au caractere *\n* qui est recu lorsque l utilisateur fait *Enter*.

### iomanip

Le sujet demande que les données sur les contacte affichée lors d un SEARCH soit affiché dans des colones de 10 caractères. Pour se faire, j ai utiliser la methode `std::setw()`. Il fallait aussi trouver une solution pour tronquer les données qui comportait plus de 10 caractères. Pour se faire, j ai creer une fonction *truncate* :

```c++
std::string	PhoneBook::truncate(const std::string &str, size_t width) const
{
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	return str;
}
```

## ex02

### Time

Afin de pouvoir afficher l horodatage, il a fallu utiliser des fonctions pour pouvoir calculer le temps ecouler. Pour faire ces manipulations sur le temps, j ai utiliser des fonction fournie par la bibliotheque *ctime*.

`std::time_t now = std::time(0);` : la fonction *time* permet de recuperer le temps en second eecouler depuis le 1er janvier 1970 (timestamp).

`std::tm *localtm = std::localtime(&now);` : J utilise la fonction *localtime()* afin de convertir le timestamp *now* en une structure de donnees qui est plus facile a traiter. Cette structure contient les informations comme par exemple : l année, le mois, ect...

Pour afficher l année, j utilise `localtm->tm_year + 1900`. Ici, nous devons ajouter 1900 car tm_years contient le nombre d année ecoulée depuis 1900. Afin d avoir l année, il faut donc ajouter 1900.

Pour le mois (localtm->tm_mon + 1), nous devons ajouter 1 car les mois sont indexer a partir de 0.

Tout se formatage affiche la date sous forme *[YYYYMMDD_HHMMSS]*.

### setfill

Pour afficher l horodatage, j utilise la fonction `setfill('0')`. Cette fonction permet de remplir un champ avec le caractere passer en argument. Cela permet d afficher correctenment les informations si elles sont moins grande que la taille du champ.
