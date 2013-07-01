# CyleSoft FileDiff and StringDiff

These are really, really simple little utilities. I'm not even sure if they're useful yet. All they do is use a Levenshtein distance algorithm to calculate the number of differences between two strings. **stringdiff** takes two strings as input, while **filediff** takes two text files.

## Installing

Basically you need a C compiler, that's all. Probably overkill, but on Debian I just installed the *build-essential* package and that did the trick.

    gcc -o filediff filediff.c
    gcc -o stringdiff stringdiff.c
    
That will build both filediff and stringdiff, respectively, of course.

## Usage

### filediff

Send it two plain text document filenames as arguments and it'll show how many differences there are between the two using a Levenshtein distance algorithm, found [here](http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C). Example:

    ./filediff textfile1.txt textfile2.txt

Or, use -v to give "verbose" output, though it's not very useful (yet). Example:

    ./filediff -v textfile1.txt textfile2.txt

### stringdiff

Send it two strings and it'll show how many differences between the two using a Levenshtein distance algorithm, found [here](http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C). Example:

    ./stringdiff "Hello there" "Hello world"

(That'll return "5".)
