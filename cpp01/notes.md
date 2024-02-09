# Notes

## Ex00

### new /delete

Pour la première fois dans cet exercice, nous devons utiliser les mots clé *new* et *delete*. Ils sont l'équivalent de *malloc()* et *free()*. Ils sont la manière CPP d interagir avec le heap.

La syntaxe de *new()* est `obj *obj_ptr = new obj`. *new()* se charge de réserver le bon nombre de mémoire en fonction de la taille de l objet a stocker sur la heap.

*CPP* n’élimine pas les problèmes de fuite de mémoire. Quand nous utilisons le mot cle *new*, c'est à nous d'appeler *delete* quand nous voulons libérer la mémoire. La syntaxe est très simple. Il suffit de taper `delete <obj>`.

## Ex01

### new array et delete[]

Dans cet exercice, il nous est demandé de créer un tableau de pointeur sur objet sur la heap. Pour se faire, nous devons utiliser *new* et *delete* mais avec une syntaxe un petit peu différentes.

```cpp
horde = new Zombie[n];
```

Ici, nous réservons en mémoire un tableau de *n* pointer sur *Zombie*. Ce qui fait que c'est l'allocation d un tableau et non pas d'un simple objet et l utilisation des *[]* afin de spécifier le nombres de pointeur que nous voulons stocker.

Vu que nous utilisons *new* pour allouer notre tableau, nous devons aussi le mot-clé *delete* afin de libérer la mémoire et pas créer de fuite. Pour utiliser *delete* sur un tableau, nous devons ajouter les *[]*, `delete[] <array>`.

### check bad alloc

Comme en *C*, c est une bonne pratique de vérifier que l allocation de la mémoire a bien pu être faite par l'OS. Pour se faire, nous pouvons utiliser les exceptions et le bloque *try / catch*.

```cpp
	try
	{
		horde = new Zombie[n];
		for (int i = 0; i < n; ++i)
		{
			horde[i].setName(name);
		}
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << "bad_alloc caught: " << e.what() << '\n';
		return NULL;
	}
```

Ici, nous exécutons nos *new* dans un bloque *try*. Si une exception est lev par le code exécuter dans le bloque *try*, elle pourra être capturée et donc traité dans le bloque *catch*. Ici, notre bloque *catch* essaye de capturer une exception *bad_alloc* et si elle survint,  stock l exception dans une variable *e*.

Ici, nous faisons une utilisation très simple des exceptions et du bloque *try / catch*. Nous verrons plus en profondeur son utilisation dans la suite de l apprentissage du CPP.

## Ex02

Cette exercice est là pour présenter la différence entre les *pointer* et les *references*.

Une reference se comporte dans beaucoup de cas comme un pointeur, la logique est la même, cela permet de stocker l'address vers un élément en mémoire.

La différence entre un pointer et une ref et qu'une ref ne peu pas pointer sur rien (*NULL*) et une reference ne peu pas changer d'adresse sur la quel elle point une fois que l initialisation est fait.

En gros, une reference est un pointeur constant sur une adresse non NULL.

## Ex03

Cet exercice nous permet de mettre en pratique les *pointeur* et les *reference*. Nous devons faire deux class *Human* plus ou moins similaire. La différence est que une classe dois absolument prendre une arme lors de sa creation (reference car une reference ne peu pas être NULL) alors que l autre doit pouvoir être créée sans avoir d arme (*pointeur* car un pointer peu pointer sur NULL).

## Ex04

### ifstream

*ifstream* signifie *input file stream* c'est un objet qui permet donc de lire depuis un fichier.

```c++
#include <fstream>
#include <iostream>

int main() {
	std::ifstream file(<path>); // Ouverture du fichier en lecture.
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}
		file.close();
	}
	std::cout << "cannot open file\n";
	return 0;
}
```

Dans cet exemple, je crée un objet *ifstream* en lui passant en paramètre le chemin. Ensuite, je vérifie que le fichier est bien ouvert grâce a la méthode *.is_open()* de l'instance *ifstream*. Nous affichons toute les lignes du fichier grâce a *getline()* de *iostream*. Pour fermer le fichier, il nous suffit d'appeler la méthode *close()* de l objet *ifstream*. Il n est pas forcement utile de fermer le fichier car il sera automatiquement close a la fin du scoop grâce au destructeur de la class *ifstream*, il est quand même possible de le fermer manuellement si besoin comme je viens de le montrer.

### ofstream

*ofstream* est un objet qui permet d’écrire dans un fichier. C est un acronyme pour *output file stream*.

```cpp
#include <fstream>
#include <iostream>

int main() {
	std::ofstream file(<path>); // Ouverture du fichier en écriture
	if (file.is_open()) {
		file << "This string will be in the file !" << std::endl;
		file.close();
	}
	else {
		std::cout << "cannot open file" << std::endl;
	}
	return 0;
}
```

Ici, nous écrivons une phrase dans notre fichier ouvert. Nous pouvons remarquer que l'utilisation de *ofstream* est très similaire a l'utilisation de *ifstream*. Nous l'ouvrons de la même manière (en passent notre chemin au constructeur de *ofstream*) et nous utilisons les mêmes méthodes.

### ostringstream

Comme nous l'avons déjà vu, une *ostringstream* est un moyen de créer des chaînes de caractères en mémoire comme dans un fichier sans avoir besoin d'ouvrir ou de créer un fichier.

Dans l'ex03, j utilise un *ostringstream* afin de stocker tous le contenu de mon fichier source et en faire qu'une seul grosse string que je pourrais plus tard inclure dans le fichier de sortie.

```cpp
#include <fstream>
#include <iostream>

int main() {
	std::ostringstream ss;

	ss << "Hello ";
	ss << "Wordld!!" << std::endl;
	std::string res = ss.str();
	std::cout << res << std::endl;
	return 0;
}
```

Ici, dans cette exemple, je crée un objet de type *ostringstream*. Ensuite, j'ajoute mes strings dans le stream que je fini par reconvertir en string avec la méthode *str()*;

## Ex05

### Tableau de pointer sur fonction

Cet exercice demande d'utiliser les pointers sur fonctions. Donc l'enjeu est de trouver un moyen d'appeler la bonne fonction par rapport à la string passée en paramètre.

Pour résoudre se problème, j'ai décidé de créer un tableau de pointeur sur fonction. Cela fonctionne très bien dans ce cas car toutes les fonctions de Harl ont les mêmes prototypes (`void <function_name>(void) const`). Cela permet de créer un type générique permettant de représenter toutes les fonctions et donc de les stocker dans un tableau.

```cpp
typedef void (Harl::*FuncPtr)() const;
```

Ici, j'utilise *typedef* hérité du *C* pour créer un *type* nommé *FuncPtr* qui est un *pointer* sur une fonction membre de la class *Harl*. La fonction membre ne prend pas d'argument et renvoi *void*.

Maintenant que j'ai ce type, je peux créer un tableau contenant toutes mes fonctions :

```cpp
	FuncPtr funcs[] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
```

Ici, j'ai créé un tableau de 4 *FuncPtr* nommé *func*. Ici, je peux laisser vide les *[]* car le compilateur va déterminer automatiquement que le tableau fait 4 éléments.

Maintenant que j'ai mon tableau contenant mes pointers sur fonction, il m'a suffit de faire un tableau de *string* cont

## Ex06
