import speech_recognition as sr
import pyttsx3
import serial
import time

# Initialize text-to-speech engine and speech recognizer
engine = pyttsx3.init()
recognizer = sr.Recognizer()

# Adjust this to your serial port
SERIAL_PORT = '/dev/tty.usbserial-0001'  # Change accordingly
BAUD_RATE = 9600

try:
    arduino = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=2)
    time.sleep(2)  # Wait for Arduino connection to stabilize
except serial.SerialException:
    print(f"Error: Could not open serial port {SERIAL_PORT}")
    exit(1)

def speak(text):
    print(f"SPYDERR: {text}")
    engine.say(text)
    engine.runAndWait()

def listen():
    with sr.Microphone() as source:
        recognizer.adjust_for_ambient_noise(source)
        print("Listening...")
        try:
            audio = recognizer.listen(source, phrase_time_limit=4)
            command = recognizer.recognize_google(audio)
            print(f"You said: {command}")
            return command.lower()
        except sr.UnknownValueError:
            speak("Sorry, I didn't catch that.")
        except sr.RequestError:
            speak("Speech service is unavailable right now.")
        return ""

def send_command_to_arduino(cmd):
    try:
        arduino.write((cmd + '\n').encode())
        # Optional: wait for response from Arduino (if implemented)
        # response = arduino.readline().decode().strip()
        # print(f"Arduino: {response}")
    except serial.SerialException:
        speak("Error communicating with the robot.")

def handle_command(command):
    if "walk" in command:
        send_command_to_arduino("walk")
        speak("Walking forward")
    elif "ripple" in command:
        send_command_to_arduino("ripple")
        speak("Doing ripple walk")
    elif "left" in command:
        send_command_to_arduino("left")
        speak("Turning left")
    elif "dance" in command:
        send_command_to_arduino("dance")
        speak("Let's dance")
    elif "stop" in command or "quit" in command or "exit" in command:
        speak("Goodbye!")
        arduino.close()
        exit(0)
    else:
        speak("I don't know that command")

if __name__ == "__main__":
    speak("SPYDERR online and listening for your commands.")
    try:
        while True:
            cmd = listen()
            if cmd:
                handle_command(cmd)
    except KeyboardInterrupt:
        speak("Shutting down. Bye!")
        arduino.close()
