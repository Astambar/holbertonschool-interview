#include "lists.h"

/**
 * check_cycle - fonction qui vérifie si une liste chainée a un cycle
 * @list: liste chainée à vérifier
 *
 * Return: 0 si la liste n'a pas de cycle, 1 sinon.
 */
int check_cycle(listint_t *list)
{
listint_t *tortue, *lapin;

/* vérifie que la liste n'est pas vide */
if (!list)
	return (0);

/* initialisation des pointeurs */
tortue = list;
lapin = list;

/* boucle jusqu'à ce que la tortue ou le lapin atteigne la fin de la liste */
while (lapin && lapin->next)
{
	tortue = tortue->next;
	lapin = lapin->next->next;

	/* détection d'un cycle */
	if (tortue == lapin)
		return (1);
}

/* pas de cycle détecté */
return (0);
}
