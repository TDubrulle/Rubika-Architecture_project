############## Français ##############
Rubika-Architecture_project
Projet pour le cours d'architecture et C++

Ceci est un projet pour l'école, dont le but et d'améliorer les connaissances en C++ et en Design patterns.
Le projet consiste en la création d'un petit jeu de combat (comme Streetfighter ou Tekken),
où deux joueurs s'affrontent jusqu'à ce que l'un perd,
où que le temps se soit écoulé.
Le projet a été réalisé avec Visual Studio 2015 et SFML 2.3.2.

Commentaires:

*/!\ SFML 2.3.2 a été utilisé pour réaliser ce projet. Je n'ai pas généralisé l'accès à la librairie; il faut donc modifier les propriétés du projet pour que celui-ci fonctionne.

*On peut encore améliorer ce moteur. Par exemple, il est possible de:

-Faire une restructuration des classes pour mieux respecter le patron Modèle-Vue-Contrôleur: Certaines classes n'ont pas de vue à part et demande pourtant d'afficher des éléments
-Décomposer Character en plusieurs parties distinctes (blocage, attaque, vie...) pour réduire son poids sur le long terme. L'ajout d'éléments rendra la classe plus grande sans pour autant qu'elle en ait besoin de toutes.
-Faciliter la création de nouveaux états (characterState). Le modèle d'état choisi étant celui mathématique, il faut nécessairement rajouter pour chaque états les états auxquels il peut se rajouter. Cela est avantageux dans le sens qu'il est possible de créer autant d'états que l'on souhaite avec des valeurs différentes, mais cela peut être fastidieux car il faut rajouter tous les liens entre les états.
-Par ailleurs, offrir un gestionnaire des contrôles: celui-ci permettrait de lier états et entrées (clavier, manette...).

############## English ##############
Rubika-Architecture_project
Project for architecture and C++ lessons.
This is a school project, that is aimed at improving knowledge of C++ and design patterns.
The project is a small fighter game -like Streetfighter or Tekken-,
where two players fight each other until one is defeated,
or when the timer runs out.
It was made with Visual Studio 2015 and SFML 2.3.2.

Author: Thomas Dubrulle