# D'Hont distribution method

This is a program/library to calculate the distribution of seats
in an election for a parliament, congress, etc. It uses
the [D'Hont Method](https://en.wikipedia.org/wiki/D%27Hondt_method)
to make the distribution.

__I'M NOT RESPONSIBLE FOR THE USE OF THIS CODE NOR ITS RESULTS__,
though I'm confident on the implementation.

## Context
The *D'Hont/Jefferson method* is a way to distribute seats in a proportional
representation system according to the votes. It is used to assign seats to
political parties when it is not possible to assign decimal seats. It generally tends
to favor smaller parties.

## Usage:

### Standalone executable
You may compile the source code to
produce an executable.
The data is provided in an input file like this:

__westeros.txt__

    9 20 3
    Stark 731320
    Targayren 62352
    Lannister 751748
    Arryn 82765
    Baratheon 145045
    Tully 119083
    Tyrell 49378
    Greyjoyl 64529
    Martell 254812
    
The first line has three numbers: 9,20 and 3. 
The first number (9) indicates the number of parties
(in this case houses). The second number (20) indicates the number
of seats to distribute, and the third number (3) indicates
the *barrier*. Some countries have a minimum percentage 
a party has to meet in order to receive a seat. In westeros case
it is 3%. Each line forward indicates the name of the party and how
many votes it got.

To calculate the distribution, you do:

```
$ ./dhont westeros.txt
```

And the output will be:

    Stark: 8 seats
    Lannister: 8 seats
    Baratheon: 1 seats
    Tully: 1 seats
    Martell: 2 seats
    
Another example, this time, using real data from an 
election in Madrid:

__madrid.txt__

    16 36 3
    PP 1204059
    Podemos 750607
    Ciudadanos 676684
    PSOE 643244
    IU 189265
    UPYD 43110
    PACMA 28312
    VOX 22461
    X_IZQUIERDA 5007
    FE-JONS 4691
    RECORTES0 4014
    PUM+J 2834
    PH 1849
    PCPE 1732
    SAIn 1230
    P-LIB 1056

```
$ ./dhont madrid.txt
PP: 13 seats
Podemos: 8 seats
Ciudadanos: 7 seats
PSOE: 6 seats
IU: 2 seats
```

### As a library
You may use this code as a library by including the headers
`data.h` and `dhont.h`. The files `data.c` and 
`dhont.c` are needed because they contain
function definitions. You may use `main.c` as an example.

## More info:

[D'Hont Method page at Wikipedia](https://en.wikipedia.org/wiki/D%27Hondt_method)

## Licence
MIT Licence