🔐 Arduino-Based Question Vault Security System
Ensuring Fairness and Integrity in Academic Assessments

Examination question paper leakage poses a critical challenge to the fairness of academic assessments. 
To address this issue, this project introduces an Arduino-Based Question Vault Security System—an advanced solution 
designed to ensure robust protection of sensitive materials.
🌟 Key Features
1️⃣ Dynamic PIN Mechanism

    Generates two unique, one-time-use PINs (UNLOCK PIN and LOCK PIN) upon pressing ‘0’ on a keypad.
    Each PIN is dynamic, ensuring secure access for every instance.

2️⃣ SMS-Based Authentication

    PINs are sent only to a registered phone number embedded in the system.
    Unauthorized changes to the registered number are restricted, adding an extra layer of security.

3️⃣ Scenario-Based Security

    Two-Step Authentication:
        A valid UNLOCK PIN opens the door.
        The LOCK PIN is required to secure the vault.
    The system ensures visibility of unauthorized access attempts if the door is left open.

4️⃣ Brute-Force Defense

    After 3 incorrect PIN attempts, the vault locks for 1 minute (prototype duration).
    Sends an SMS alert to the registered user about the failed attempts.

5️⃣ Double-Layered Locking Security

    Even if an intruder obtains the UNLOCK PIN, failing to provide the correct LOCK PIN triggers the defensive lock mechanism.

6️⃣ Emergency Protocols

    In case of a lost registered phone, the system allows immediate code updates to change the authorized number, ensuring adaptability to vulnerabilities.

⚙️ Components & Technology

    Microcontroller: Arduino Nano
    Communication Module: SIM800L GSM Module
    Power Supply: AC-DC adapter (5V/2A output)
    Peripheral Devices: Servo motor, 4x4 membrane keypad, 16x2 LCD display, breadboard, buck converter, and capacitors

🛠️ Why This Project Matters

This system directly addresses academic integrity issues by ensuring only authorized personnel can access sensitive examination materials. 
Its brute-force defense and two-step authentication represent significant advancements in vault security.
🚀 Future Potential

With further refinement, this system could be scaled to:

    Secure confidential documents, government files, or any sensitive physical materials.
    Enhance security across various industries with affordable, scalable technology.

💡 Contributions

Contributions to enhance the system's features and scalability are welcome!
