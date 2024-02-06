# Notes

## Ex00

### new /delete

Pour la premiere fois dans cet exercie, nous devons utiliser les mots clé *new* et *delete*. Ils sont l equivalent de *malloc()* et *free()*. Ils sont la maniere CPP d intereagi avec le heap.

La syntaxe de *new()* est `obj *obj_ptr = new obj`. *new()* se charge de reserver le bon nombre de memoir en fonction de la taille de l objet a stoquer sur la heap.

*CPP* n elimine pas les probleme de fuite de memoire. Quand nous utilisons le mot cle *new*, c est a nous d appeler *delete* quand nous voulons liberer la memoire; La syntaxe est tres simple. Il suffit de taper `delete <obj>`.

## Ex01

### new array et delete[]

Dans cet exercice, il nous est demander de crer un tableau de pointeur sur objet sur la heap. Pour se faire, nous devons utiliser *new* et *delete* mais avec une szntaxe un petit peu differantes.

```cpp
horde = new Zombie[n];
```

Ici, nous reservons en memoir un tableau de *n* pointer sur *Zombie*. Ce qui fait que c est l allocation d un tableau et non pas d un simple objet et l utilisation des *[]* afin de specifier le nombres de pointeur que nous voulons stoquer.

Vu que nous utilsons *new* pour allouer notre tableau, nous devons aussi le mot cle *delete* adin de liberer la memoire et pas creer de leaks. Pour utiliser *delete* sur un tableau, nous devons ajouter les *[]*, `delete[] <array>`.

### check bad alloc

Comme en *C*, c est une bonne pratique de verifier que l allocation de la memoire a bien pu etre faite par l OS. Pour se faire, nous pouvons utiliser les exception et le bloquer *try / catch*.

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

Ici, nous executons nos *new* dans un bloque *try*. Si une exeception est lever par le code executer dans le bloque *try*, elle pourra etre capturee et donc traiter dans le bloque catch. Ici, notre bloque *catch* essaye de capturer une exception *bad_alloc* et si elle survient stock l exception dans une variable *e*.

Ici, nous faisons une utilisation tres simple des exceptions et du bloque *try / catch*. Nous verrons plus en profondeur son utilisation dans la suite de l apprentissage du CPP.

## Ex02

Cette exercice est la pour presenter la difference entre les *pointer* et les *references*.

Une reference se comporte dans beaucoup de cas comme un pointeur, la logique est la meme, cela permet de stocker l address vers un element en memoir.

La difference entre un pointer et une ref et qu une ref ne peu pas pointer sur rien (NULL) et une reference ne peu pas changer d addresse sur la quel elle point une fois que l initialisation est fait.

En gros, une reference est un pointeur constant sur une addresse non NULL.

## Ex03

Cet exercice nous permet de mettre en pratique les *pointeur* et les *reference*. Nous devons faire deux class *Human* plus ou moins similaire. La difference est que une classe dois absolument prendre une arme lors de sa creation (reference car une reference ne peu pas etre NULL) alors que l autre doit pouvoir etre cree sans avoir d arme (*pointeur* car un pointer peu poiter sur NULL).

## Ex04

### ifstream

*ifstream* signifie *input file stream* c est un objet qui permet donc de lire depuis un fichier.

```c++
#include <fstream>
#include <iostream>

int main() {
	std::ifstream file(<path>); // Ouvertur du fichier en lecture.
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

Dans cet exemple, je crer un objet *ifstream* en lui passant en parametre le chemin. Ensuite, je verifie que le fichier est bien ouvert grace a la methode *.is_open()* de l instance *ifstream*. Nous affichons toute les ligne du fichier grace a *getline()* de *iostream*. Pour fermer le fichier, il nous suffit d appeler la methode *close()* de l objet *ifstream*. Il n est pas forcement utilse de fermer le fichier car il sera automatiquement close a la fin du scoop grace au destructeur de la class *ifstream*, il est quand meme possible de le fermer manuellement si besoin comme je viens de le montrer.

### ofstream

*ofstream* est un objet qui permet d ecrire dans un fichier. C est un acronyme pour *output file stream*.

```cpp
#include <fstream>
#include <iostream>

int main() {
	std::ofstream file(<path>); // Ouveture du fichier en ecriture
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

Ici, nous ecrivons une phrae dans notre fichier ouvert. Nous pouvons remarquer que l uti,lisation de *ofstream* est tres similaire a l utilisation de *ifstream*. Nous l ouverons de la meme manire (en passent notre chemin au constructeur de *ofstream*) et nous utilisons les memes methode.

### ostringstream

Comme nous l avons deja vu, une *ostringstream* est un moyen de creer des chaines de cractere en memoire comme dans un fichier sans avoir besoin d ouvrir ou de creer un fichier.

Dans l ex03, j utilise un *ostringstream* afin de stoquer tous le contenu de mon fichier source et en faire qu une seul grosse string que je pourrais plus tard inclure dans le fichier de sortie.

```cpp
#include <fstream>
#include <iostream>

int main() {
	std::ostringstream ss;

	ss << "Hello ";
	ss << "Wordld!!" << std::endl;
	std::string res = ss.str();
	std::cout << res << std::endl;
	return 0
}
```

Ici, dans cette exemple,je cree un objet de type *ostringstream*. Ensuite, j ajoute mes stringdabs le stream que je fini par reconvertir en string avec la methode *str()*;

## Ex05

### Tableau de pointer sur fonction

## Ex06
