import pandas as pd
import sqlite3
from sqlalchemy import create_engine
from FlightRadar24 import FlightRadar24API

import os

print("Current working directory:", os.getcwd())

#sqlite setup
cnx = sqlite3.connect('test.db')


e = create_engine('sqlite://')
#flight radar config
fr_api = FlightRadar24API()
flight_tracker = fr_api.get_flight_tracker_config()
fr_api.set_flight_tracker_config(flight_tracker)



def get_data():
    #flight radar dataframe, reset it to empty
    df = pd.DataFrame(columns=['origin', 'destination', 'callsign', 'airline','lat', 'lng', 'atd', 'heading']) 

    #getting flight data we want and adding it to pandas df
    flights = fr_api.get_flights()
    for flight in flights:
        df.loc[len(df.index)] = [flight.origin_airport_iata,
                            flight.destination_airport_iata,
                            flight.callsign,
                            flight.airline_icao,
                            flight.latitude,
                            flight.longitude,
                            flight.altitude,
                            flight.heading]
        
    print(df.iloc[25])
    df.to_sql(name='flight_data', con=cnx, if_exists='replace')

get_data()