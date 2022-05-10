from ast import While
import datetime as dt
import pytz 
import requests
import matplotlib.pyplot as plt
import pandas as pd
from smbus import SMBus
import time
addr = 0x8
bus = SMBus(1)
arduino = 0
value = 0 
class weather_led_strip:
    def checkToApi():
        datah = ""
        """
        Settings:
        """
        postHistoricalURL = "https://api.tomorrow.io/v4/timelines"

        # get your key from app.tomorrow.io/development/keys

        apikey = "Insert api key"

        location = [""]

        fields = ["temperature",
        "precipitationType",
        "cloudCover",
        "precipitationIntensity"
        ]

        units = "metric"

        timesteps = ["current"]

        now = dt.datetime.now(pytz.UTC)

        timezone = "Europe/Oslo"
        """
        Gathering the data from the api.
        """
        body = {"location": location, "fields": fields, "units": units, "timesteps": timesteps, "timezone":timezone}
        response = requests.post(f'{postHistoricalURL}?apikey={apikey}', json=body)
        data = response.json()
        data = data["data"]["timelines"]
        """
        Converting the list that is recived to useable data
        """
        datah = str(data)
        datah = datah.replace("]","")
        datah = datah.replace("[","")
        datah = datah.replace("}","")
        datah = datah.replace("{","")
        datah = datah.replace(":","")
        datah = datah.replace("'","")
        datah = datah.replace(",","")
        datah = list(datah.split(" "))
        cloud = float(datah[-7])# Say how much cloud there is, it gives a value from 0 to 100. Which is a value showing procentage.
        amountOfRain = float(datah[-5])# Says amount of precipitation in mm/hr, it can look like 2,45 and 0,15. It is a value above 0
        weather = int(datah[-3])
        """ Gives a value based on what type of precipitation, 
            0 = no precipitation
            1 = rain
            2 = snow
            3 = freezing rain
            4 = ice pellet
        """
        temprature = float(datah[-1])#Gives a value in celsius ít can look like -5 and 12,5
        print(datah)

        if temprature >= 10:
            value = 10
        return value
    def send_data():
        return bus.write_byte(addr, arduino)
while True:
    arduino = weather_led_strip.checkToApi()
    weather_led_strip.send_data()
    time.sleep(500)
