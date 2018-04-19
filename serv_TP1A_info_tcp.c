// @TITLE : Serveur d'echo sur le port pass� en argument 
// @BRIEF : R�p�te ce qu'il re�oit et l'affiche. La connexion s'arrete apres reception de bye.
// @AUTHOR : Ph Lefebvre - ENSI de Caen

#include <errno.h>                 // biblio des erreurs
#include <sys/socket.h>            // biblio pour les socket
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>                 // biblio pour les E/S.
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define PAQUET_LEN 64

int main(int argc, char **argv) {
    int er, lgr;                   // gestion des erreurs
    int s;                         // socket d'ecoute du port
    int sd;                        // socket de dialogue avec le client.
    unsigned char paquet[PAQUET_LEN];             // paquet recu / envoye

    struct sockaddr_in adTo, adFrom;    // adresse au format internet

    unsigned int ladd = sizeof(struct sockaddr_in);  // longueur de l'adresse de reception
    int port;                        // port de connexion

    if (argc != 2) {
        printf("Erreur argument 1 : serveur.exe no_port \n");
        exit(-1);
    } else sscanf(argv[1], "%d", &port);

    /* On ouvre la socket  Internet en mode connecte. 6 est le num�ro de TCP , cf. le fichier /etc/protocols*/
    if ((s = socket(AF_INET, SOCK_STREAM, 6)) < 0) {
        perror("\nERREUR socket\n");
        exit(-1);
    }

    adTo.sin_family = AF_INET;           // adresses de type internet
    adTo.sin_port = htons(port);        // numero de port du serveur
    adTo.sin_addr.s_addr = INADDR_ANY;   // accepte les connexions de n'importe quelle interface ethernet, wifi...

    /* On attache la socket au port d'ecoute */
    er = bind(s, (struct sockaddr *) &adTo, sizeof(struct sockaddr_in));
    if (er < 0) {
        perror("bind : ");
        exit(-1);
    }

    /* On fixe le nombre maximum de clients simultanes en attente. Ici 1 seule*/
    /* passe la socket en mode LISTEN */
    er = listen(s, 1);
    if (er < 0) {
        perror("listen : ");
        exit(-1);
    }
/* D�pile une demande de connexion. Attend si aucune connexion encore n'est encore arriv�e.
 * Cr�e une socket de dialogue si un client se connecte.
 * */

    sd = accept(s, (struct sockaddr *) &adFrom, &ladd);
    printf("1 client !\n");
    do {
        lgr = recv(sd, paquet, PAQUET_LEN - 1, 0);     // on lit au maximum PAQUET_LEN octets venant du client.
        if (lgr == 0) {
            printf("Deconnexion par le client !\n\n");
            exit(0);
        }
        if (lgr < 0) {
            perror("pb recv");
            exit(-1);
        }
        paquet[lgr] = '\0';                        // le paquet re�u n'est pas une chaine de caract�re => ajout de "\0" � la fin
        printf("paquet de longueur %d re�u : %s\n", lgr, paquet);
        send(sd, paquet, lgr, 0);          // reemission du paquet recu.
    } while ((strncmp((char *) paquet, "bye", 3)));      // on compare les 3 premiers octets recus a "bye"
    printf(" Mon client s'est deconnecte.\n");
    close(sd);                         // fermeture de la socket de dialogue. Provoque la d�connexion si le buffer de r�ception est vid�
    close(s);                            // fermeture de la socket d'�coute
    return (0);
}

