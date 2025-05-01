# RNG System Modeling

This is a simple and extensible C++ project for modeling and experimenting with random number generators (RNGs). The key idea is to provide a reusable **abstract base class `RNGBASE`**, which encapsulates the common interface and behavior of any RNG algorithm. You only need to implement **one abstract function** to create your own RNG.

---

## 🔧 Key Components

### `RNGBASE` (Abstract Base Class)
Defines a standard interface for all RNG algorithms:
- Automatically manages state and previous outputs.
- Provides:
  - Integer & real number generation
  - Seed generation
  - Test printing
  - Batch number generation

> To implement your own RNG, **inherit from `RNGBASE`** and **override `generateRandomIntegerNumberBack()`** with your algorithm logic.

### `LFG` (Lagged Fibonacci Generator)
An example implementation of a custom RNG using the Lagged Fibonacci approach:
- Takes two seed values.
- Uses a merge function (default: addition) applied to previous values.
- You can set a custom merge operation (e.g., XOR, subtraction).

---

## 🚀 Example: How It Works

To create a new RNG algorithm:
```cpp
class MyRNG : public RNGBASE {
protected:
    int generateRandomIntegerNumberBack() override {
        // your custom logic
    }

public:
    MyRNG(int mod) : RNGBASE(mod) {}
};
```

Then, use it like:
```cpp
MyRNG rng(100);
rng.printNTests(10);
```

---

## 📂 File Structure

```text
├── RNGBASE.h / .cpp    // Abstract RNG class
├── LFG.h / .cpp        // Lagged Fibonacci implementation
```

---

## 📌 Why This Design?

- **Modular**: Easy to plug in new RNG algorithms.
- **Reusable**: Shared logic for seeding, printing, and tracking output.
- **Focused**: You only need to implement the RNG logic — the base class handles the rest.

---

## 📈 Sample Output (from `printNTests(3)`)

```
|Iteration |Random Number       |Random Real Number
|0         |56                  |0.56                |
|1         |87                  |0.87                |
|2         |43                  |0.43                |
|3         |30                  |0.3                 |
|4         |73                  |0.73                |
|5         |3                   |0.03                |
|6         |76                  |0.76                |
|7         |79                  |0.79                |
|8         |55                  |0.55                |
|9         |34                  |0.34                |
```

---

## 🧠 Concepts Modeled

- Abstract base class design in C++
- Real & integer random number generation
- Functional programming via `std::function`
- Seed-based deterministic generation

---

## 📬 Author

Created by **Mostafa Osman**, **Saif Ahamed** – April 2025

---

Would you like me to generate a badge section (e.g., for build status, license) or an example program demonstrating both classes?
