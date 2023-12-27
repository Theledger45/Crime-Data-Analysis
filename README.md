# Crime Data Analysis Tool README

## Overview
The Crime Data Analysis Tool is a C++ application designed to manage and analyze crime data, particularly focusing on incidents involving gunshot injuries and homicides. It utilizes a binary tree structure for efficient data storage and retrieval. The application reads data from a CSV file and allows users to search for specific cases using case numbers.

## Features
- **Data Insertion**: Automatically reads and inserts crime data from a specified CSV file into a binary tree.
- **Search Functionality**: Users can search for a specific case using its unique case number.
- **Case Data Display**: For each searched case, the application displays details like incident primary, gunshot injury status, and victim name.
- **In-Order Printing**: The application can print all case numbers stored in the binary tree in ascending order.

## How to Use
1. **Compile the Code**: Ensure you have a C++ compiler installed. Compile the code using your preferred compiler or IDE.
2. **Prepare the Data File**: The CSV file should be in the format of `case number, incident primary, gunshot injury, victim first name, victim last name`. Place this file in an accessible directory.
3. **Run the Application**: Execute the compiled program.
4. **Search for Cases**: When prompted, enter a case number to retrieve details about that case.

## System Requirements
- C++ compiler (GCC, Clang, MSVC, etc.)
- Access to a terminal or command-line interface

## File Structure
- `main.cpp`: Contains the main application code including the binary tree structure, file reading mechanism, and user interaction.

## Note
- Ensure the path to the CSV file is correctly specified in the `main()` function.
- The application currently handles a specific CSV format. Any deviation in the file format might require code adjustments.
