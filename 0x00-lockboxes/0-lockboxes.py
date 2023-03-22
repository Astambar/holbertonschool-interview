#!/usr/bin/python3
"""lockboxes function unlocked boxe"""


def canUnlockAll(boxes):
    """
    Vérifie si toutes les boîtes peuvent être déverrouillées.
    Prend une liste de listes en argument et renvoie True ou False.

    :param boxes: Stocke les boîtes.
    :return: True si toutes les boîtes peuvent être déverrouillées.
    """

    # Initialise une liste avec la première boîte, qui est ouverte au début.
    keys = [0]

    # Stocke le nombre total de boîtes.
    num_boxes = len(boxes)

    # Parcourt chaque boîte dans la liste.
    for current_box_index, current_box in enumerate(boxes):

        # Si la boîte est non vide.
        if current_box:

            # Parcourt chaque clé de la boîte.
            for key in current_box:

                # Vérifie si la clé n'est pas déjà dans la liste des clés,
                # si elle n'ouvre pas la boîte elle-même
                # et si elle est une clé valide
                # (inférieure au nombre total de boîtes).
                if key not in keys and key != current_box_index:
                    if key < num_boxes:

                        # Ajoute la clé à la liste des clés.
                        keys.append(key)

    # Vérifie si le nombre de clés dans la liste
    # est égal au nombre total de boîtes.
    return len(keys) == num_boxes
