#include<iostream>
#include<cstdio>
#include <unistd.h>

#define OUT(outf) #outf
#define HELLO
// follow http://c-faq.com/stdio/rd.kirby.c

void say()
{
    int fd;
    fpos_t pos;
 //   printf("stdout terminal,");
 //   fflush(stdout);
    fgetpos(stdout,&pos);
    fd = dup(fileno(stdout));
    freopen(OUT(HELLO),"w",stdout);
    std::cout<<"aaa ";
    std::cout<<" aaa ";
    fflush(stdout);
    dup2(fd,fileno(stdout));
    close(fd);
    clearerr(stdout);
    fsetpos(stdout,&pos);
}

int main()
{
    std::cout<<"hello\n";
    say();
    std::cout<<"1\n";
    std::cout<<"ahello\n";
}

