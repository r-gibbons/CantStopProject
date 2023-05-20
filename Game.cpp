//
// Created by Ryan on 2/15/2023.
//

#include "Game.hpp"

Game::Game()
{
    diceSet = new FakeDice;
    //diceSet = new CantStopDice;
    gameStatus = Begin;
    //diceSet = &CSDice;         proper polydice - uncomment later
    //player = getNewPlayer();
}

//-----------------------------------------------------
Player* Game::getNewPlayer() {
    string pName;
    char pColor;
    bool success = false;
    while(!success) {
        try {
            cout << "Enter Player Name" << endl;
            cin >> pName;
            cout << "Enter Color: ";

            for (int c = 0; c < 4; c++) {
                if (unusedColors[c] != '0') {
                    cout << unusedColors[c] << ", ";
                }
            }

            cin >> pColor;
            pColor = toupper(pColor);
            validatePlayer(pName, pColor);
            success = true;
            unusedColors[unusedColors.find_first_of(pColor)] = '0';
            return new Player(pName,pColor);
        }
        catch (BadPlayer &bp) { bp.print(); }
    }

}
void Game::validatePlayer(string vPlayer,char c) {
    bool cCheck = true;
    bool nCheck = true;
    int color = unusedColors.find_first_of(c);
    if(color == string::npos){cCheck = false;}

    for(int p=0; p < playerList.getCount(); p++){
        if((int)playerList.currentPlayer()->getColor() == color+1) {
            cCheck = false;
        }
        if(playerList.currentPlayer()->getName() == vPlayer){
            nCheck = false;
        }
        playerList.next();
    }

    if(!cCheck && !nCheck){throw BadPlayer(vPlayer,c);}
    if(!cCheck){throw BadColor(vPlayer,c);}
    if(!nCheck){throw BadName(vPlayer,c);}
}

//----------------------------------------------
void Game::Run(){
    bool playersAdded = false;
    while(!playersAdded){
        char choice;
        cout << "A:Add Player - B:Remove Player - C:To Start Game" << endl;
        cin >> choice;
        choice = toupper(choice);
        if(choice == 'A') {
            if(playerList.getCount() != 4) {
                playerList.addCell(getNewPlayer());
            }
        }
        else if(choice == 'B'){
            int pPos;
            playerList.init();
            cout << playerList << endl;
            cout << "Enter Which Player To Remove" << endl;
            cin >> pPos;
            matchPlayer(pPos);
            playerList.remove();
            playerList.init();
            cout << playerList << endl;

        }
        else{
            playersAdded = true;
        }
    }
    //cout << playerList;
    while(gameStatus == Begin){
        player = playerList.currentPlayer();
        board.StartTurn(player);
        //testOneTurn();
        oneTurn(player);
        if(gameStatus!= Quit) {
            if (player->getScore() >= 3) { gameStatus = Done; }
            playerList.next();
        }
    }
    cout << "Game State: " << statusNames[gameStatus] << endl;
    cout << board << endl;


}

void Game::matchPlayer(int pos) {
    playerList.init();
    int counter =0;
    while(counter != pos){
        playerList.next();
        counter++;
    }

    char c;
    switch((int)playerList.currentPlayer()->getColor()){
        case 1:
            c = 'O';
            break;
        case 2:
            c = 'Y';
            break;
        case 3:
            c = 'G';
            break;
        case 4:
            c = 'B';
            break;
    }
    for(int x =0; x < 4; x++){
        if(unusedColors[x] == '0'){
            unusedColors[x] = c;
            break;
        }
    }
}
void Game::testOneTurn() {
    isPlaying = true;
    while(isPlaying){
        char input;
        bool success = false;
        while(!success) {
            cout << *player;
            curDice = diceSet->roll();
            try {
                input = curDice[2]+48;
                cout << input << endl;
                validateChoice(input);
                success = true;
            }
            catch(BadChoice& bc){bc.print();}
        }
    }

}

//----------------------------------------------
void Game::oneTurn(Player *pp) {
    isPlaying = true;
    char pInput='0';
    while (isPlaying) {
        try {
            cout << *player;
            cout << "Enter Number To Pick: " << '\n'
                 << "1: Roll - 2: Stop - 3: Resign" << endl;
            cin >> pInput;
            validateChoice(pInput);
        }
        catch(BadChoice& bc){bc.print();}
    }
}
//----------------------------------------------------------------------------
void Game::validateChoice(char input) {
    switch (input) {
        case '1':
            curDice = diceSet->roll();
            if (performMove()) {
                cout << board << endl;
            }
            return;
        case '2':
            board.Stop();
            cout << board;
            isPlaying = false;
            return;
        case '3':
            cout << playerList;
            playerList.remove();
            cout << playerList;
            if(playerList.empty()){gameStatus = Quit;}
            isPlaying = false;
            return;
        default:
            throw(BadChoice(input));
    }
}
//-----------------------------------------------------------------------------
bool Game::performMove() {
    /*if (CheckInput(input[0]) && CheckInput(input[1]) && input[0] != input[1]) {*/
        //int *toCombine = combineValues(input[0],input[1]);
        //toMove[0] = toCombine[0] + toCombine[1];
        //toMove[1] = toCombine[2] + toCombine[3];

        bool firstMove = board.Move(curDice[0]);
        bool secondMove = board.Move(curDice[1]);

        if (firstMove || secondMove) {
            return true;
        }
        else {
            cout << "bust" << endl;
            board.Bust();
            isPlaying = false;
            cout << board << endl;
            return false;
        }
    }
//}


