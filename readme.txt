1. Describe the state of your program, exactly what works and what does not work.
The program does the following:
– Initialize the contents of each of the three categories of books 
– Process an arbitrary sequence of check-outs, returns, and displays of different kinds of information  

2. List your hash table(s) that you wrote (not STL) - briefly what they are used for and file they are found in. (Include any factories that are essentially hash tables).
- "mediaFactory.h": hash table for creating a media object
- "commandFactory": hash table for creaitng a command object

3. State which file and which function you read the book data, just high-level function calls, i.e., how/where it gets into your collections.
<manager.h>
inputMediaFile: reads "data4books.txt" and insert media object to binary search tree 

<mediaFactory.h>
mediaFactory creates media object through hash function and returns it


4. State which file and which function you read the command data, high-level function calls, how/where you perform the commands.
<manager.h>
inputCommandFile: reads "data4commands.txt" and create command object from a command factory, finally it processes each command 

<commandFactory.h>
commandFactory creates command object by hash function 

<commannd.h>
create() function operates each command

<patronList.h>
retrieve patron

<patron.h>
checkOut() function to record history 

5. Describe any dirty little secrets (e.g., switch used, or if-else-if, etc.)  If you feel they do not violate the open-closed design principle, explain.
I have a 6,000 bytes memory leaks 

6. Describe anything you are particularly proud of ...