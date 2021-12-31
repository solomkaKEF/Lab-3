#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double f(double x);
double hord(double x1 , double x2 , double eps , int select , unsigned int max , long int *pbegin , long int *pend);
double half_division(double x1 , double x2 , double eps , int select , unsigned int max , long int *pbegin , long int *pend);
void boss(void);

int main()
{
    double result , x1 , x2 , eps;
    int select, method;
    unsigned int max;
    long int begin , end;
    long int *pbegin = &begin;
    long int *pend = &end;

    do
    {
        printf("enter intervals x1 and x2 \n");
        scanf("%lf %lf",&x1 , &x2);
    }
    while (f(x1)*f(x2) > 0);

        printf("Enter mistake degree for the eps and max number of iterations\n");
        scanf("%lf", &eps);
        scanf("%u", &max);

        printf("Choose calculation method \n 1)Hord method \n 2)Half division method\n");
        scanf("%d", &method);

        printf("Do you want to see results every iteration? \n1)Yes \n2)No\n");
        scanf("%d", &select);

    if (method == 1){
        result = hord(x1 , x2 , pow(10,eps) , select, max , pbegin , pend);
    }
    else if (method == 2) {
        printf("test");
    }
    else {
        result = half_division(x1 , x2 , pow(10,eps), select, max, pbegin, pend);
    }

    if (select != 1) {
        printf("result is %lf \n", result);
    }

    printf("Time spent %d  *10^(-3) seconds", *pend);

    return 0;
}

//==============================================

double f(double x) {

    return (pow(x,3)/10) + (x/5) + 6;
}

//==============================================

double hord(double x1 , double x2 , double eps, int select, unsigned int max , long int *pbegin , long int *pend) {

    double x;
    unsigned int count, next;
    long int sum_time;

    do
    {
        *pbegin = clock();
        //printf("%d     ", clock());
        x = (f(x2)*x1 - f(x1)*x2)/(f(x2) - f(x1));
        if (f(x)*f(x1) > 0)
        {
            x1 = x;
        }
        else
        {
            x2 = x;
        }
        *pend = clock();
        // printf("%d     \n", clock());
        sum_time = sum_time + (*pend - *pbegin);
        count++;
        if (select == 1){
            printf("horda %lf \n", x);
            getchar();
        }
        else if (count == max) {

            printf("Max number of iterations has been reached.What would you do:\n1)Do again %u iterations\n2)Continue calculating to the finish\n3)Exit\n", count);
            scanf("%d", &next);
            switch(next) {

                case 1: count = 0;break;
                case 2: break;
                default:
                    if (select != 1) {
                        printf("\nNumber of iterations %u \n", count);
                    }
                    *pend = sum_time;
                    return x;
            }
        }
    }
    while ( fabs(f(x)) >= eps);

    if (select != 1) {
        printf("Number of iterations  %u \n", count);
    }
        *pend = sum_time;
        return x;
}

//=============================================

double half_division(double x1 , double x2 , double eps , int select, unsigned int max, long int *pbegin , long int *pend) {
    double x;
    unsigned int count;
    int next;
    long int sum_time;

    do
    {
        *pbegin = clock();
        x = (x1 + x2)/2;
        if (f(x)*f(x1) > 0){
            x1 = x;
        }
        else{
            x2 = x;
        }
        *pend = clock();
        sum_time = sum_time + (*pend - *pbegin);
        count++;

        if (select == 1){
            printf("half division %lf \n", x);
            getchar();
        }
        else if (count == max) {
            printf("Max number of iterations has been reached.What would you do:\n1)Do again %u iterations\n2)Continue calculating to the finish\n3)Exit\n", count);
            scanf("%d", &next);
            switch(next) {

                case 1: count = 0;break;
                case 2: break;
                default:
                    if (select != 1) {
                        printf(" \nNumber of iterations %u \n", count);
                    }
                    *pend = sum_time;
                return x;
            }
        }
    }
    while ( fabs(x1 - x2) >= eps);

    if (select != 1) {
        printf("Number of iterations  %u \n", count);
    }
        *pend = sum_time;
        return x;
}








































































































































































