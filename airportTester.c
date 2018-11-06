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
Airport* beijingAirport = createAirport("PEK", "lrg", "Beijing Capital International Airport", 40.0799, 116.6031, 115, "Beijing, China", "CHI");
Airport* dubaiAirport = createAirport("DXB", "lrg", "Dubai International Airport", 25.2532, 55.3657, 62, "Dubai, United Arab Emirates", "UAE");
Airport* charlesAirport = createAirport("CDG", "lrg", "Charles de Gaulle Airport", 49.0097, 2.5479, 390, "France, France", "FRA");
Airport* amsterdamAirport = createAirport("AMS", "lrg", "Amsterdam Airport Schiphol", 52.3105, 4.7683,  -9, "Amsterdam, Netherlands", "NTH");
Airport* denverAirport = createAirport("DEN", "med", "Denver International Airport", 39.8561, -104.6737, 5430, "Denver, Colorado", "USA");


printf("\n***airportToString Function Test***\n");
//converts Airport type to string and prints result
printf("%s\n", airportToString(laAirport));
printf("%s\n", airportToString(jfkAirport));
printf("%s\n", airportToString(lincolnAirport));
printf("%s\n", airportToString(charlesAirport));
printf("%s\n", airportToString(amsterdamAirport));

printf("\n***initAirport Function Test***\n");
//prints incorect airport strings
printf("Incorect Initialized Airport Strings:\n");
printf("%s\n", airportToString(atlantaAirport));
printf("%s\n", airportToString(omahaAirport));
printf("%s\n", airportToString(sydenyAirport));
printf("Corrected Strings:\n");
//corrects the airport strings using initAirport function
initAirport(atlantaAirport, "ATL", "lrg", "Hartsfield–Jackson Atlanta International Airport", 33.6407, -84.4277, 1027, "Atlanta, Gerogia", "USA");
initAirport(omahaAirport, "OMH", "sml", "Eppley Airfield", 41.3019, -95.8937, 984, "Omaha, Nebraska", "USA");
initAirport(sydenyAirport, "SYD", "lrg", "Sydney Airport", -33.9399, 151.1753, 30, "Sydney, Australia", "AUS");
//prints correct airport string
printf("%s\n", airportToString(atlantaAirport));
printf("%s\n", airportToString(omahaAirport));
printf("%s\n", airportToString(sydenyAirport));

//prints distince from two airports using getAirDistance function
printf("\n***getAirDistance Function Test***\n");
printf("Distince from Beijing Airport to Denver Airport: %fmi\n", getAirDistance(beijingAirport, denverAirport));
if (fabs((getAirDistance(beijingAirport, denverAirport)) - 10191.085441) < 0.01) {
  printf("Sucessful calculation! \n");
}
printf("Distince from Beijing Airport to Dubai Airport: %fmi\n", getAirDistance(beijingAirport, dubaiAirport));
if (fabs((getAirDistance(beijingAirport, dubaiAirport)) == 5846.494940) < 0.01) {
  printf("Sucessful calculation! \n");
}
printf("Distince from Denver Airport to Dubai Airport: %fmi\n", getAirDistance(denverAirport, dubaiAirport));
if (fabs((getAirDistance(denverAirport, dubaiAirport)) == 12485.293964) < 0.01){
  printf("Sucessful calculation! \n");
}

  Airport* list = (Airport*) malloc(sizeof(Airport) * 4);
  initAirport(&list[0], "ATL", "lrg", "Hartsfield–Jackson Atlanta International Airport", 33.6407, -84.4277, 1027, "Atlanta, Gerogia", "USA");
  initAirport(&list[1], "OMH", "sml", "Eppley Airfield", 41.3019, -95.8937, 984, "Omaha, Nebraska", "USA");
  initAirport(&list[2], "SYD", "lrg", "Sydney Airport", -33.9399, 151.1753, 30, "Sydney, Australia", "AUS");
  initAirport(&list[3], "LNK", "sml", "Lincoln Airport", 40.8507, -96.7581, 1219, "Lincoln, Nebraska", "USA");
  printf("Trip one has an estimated time of: %f\n", getEstimatedTravelTime(list, 4, 657, 1));

  Airport* list1 = (Airport*) malloc(sizeof(Airport) * 4);
  initAirport(&list[0], "AMS", "lrg", "Amsterdam Airport Schiphol", 52.3105, 4.7683,  9, "Amsterdam, Netherlands", "NTH");
  initAirport(&list[1], "LAX", "lrg", "Los Angeles International Airport", 33.9416, -118.4085, 125, "Los Angeles, California", "USA");
  initAirport(&list[2], "JFK", "lrg", "John F. Kennedy International Airport", 40.6413, -73.7781, 13, "Queens, New York", "USA");
  initAirport(&list[3], "DEN", "med", "Denver International Airport", 39.8561, -104.6737, 5430, "Denver, Colorado", "USA");
  printf("Trip two has an estimated time of: %f\n", getEstimatedTravelTime(list1, 4, 872, 2));

  Airport* list2 = (Airport*) malloc(sizeof(Airport) * 4);
  initAirport(&list[0], "LNK", "sml", "Lincoln Airport", 40.8507, -96.7581, 1219, "Lincoln, Nebraska", "USA");
  initAirport(&list[1], "SYD", "lrg", "Sydney Airport", -33.9399, 151.1753, 30, "Sydney, Australia", "AUS");
  initAirport(&list[2], "JFK", "lrg", "John F. Kennedy International Airport", 40.6413, -73.7781, 13, "Queens, New York", "USA");
  initAirport(&list[3], "LNK", "sml", "Lincoln Airport", 40.8507, -96.7581, 1219, "Lincoln, Nebraska", "USA");
  printf("Trip one has an estimated time of: %f\n", getEstimatedTravelTime(list2, 4, 1000, 3));

return 0;
}
