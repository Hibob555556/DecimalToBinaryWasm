# ⚡ C WASM Decimal & Binary Converter

A high-performance number conversion tool built using **C and WebAssembly**, with a modern JavaScript UI. This project demonstrates how low-level languages can be leveraged in the browser for efficient computation while maintaining a clean, responsive user experience.

* * *

## 🚀 Overview

This application converts:

* **Decimal → Binary** (formatted into padded 8-bit octets)
* **Binary → Decimal**

The core logic is written in **C** and compiled to **WebAssembly (WASM)** using Emscripten. A lightweight JavaScript layer connects the UI to the compiled module.

* * *

## 🧠 Why This Project?

This project was built to explore:

* Bridging **low-level systems programming (C)** with modern web applications
* Leveraging **WebAssembly** for performance-critical logic
* Building **clean, responsive UI** while integrating compiled code
* Understanding memory management and string handling across WASM boundaries

* * *

## 🛠️ Tech Stack

* **C**
* **WebAssembly (WASM)**
* **Emscripten**
* **JavaScript**
* **HTML5 / CSS3**

* * *

## ⚙️ How It Works

### Decimal → Binary

* Converts an integer into binary using division by 2
* Pads output into 8-bit groups

### Binary → Decimal

* Iterates through the binary string
* Accumulates value using base-2 multiplication

* * *

## 🧪 Example

Decimal Input: 42Binary Output: 00101010

Binary Input: 101010Decimal Output: 42

* * *

## 🏗️ Build Instructions

### Compile

emcc main.c -o main.js -s EXPORTED_RUNTIME_METHODS='["cwrap"]'

### Run

python -m http.server

Then open <http://localhost:8000>

* * *

## 💡 Key Learnings

* JS ↔ WASM communication
* Memory management in C
* Using EMSCRIPTEN_KEEPALIVE
* Debugging WASM

* * *

## 👤 Author

Cayden Lunt
