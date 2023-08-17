#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section . Contains the user-defined datatypes for the race

//Race datatype
struct Race{
  int numberOfLaps;
  int currentLap;
  char *firstPlaceDriverName;
  char *firstPlaceRaceCarColor;
};

//RaceCar datatype
struct RaceCar{
  char *driverName;
  char *raceCarColor;
  int totalLapTime;
};

// Print functions section

// A fun introduction message
void printIntro(void){
  printf("\nWelcome to our main event digital race fans!\nI hope everybody has their snacks because we are about to begin!\n");
}

//A race count down message
void printCountDown(void){
  printf("\nRacers Ready! In...\n5\n4\n3\n2\n1\nRace!\n");
}

//Informs the audience of the race leader after every lap
void printFirstPlaceAfterLap(struct Race race){
printf("\nAfter lap number %d\nFirst Place Is: %s in the %s race car!\n", race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

//Prints a congratulatory message to the winner and informs the audience the race is over
void printCongratulation(struct Race race){
printf("\nLet's all congratulate %s in the %s race car for an amazing performance.\nIt truly was a great race and everybody have a goodnight!\n\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

// Logic functions section

//Calculates the time it takes a race car to complete a lap.
//The variables that sum up the time are initialized to a random number between 1 and 3
int calculateTimeToCompleteLap(void){
  int speed = (rand() %3) + 1;
  int acceleration = (rand() %3) + 1;
  int nerves = (rand() %3) + 1;
  return speed + acceleration + nerves;
}

/*
Computes the total time for which a race car has been racing
The total lap time is a sum of the initial value and the time it took to complete a lap.
The input parameter is a pointer to a RaceCar struct datatype.
It has no output.
*/ 
void updateRaceCar(struct RaceCar* raceCar){
raceCar->totalLapTime += calculateTimeToCompleteLap();
}

/*
Computes who the new first place driver is and what car color they are driving.
The RaceCar with the lowest total lap time wins the lap
The input parameters are the pointers to the race and RaceCar struct datatypes
It has no Output
*/
void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2){
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime){
    race->firstPlaceDriverName = raceCar1->driverName;
    race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
    }
  else {
    race->firstPlaceDriverName = raceCar2->driverName;
    race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
  }
}

/*
Starts the race between two RaceCars while initializing the race with the desired number of laps(5) and current(1).
For each lap, it updates the total lap time for each race car, computes the first place winner, prints the first place information, and increases the current lap by 1. And prints out the congratulatory message after the final lap.
Its input parameters are pointers to the RaceCar datatypes.
Its has no output.
*/
void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2){
struct Race race = {5,1,"",""};
for (int i = 0; i < race.numberOfLaps; i++){
  updateRaceCar(raceCar1);
  updateRaceCar(raceCar2);
  updateFirstPlace(&race, raceCar1, raceCar2);
  printFirstPlaceAfterLap(race);
  race.currentLap++;
}
printCongratulation(race);
}


int main() {
	srand(time(0));
  //Create & initialize two race car Data types-- each representing a racer
  struct RaceCar r1 = {"Bobo", "Green",5};
  struct RaceCar r2 = {"Bolu","Red",5};
  //print the intro message
  printIntro();
  //print the countdown message
  printCountDown();
  //start the race
  startRace(&r1,&r2);
};