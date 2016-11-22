#include "proxy.h"
#include "proxy_util.h"

int main(int argc, char* argv[]) {
    if(process_command_line_input(argc, argv)) {
        fprintf(stderr, "Usage %s: <log> <alpha> <listen-port> <fake-ip> " \
                    "<dns-ip> <dns-port> <www-ip>\n\n", argv[0]);
        return 1;
    }

    fprintf(stdout, "proxy start...\n");

    start_proxy();
    return 0;
}