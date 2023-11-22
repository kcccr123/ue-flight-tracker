import pandas as pd
import sqlite3
from sqlalchemy import create_engine
from FlightRadar24 import FlightRadar24API
import schedule
import time


#sqlite setup

cnx = sqlite3.connect('test.db')
if cnx:
    unreal.log("connected")

e = create_engine('sqlite://')

#flight radar config
fr_api = FlightRadar24API()
flight_tracker = fr_api.get_flight_tracker_config()
fr_api.set_flight_tracker_config(flight_tracker)



def get_data():
    unreal.log("running get_data func")

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
        
    #print(df.iloc[25])
    unreal.log("attempting pushing to db")
    df.to_sql(name='flight_data', con=cnx, if_exists='replace')
    unreal.log("pushed to db")

    unreal.log("finished get_data")
        
schedule.every(5).seconds.do(get_data)


while True:
    schedule.run_pending()
    time.sleep(1)