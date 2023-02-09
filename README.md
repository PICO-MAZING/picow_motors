# Étapes principales pour la construction du dossier picow_motors

*Ce document présente une marche à suivre testée sur Ubuntu en février 2023.*

## Installer le SDK C/C++ (et les exemples : optionnel)

Toutes les consignes d'installation sont données au Chapitre 2 du [livret de démarrage](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).

Un exemple de compilation de projet est donné au chapitre suivant.


## Mettre en place un environnement de développement

Pour la mise en place de l'environnement de développement, nous avons utilisé l'outil `Raspberry Pi Pico Project Generator`.

Cet outil simplifie la création d'un projet sur VSCode.

Pour plus de renseignements, consulter les chapitres 8.2 et 8.3 du [livret](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).

## Développer en C/C++

Pour se familiariser avec l'API du SDK, il est conseillé de se référer à la [documentation officielle](https://raspberrypi.github.io/pico-sdk-doxygen/).

## Exemple de manipulation des capteurs

Le fichier `picow_motors.cpp` présente un exemple d'utilisation des capteurs du robot.