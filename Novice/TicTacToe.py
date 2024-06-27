
board = ["-" for x in range(9)]

def displayBoard():
    print("{}|{}|{}".format(board[0], board[1], board[2]))
    print("{}|{}|{}".format(board[3], board[4], board[5]))
    print("{}|{}|{}".format(board[6], board[7], board[8]))

def playerMove(player):    
    print("Your turn player {}".format(player))
    choice = int(input("Enter your choice 1-9: ").strip())

    # Keep asking play for position untul they find an open space
    invalid = True
    while(invalid):
        if board[choice-1] == "-":
            board[choice-1] = player
            invalid = False
        else:
            print("That space is already taken.")
            choice = int(input("Enter your choice 1-9: ").strip())
    displayBoard()

# return false if game has been won -> game over 
def check_win():
    # check rows win 
    for i in range(3):
        if board[i*3] == board[3*i+1] == board[3*i+2] != '-':
            print("{} won by row!".format(board[i*3]))
            return True
        
    # check collomns win 
    for i in range(3):
        if board[i] == board[i+3] == board[i+6] != '-':
            print("{} won by column!".format(board[i]))
            return True
        
    # check diagonals win 
    if board[0] == board[4] == board[8] != '-': 
        print("{} won by diagonal!".format(board[4]))
        return True
    if board[6] == board[4] == board[2] != '-':
        print("{} won by diagonal!".format(board[4]))
        return True
    
    return False

# return true is tie -> game over (currently not in use)
# possibly develop to see when a tie in inevatable
def check_tie():
    for i in range(9):
        if board[i] == '-':
            return False
    
    return True 

# return true if game has ended (not in use)
# if check_tie() is developed more to make line 74-76 obsolete
# enable this function
def check_game_over():
    if check_tie() or check_win():
        return True
    return False 


def playGame():
    displayBoard()
    game_over = False
    players = ['X', 'O']
    turn = 0

    while game_over == False:
        playerMove(players[turn%2])
        game_over = check_win()
        if turn >= 8:
            print("Its a tie!")
            game_over = True
        turn = turn + 1

def main():
    choice = input("Do you wish to play Tic Tac Toe? (Y/N): ")

    if choice == 'Y' or choice == 'y':
        playGame()

    print("Goodbye!")
if __name__ == '__main__':
    main()
