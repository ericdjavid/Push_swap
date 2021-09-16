# :trident: PUSH_SWAP PROJECT :trident:

## Description du projet :bookmark_tabs:
Cr�er un programme qui prend en param�tres des entiers (positifs ou n�gatifs) et les trie de mani�re croissante avec le moins d'actions possibles. Vous avez 2 stacks (A et B) et les nombres sont initialis�s sur la premi�re.

Les coups possibles sont :
- SA/SB : swap le premier et le deuxi�me nombre de la stack
- RA/RB : envoie le premier nombre de la stack en fin de liste
- RRA/RRB : envoie le dernier nombre de la stack en t�te de liste
- RR/RRR : comme les deux actions pr�c�dentes mais pour les 2 stacks en m�me temps (PS: je n'ai pas utilis� ces actions dans le cadre de mon projet).

Vous devez faire environ moins de 1000 coups pour 100 arguments et 8000 pour 500 arguments pour valider le projet.

## Methodologie :fountain_pen:
1. j'ajoute des index aux nombres
2. J'identifie le nombre pivot, celui � partir duquel on obtient la plus grande suite de nombre respectant l'un des deux crit�res suivants 
	- soit avec l'index croissant cons�cutif le plus long 
	- soit la suite de nombre la plus grande (non cons�cutive) 
3. J'envoie tous les nombres qui ne font pas partie de cette suite en stack B 
	3.1 attention, si la liste de nombre est > 100, je divise la liste en 2 ou 3 groupes et j'envoie d'abord les nombres du 1er groupe, ainsi de suite... 
4. Pour chaque nombre de la stack B, je calcule le nombre de coup pour l'envoyer en stack A et pour rendre la stack A pr�te � le recevoir 
5. J'envoie le nombre qui n�cessite le moins de coup possible et j'it�re jusqu'� que la stack B soit vide 
6. Si A n'est pas tri�, je rotate jusqu'� ce que le plus petit nombre soit en premi�re position


## Faire fonctionner le code :hammer_and_wrench:
- git clone https://github.com/ericdjavid/push_swap.git
- make
- ./push_swap [param�tres]
	- vous pouvez �galement utiliser un fichier contenant les arguments pour les grandes s�ries avec la commande suivante :  xargs -a tests/fichier.txt ./push_swap

## Testeurs
- https://github.com/laisarena/push_swap_tester
- https://github.com/lmalki-h/push_swap_tester