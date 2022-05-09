import datetime as dt
import pytz 
import requests
import matplotlib.pyplot as plt
import pandas as pd

#class weather_led_strip(self):
#def CheckToApi(self):
datah = ""
postHistoricalURL = "https://api.tomorrow.io/v4/timelines"

# get your key from app.tomorrow.io/development/keys
apikey = "Insert api key"

location = ["Location (cordinates)"]

fields = ["temperature",
"precipitationType",
"cloudCover",
"precipitationIntensity"
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
cloud = float(datah[-7])
AmountOfRain = float(datah[-5])
weather = int(datah[-3])
temprature = float(datah[-1])
print(datah)

if temprature >= 10:
    print("warm")
