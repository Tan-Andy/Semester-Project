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

* The program did not seem to work on windows, the OS that Andy used for his coding. Specifically the processes calling the normalization function (echo and normalize). When calling these the file would frequently just be 0's all the way through, we were unable to come to a good conclusion as to why this happened as the program worked perfectly for Phillip, who did the coding on MacOS. Ultimately we were able to generate all the processed files for each of the input files on the Mac end, but not on windows.

* In theory the program should be able to do all processing from a single execution of the program, however in our testing for best results the program should be exited between each processing, it does not need to be recompiled.

* Outlier values of gain may cause inaudible files in the gain functions as there is currently no bounds check implemented. All values between 0 and 1 work well, values above 1 vary depending on the inputted file.
    

Challenges
-------------------

There were a few main challenges for us, mostly at the beginning of the project:

* It was difficult to figure out what needed to change between 8 bit and 16 bit, and mono and stereo at first, mostly because it took us some time and the help of the videos to figure out how were were actually inputting our data. From there we had to decide on how to actually implement it without doing a specific function for each type of sound i.e. having 3 echo functions, 3 normalize, and 3 gain. Fortunately we were able to modify the information in the video and generalize it to handle all 3 types of audio.

* Because the idea of sound files was pretty new to both of us, it was difficult to understand exaclty how things worked and to know how actions we took affeceted it. For instance, there was difficulty in stereo where the first half of the file was being processed normally but the other half was constant static at full volume. To fix this we had to go in and modify how we read files to care about the number of channels and increase the amount of data that was read to actually make sure were gathering the correct data.

* We were missing 1 of our group members which certainly did not help the work load.

* We struggled to find appropriate situations to use certain c++ features, for instance inheritance for some of the features failed to be convincing enough over some of its alternatives. As a result we probably have some design choices that could be combined into one or two files. 

* It was very difficult to actually know if your code was working until you had already written a significant amount of code. For us we were not able to test our processors were working until we had the file input done, file output done, and all of the inbetween in order to begin testing. i.e. the only thing we could do was make sure it compiled, but we did not know if it worked until about 70% of the way through the project.

### UML DIAGRAM

#### Quantization (bit depth)
