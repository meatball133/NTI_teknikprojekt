import datetime as dt
import pytz 
import requests
import matplotlib.pyplot as plt
import pandas as pd
import RPi.GPIO as GPIO
import pigpio
led_pin = 17
led_pin2 = 22
led_pin3 = 24
GPIO.setmode(GPIO.BCM)
GPIO.setup(led_pin, GPIO.OUT)
GPIO.setup(led_pin2, GPIO.OUT)
GPIO.setup(led_pin3, GPIO.OUT)

datah = ""
postHistoricalURL = "https://api.tomorrow.io/v4/timelines"

# get your key from app.tomorrow.io/development/keys
apikey = "Insert api key"

location = ["Location (cordinates)"]

fields = ["temperature",
"precipitationType",
"cloudCover"
]

units = "metric"

timesteps = ["current"]

now = dt.datetime.now(pytz.UTC)

timezone = "Europe/Oslo"


body = {"location": location, "fields": fields, "units": units, "timesteps": timesteps, "timezone":timezone}
response = requests.post(f'{postHistoricalURL}?apikey={apikey}', json=body)
data = response.json()
data = data["data"]["timelines"]
datah = str(data)
datah = datah.replace("]","")
datah = datah.replace("[","")
datah = datah.replace("}","")
datah = datah.replace("{","")
datah = datah.replace(":","")
datah = datah.replace("'","")
datah = datah.replace(",","")
datah = list(datah.split(" "))
cloud = float(datah[-5])
weather = int(datah[-3])
temprature = float(datah[-1])

if temprature >= 10:
    pi = pigpio.pi()
    pi.set_PWM_dutycycle(17, 100)