void boss(void) {
printf("c::::::::::::::::::clllll:,'''......''''',,,,,,''..............'''',,,,,,,,,,''''''''''''',,'''''';: \n");
printf("c::::::::::::::::::clllc;;,''.........''',,,,'......          ....'',,,,,,,,,''''''''''''',,,''''';: \n");
printf("c:::::::::::;;;;;;:ccllc:;,''........'''',,'...                  ....',,,,,,,''''''''''''',,,''''';: \n");
printf("c::::::::::::::::::ccllllc,'.........''''''..                       ..',,,,,,''''''''''''',,,''''';: \n");
printf("c::::::::::::;;::::ccllllc,'...........''...                          .',,,,,''''''''''''',,'''''';: \n");
printf("c:::::::::::::::::::cllllc;'...........''.....                        ..,,,,,'''''''''''',,,,''''';: \n");
printf("cc::::cllc:::::::::ccllllc;''...........'............. .......        .',,,,,,'''''''''',,,,'''''';: \n");
printf("llcllcclllcccccccccllllllc;'''''......'''...',,,;;;,,'''''''...       .',,,,,,,,,,,,,,,,,''''''''';: \n");
printf("lllllllllllllllllllllllllc;'''''......''''.':llooolllllllllc;...     ..,,,,,,,,,,,,,,,'''''''''''';: \n");
printf("lllllllllllllllllllllllllc;'''''......''''';:codxddddddddoooc;....   .',,,,,,,,,,,,,''''''''''''''', \n");
printf("llllllllllllllllllllllllll;''''......''''',::::cldddollllllllc,......',,,,,,,,,,'''''''''''''''''''' \n");
printf("llllllllllllllllllllllllll;''''......'''',;lllllcdxxdc::cllllc;....',,,,,,,,,,,''''''''''''''''''''. \n");
printf("llllllllllllllllllllllllll:'''''......''',:odddddkOOxdolooodoc;'..,,,,,,,,,,,,'''''''''''''''''''''. \n");
printf("llllllllllllllllllllllllll:''''.......''',;oxxxxxOOOkkkkxxxxoc;,,,;,,,,,,,,,,,'''''''''''''''''''''. \n");
printf("lllllllllllllllllllllllllc:'..'.......'''';lodddxkkkxxxxkxxol:;,,;,,,,,,,,,,,,'''''''''''''''''''''. \n");
printf("lllllllllllllllllllllllccc:'..''.....',,,,,cloooooooooodddolc:;,,,,,,,,,,,,,,,'''''''''''''''''''''. \n");
printf("lllllllllllllllllllllccccc:,.'''.....',;clcldooooooolooddoolc;,,,,,,,,,,,,,,,,'''''''''''''''''''''. \n");
printf("llllllllllllllllllllllllll:,.........'',;::::clllooooloddolc;,',,,,,,,,,,,,,,''''''''''''''''''''''. \n");
printf("llllllllllllllllllllllllll:,..'''';;;:clool,.,cllllooooolc;,'..',,,,,,,,,,,,,''''''''''''''''''''''. \n");
printf("llllllllllllllllllllllllllc;;;:::cllodxddddc,:oolllllllc;,'....',,,,,,,,,,,,,''''''''''''''''''''''. \n");
printf("lllllllllllllllllllllllclllooddddooxxdddddoc:::;,'',,;;,.......'''',,,,,,,,,,''''''''''''''''''''''. \n");
printf("llllllllllllllllllllllooodxxkxxddodkxkkxddooll:'....,,'....''..',,,,,,,,,,,,,''''''''''''''''''''''. \n");
printf("lllllllllllllllllllodxOOOkkkkkxxodkdoddxxddodol:;,';c:'....':lc,,,,,,,,,,,,''''''''''''''''''''''''. \n");
printf("lllllllllllllllllodxk0KKK0OOkkxddO0dl;'';coooolllc:ox:','''',:lc,,,,,',,,''''''''''''''''''''''''''. \n");
printf("lllllllllllllllodxkkOO00000OOkddxO00Oxl,';:cloooolcdd:;;;,,''',,,,''..',,,'''''''''''''''''''''''''. \n");
printf("llllllllllllllodxkkOOOO00OOOOxddkO0000Oxl;'':coolcccc:c::;;,,,,'''.....';;,,'''''''''''''''''''''''. \n");
printf("lllllllllllllodxxkkOOOOOOOOkxdoxkO00000Oko;:l;,clccccclc::;;,,,,'......',;;;,,'''''''''''''''''''''. \n");
printf("llllllllllllodxxxkkkkkkkkkkdoddxO00000OOkkdc;;cc;:ccccooolc:;,'..'....''',;;;;,'''''''''''''.''''''. \n");
printf("lllllllllllllodxxxxxxkkxxdooodxO000000OOOOkxlcll;;;;;cdxxdoc;'''...',,,'',;:::;,'''''''''''..''''''. \n");
printf("lllllllllllllooddxxxxdddoclodxO0000000OOOOkkkd:;oxxl,;oxxdl;,'...',::;,,,,;;::;,,''''''''''..''''''. \n");
printf("llllllllllooooooddddddolccloxO0000000000OOOOkkxl;;;,'.,lo:'.....,:cc::;,,,;;:::;,''''''''''..''''''' \n");
printf("lllllllllodddoooddxxxxdl;:ldkO0000000000OOOOOkkxl;,,'.'::,....';ccccc:;;,,;,;::;,,'''''''''...'''''' \n");
printf("lllllllloodxxdddxxkkkkxc;coxkOO0000000000000Okkxdlll:;:lolc;,;:clllcc::;,''',;:;,,'''''''''...'''''' \n");
printf("llllllllodxxxxxxxkkkkkd:,:odxkkOOO00000000000Okxdlcll;:lddkxlclllllcc::;,'...,;;,,'''''''''...'''''' \n");
printf("llllllloodxxxxxxxkkkkxo;';cloddxxkkkkkOOOOOOOOkxo:,,'..',:loooolllccc::;,''..,;;,,'''.'..''...'''''. \n");
printf("llllllloddxxxxxxxxxxddc,';::cllooddddxxxxxxxxxdo:,'......;loollllcc:::;,,'..';;;,,''...........''''' \n");
printf("llllllloddxxkkxxxxxddl;..,;;;;:ccccccloooooooll:,'..,;..;clllllccc::;;,,''..,;;;,'''...........''''. \n");
printf("llllllloddxxkkkkxxddoc...,,'::,;c;,;;;::::::::c:,......';:ccccc::;;,,'''...,;;;,,'''............'''. \n");
printf("llllllooddxxkkkkxxddl,..',,,cc,:o:.:o;;dl,'',,;cc:;,'....'',,;;;;,,'......,;;;;,'''.............'''. \n");
printf("lllllloddxxxkkkxxddoc,';cooooooooc;c:,:dc'....,ldddoc'...................';;;;;,''..............'.'. \n");
printf("lllllloddxxxxxxxddol:;,;codxxkOOOOOxdollcc:;;;lddoooo:...................';;::;;,''................. \n");
printf("llllllodxxxxdddddolc:;,;codxxkkOOOOOOkkkkkkkxxkkdooodo;'''...............';;:::;,''................. \n");
printf("llllloxxkkxddoooolcc:;,;codxkkOOOOOOOOOO0000OOkxxddddolc::;;,,''.........,;;:::;,,'................. \n");
printf("lllloxkkkkxdooollccc:;,;codxxkkOOOOOOOO0000OOkkkkkxxxddolc:;;,'''........,;;::::;,''................ \n");
printf("lllldxkkkkdoolllccc::;,;:lodxxkkOkkkOOOOOOOOOOkkkkkkkxdol:;,,,'''........,;;::::;,''................ \n");
printf("lllodkkOOkdoollcccc:;;,;:cloodxxxxxkkkkkkkkkkkkkkkkkxxdlc;,''''''........';;:::::;,'................ \n");
printf("lllodkkOOkdooolccc::;;,,:clloodddxxxxxxkkkkkkkkkkkkxxdoc:;,,'''''........',;:::::;,''............... \n");
printf("lllodkkOOkxddolccc:;;;,,;cloodddxxxxxkkkOOOOOkkkkkkxxdolc:;,,'''.........',;::::::;;,'.............. \n");
printf("lllodxkkkkxdolccc:;;;;;;;cooddxxxxxkkkkkOOOOOkkkkkkxxxdoc:;,''''.........',;;:::::::;,'............. \n");
printf("lllodxkkkkxdolccc:;;:::::coddxxkkkkkkxxkkkOkkkkkkkxxxddlc:;''''''........',;;::::ccc:;'............. \n");
}






