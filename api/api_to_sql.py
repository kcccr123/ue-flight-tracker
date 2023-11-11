import pandas as pd
from FlightRadar24 import FlightRadar24API
import sqlite3
from sqlalchemy import create_engine


#sqlite setup

cnx = sqlite3.connect('test.db')
e = create_engine('sqlite://')




#flight radar dataframe
df = pd.DataFrame(columns=['origin', 'destination', 'callsign', 'lat', 'lng', 'atd']) 


#flight radar config
fr_api = FlightRadar24API(...)
flight_tracker = fr_api.get_flight_tracker_config()
fr_api.set_flight_tracker_config(flight_tracker)


#getting flight data we want and adding it to pandas df
flights = fr_api.get_flights()
for flight in flights:
    #print(flight.origin_airport_iata)
    #print(flight.destination_airport_iata)
    #print(flight.aircraft_code)
    #print(flight.altitude)
    #print(flight.longitude)
    #print(flight.latitude)

    df.loc[len(df.index)] = [flight.origin_airport_iata,
                         flight.destination_airport_iata,
                         flight.aircraft_code,
                         flight.latitude,
                         flight.longitude,
                         flight.altitude]

print(df)

df.to_sql(name='flight_data', con=cnx)