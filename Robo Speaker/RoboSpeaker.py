import os

# Path for PowerShell command to enable text-to-speech
path = "powershell.exe -Command \"Add-Type -AssemblyName System.Speech; (New-Object System.Speech.Synthesis.SpeechSynthesizer)\""

if __name__ == "__main__":
    print("Welcome to Gyanendra RodoSpeaker!")
    print("Enter text to have it pronounced. Type 'q' to exit.")
    
    # Continuous input loop
    while True:
        x = input("Enter what you want to pronounce: ")
        if x.lower() == "q":  # Press 'q' to stop
            os.system(f"{path}.Speak('Goodbye, friends')")
            break
        elif os.name == "nt":  # Checking if the operating system is Windows
            command = f"{path}.Speak('{x}')"
        else:
            command = f"{x}"
        
        # Execute the command for text-to-speech
        os.system(command)

# Note: Uncomment the following multiline comment if you want to include it as a docstring
"""
Gyanendra's, a dedicated Python enthusiast from India, exudes a passion for programming that permeates his projects. With a keen eye for detail and an unwavering commitment to excellence, he immerses himself in the intricacies of code, continually expanding his skill set. Whether delving into complex algorithms or crafting elegant solutions, Gyanendra approaches each challenge with tenacity and creativity. His journey in the realm of technology is not only marked by technical prowess but also by a profound desire to make a meaningful impact. Through his endeavors, Gyanendra exemplifies the boundless potential of determination and ingenuity in the world of software development.
"""
