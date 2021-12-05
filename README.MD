# CS 202 Semester Project, F21
Basic Level Project
Group 22 Phillip Damke & Andy Tan
============================
Split of Work
--------
All files were collaborative with the other person providing input and bits of code

*   **File I/O (Andy) :** wavManager.h, wavManager.cpp ,wavPrinter.h, wavPrinter.cpp <br>
        - Reading and writing of wav files
    
*   **Processing (Phillip) :** echo.h, echo.cpp, gain.h, gain.cpp, normalize.h, normalize.cpp <br>
        - Actual implementation of these into main and wavManager <br>
        - Necessary variations to handle 8/16 bit or mono/stereo
    
*   **User Interface (Andy) :** main.cpp, uInterface.h, uInterface.cpp <br>
        - Logic flow, console input/output, handling of errors/invalid inputs
    

Issues
--------------

All functionality is present in the program and has successfully generated the desired output on Phillip's end, however there are a few known issues:

* Values of gain greater than or equal to 1 when inputted into the echo function sometimes do not generate correct files.

* The program appears to have different functionality on MacOS and (ANDY'S OS HERE), all functions work correctly for Mac, some output empty files for (ANDY'S OS HERE).

* In theory the program should be able to do all processing from a single execution of the program, however in our testing for best results the program should be exited between each processing, it does not need to be recompiled.

* Outlier values of gain may cause inaudible files in the gain functions as there is currently no bounds check implemented. All values between 0 and 1 work well, values above 1 vary depending on the inputted file.
    

Challenges
-------------------

*   BrO LikE wuT in dA hECk wuz dis prJect lul?
A section detailing the challenges that you encountered in the project

### UML DIAGRAM

#### Quantization (bit depth)
