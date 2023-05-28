#  Project 2: Alternative Language Project 
## Objective 
> Read a CSV file that contains 1000 cell phones
> Create a Cell class and assign the column as class attributes
> Create Getter and Setters for the attributes
> Store the objects in data structures native to c++

## Data Ingestion and Cleaning
You must perform transformations on the data as it comes in, or after it is being ingested. This a process called data cleaning and these are the steps:
1. Replace all missing or "-" values with null or something similar that can be ignored during calculations.
2. Transform data in appropriate columns according to instructions. For example in the body_weight column, a typical value is '190 g (6.70 oz)'' and needs to be converted to '190'.
3. Convert data types in appropriate columns

## Questions to Answer about the Language
>1. Which programming language and version did you pick?
> For this assignment I decided to do C++, Version 17
>2. Why did you pick this programming language?
> I picked it out of curiosity, I could have gone with any other language for the assignment, but I wanted to use something low level. I originally wanted to use C it doesn't support classes
>3. How your programming language chosen handles: object-oriented programming, file ingestion, conditional statements, assignment statements, loops, subprograms (functions/methods), unit testing and exception handling. If one or more of these are not supported by your programming language, indicate it as so.
> Every thing feels super familiar almost like java
>4. List out 3 libraries you used from your programming language (if applicable) and explain what they are, why you chose them and what you used them for.
> iostream so that I could use the output stream and print to console. array just a really nice wrapper arrays. vector similar to linked list, allows to store a lot of data without specifying size, map similar to java map, allows to store data based on key, fstream, so I could infest the file

## Questions to Answer From Data
>1. What company (oem) has the highest average weight of the phone body?
> HP
>2. Was there any phones that were announced in one year and released in another? What are they? Give me the oem and models.
> Motorola One Hyper, Motorola Razr 2019, and Xiaomi Redmi K30 5g
>3. How many phones have only one feature sensor?
> 432
>4. What year had the most phones launched in the 2000s? 
> 2019