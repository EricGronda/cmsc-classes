# File:    proj1.py
# Author:  Eric Gronda
# Date:    10/16/17
# Section: 06
# E-mail:  gt32930@umbc.edu
# Description:
#   DESCRIPTION GOES HERE

# main menu options
USER_QUIT    = -1
MENU_SEARCH  = 0
MENU_CREATE  = 1

MAX_SONG_NUM = 10  # maximum number of songs in a playlist

# these constants are used to give names to the columns of the 2D list
YEAR     = 0
ARTIST   = 1
TITLE    = 2
GENRE    = 3
DURATION = 4
TEMPO    = 5

DETAIL_MIN = YEAR   # minimum value; used for getValidInput()
DETAIL_MAX = TEMPO  # maximum value

# THE REST OF YOUR CONSTANTS GO HERE!!
COLUMN_MAX = 5

# types of playlists
YEAR_PLAY = 1
ARTIST_PLAY = 2
GENRE_PLAY = 3

# length of playlist
LENGTH_MIN = 0
LENGTH_MAX = 10

###############################################################################
# make2DList() constructs a 2D list from a file that contains information
#              about songs in a music library, such as year and artist
# Input:       filename;   a string of the music library's file name
# Output:      resultList; a 2D list of that file in the format below
#  __________________________________________________
# |   0  |    1   |   2   |   3   |     4    |   5   |
# |------|--------|-------|-------|----------|-------|
# | year | artist | title | genre | duration | tempo | 
# |--------------------------------------------------|
# | year | artist | title | genre | duration | tempo | 
# |--------------------------------------------------|
# | year | artist | title | genre | duration | tempo | 
# |--------------------------------------------------|
# | year | artist | title | genre | duration | tempo | 
#  --------------------------------------------------
def make2DList(filename):
    fileObj = open(filename)
    lines = fileObj.readlines()
    fileObj.close()

    resultList = []
    index = 0

    while index < len(lines):
        line = lines[index].strip().split(",")
        line[YEAR]     = int(line[YEAR]) 
        line[DURATION] = float(line[DURATION])
        line[TEMPO]    = float(line[TEMPO])
        resultList.append(line)
        index += 1

    return resultList


# OTHER FUNCTIONS GO HERE
###############################################################################
# displayMainMenu() displays the main menu for the program, containing the
#                   choice to either search for a song or create a playlist
# Input:            None
# Output:           None
def displayMainMenu():
    #Decide to Perform a search or Create a playlist
    print("\nWhat would you like to do next?")
    print("\t0) Perform a search.")
    print("\t1) Create a playlist.\n")

###############################################################################
# getValidInput() ensure user enters a valid number input through sentinel loop
# Input:          prompt; a string to use when asking for an input
#                 minimum; a minimum integer
#                 maximum; a maximum integer                 
# Output:         userInput; an integer within the range
def getValidInput(prompt , minimum , maximum):
    # display prompt and get userInput
    userInput = int(input(prompt))
    
    # check if userInput is between maximum and minimum
    validInput = False
    while validInput == False:
        validInput = True

        # re-prompt if below minimum
        if userInput < minimum:
            validInput = False
            print("You entered invalid input.")
            userInput = int(input(prompt))

        # re-prompt if above maximum
        elif userInput > maximum:
            validInput = False
            print("You entered invalid input.")
            userInput = int(input(prompt))
        
    return userInput

###############################################################################
# displayOptions() displays the different categories to choose from when 
#                  searching for a song
# Input:           None
# Output:          None
def displayOptions():
    #Display menu
    print("\tIndex Value")
    print("\t0 - Year")
    print("\t1 - Artist")
    print("\t2 - Title")
    print("\t3 - Genre")
    print("\t4 - Duration")
    print("\t5 - Tempo")

###############################################################################
# displayPLOptions() displays the different types of playlists to choose from
# Input:          None
# Output:         None
def displayPLOptions():
    print("What playlist type do you want to create?")
    print("1) Year Playlist")
    print("2) Artist Playlist")
    print("3) Genre Playlist")

