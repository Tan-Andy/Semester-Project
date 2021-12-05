Basic Level Requirements
------------------------

The basic level application presents the user with a console interface.

### Program Flow

The following pseudo-code shows the required application flow for the base level console version:

```
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
 ``` 

**File Metadata**

The data to be displayed in step (1):

*   filename
    
*   sample rate
    
*   bits per sample
    
*   stereo or mono

### Documentation

All header files and functions must be documented using the Doxygen Javadoc format. The README page should include

*   A line saying whether this is a basic or challenge level project
*   The full names of each team member
*   The contribution of each team member
*   A UML diagram showing the basic design
*   A section detailing issues, including any functionality that is missing
*   A section detailing the challenges that you encountered in the project
*   Instructions for building the application if anything is required beyond _make_

The Doxygen files should be generated into a folder called _docs._

Grading
-------

This project will be graded using standard grading with partial credit. There will not be an opportunity for redo, as this project is due toward the end of the semester and there will not be time for redo and grading.

Grading will be based on

*   use of Git
    
*   correct use of C++ features such as templates, inheritance, interfaces, exceptions, and composition
    
*   correctness of the implementation of the required processes
    
*   runtime stability
    

See the rubric for details.

What to Turn In
---------------

*   All source code must be managed in Github, and the repository URL turned in to WebCampus. Include the team member names and your group number in the submission.