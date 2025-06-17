📖 [Read Full Instructions](go to wiki and then click on instructions to deeply understand)

# SPydeRR Robot 🕷️

**SPydeRR** is an intelligent spider-themed quadruped robot built with a combination of Arduino (ESP8266) and Python. It features voice interaction, web search, jokes, weather updates, and physical movement — powered by servos and AI.

## 🧠 Features
- Voice-controlled assistant (Python-based)
- Real-world robot movement (Arduino-controlled)
- Jokes, weather, and search with speech responses
- Spider-style motion control via 8 servo legs

## 📦 What's Inside?
- `spyderr_robot.py` - Python code for voice assistant & logic
- `arduino_movement.ino` - Arduino code to control the robot's legs
- `requirements.txt` - Python dependencies

## 🔗 How It Works (Arduino + Python)
1. **Arduino handles physical movements**  
   It receives commands (e.g., "walk", "turn") via Serial from Python and moves servos accordingly.

2. **Python handles voice and brain**  
   It listens to the user, responds via voice, and sends action commands to the Arduino via USB Serial.

3. The two parts communicate through the **Serial Port (USB)** using standard text commands like `walk_forward`, `bow`, etc.

## 🛠️ Setup Instructions

### Arduino:
- Use ESP8266-compatible board
- Upload `arduino_movement.ino` using Arduino IDE
- Connect 8 servos to the correct digital pins
- Power the servos with external 5-6V battery pack (NOT via USB)

### Python:
```bash
pip install -r requirements.txt
Connect the board via USB

Run the assistant:

bash
Copy code
python3 spyderr_robot.py
Communication:
The Python script sends Serial commands like:

"walk_forward\n"

"turn_left\n"

The Arduino receives these over Serial and maps them to leg movements.

⚡ Example Workflow
vbnet
Copy code
User: "Hey SPydeRR, tell me a joke!"
→ Python tells a joke and sends `joke_shake` to Arduino
→ Arduino makes the legs wiggle playfully
🔋 Power Notes
ESP8266 board via USB

Servos powered by 4x AA battery pack

Ground of battery must be connected to board GND

📷 Project Photos & Video
(Include photos of wiring and video demo here)

🧑‍💻 Author
Created by [Your Name]
GitHub: github.com/Nimitg2012

