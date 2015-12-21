#include <stdio.h>
#include <string.h>

//This program is to find a necessary track in a list of tracks.

char tracks[][80] = {
	"I left my heart in Harvard Med School",
	"Newark, Newark - a wonderful town",
	"Dancing with a Dork",
	"From here to maternity",
	"The girl from Iwo Jima",
};

void find_track(char track_name[])
{
	int i;
	for (i = 0; i < 5; i++) {
	
		if (strstr(tracks[i], track_name)) {
			printf ("Track %i: '%s'\n", i, tracks[i]);
		}
	}
}

int main()
{
	char track_name[80];
	char *pos;
	printf ("Enter a track, please: ");
	fgets (track_name, 80, stdin);

	if ((pos = strchr(track_name, '\n')) != NULL){
    	*pos = '\0';
	}

	find_track(track_name);
}