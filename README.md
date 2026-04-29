# Virtual Hackathon Management System

A console-based C++ application for managing virtual hackathon events built as a first-year structured programming project at **Ain Shams University**.

---

## Overview

This system simulates a complete hackathon platform where teams register, submit projects, receive scores from judges, and rankings are calculated automatically. All data is persisted between sessions using flat text files.

---

## 🗂️ Project Structure

```
asu-hackathon-system/
├── src/
│   ├── main.cpp           # Entry point, menu loop, global array definitions, pre-stored data
│   ├── globals.h          # Structs, constants, extern declarations, function prototypes
│   ├── auth.cpp           # Admin login and logout logic
│   ├── teams.cpp          # Team registration
│   ├── project.cpp        # Project title submission and updates
│   ├── evaluation.cpp     # Adding evaluations with innovation, technical presentation scores
│   ├── score.cpp          # Calculating final team scores from evaluations
│   ├── ranking.cpp        # Sorting teams by final score and assigning ranks
│   ├── report.cpp         # Displaying final report with all teams, scores, and winner
│   └── fileio.cpp         # Loading all data from files on startup, saving on exit
├── data/
│   ├── admins.txt         # Persisted admin records
│   ├── teams.txt          # Persisted team records
│   ├── judges.txt         # Persisted judge records
│   └── evaluations.txt    # Persisted evaluation records
└── README.md
```

---

## Course Info

| Field       | Details                         |
|-------------|---------------------------------|
| University  | Ain Shams University            |
| Course      | Structured Programming (CIS150) |
| Language    | C++ (procedural only)           |

---

## Team

[@xmkabel](https://github.com/xmkabel) •
[@Karim00Mahmoud](https://github.com/Karim00Mahmoud) •
[@Mazen-Elatfy](https://github.com/Mazen-Elatfy) •
[@Ahmed-Bayam](https://github.com/Ahmed-Bayam) •
[@GannahSaeed](https://github.com/GannahSaeed) •
[@RanaTharwat52](https://github.com/RanaTharwat52) •
[@rawanamr2006](https://github.com/rawanamr2006)
