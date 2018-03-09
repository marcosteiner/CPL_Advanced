# ﻿Resultat Tracer:
## Aufgabe 1:
Tracer created: main
Tracer created: inner

//call to function foo
  Tracer created: inner  	-- Tracer copied: inner copy
  Tracer created: foo
  Tracer: inner          	-- Tracer: inner copy
  Tracer destoryed: foo
  Tracer destroyed: inner	-- Tracer destroyed: inner copy

//call to funciton bar
  Tracer created: bar
  Tracer: inner


Tracer: bar
Tracer: inner
				-- Tracer destroyed: bar
				-- Tracer destroyed: inner

//call to function foo
  Tracer created: temp
  Tracer created: foo
  Tracer: temp
  Tracer destroyed: foo
  Tracer destroyed: temp

Tracer: main
				-- Tracer destroyed: main

## Aufgabe 2
Tracer created: T1
Tracer created: T2
Tracer created: T3
Tracer created: T4

//Copy construction of the vector
Tracer copied: T1 copy
Tracer copied: T2 copy
Tracer copied: T3 copy
Tracer copied: T4 copy

__Output__
Tracer created: T1                  --Element allocation on heap
Tracer copied: T1 copy              --Pushback on Vector
Tracer destroyed: T1                --Destruction Heap element
Tracer created: T2                  --Element allocation on heap
Tracer copied: T2 copy              --New Vector and pushback
Tracer copied: T1 copy copy         --Exception safety, immer ein
Tracer destroyed: T1 copy           ------ Gültiges Element vorhand
Tracer destroyed: T2                ------ Das Element kommt dann
Tracer created: T3                  ------ and die richtige stelle
Tracer copied: T3 copy
Tracer copied: T1 copy copy copy
Tracer copied: T2 copy copy
Tracer destroyed: T1 copy copy
Tracer destroyed: T2 copy
Tracer destroyed: T3
Tracer created: T4
Tracer copied: T4 copy
Tracer destroyed: T4
Tracer copied: T1 copy copy copy copy
Tracer copied: T2 copy copy copy
Tracer copied: T3 copy copy
Tracer copied: T4 copy copy
Tracer destroyed: T1 copy copy copy copy
Tracer destroyed: T2 copy copy copy
Tracer destroyed: T3 copy copy
Tracer destroyed: T4 copy copy
Tracer destroyed: T1 copy copy copy
Tracer destroyed: T2 copy copy
Tracer destroyed: T3 copy
Tracer destroyed: T4 copy


## Aufgabe 3
__Does the code below compile if you don't specify the copy-assignment operator?__
Yes it compiles, but I don't quite understand what it does exactly


__Do you define the assignment operator as free or as member function? Why?__
Its a member function because I have to have access to the members and also set the members.

## Aufgabe 4
__How does the behavior of the output change with respect to the implmentation with the copying tracer?__ <br>
You might need to wrap the local variable passed to function foo and the assignment with std::move to have the program compile with the move-only class Tracer. Explain why std::move is required. What would happen otherwise (without std::move)? Why does it not compile?
>Because the parameter is provided by value



Tracer created: origin
Tracer created: target
origin moved-assigned
origin moved to
Tracer destroyed: origin moved-assigned
Tracer destroyed: origin moved to
__As you have a moveable type what happens if you just call std::move on a tracer object? What is the output of the call below?__

__Why?__


## Aufgabe 5

Tracer created: T1 <br>
Tracer move constructed: T1 <br>
Tracer destroyed: T1 <br>
Tracer created: T2 <br>
Tracer move constructed: T2 <br>
Tracer move constructed: T1 <br>
Tracer destroyed: T1 <br>
Tracer destroyed: T2 <br>
Tracer created: T3 <br>
Tracer move constructed: T3 <br>
Tracer move constructed: T1 <br>
Tracer move constructed: T2 <br>
Tracer destroyed: T1 <br>
Tracer destroyed: T2 <br>
Tracer destroyed: T3 <br>
Tracer created: T4 <br>
Tracer move constructed: T4 <br>
Tracer destroyed: T4 <br>
Tracer destroyed: T1 <br>
Tracer destroyed: T2 <br>
Tracer destroyed: T3 <br>
Tracer destroyed: T4 <br>

>The elements always behaved as I expected

## Aufgabe 6
creating the container took: 15.8693s time <br>
creating the container took: 12.0946s time <br>

The first creation is with move constructor and the second with copy constructor
