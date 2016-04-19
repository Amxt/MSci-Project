## MSci Project

Note: The macro in this repository are older versions as I no longer have access to my university server where I started storing my macro half way through the project.

The aim of this project (in short) was to conduct a parameter scan for a 9 dimensional equation that describes a particle physics interaction. Essentially this involved independently incrementing each variable by steps within a predetermined range and conducting a set amount of “Toy pseudo experiments” at each point, and then performing a maximum likelihood fit on them. This process led to a vast output of data. The data was then graphed in various arrangements (1000+ graphs).

## Example

Let’s say we have a 2 dimensional equation with variables x and y, both of which are only valid between 0 and 1. To perform a parameter scan, we would first set y=0 and increment x by our chosen step. So if we were to choose a step of 0.1, we would run a set amount of “Toy pseudo experiments” which can be thought of as a set amount of loops (like in a For loop) which each generate a set amount of random events. A maximum-likelihood fit is performed for each toy experiment. We then increment x by 0.1 so now x=0.2 and y=0. The process is repeated. After the steps for x are complete, the process is repeated for y. This is essentially a comprehensive way to optimise the equation. 

## Setup

The code is written to work with the CERN ROOT framework (which is essentially a c/c++ interpreter). The API used are AFit and RooFit. I worked on a linux based server through SSH and so I eventually figured out how to automate everything so that I could let the Prime4 macro run continuously over a few days. This was essential because it takes a very long time to complete a full parameter scan (144 hours+).

## toymacro

The toymacro macro sets up the variables for the parameter scan and also controls where the output data is stored. A script can be written so that toy macro cycles through all of the variables without having to hardcode the desired variables, increments, toy experiment number or event number. The variable are then passed onto Prime4. This is incredibly useful because various configurations of the variables were used, and toymacro allowed me to write a simple script to change the variable configuration rather than having to change the actual code each time.

## Prime4

Prime4 is where the parameter scan actually occurs. It generates various types of data which are separated into columns and saved to the relevant file automatically.

## gplot

gplot imports the data created by Prime4 that was stored in various files and plots graphs for the data. It is incredibly flexible as I can tell it to draw one specific graph, or a specific set of graphs such as ‘pull’ graphs for variable S6 or ‘fit error’ graphs for all the variables and so on. This was particularly useful because I had very limited memory available and It wasn’t possible to create and save all 1000+ graphs. gplot allowed me to create the graphs when and if I needed them very easily.

gplot was my first attempt at object oriented programming without knowing much about it before hand. The implementation is terrible and the code is very messy but it works. The goal was just to familiarise myself with some OOP concepts without worrying too much about using it correctly. This was written about 3 months after I had written my first line of code. 