###############################################################################
# colToString() converts the column choice number to a string
# Input:        colNum; user entered column choice number
# Output:       colStr; string of column choice number
def colToString(colNum):
    if(colNum == YEAR):
        colStr = "Year"
    elif(colNum == ARTIST):
        colStr = "Artist"
    elif(colNum == TITLE):
        colStr = "Title"
    elif(colNum == GENRE):
        colStr = "Genre"
    elif(colNum == DURATION):
        colStr = "Duration"
    elif(colNum == TEMPO):
        colStr = "Tempo"

    return colStr

###############################################################################
# rowInput() prompts a string (row) based on column choice of the user
# Input:     column; string of user's column choice
# Output:    row; user's string for row in songs
def rowInput(column):
    prompt = "Enter the value you want to search for " + column + ": "
    row = input(prompt)
    return row

###############################################################################
# castType() casts the type of input to match that in songs
# Input:     userRow; user entered value for the row of songs
#            column; column chosen by user
# Output:    goodType; userRow with a matching variable type
def castType(userRow , column):
    if(column == YEAR):
        goodType = int(userRow)
    elif(column == ARTIST):
        goodType = str(userRow)
    elif(column == TITLE):
        goodType = str(userRow)
    elif(column == GENRE):
        goodType = str(userRow)
    elif(column == DURATION):
        goodType = float(userRow)
    elif(column == TEMPO):
        goodType = float(userRow)

    return goodType

###############################################################################
# checkLength() checks to see if the length of playlist is within user request
# Input:        playlist; list of songs that fit under the playlist
#               length; user's length of the playlist
# Output:       goodPlay; a playlist of good length
def checkLength(playlist , length):
    # playlist is too long
    while(len(playlist) > length):
        playlist.remove(playlist[len(playlist) - 1])
    
    goodPlay = playlist

    return goodPlay

###############################################################################
# checkEqual() checks for equivalence of user's row value and actual row value
# Input:       userRow; user entered value for the row of songs
#              songsRow; string in songs list to test equivalence
#              column; column chosen by user
# Output:      equivString; True or False value based on equivalence of userRow
#              and songsRow
def checkEqual(userRow , songsRow, column):
    # check duration/tempo
    if(column == DURATION or column == TEMPO):
        if(float(userRow) <= float(songsRow)):
            equivString = True
        else:
            equivString = False
    # check all other types
    else:
        if(userRow == songsRow):
            equivString = True
        else:
            equivString = False

    return equivString

###############################################################################
# matchSongs() iterates over a list and uses checkEqual() to determine which
#              songs will be added to a list of matched songs
# Input:       userRow; user entered value for the row of strings
#              songs; 2D list of songs to search through
#              column; choice of column entered by user
# Output:      matchedSongs; songs that match the users column and row 
def matchSongs(userRow , songs, column):
    index = 0
    rowList = songs[column]
    matchedSongs = []

    # cycle through songs by iterating index
    while(index < len(songs)):
        # change the variable type of userRow to match that in songs
        userRow = castType(userRow , column)

        # check if userRow == songs[index][column]
        match = checkEqual(userRow , songs[index][column] , column)

        # add song to matchedSongs if equivalent
        if(match == True):
            matchedSongs.append(songs[index])

        index += 1

    return matchedSongs

#############################################################################
# printSongs() displays a list of songs from a 2D list
# Input:         songs; 2D list of songs to display
# Output:        None
def printSongs(matchedSongs , msg):
    # if search has no results
    if(matchedSongs == []):
        print("Your search returned no results.")

    else:
        # display header
        print(msg)
        
        # iterate over 1st list
        indexSong = 0
        while(indexSong < len(matchedSongs)):
            indexWord = 0
            string = ""
        
            # convert elements of song into string
            year = str(matchedSongs[indexSong][YEAR])
            genre = str(matchedSongs[indexSong][GENRE])
            artist = str(matchedSongs[indexSong][ARTIST])
            title = str(matchedSongs[indexSong][TITLE])
        
            # print the song
            print(year , "-" , genre , "-" , artist , "-" , title)
     
            # update index
            indexSong += 1

