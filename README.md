## 🏦 ATM Machine Simulation in C

A simple console-based ATM simulation project built using the C programming language. This project demonstrates key programming concepts such as **conditional statements, loops, functions, and file I/O**.

---

### 🚀 Features

* 🔐 **User PIN login system**
* 💰 **Check account balance**
* ➕ **Deposit money**
* ➖ **Withdraw money**
* 🔄 **Change PIN securely**
* 💾 **Balance and PIN are saved in files**
* 🛡️ Prevents data loss even after restarting the program

---

### 📁 Files Used

* `balance.txt` – stores the user's current account balance
* `pin.txt` – stores the user's 4-digit PIN securely

---

### 💻 How to Run the Program

1. **Save the source code** to a file named `atm_simulation.c`
2. **Compile the code**:

   ```bash
   gcc atm_simulation.c -o atm
   ```
3. **Run the executable**:

   ```bash
   ./atm
   ```
4. Default PIN is `1234` (it will be created automatically if `pin.txt` doesn’t exist).

---

### 🧠 Concepts Covered

* Functions and modular programming
* File handling in C (`fopen`, `fscanf`, `fprintf`, `fclose`)
* Loops and conditional logic
* Persistent storage using text files
* User input validation and security checks

---

### 🔐 Change PIN Flow

1. Select option `4` from the ATM menu
2. Enter your current PIN
3. Enter and confirm your new PIN
4. The new PIN is saved to `pin.txt` and used for future logins

---

### 📦 Sample ATM Menu

```
===== ATM MENU =====
1. Check Balance
2. Deposit
3. Withdraw
4. Change PIN
5. Exit
====================
Enter your choice:
```

---

### 📌 To-Do (Optional Features)

* 🧾 Mini statement of last 5 transactions
* 🔄 Reset PIN with security questions
* ⏳ Add transaction date/time using `time.h`
* 📊 GUI version with C/C++ graphics or using Python

---

### 📜 License

This project is open-source and free to use for educational purposes.

---


