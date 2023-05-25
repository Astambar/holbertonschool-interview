#!/usr/bin/python3
"""_0-validate_utf8.py_
"""


def is_continuation_byte(byte):
    """
    Vérifie si l'octet donné est un octet de continuation (commence par 10)
    """
    bin_rep = format(byte, '#010b')[-8:]
    return bin_rep.startswith('10')


def get_num_of_bytes(byte):
    """
    Renvoie le nombre d'octets
    de continuation attendus
    pour un caractère multioctet
    """
    bin_rep = format(byte, '#010b')[-8:]
    if bin_rep.startswith('110'):
        return 1
    elif bin_rep.startswith('1110'):
        return 2
    elif bin_rep.startswith('11110'):
        return 3
    else:
        return 0


def validUTF8(data):
    """
    Détermine si l'ensemble de données
    représente un encodage UTF-8 valide
    """
    num_of_bytes = 0

    for byte in data:
        # Vérifiez si c'est un octet de continuation
        if num_of_bytes > 0:
            if not is_continuation_byte(byte):
                return False
            num_of_bytes -= 1
        # Vérifiez si c'est le premier octet d'un caractère multioctet
        else:
            num_of_bytes = get_num_of_bytes(byte)
            # Si ce n'est pas un octet de continuation et
            # pas le premier octet d'un caractère multioctet,
            # il devrait commencer par 0 (caractère à un seul octet)
            if num_of_bytes == 0 and byte & 0b10000000:
                return False

    # Renvoie True si tous les octets sont correctement codés
    return num_of_bytes == 0
