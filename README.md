# :trident: PUSH_SWAP PROJECT :trident:

## Description du projet
Créer un programme qui prend en paramètres des entiers (positifs ou négatifs) et les trie de manière croissante avec le moins d'actions possibles. Vous avez 2 stacks (A et B) et les nombres sont initialisés sur la première.

Les coups possibles sont :
SA/SB : swap le premier et le deuxième nombre de la stack
RA/RB : envoie le premier nombre de la stack en fin de liste
RRA/RRB : envoie le dernier nombre de la stack en tête de liste
RR/RRR : comme les deux actions précèdentes mais pour les 2 stacks en même temps (PS: je n'ai pas utilisé ces actions dans le cadre de mon projet).

Vous devez faire environ moins de 1000 coups pour 100 arguments et 8000 pour 500 arguments pour valider le projet.

## Methodologie
1. j'ajoute des index aux nombres
2. J'identifie le nombre pivot, celui à partir duquel on obtient la plus grande suite de nombre respectant l'un des deux critères suivants 
	- soit avec l'index croissant consécutif le plus long 
	- soit la suite de nombre la plus grande (non consécutive) 
3. J'envoie tous les nombres qui ne font pas partie de cette suite en stack B 
	3.1 attention, si la liste de nombre est > 100, je divise la liste en 2 ou 3 groupes et j'envoie d'abord les nombres du 1er groupe, ainsi de suite... 
4. Pour chaque nombre de la stack B, je calcule le nombre de coup pour l'envoyer en stack A et pour rendre la stack A prête à le recevoir 
5. J'envoie le nombre qui nécessite le moins de coup possible et j'itère jusqu'à que la stack B soit vide 
6. Si A n'est pas trié, je rotate jusqu'à ce que le plus petit nombre soit en première position


## Faire fonctionner le code
- git clone https://github.com/ericdjavid/push_swap.git
- make
- ./push_swap [paramètres]
	- vous pouvez également utiliser un fichier contenant les arguments pour les grandes séries avec la commande suivante :  xargs -a tests/fichier.txt ./push_swap

