#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int s, v, walktime, totaltime, outtime, hour = 8;
	cin >> s >> v;
	if (s % v == 0) {
		walktime = s / v;
	} else {
		walktime = s / v + 1;
	}
	totaltime = walktime + 10;
	outtime = 1440 - totaltime;
	while ( outtime >= 60) {
		hour++;
		outtime -= 60;
		if (hour >= 24) {
			hour -= 24;
		}
	}

	printf("%02d:%02d", hour, outtime);
	cout << hour << outtime << endl;
	return 0;
}