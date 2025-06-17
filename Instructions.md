📘 [Click here for Full Instructions](Instructions.md)
🕷️ SPydeRR: The Spider-Themed Voice-Controlled Robot (Beginner-Friendly Guide)
Link to the robot: ACEBOTT ESP8266 Quadruped Bionic Spider Robot

🧠 What is This Project?
SPydeRR is a spider-like robot that walks, turns, and moves based on your voice commands! It uses:
	•	Python for voice control and intelligence
	•	Arduino (ESP8266) for moving the robot legs using 8 servos

📦 What You Need
🔌 Hardware:
	•	The ACEBOTT ESP8266 Spider Robot kit
	•	4x AA Battery holder (or Li-ion 6V pack)
	•	Jumper wires
	•	USB cable for programming
	•	Laptop with Internet

🧰 Software:
	•	Arduino IDE
	•	Python 3.8+
	•	Required Python libraries
	•	USB drivers (CP2102 or CH340 if needed)

⚙️ How it Works
Component
Role
ESP8266
Brain that controls servo motors
Servos (8)
Legs of the spider
Python Script
Voice assistant that sends commands to Arduino
Serial Port
Connects Python (brain) to Arduino (body)


🛠️ Step-by-Step Instructions
✅ STEP 1: Set Up Arduino IDE
	1	Download Arduino IDE from arduino.cc
	2	Go to File > Preferences and add this board URL: bash Copy code   http://arduino.esp8266.com/stable/package_esp8266com_index.json
	3	  
	4	Go to Tools > Board > Boards Manager
	◦	Search for ESP8266 and install it
	5	Select the board:
	◦	Go to Tools > Board > NodeMCU 1.0 (ESP-12E Module) or Generic ESP8266 Module
	6	Select the correct port:
	◦	Go to Tools > Port and choose the USB port (e.g., /dev/cu.usbserial-0001)

✅ STEP 2: Upload the Arduino Code
	1	Open arduino_movement.ino in Arduino IDE.
	2	Make sure the board and port are selected.
	3	Click Upload (→).
	4	After upload:
	◦	You’ll see Done uploading.
	◦	The servos may twitch once (that's good!)

✅ STEP 3: Power the Robot Safely
	•	Connect:
	◦	Servo RED wires to battery positive (+)
	◦	Servo BLACK/BROWN wires to battery negative (–)
	◦	Also connect battery negative (–) to ESP8266 GND
	•	Plug in the battery pack (the robot is now powered)

✅ STEP 4: Install Python & Dependencies
	1	Install Python from python.org
	2	Open Terminal or Command Prompt.
	3	Navigate to the folder with your project.
	4	Run: bash Copy code   pip install -r requirements.txt
	5	  

✅ STEP 5: Run the Python Voice Assistant
	1	Connect your robot via USB (again) — this is for communication only, not servo power.
	2	In Terminal: bash Copy code   python3 spyderr_robot.py
	3	  
	4	You’ll hear: css Copy code   "Hello! I am SPydeRR. How can I assist you today?"
	5	  
	6	Speak commands like:
	◦	“Tell me a joke”
	◦	“What’s the weather in Agra”
	◦	“Search for spider robot”
	◦	“Goodbye SPydeRR” (to exit)

🔁 How Arduino + Python Work Together
	1	Python listens to your voice.
	2	Python responds with voice and sends commands via Serial (USB).
	3	Arduino receives text like walk_forward\n and moves the legs accordingly.

🧪 Troubleshooting
Problem
Solution
Board not detected
Check USB cable and drivers (CH340/CP2102)
No leg movement
Check battery pack and servo wiring
Python error
Ensure Python 3 and libraries are installed
Voice not recognized
Try speaking slowly and clearly


⚡ Future Ideas
	•	Add gesture controls
	•	Add obstacle sensors
	•	Add WiFi commands

🧑‍💻 Author
Created by [Your Name]
GitHub: https://github.com/yourusername
