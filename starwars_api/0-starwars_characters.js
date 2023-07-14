#!/usr/bin/node
/*
 * Script pour afficher les noms des personnages d'un film Star Wars spécifié.
 * L'ID du film est passé en tant que premier argument de ligne de commande.
 * Ce script utilise l'API Star Wars (https://swapi.dev/) pour récupérer les données du film et des personnages.
 * Il utilise le module `request` pour effectuer des requêtes HTTP à l'API.
 */

const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`;

// Effectue une requête à l'URL du film pour récupérer les données du film
request(url, async function (error, response, body) {
  if (error) {
    // En cas d'erreur, affiche l'erreur
    console.log(error);
  } else {
    // Récupère la liste des personnages du film
    const characters = JSON.parse(body).characters;
    // Parcourt la liste des personnages
    for (const c in characters) {
      // Pour chaque personnage, effectue une requête à son URL pour récupérer ses données
      const response = await new Promise((resolve, reject) => {
        request(characters[c], (error, response, body) => {
          if (error) {
            // En cas d'erreur, rejette la promesse avec l'erreur
            reject(error);
          } else {
            // Sinon, résout la promesse avec le nom du personnage
            resolve(JSON.parse(body).name);
          }
        });
      });
      // Affiche le nom du personnage
      console.log(response);
    }
  }
});
