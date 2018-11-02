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

Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv) {
  Airport* airport = (Airport*)malloc(sizeof(Airport));

  airport->gpsId = (char*)malloc(sizeof(char) * (strlen(gpsId) + 1));
  strcpy(airport->gpsId, gpsId);

  airport->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
  strcpy(airport->type, type);

  airport->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
  strcpy(airport->name, name);

  airport->latitude = latitude;

  airport->longitude = longitude;

  airport->elevationFeet = elevationFeet;

  airport->city = (char*)malloc(sizeof(char) * (strlen(city) + 1));
  strcpy(airport->city, city);

  airport->countryAbbrv =
      (char*)malloc(sizeof(char) * (strlen(countryAbbrv) + 1));
  strcpy(airport->countryAbbrv, countryAbbrv);

  return airport;
}

void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv) {
  airport->gpsId = (char*)malloc(sizeof(char) * (strlen(gpsId) + 1));
  strcpy(airport->gpsId, gpsId);

  airport->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
  strcpy(airport->type, type);

  airport->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
  strcpy(airport->name, name);

  airport->latitude = latitude;

  airport->longitude = longitude;

  airport->elevationFeet = elevationFeet;

  airport->city = (char*)malloc(sizeof(char) * (strlen(city) + 1));
  strcpy(airport->city, city);

  airport->countryAbbrv =
      (char*)malloc(sizeof(char) * (strlen(countryAbbrv) + 1));
  strcpy(airport->countryAbbrv, countryAbbrv);
}

char* airportToString(const Airport* a) {
  int n = strlen(a->gpsId) + strlen(a->type) + strlen(a->name) +
          strlen(a->city) + strlen(a->countryAbbrv) + sizeof(double) +
          sizeof(double) + sizeof(int);

  char* buff = (char*)malloc(sizeof(char) * (n + 300));

  sprintf(buff, "GPSID:      %s\nSize:       %s\nName:       %s\nLatitude-   %f\nLongitude-  %f\nElevation-  %dft\nCity:       %s\nCountry:    %s\n",
          a->gpsId, a->type, a->name,
          a->latitude, a->longitude, a->elevationFeet, a->city,
          a->countryAbbrv);

  return buff;
}

double getAirDistance(const Airport* origin, const Airport* destination) {
  int r = 6371;

  double rLatitudeA = ((origin->latitude) / 180) * M_PI;
  double rLatitudeB = ((destination->latitude) / 180) * M_PI;
  double rLongitudeA = ((origin->longitude) / 180) * M_PI;
  double rLongitudeB = ((destination->longitude) / 180) * M_PI;
  double rLongitudeDiffernce = rLongitudeB - rLongitudeA;

  return (acos((sin(rLatitudeA) * sin(rLatitudeB)) +
               (cos(rLatitudeA) * cos(rLatitudeB) * cos(rLongitudeDiffernce))) *
          r);
}

double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs) {
  int i = 0;
  int j = 1;
  int r = 6371;
  double totaldistince = 0;
  double distince = 0;

  while (j < size) {
    double rLatitudeA = (stops[i].latitude / 180) * M_PI;
    double rLatitudeB = (stops[j].latitude / 180) * M_PI;
    double rLongitudeA = (stops[i].longitude / 180) * M_PI;
    double rLongitudeB = (stops[j].longitude / 180) * M_PI;
    double rLongitudeDiffernce = rLongitudeB - rLongitudeA;

    distince =
        acos((sin(rLatitudeA) * sin(rLatitudeB)) +
             (cos(rLatitudeA) * cos(rLatitudeB) * cos(rLongitudeDiffernce))) *
        r;

    totaldistince += distince;
    j++;
    i++;
  }

  return ((totaldistince / aveKmsPerHour) + (aveLayoverTimeHrs * (size - 1)));
}
