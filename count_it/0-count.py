#!/usr/bin/python3
"""
0-count.py
"""

import requests


def count_words(subreddit, word_list, counts=None):
    """
    Compte les occurrences de mots-clés dans les titres
    des articles populaires d'un subreddit.

    Args:
        subreddit (str): Le subreddit à interroger.
        word_list (list): Une liste de mots-clés dont
        on veut compter les occurrences.
        counts (dict, optionnel): Un dictionnaire pour stocker
        les comptages de mots-clés de manière récursive.

    Returns:
        None
    """
    # Si le dictionnaire de comptages n'est pas fourni, on le crée
    if counts is None:
        counts = {}

    # Effectuer une requête à l'API Reddit pour obtenir
    # les articles populaires du subreddit
    response = requests.get(f"https://www.reddit.com/r/{subreddit}/hot.json",
                            headers={"User-Agent": "count_it/0.1"})
    data = response.json()

    # Parcourir les articles et leurs titres
    for post in data['data']['children']:
        title = post['data']['title'].lower()
        # Parcourir les mots-clés à compter
        for word in word_list:
            # Vérifier si le mot-clé est présent dans le titre de l'article
            if word.lower() in title:
                # Incrémenter le compteur du mot-clé
                if word in counts:
                    counts[word] += 1
                else:
                    counts[word] = 1

    # Si la réponse contient un élément "after",
    # cela signifie qu'il y a plus d'articles à récupérer
    # Donc, on rappelle la fonction de manière récursive
    # avec le même subreddit et les mêmes mots-clés
    if 'after' in data['data'] and data['data']['after']:
        count_words(subreddit, word_list, counts)

    # Si aucun comptage n'a été effectué, on quitte la fonction
    if not counts:
        return

    # Trier les comptages par ordre décroissant en fonction du nombre
    # d'occurrences
    # En cas d'égalité, trier alphabétiquement par ordre croissant
    sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0].lower()))
    # Afficher les résultats
    for keyword, count in sorted_counts:
        print(f"{keyword}: {count}")


if __name__ == '__main__':
    import sys

    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print(
            "Ex: {} programming 'python java javascript'".format(sys.argv[0])
            )
    else:
        subreddit = sys.argv[1]
        keywords = sys.argv[2].split()
        count_words(subreddit, keywords)
