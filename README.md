Banker’s Algorithm – Resource Safety Checker

A C++ Implementation of Deadlock Avoidance

📌 Program Description

This program implements the Banker’s Algorithm, a deadlock avoidance algorithm to determine whether a system is in a safe state given:

•	A set of processes

•	Their resource allocations

•	Their maximum possible demands

•	The system’s currently available resources


🧠 Algorithm Overview

The Banker’s Algorithm works by checking whether processes can safely complete in some order without causing a deadlock.

It evaluates each process to see if its remaining needs can be met with the system’s current resources. If so:
  1. The process is considered runnable.
  2. Its allocated resources are released upon completion.
  3. The algorithm continues with the updated available resources.

If all processes can finish, the system is safe, and the program outputs a safe sequence.

If no remaining process can run with available resources, the system is unsafe, potentially leading to a deadlock.

✔️ Objective of the Program

1.	Read a set of processes from data.txt, including allocation and maximum demand vectors.
2.	Read the system’s available resources.
3.	Determine:
	
	a. Whether the system is currently in a safe or unsafe state.

	b. If safe, produce the safe sequence of process execution.

Answer to assignment question : Yes the system is in a safe state. The sequence is P3->P4->P1->P2->P0

▶️ Usage Instructions
1. File Requirements (data.txt)

Your data.txt file should contain one line per process

	A_alloc B_alloc C_alloc | A_max B_max C_max
Final line should include available resources

   	A_available B_available C_available
    
Example data.txt:
```
#Alloc| Max
0 1 0 | 7 5 3
2 0 0 | 3 3 2
3 0 2 | 9 0 2
2 2 1 | 2 2 2
0 0 2 | 4 3 3

#resources available
3 2 2
```

2. How to compile
   -uses make file to compile in c++
   ```make run```
   other commands
   -clears executable
   ```make clean```

3. Program Output
	  •	Whether the system is in a safe or unsafe state
	  •	If safe, will print out safe state sequence order

   example screenshots:
   
<img width="1329" height="873" alt="progAssigment2-example1" src="https://github.com/user-attachments/assets/f8d7a988-b1d1-49c2-b510-67d011034e26" />



<img width="1580" height="1003" alt="progAssignment2-example2" src="https://github.com/user-attachments/assets/db0ab4d1-0408-4303-b713-c3743f41e00c" />

