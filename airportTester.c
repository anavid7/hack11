/**
* Author(s): David Ryan, Collin Sipple, Victor Nguyen
* Date Created: 11/1/2018
* Date Modified: 11/1/2018
* Class: CSCE155e
* Professor: Dr. Chris Bourke
* NUID: 47810715
*/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "airport.h"


int main(int argc, char **argv) {


Airport* laAirport = createAirport("LAX", "lrg", "Los Angeles International Airport", 33.9416, -118.4085, 125, "Los Angeles, California", "USA");
Airport* jfkAirport = createAirport("JFK", "lrg", "John F. Kennedy International Airport", 40.6413, -73.7781, 13, "Queens, New York", "USA");
Airport* lincolnAirport = createAirport("LNK", "sml", "Lincoln Airport", 40.8507, -96.7581, 1219, "Lincoln, Nebraska", "USA");
Airport* atlantaAirport = createAirport("1341", "sdkflj", "Hartsfield–Jackson Atlanta International Airport", 5, 928198, 7, "Atlanta, Gerogia", "Coding is great!!");
Airport* omahaAirport = createAirport("We gunna win", "Suppppper big", "Eppley Airfield", 41324.3019, -923523, 333333, "Omaha, Nebraska", "coding is better then pizza");
Airport* sydenyAirport = createAirport("once upon a time", "There was a frog", "who went to the lake", -3334, 0, 0, "and went for a", "swim");
//Airport* beijingAirport = createAirport("PEK", "lrg", "Beijing Capital International Airport", 40.0799, 116.6031, 115, "Beijing, China", "CHI");
//Airport* dubaiAirport = createAirport("DXB", "lrg", "Dubai International Airport", 25.2532, 55.3657, 62, "Dubai, United Arab Emirates", "UAE");
// Airport* charlesAirport = createAirport("CDG", "lrg", "Charles de Gaulle Airport", 49.0097, 2.5479, 390, "France, France", "FRA");
// Airport* amsterdamAirport = createAirport("AMS", "lrg", "Amsterdam Airport Schiphol", 52.3105, 4.7683, "Amsterdam, Netherlands", "NTH");
// Airport* denverAirport = createAirport("DEN", "med", "Denver International Airport", 39.8561, -104.6737, "Denver, Colorado", "USA");


printf("\n***airportToString Function Test***\n");
printf("%s\n", airportToString(laAirport));
printf("%s\n", airportToString(jfkAirport));
printf("%s\n", airportToString(lincolnAirport));

printf("\n***initAirport Function Test***\n");
printf("Incorect Initialized Airport Strings:\n");
printf("%s\n", airportToString(atlantaAirport));
printf("%s\n", airportToString(omahaAirport));
printf("%s\n", airportToString(sydenyAirport));
printf("\nCorrected Strings:\n");
initAirport(atlantaAirport, "ATL", "lrg", "Hartsfield–Jackson Atlanta International Airport", 33.6407, -84.4277, 1027, "Atlanta, Gerogia", "USA");
initAirport(omahaAirport, "OMH", "sml", "Eppley Airfield", 41.3019, -95.8937, 984, "Omaha, Nebraska", "USA");
initAirport(sydenyAirport, "SYD", "lrg", "Sydney Airport", -33.9399, 151.1753, 30, "Sydney, Australia", "AUS");
printf("%s\n", airportToString(atlantaAirport));
printf("%s\n", airportToString(omahaAirport));
printf("%s\n", airportToString(sydenyAirport));

return 0;
}
