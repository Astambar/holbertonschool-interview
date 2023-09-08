#include "lists.h"
/**
 * find_listint_loop - trouve la boucle dans une liste chaînée.
 * @head: celà représente la tête de la liste et permet de trouvé une boucle
 * Return: nœud où se trouve la boucle sinon NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *idk, *idk2;

	idk = head;
	idk2 = idk;
	while (idk && idk2 && idk2->next)
	{
		idk = idk->next;
		idk2 = idk2->next->next;
		if (idk == idk2)
		{
			idk = head;
			while (idk && idk2)
			{
				if (idk == idk2)
					return (idk);
				idk = idk->next;
				idk2 = idk2->next;
			}
		}
	}
	return ('\0');
}
