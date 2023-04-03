#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int x, y, d, e;
int t = 2, r = 12, o = 3 * r;
void moon(char c1, char c2) {
	for (double v = t; v >= -t; v -= 0.05) {
		for (x = r; x >= -r; x --) {
			d = t * sqrt(r * r - x * x);
			e = v * sqrt(r * r - x * x) + d;
			for (y = 1; y < o - d; y ++) putchar(' ');
			for (; y < o + d - e + 1; y ++) putchar(c1);
			for (; y < o + d; y ++) putchar(c2);
			putchar(c2); puts("");
		}
		system("cls");
	}
}
main() {
	moon('*', ' ');
	moon(' ', '*');
}
