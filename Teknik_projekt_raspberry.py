#required libaries:
import datetime as dt
import pytz 
import requests
import matplotlib.pyplot as plt
import pandas as pd
from smbus import SMBus
import time
addr = 0x8 #Say which port the smbus is going to use
bus = SMBus(1)# Deffine that SMBus(1) has the same name as bus
arduino = 0
value = 0 
class weather_led_strip: # This is a group of functions
    def checkToApi(): # This is a function
        datah = ""
        """
        Settings:
        """
        postHistoricalURL = "https://api.tomorrow.io/v4/timelines"

        apikey = "Insert api key"# get your key from app.tomorrow.io/development/keys

        location = [""]# Input cordinates

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
        Gathering the data from the api:
        """
        body = {"location": location, "fields": fields, "units": units, "timesteps": timesteps, "timezone":timezone}
        response = requests.post(f'{postHistoricalURL}?apikey={apikey}', json=body)
        data = response.json()
        data = data["data"]["timelines"]
        """
        Converting the list that is recived to useable data:
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
        temprature = float(datah[-1])#Gives a value in celsius it can look like -5 and 12,5
        print(datah)
        """
        Convert the weather to diffrent data points:
        """
        #ingen nederbörd
        if temprature < 0 and cloud < 10 and weather == 0:
            value = 1
        elif temprature < 0 and cloud < 50 and weather == 0:
            value = 2
        elif temprature < 0 and cloud < 100 and weather == 0:
            value = 3

        elif temprature < 10 and cloud < 10 and weather == 0:
            value = 4
        elif temprature < 10 and cloud < 50 and weather == 0:
            value = 5
        elif temprature < 10 and cloud < 100 and weather == 0:
            value = 6

        elif temprature < 15 and cloud < 10 and weather == 0:
            value = 7
        elif temprature < 15 and cloud < 50 and weather == 0:
            value = 8
        elif temprature < 15 and cloud < 100 and weather == 0:
            value = 9

        elif temprature < 20 and cloud < 10 and weather == 0:
            value = 10
        elif temprature < 20 and cloud < 50 and weather == 0:
            value = 11
        elif temprature < 20 and cloud < 100 and weather == 0:
            value = 12

        elif temprature < 60 and cloud < 10 and weather == 0:
            value = 13
        elif temprature < 60 and cloud < 50 and weather == 0:
            value = 14
        elif temprature < 60 and cloud < 100 and weather == 0:
            value = 15

        # regn
        if temprature < 0 and cloud < 10 and weather == 1:
            value = 16
        elif temprature < 0 and cloud < 50 and weather == 1:
            value = 17
        elif temprature < 0 and cloud < 100 and weather == 1:
            value = 18

        elif temprature < 10 and cloud < 10 and weather == 1:
            value = 19
        elif temprature < 10 and cloud < 50 and weather == 1:
            value = 20
        elif temprature < 10 and cloud < 100 and weather == 1:
            value = 21

        elif temprature < 15 and cloud < 10 and weather == 1:
            value = 22
        elif temprature < 15 and cloud < 50 and weather == 1:
            value = 23
        elif temprature < 15 and cloud < 100 and weather == 1:
            value = 24

        elif temprature < 20 and cloud < 10 and weather == 1:
            value = 25
        elif temprature < 20 and cloud < 50 and weather == 1:
            value = 26
        elif temprature < 20 and cloud < 100 and weather == 1:
            value = 27

        elif temprature < 60 and cloud < 10 and weather == 1:
            value = 28
        elif temprature < 60 and cloud < 50 and weather == 1:
            value = 29
        elif temprature < 60 and cloud < 100 and weather == 1:
            value = 30

        # snö
        if temprature < 0 and cloud < 0 and weather == 2:
            value = 31
        elif temprature < 0 and cloud < 0 and weather == 2:
            value = 32
        elif temprature < 0 and cloud < 0 and weather == 2:
            value = 33

        elif temprature < 10 and cloud < 10 and weather == 2:
            value = 34
        elif temprature < 10 and cloud < 50 and weather == 2:
            value = 35
        elif temprature < 10 and cloud < 100 and weather == 2:
            value = 36


        return value # Skickar vidare value värdet
    def send_data(): # A function that sends the value from the function checkToApi to the Arduino
        return bus.write_byte(addr, arduino)
while True: #This loops run forever
    arduino = weather_led_strip.checkToApi() #Runs the weather data function
    weather_led_strip.send_data()#Runs the send data function
    time.sleep(500) #Pause the script for 5 min
