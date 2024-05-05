import requests
import json
import os

# Prompt the user to enter the city name
city = input("Enter the city name: ")

# Construct the URL for weather API request
url = f"http://api.weatherapi.com/v1/current.json?key=e66a621b79094f6e868192429242904&q={city}"

# Send GET request to the Weather API
r = requests.get(url)

# Parse the JSON response
widc = json.loads(r.text)

# Extract the temperature from the response
temperature = widc["current"]["temp_c"]
print(f"Temperature in {city}: {temperature} degrees Celsius")

# Use text-to-speech synthesis to speak out the weather information
os.system(
    f"powershell.exe -Command \"Add-Type -AssemblyName System.Speech; (New-Object System.Speech.Synthesis.SpeechSynthesizer).Speak('Today''s weather of {city} is {temperature} degrees Celsius')\""
)
