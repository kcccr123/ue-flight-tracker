#pragma once

#include "CoreMinimal.h"
#include "Flight.h"

class Airline
{
private:
    TArray<TSharedPtr<Flight>> flights;
    FString icao;

public:
    Airline(FString icao);

    int addFlight(TSharedPtr<Flight> flight);

    TArray<TSharedPtr<Flight>> getFlights();
};
