#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int energy = 3;
int round_no = 1;
int started = 0;

int main(void) {
    int c;
    static struct termios oldt, newt;

    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON);

    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

	printf("Press enter to start\n");

    while ((c = getchar()) != 'q') {
        putchar(c);

		if (c) {
			printf("\n\n");
			printf("\e[1;1H\e[2J");

			printf("░██████╗░█████╗░███╗░░░███╗██╗░██████╗  ░█████╗░██╗░░██╗██╗███████╗\n");
			printf("██╔════╝██╔══██╗████╗░████║╚█║██╔════╝  ██╔══██╗╚██╗██╔╝██║██╔════╝\n");
			printf("╚█████╗░███████║██╔████╔██║░╚╝╚█████╗░  ███████║░╚███╔╝░██║█████╗░░\n");
			printf("░╚═══██╗██╔══██║██║╚██╔╝██║░░░░╚═══██╗  ██╔══██║░██╔██╗░██║██╔══╝░░\n");
			printf("██████╔╝██║░░██║██║░╚═╝░██║░░░██████╔╝  ██║░░██║██╔╝╚██╗██║███████╗\n");
			printf("╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝░░░╚═════╝░  ╚═╝░░╚═╝╚═╝░░╚═╝╚═╝╚══════╝\n");
			printf("\n");
			printf("███████╗███╗░░██╗███████╗██████╗░░██████╗░██╗░░░██╗  ░█████╗░░█████╗░██╗░░░██╗███╗░░██╗████████╗███████╗██████╗░\n");
			printf("██╔════╝████╗░██║██╔════╝██╔══██╗██╔════╝░╚██╗░██╔╝  ██╔══██╗██╔══██╗██║░░░██║████╗░██║╚══██╔══╝██╔════╝██╔══██╗\n");
			printf("█████╗░░██╔██╗██║█████╗░░██████╔╝██║░░██╗░░╚████╔╝░  ██║░░╚═╝██║░░██║██║░░░██║██╔██╗██║░░░██║░░░█████╗░░██████╔╝\n");
			printf("██╔══╝░░██║╚████║██╔══╝░░██╔══██╗██║░░╚██╗░░╚██╔╝░░  ██║░░██╗██║░░██║██║░░░██║██║╚████║░░░██║░░░██╔══╝░░██╔══██╗\n");
			printf("███████╗██║░╚███║███████╗██║░░██║╚██████╔╝░░░██║░░░  ╚█████╔╝╚█████╔╝╚██████╔╝██║░╚███║░░░██║░░░███████╗██║░░██║\n");
			printf("╚══════╝╚═╝░░╚══╝╚══════╝╚═╝░░╚═╝░╚═════╝░░░░╚═╝░░░  ░╚════╝░░╚════╝░░╚═════╝░╚═╝░░╚══╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝\n");
			printf("\n");

			printf("Instructions: \n");
			printf("Press '1' to decrement energy and '2' to increment energy\n");
			printf("Press the spacebar to go to next round\n");
			printf("Press 'n' to start a new game\n");
			printf("Press 'q' to exit this energy counter\n\n");

			if (c == '1') {
				if (energy != 0)
					energy -= 1;
			} else if (c == '2') {
				if (energy < 10)
					energy += 1;
			} else if (c == ' ') {
				round_no += 1;
				energy += 2;
				if (energy >= 10)
					energy = 10;
			} else if (c == 'n') {
				round_no = 1;
				energy = 3;
			}

			printf("Round %d\n", round_no);
			printf("Enemy's energy count: %d\n", energy);
		}
	}

    /*restore the old settings*/
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);


    return 0;
}