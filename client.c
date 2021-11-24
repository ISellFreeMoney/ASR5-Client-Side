#include <stdio.h>
#include <netdb.h>
#include <strings.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct sockaddr_in sa;
    struct hostent *hp; // a obtenir en lisant le fichier host
    struct servent *sp; // a obtenir en lisant le fichier services
    int s;
    hp = gethostbyname(argv[1]);
    printf("%d\n", hp->h_addr[0]);
    sp = getservbyname("msp", "tcp");
    printf("%d\n", sp->s_port);

    s = socket(hp->h_addrtype, SOCK_STREAM, 0);
    printf("%d\n", s);

    sa.sin_family = hp->h_addrtype;
    sa.sin_port = sp->s_port;
    bcopy(hp->h_addr, (char *)&sa.sin_addr, hp->h_length);

    int c = connect(s, (struct sockaddr *)&sa, sizeof(sa));

    if (c < 0)
    {
        perror("connect");
    }

    return 0;
}