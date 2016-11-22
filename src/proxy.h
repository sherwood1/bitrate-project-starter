#ifndef PROXY_H
#define PROXY_H

#include <stdio.h>

#define FILE_NAME_LEN 100
#define IP_LEN 20
#define BUF_LEN 100

char log_str[FILE_NAME_LEN];
float alpha;
int listen_port;
char fake_ip[IP_LEN];
char dns_ip[IP_LEN];
int dns_port;
char www_ip[IP_LEN];

FILE* logs;

#endif