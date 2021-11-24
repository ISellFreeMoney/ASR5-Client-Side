#include <stdio.h>
#include <netinet/in.h>

// On declare: 
struct sockaddr_in sa;
struct hostend *hp; // a obtenir en lisant le fichier host
struct servent *sp; // a obtenir en lisant le fichier services

// On sait que
typedef struct sockaddr_in{
    short sin_family; // famille d'adresse : AF_INET
    unsigned short sin_port; // port dqns l'ordre d'octets reseau
    struct in_addr sin_addr; // Adresse Internet
    char sin_zero[8];
};

struct in_addr{
    uint32_t s_addr; // adresse dans l'ordre d'octets reseau
};
