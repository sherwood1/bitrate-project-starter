#include "proxy.h"
#include "proxy_util.h"
#include <string.h>
#include <assert.h>
#include <signal.h>

int process_command_line_input(int argc, char *argv[]) {

    // parse command line input
    if(argc != 8) {
        fprintf(stderr, "arg number illegal\n");
        return 1;
    }
    
    if(strlen(argv[1]) >= FILE_NAME_LEN) {
        fprintf(stderr, "log_str illegal\n");
        return 1;
    }
    strcpy(log_str, argv[1]);
    
    if(strlen(argv[2]) >= BUF_LEN) {
        fprintf(stderr, "alpha illegal\n");
        return 1;
    }
    sscanf(argv[2], "%f", &alpha);

    if(strlen(argv[3]) >= BUF_LEN) {
        fprintf(stderr, "listen port illegal\n");
        return 1;
    }
    sscanf(argv[3], "%d", &listen_port);

    if(strlen(argv[4]) >= IP_LEN) {
        fprintf(stderr, "fake-ip illegal\n");
        return 1;
    }
    strcpy(fake_ip, argv[4]);

    if(strlen(argv[5]) >= IP_LEN) {
        fprintf(stderr, "dns ip illegal\n");
        return 1;
    }
    strcpy(dns_ip, argv[5]);

    if(strlen(argv[6]) >= BUF_LEN) {
        fprintf(stderr, "dns-port illegal\n");
        return 1;
    }
    sscanf(argv[6], "%d", &dns_port);

    if(strlen(argv[7]) >= FILE_NAME_LEN) {
        fprintf(stderr, "www-ip illegal\n");
        return 1;
    }
    strcpy(www_ip, argv[7]);

    // start logging
    assert((logs = fopen(log_str, "w")) != NULL);
    fprintf(logs, "alpha\t%f\n", alpha);
    fprintf(logs, "listen_port\t%d\n", listen_port);
    fprintf(logs, "fake-ip\t%s\n", fake_ip);
    fprintf(logs, "dns-ip\t%s\n", dns_ip);
    fprintf(logs, "dns-port\t%d\n", dns_port);
    fprintf(logs, "www-ip\t%s\n", www_ip);
    fprintf(logs, "\nlog start...\n\n");
    fflush(logs);

    // ignore sigpipe signal
    signal(SIGPIPE, SIG_IGN);

    return 0;
}

void start_proxy() {

}