/** Iterate over primes using C primesieve_iterator, totalling modulus results (last digits). */

#include <primesieve.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>    // memcpy
#include <time.h>
#include <signal.h>
#include <stdlib.h>    // exit
#include <sys/types.h> // getpid
#include <unistd.h>    // getpid

#define BASES 59
#define HIDEZEROS

#define MEACH  1
#define MTOTS  2
//#define DMETH  MEACH
#define DMETH  MTOTS
#define VWIDTH "6"
#define TIME_TEST_COUNT_MIN 200   // every THIS loops we load the time
#define UPDATE_TIME 2             // every THIS seconds we update display

void _cursor(void) { printf("\033[?25h"); }
void _nocursor(void) { printf("\033[?25l"); }
void _interrupt(int dummy) { _cursor(); printf("\n"); exit(0); }
static void sig_tstp(int signo) {
	/* based on https://github.com/Arkham/c_examples/blob/master/apue/signals/sigtstp.c */
	sigset_t mask;
	/* here we should handle terminal change, move cursor, reset tty mode */
	printf("\nCome back soon (suspending)...\n");
	_cursor();
	/* unblock SIGTSTP, since it's blocked because we are handling it */
	sigemptyset(&mask);
	sigaddset(&mask, SIGTSTP);
	sigprocmask(SIG_UNBLOCK, &mask, NULL);
	/* reset disposition to default and send SIGTSTP to ourselves */
	signal(SIGTSTP, SIG_DFL);
	kill(getpid(), SIGTSTP);
	/* here we have resumed.  re-establish handler */
	signal(SIGTSTP, sig_tstp);
	/* hide cursor again */
	_nocursor();
}

void setup_suspend(void) {
	/* catch SIGTSTP only if shell supports job control */
	if (signal(SIGTSTP, SIG_IGN) == SIG_DFL)
		signal(SIGTSTP, sig_tstp);
}

int main() {
	time_t timest, timelast, timecur;
	primesieve_iterator it;
	primesieve_init(&it);
	uint64_t d[BASES+1][BASES];
	memset(&d, 0, (BASES+1)*BASES*sizeof(**d));

	uint64_t prime = 0;
	uint64_t count = 0;

	timecur = timelast = timest = time(NULL);
	/* iterate over the primes below 10^10 */
	printf("\033[2J");
	signal(SIGINT, _interrupt);
	setup_suspend(); // special handling of SIGTSTP
	_nocursor();
	while ((prime = primesieve_next_prime(&it)) < 10000000000ull) {
		char update_display;
		if (!(count % TIME_TEST_COUNT_MIN)) timecur = time(NULL);
		if (count > 1 && (timecur > timelast+UPDATE_TIME)) update_display=1;
		else update_display=0;

		if (update_display) printf("\033[2J");

		for (int base=2; base<=BASES; base++) {
			int mod;
			mod = prime % base;
#if DMETH == MEACH
			if (update_display)
				printf("Prime: %-20" PRIu64 ": %% %2d %2d  Tot: %" PRIu64 "\n",
					prime, base, mod, d[base][mod]);
#endif
			d[base][mod]++;
		}
		count++;
#if DMETH == MTOTS
		if (update_display) {
			printf("\033[H");
			printf("\033[44;33;1m Prime modulus distribution. \033[;1m X-axis is modulus result, Y is the base (of the modulus).\033[0m\n");
			printf(" Total primes tested: %" PRIu64 "  Current prime: %" PRIu64 "\n", count, prime);
			// Headers
			for (int base=1; base<BASES; base++) {
				if (base==1) printf("   |");
				printf("%"VWIDTH"d", base);
			}
			printf("\n");
			printf("---+");
			for (int i=1; i<BASES; i++) printf("------"); // vwidth
			printf("\n");
			
			timelast = timecur;
			for (int base=1; base<=BASES; base++) {
				printf("%2d |", base);
				for (int mod=1; mod<BASES; mod++) {
					double val = 100*((double)d[base][mod])/count;
#ifdef HIDEZEROS
					if ((int)val == 0) printf("      ");
					else printf("%"VWIDTH".2f", val);
#else
					printf("%"VWIDTH".2f", val);
#endif
				}
				printf("\n");
			}
		}
#endif
	}
	//sum += prime;

	//primesieve_free_iterator(&it);
	//printf("Sum of the primes below 10^10 = %" PRIu64 "\n", sum);
	return 0;
}

