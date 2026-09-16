# Singly Linked List in C

Implémentation complète d'une **liste chaînée simple (singly linked list)** en C pur, écrite dans le cadre de mon apprentissage à 42. Zéro dépendance externe — juste `unistd.h` et `stdlib.h`.

## Fonctionnalités

| Fonction | Description | Complexité |
|---|---|---|
| `add_back` | Insertion en fin de liste | O(n) |
| `insert_at` | Insertion à un index donné (gère liste vide, index 0, index hors limites) | O(n) |
| `delete_value` | Suppression du premier nœud dont le contenu correspond (comparaison **par valeur**, pas par adresse) | O(n) |
| `sort_list` | Tri alphabétique par **échange physique de nœuds** (bubble sort adapté aux listes chaînées, sans copier le contenu) | O(n²) |
| `print_list` / `free_list` | Parcours et libération complète sans fuite mémoire | O(n) |

## Compiler et exécuter

```bash
gcc -Wall -Wextra -Werror -o linked_list linked_list.c
./linked_list delta bravo echo alpha
```

## Vérification mémoire

Le code est testé sous AddressSanitizer / LeakSanitizer — zéro fuite, zéro use-after-free, zéro double-free :

```bash
gcc -Wall -Wextra -g -fsanitize=address,leak -o linked_list linked_list.c
./linked_list a b c
```

## Subject

Implémenter, en C pur (`unistd.h` et `stdlib.h` uniquement), une liste chaînée simple (`singly linked list`) manipulable en ligne de commande via `argv`, avec les contraintes suivantes :

- **Aucune fonction de la libc pour la logique** : la comparaison de chaînes, l'affichage et le parcours doivent être réimplémentés à la main (`ft_strcmp`, `ft_putstr`).
- **Une seule fonction d'allocation** (`new_node`) : toute création de nœud doit passer par ce point unique, sans allocation "cachée" ailleurs dans le code.
- **Gestion mémoire stricte** : zéro fuite, zéro use-after-free, zéro double-free, vérifiable sous `valgrind` ou AddressSanitizer.
- **`insert_at`** doit gérer correctement les trois cas limites : liste vide, insertion en tête (`index == 0`), et insertion au-delà de la fin de la liste (ajout en queue).
- **`delete_value`** doit comparer le **contenu** des chaînes, jamais leurs adresses mémoire.
- **`sort_list`** doit trier en échangeant les **nœuds eux-mêmes** (reconnexion des pointeurs `next`), sans jamais copier ou échanger les champs `value` — le contenu doit rester physiquement attaché à son nœud d'origine.
- **Norme de compilation** : `-Wall -Wextra -Werror` sans aucun warning.

## Subject

Implémenter une liste chaînée simple en C, sans bibliothèque externe, en respectant les contraintes suivantes :

- Aucune fuite mémoire tolérée : chaque `malloc` doit être soit rattaché à la liste, soit libéré — jamais les deux à la fois, jamais aucun des deux.
- La comparaison de deux chaînes doit se faire **par contenu**, jamais par adresse de pointeur (`==` sur des `char *` est interdit).
- `insert_at` doit gérer explicitement les cas limites : liste vide, index 0, et index supérieur ou égal à la longueur de la liste (insertion en fin de liste).
- `sort_list` doit trier en échangeant les **nœuds eux-mêmes** (réorganisation des pointeurs `next`), sans jamais permuter le champ `value` — l'identité physique de chaque nœud doit être préservée.
- Le programme doit rester propre sous `valgrind` / `AddressSanitizer` : zéro fuite, zéro use-after-free, zéro double-free.
- Norme de compilation stricte : `-Wall -Wextra -Werror`, zéro warning toléré.
