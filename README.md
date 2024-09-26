# RayTracer

**RayTracer** est un moteur de rendu utilisant la technique du raytracing pour générer des images réalistes en simulant les effets de lumière et d'ombres dans une scène donnée. Ce moteur calcule précisément la manière dont les rayons de lumière interagissent avec les objets, permettant de créer des rendus visuels avec des ombres, des réflexions et des réfractions extrêmement réalistes.

## 🎯 Objectif

L'objectif de **RayTracer** est de simuler un environnement 3D réaliste en traçant les rayons de lumière et en appliquant des effets tels que :

- **Reflets réalistes** : Simulation de la réflexion de la lumière sur des surfaces lisses (miroirs, eau, etc.).
- **Ombres dynamiques** : Les objets projettent des ombres réalistes en fonction de la position et de l'intensité des sources lumineuses.

## 📸 Fonctionnalités principales

- **Moteur de raytracing** : Génère une scène 3D en traçant le chemin des rayons lumineux.
- **Effets de lumière** : Prend en compte les sources lumineuses pour un rendu fidèle avec des ombres et des reflets.
- **Objets 3D** : Supporte plusieurs types de primitives géométriques (sphères, plans, Cubes) pour la création des scènes.

## 🖥️ Scènes supportées

**RayTracer** peut générer des rendus de différentes scènes 3D, avec des possibilités de personnalisation comme :

- **Sphères** : Créer des objets sphériques avec différents matériaux.
- **Plans** : Simuler des sols, des murs ou des surfaces réfléchissantes.
- **Objets composites** : Créer des scènes avec plusieurs objets et lumières pour obtenir un rendu complexe.

Voici un exemple simple d'une scène avec une sphère et une lumière :

```cfg
name = "Our Raytracer";

inventory =
{
  camera = ( { width_resolution  = "1280";
              height_resolution = "720";
              pos_x = "0";
              pos_y = "0";
              pos_z = "0";
              rotation_x = "0";
              rotation_y = "0";
              rotation_z = "0";
              fov = "72.0";
              }
          );

  primitive = (
               { forme = "Sphere";
              color_r = "50";
              color_g = "100";
              color_b = "75";
              pos_x = "-5";
              pos_y = "0";
              pos_z = "50";
              size = "1";
               },
               { forme = "Sphere";
              color_r = "100";
              color_g = "150";
              color_b = "100";
              pos_x = "5";
              pos_y = "0";
              pos_z = "50";
              size = "1";
               },
               { forme = "Plane";
              color_r = "50";
              color_g = "170";
              color_b = "110";
              axis = "Y"
              position = "-5";
               }
           );

  lights = ( { type = "directional";
              strengh = "100";
              pos_x = "15";
              pos_y = "0";
              pos_z = "70";
              direction_x = "-1";
              direction_y = "0";
              direction_z = "0";
              color_r = "0";
              color_g = "255";
              color_b = "0";
               }
           );
};
```

## 🌟 Exemples de rendus

Voici quelques exemples de scènes rendues avec RayTracer :

![Scène avec 2 sphères + lumière](https://github.com/TTG-Phyros/repositoriesPhotos/blob/main/RayTracer/RayTracer_avec_lumieres.png)
![Scène avec 2 sphères sans lumières](https://github.com/TTG-Phyros/repositoriesPhotos/blob/main/RayTracer/RayTracer_sans_lumieres.png)


## 📈 Performances

Le moteur de RayTracer est conçu pour fonctionner efficacement avec des scènes simples, mais le temps de rendu peut augmenter de manière significative avec des scènes plus complexes ou une haute résolution.

Nous recommandons de tester différentes résolutions et configurations de scènes pour optimiser les performances et le rendu visuel.

## 🚧 Fonctionnalités à venir

- [ ] Support pour des textures avancées et des cartes de relief.
- [ ] Ajout de nouvelles primitives 3D, telles que des cônes et des cylindres.
- [ ] Amélioration de la gestion des réfractions à travers des matériaux complexes.
- [ ] Accélération via le multi-threading ou l'utilisation du GPU pour des rendus plus rapides.

## 🚀 Installation
### Prérequis

    [MakeFile, SFML, LibconfigG++, G++]

## Instructions

### Clone le dépôt :

    git clone https://github.com/ton-compte/Raytracer.git

### Accède au dossier du projet :

    cd Raytracer

### Compile le projet :

    make

### Lance le jeu :

    ./raytracer [Path relatif de scène à afficher] (optionel : --display)

### Pour Nettoyer les fichiers :

    make fclean

## Auteur

| [<img src="https://github.com/MaximeCstb.png?size=85" width=85><br><sub>Maxime Coustabeau</sub>](https://github.com/MaximeCstb) | [<img src="https://github.com/BaptisteMERY.png?size=85" width=85><br><sub>Baptiste Mery</sub>](https://github.com/BaptisteMERY) | [<img src="https://github.com/TTG-Phyros.png?size=85" width=85><br><sub>Nicolas Audibert</sub>](https://github.com/TTG-Phyros) | [<img src="https://github.com/Gappy7.png?size=85" width=85><br><sub>Anthony Girard</sub>](https://github.com/Gappy7)
| :---: | :---: | :---: | :---: |
