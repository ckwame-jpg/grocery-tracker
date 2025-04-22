# Grocery Tracker Application

## Overview

This C++ program is a console-based grocery item tracker for small stores or personal inventory systems. It reads item data from a file, tracks how many times each item appears, and allows users to search, view a histogram, and display item frequencies. The purpose was to practice file I/O, data structures (like maps and dictionaries), and user interaction through menus — all core skills in programming languages like C++.

---

## Features

- Tracks item frequency from a user-provided dataset
- Allows search for specific item counts
- Displays a histogram for visual frequency output
- Uses file input/output and maps for efficient storage and lookup
- Built with modular functions for maintainability

---

## Files Included

- `GroceryTracker.cpp` — Main source code for the app
- `frequency.dat` — Output data file that stores item counts
- `CS210_Project_Three_Input_File.txt` — Sample input file of grocery items
- `README.md` — This file

---

## Reflection (Journal)

**What problem was this solving?**  
This project solves the issue of tracking grocery item frequency efficiently using code, instead of doing it manually. It's like a basic analytics system for a corner grocer or food service business.

**What did I do particularly well?**  
I did well structuring the code into clean, separate functions for loading, counting, displaying, and writing output. I also used `unordered_map` to get fast lookups and frequency updates.

**What could be improved?**  
I'd like to implement better input validation and exception handling in future versions. For example, it could handle typos or corrupted files more gracefully and provide clearer feedback to the user.

**What was the most challenging part?**  
Debugging the file input/output process, especially ensuring the frequency data saved correctly to `frequency.dat`. Testing helped a lot, and I referenced Stack Overflow and the C++ documentation to troubleshoot edge cases.

**What skills will transfer forward?**  
Understanding how to use maps for data aggregation is huge — it’s something I’ll use in future data-driven projects. This also reinforced good practices around modular code and user menu design.

**How did I make the code maintainable and readable?**  
- Used clear, descriptive function names
- Commented each section for future reference
- Broke down tasks into single-purpose functions
- Separated data processing from user interaction

---

## How to Run

1. Clone this repository  
   ```bash
   git clone https://github.com/yourusername/grocery-tracker.git
   cd grocery-tracker

2. Compile the program
   ```bash
   g++ GroceryTracker.cpp -o GroceryApp
   
3. Run the Program
   ```bash
   ./GroceryApp
 
