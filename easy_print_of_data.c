#include <stdio.h>

//This is easy program that scans info(3 fields) is typed in terminal and after prints it.
int main()

{
	float latitude;
	float longitude;
	char info[80];
	int started = 0;

	puts ("data = [");
	while (scanf ("%f, %f,%79[^\n]", &latitude, &longitude, info) == 3) {
		if (started)
			printf (",\n");
		else
			started = 1;
		if ((latitude< -90) || (latitude > 90)) {
			fprintf (stderr, "Error!!! invalid latitude: %f\n", latitude);
			return 2;
		}
		if ((longitude < -180) || (longitude > 180)) {
			fprintf(stderr, "Erooor!!! Invalid longitude: %f", longitude );
			return 2;
		}
		printf ("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
	}

	puts ("\n");
	return 0;

}