###############################################################################
# playToCol() converts the playlist type to a column value
# Input:      playlistType; value for the selected playlist type
# Output:     column; column value in songs
def playToCol(playlistType):
    if(playlistType == YEAR_PLAY):
        column = YEAR
    elif(playlistType == ARTIST_PLAY):
        column = ARTIST
    elif(playlistType == GENRE_PLAY):
        column = GENRE

    return column

###############################################################################
# search() Performs the search function of the program
# Input:   songs; 2D list of songs from given file
# Output:  
def search(songs):
    # get column choice from user
    searchPrompt = "Enter a column choice (0 - 5): "
    columnChoice = getValidInput(searchPrompt, DETAIL_MIN, DETAIL_MAX)
    # convert choice number to string
    columnString = colToString(columnChoice)
    
    # prompt string (row) based on the column choice
    userRow = rowInput(columnString)

    # iterate over list (row), checking to see if search input is
    # equivalent to any strings
    # checkEqual() used in matchSongs()
    matchedSongs = matchSongs(userRow , songs , columnChoice)

    return matchedSongs


def main():
    # opening statement
    print("This is the Music Organizer 3000!\n")

    # get the filename from the user
    songs = input("Enter the filename of your song library: ")
    # call the provided make2DList function to read in songs
    songs = make2DList(songs)
    
    # create a prompt for menu choice
    # display the main menu options
    displayMainMenu()
    # priming read for getting menu choice
    mainPrompt = "Enter a menu choice (0 - 1) or '-1' to exit: "
    mainChoice = getValidInput(mainPrompt, USER_QUIT , MENU_CREATE)
    
    # searches used to cycle main menu
    searches = 0

    # if menu choice != -1 (for QUIT)
    while(mainChoice != USER_QUIT):
        
        # if code has already been run
        if(searches > 0):
            
            # create a prompt for menu choice
            # display the main menu options
            displayMainMenu()
            # priming read for getting menu choice
            mainPrompt = "Enter a menu choice (0 - 1) or '-1' to exit: "
            mainChoice = getValidInput(mainPrompt, USER_QUIT , MENU_CREATE)

        # if they want to search
        if(mainChoice == MENU_SEARCH):
            
            # create a prompt for the column choice
            # display the search options
            displayOptions()
            
            # Search songs
            matchedSongs = search(songs)

            # display list of songs found under search
            msg = "\nFound the following:"
            printSongs(matchedSongs , msg)

        #if they want to create a playlist
        elif(mainChoice == MENU_CREATE):
            
            # create a prompt for playlist type
            # display the playlist options
            displayPLOptions()
            # choose type of playlist
            playlistPrompt = "Choose a playlist to make: "
            playlistType = getValidInput(playlistPrompt , YEAR_PLAY , GENRE_PLAY)

            # get length of playlist
            lengthPrompt = "Enter the length of your playlist (0-10): "
            length = getValidInput(lengthPrompt , LENGTH_MIN , LENGTH_MAX)

            # convert playlistType to column
            column = playToCol(playlistType)
            # convert column to string
            colString = colToString(column)

            # get userRow
            msg = "Enter a " + colString.lower() + " to make a playlist of: "
            userRow = input(msg)

            # match songs in the same column
            playlist = matchSongs(userRow , songs , column)
            
            # check length of playlist
            playlist = checkLength(playlist , length)

            # if no songs in playlist
            if(len(playlist) == 0):
                msg = "doesn't exist in your library."
                print("Sorry, the" , colString.lower() , userRow , msg)
                print("\nUnable to create a playlist based on that criteria.")
            # if songs in playlist
            else:
                msg = "\nCreated this playlist:"
                printSongs(playlist , msg)

        # update searches
        searches += 1

    # closing program prompt
    print("Thanks for using the Music Organizer 3000, come again!")


main()
