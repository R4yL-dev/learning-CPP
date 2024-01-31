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

## ex02

