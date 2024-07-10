# 80dB-noisecut


*ส่วนประกอบที่ใช้:*
ESP32 Mini (เช่น ESP32-WROOM-32D)
MEMS Microphone (เช่น INMP441)
Mini Speaker (เช่น ลำโพง 8 โอห์ม 0.5 วัตต์)
PAM8403 Amplifier
Li-Po Battery 3.7V
Capacitors and Resistors
การต่อวงจร:
MEMS Microphone:

VCC: เชื่อมต่อกับ 3.3V ของ ESP32
GND: เชื่อมต่อกับ GND ของ ESP32
SCK (หรือ BCLK): เชื่อมต่อกับ GPIO14 ของ ESP32
SD (หรือ DOUT): เชื่อมต่อกับ GPIO32 ของ ESP32
WS (หรือ L/R CLK): เชื่อมต่อกับ GPIO15 ของ ESP32
PAM8403 Amplifier:

VCC: เชื่อมต่อกับ 3.3V ของ ESP32
GND: เชื่อมต่อกับ GND ของ ESP32
IN+ และ IN-: เชื่อมต่อกับเอาต์พุต DAC ของ ESP32 (เช่น GPIO25)
Mini Speaker:

เชื่อมต่อกับเอาต์พุตของ PAM8403 Amplifier
