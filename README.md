# Semester-Project
Different aspects:
File I/O__
Processing__
GUI/Control

# File I/O
Gather metadata info to display
Store data into an array
Send array to Processing
Recieve new array to package back into a new wav file
Use Lancaster's header

# Processing
Recieve what type of processing and the array to process
Processes:
  Normalization
  Echo
  Gain Adjustment
 Send modified array back to File i/o
 
# GUI/Control:
 
 GUI:
Start: Present start menu
If user selects quit, exit program
Else
  Request filename from user
  Open file specified by filename
  If file does not exist or file is not wav file
    display error message and goto start
  else
    read file metadata
(1) display metadata to user
    present user with processor menu
    If user selects processor option
      request output filename
      run processor
      save file
      goto Start
      
Control:
Send and recieve information from the other branches

# Other
Classes:
Abstract Classes:
Interface
Inheritance, composition
Templates?
