import datetime as dt
import pytz 
import requests
import matplotlib.pyplot as plt
import pandas as pd
datah = ""
postHistoricalURL = "https://api.tomorrow.io/v4/timelines"

# get your key from app.tomorrow.io/development/keys
apikey = "OcZAVVfHBDZL40M2k64SLa0KsSRDVGym"

location = [57.685736, 11.978515]

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
print(cloud)
print(weather)
print(temprature)
if temprature >= 10:
    print("warm")
# storterat efter weather, sedan temperatur och sist moln (i prioritet) 
# klart väder
if temprature < 0 and cloud < 10 and weather == 0:
    print(1)
if temprature < 0 and cloud < 50 and weather == 0:
    print(2)
if temprature < 0 and cloud < 100 and weather == 0:
    print(3)

if temprature < 10 and cloud < 10 and weather == 0:
    print(0)
if temprature < 10 and cloud < 50 and weather == 0:
    print(0)
if temprature < 10 and cloud < 100 and weather == 0:
    print(0)

if temprature < 15 and cloud < 10 and weather == 0:
    print(0)
if temprature < 15 and cloud < 50 and weather == 0:
    print(0)
if temprature < 15 and cloud < 100 and weather == 0:
    print(0)

if temprature < 20 and cloud < 10 and weather == 0:
    print(0)
if temprature < 20 and cloud < 50 and weather == 0:
    print(0)
if temprature < 20 and cloud < 100 and weather == 0:
    print(0)

if temprature < 60 and cloud < 10 and weather == 0:
    print(0)
if temprature < 60 and cloud < 50 and weather == 0:
    print(0)
if temprature < 60 and cloud < 100 and weather == 0:
    print(0)

# regn
if temprature < 0 and cloud < 0 and weather == 1:
    print(0)
if temprature < 0 and cloud < 0 and weather == 1:
    print(0)
if temprature < 0 and cloud < 0 and weather == 1:
    print(0)

if temprature < 10 and cloud < 10 and weather == 1:
    print(0)
if temprature < 10 and cloud < 50 and weather == 1:
    print(0)
if temprature < 10 and cloud < 100 and weather == 1:
    print(0)

if temprature < 15 and cloud < 10 and weather == 1:
    print(0)
if temprature < 15 and cloud < 50 and weather == 1:
    print(0)
if temprature < 15 and cloud < 100 and weather == 1:
    print(0)

if temprature < 20 and cloud < 10 and weather == 1:
    print(0)
if temprature < 20 and cloud < 50 and weather == 1:
    print(0)
if temprature < 20 and cloud < 100 and weather == 1:
    print(0)

if temprature < 60 and cloud < 10 and weather == 1:
    print(0)
elif temprature < 60 and cloud < 50 and weather == 1:
    print(0)
elif temprature < 60 and cloud < 100 and weather == 1:
    print(0)

# snö
if temprature < 0 and cloud < 0 and weather == 2:
    print(0)
if temprature < 0 and cloud < 0 and weather == 2:
    print(0)
if temprature < 0 and cloud < 0 and weather == 2:
    print(0)

if temprature < 10 and cloud < 10 and weather == 2:
    print(0)
if temprature < 10 and cloud < 50 and weather == 2:
    print(0)
if temprature < 10 and cloud < 100 and weather == 2:
    print(0)

