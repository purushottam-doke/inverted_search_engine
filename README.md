# Inverted Search Engine

## 📌 Overview

The **Inverted Search Engine** is a command-line based search application developed in **C** using **Hash Tables and Linked Lists**.

The project creates an **inverted index** from multiple text files. Instead of searching every file from the beginning whenever a word is queried, the inverted index stores each word along with the list of files in which it occurs and the corresponding word frequency.

This makes searching faster and demonstrates the practical use of **data structures, file handling, dynamic memory allocation, and hashing** in C.

---

## 🚀 Features

* Create an inverted index from multiple `.txt` files
* Store unique words using a hash table
* Maintain file information using linked lists
* Store the frequency of each word in every file
* Search for a word and display:

  * Word
  * Number of files containing the word
  * File names
  * Word frequency in each file
* Display the complete database
* Update the database with additional files
* Save the database to a file
* Load an existing database
* Handle duplicate words and duplicate file entries

---

## 🧠 How Inverted Search Works

An inverted index maps a **word → files containing that word**.

For example, suppose we have:

```text
file1.txt
----------------
hello world hello

file2.txt
----------------
hello embedded world
```

The inverted index can be represented as:

```text
hello
 ├── file1.txt : 2
 └── file2.txt : 1

world
 ├── file1.txt : 1
 └── file2.txt : 1

embedded
 └── file2.txt : 1
```

Here, the number after each filename represents the frequency of that word in the file.

---

## 🏗️ Data Structures Used

### Hash Table

A hash table is used to store words and provide efficient access during search.

```text
Hash Table
    |
    +-- Index 0
    +-- Index 1
    +-- Index 2
    ...
    +-- Index 26
```

Each hash-table index can contain a linked list of words that map to the same index.

### Linked Lists

Linked lists are used to maintain:

* Multiple words at the same hash index
* Multiple files containing a particular word
* Word frequency information for each file

A simplified structure is:

```text
Hash Table
    |
    v
  Word
   |
   +---- File 1 → Frequency
   |
   +---- File 2 → Frequency
   |
   +---- File 3 → Frequency
```

---

## 📂 Project Structure

```text
INVERTED_SEARCH/
│
├── main.c
├── create_database.c
├── create_database.h
├── search.c
├── search.h
├── display.c
├── display.h
├── update.c
├── update.h
├── save.c
├── save.h
├── types.h
├── common.h
├── README.md
└── input/
    ├── file1.txt
    ├── file2.txt
    └── file3.txt
```

> The exact file names may vary depending on your implementation.

---

## ⚙️ Technologies Used

* **Language:** C
* **Data Structures:** Hash Table, Linked List
* **Concepts:** File Handling, Dynamic Memory Allocation, Pointers, Structures
* **Compiler:** GCC
* **Platform:** Linux / Windows with GCC

---

## 🔧 Compilation

Clone the repository:

```bash
git clone https://github.com/purushottam-doke/inverted_search_engine.git
```

Navigate to the project directory:

```bash
cd inverted_search_engine
```

Compile the source files:

```bash
gcc *.c -o inverted_search
```

Run the program:

```bash
./inverted_search
```

On Windows:

```bash
inverted_search.exe
```

---

## 🖥️ Application Flow

```text
              Start
                |
                v
        Read Input Files
                |
                v
        Create Inverted Index
                |
                v
       +--------+--------+
       |        |        |
       v        v        v
    Search   Display    Save
       |        |        |
       +--------+--------+
                |
                v
               Exit
```

---

## 🔍 Search Example

Suppose the user searches for:

```text
embedded
```

The program may display:

```text
Word: embedded
Files found: 2

File: file1.txt
Frequency: 3

File: file3.txt
Frequency: 1
```

This allows the user to quickly identify which files contain the searched word.

---

## 💡 Key Concepts Demonstrated

This project provided hands-on experience with:

* Hash table implementation
* Linked list manipulation
* Collision handling
* Structures and pointers
* Dynamic memory allocation
* File I/O operations
* String processing
* Searching and indexing
* Database creation and updating
* Modular programming in C
* Command-line application development

---

## 🎯 Learning Outcomes

Through this project, I gained practical understanding of how search engines can organize and retrieve information efficiently using an **inverted index**.

The project strengthened my knowledge of **C programming, Data Structures, pointers, dynamic memory allocation, linked lists, hash tables, and file handling**.

---

## 👨‍💻 Author

**Purushottam Doke**

GitHub:
https://github.com/purushottam-doke

---

## ⭐ Acknowledgement

This project was developed as part of my learning and hands-on practice in **Advanced C and Data Structures**.
