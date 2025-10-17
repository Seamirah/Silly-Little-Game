#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <cstdlib>  // system, srand, rand
#include <ctime>
#include <vector>
#include <string>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

using namespace std;

// initial status
int hunger = 100;
int energy = 100;
int cleanliness = 100;
int gamble = 0;
int sanity = 100;
int money = 50;

string petName;

//-----------Function declarations----------
void showStatus();
void feedPet();
void sleepPet();
void cleanPet();
void gamblePet();
void emotionalsupport();
void decreaseStats();
void typeText(const string& text, int delayMs = 50);
void petBlinkingAnimation();
void teachDadJoke();
void showPetArt();
void breakdownAnimation();

// admin / system functions
void activateAdminPanel();
void restartComputer();

void openURL(const string& url) {
#ifdef _WIN32
    string command = "start " + url;
#elif __APPLE__
    string command = "open " + url;
#else
    string command = "xdg-open " + url;
#endif
    system(command.c_str());
}

//-------------MAIN-------------
int main() {
    srand(static_cast<unsigned int>(time(0)));

    typeText("One day while going home, you encountered a kitten\n", 10);
    typeText("the dirty smol kitten looked at you\n", 20);
    typeText("meow! meow meow meeeow\n", 20);
    typeText("the kitten wants you to be their owner\n", 150);
    typeText("you called the kitten 'PSPSPSPSPSPS'\n", 90);
    typeText("the car approached you\n", 20);
    typeText("obviously\n", 200);
    typeText("........\n", 200);
    typeText("after kidnapping the kitten---- I mean ADOPTING  the kitten\n", 150);
    typeText("you finally came home!\n", 200);
    typeText("yay?\n", 100);
    typeText("okay enough with the intro let's get started\n", 100);
    typeText("Welcome to this Silly Little Game!\n", 190);
    typeText("This is a silly game, yes\n", 190);
    typeText("so.....\n", 200);
    typeText("anyways!\n", 50);
    typeText("Enter a name for your Silly thing: ", 50);
    getline(cin, petName);

    bool adminMode = false;

    if (petName == "youaremyspecialz") {
        adminMode = true;
        petName = "admeownistrator"; // admin name
        cout << "\n WEE WOO WEE WOO WEE WOO \n";
        typeText("how?", 190);
        cout << "\033[31mHOW DID YOU ACCESS THIS ULTRA ULTIMATE SUPER DUPER SECRET MODE?\033[0m\n";
    }

    cout << "Nice! Your little thing's name is " << petName << "!\n";

    int choice;

    while (true) {
        showStatus();

        if (hunger == 0 || energy == 0 || cleanliness == 0) {
            cout << "\nOh no! Your little thing got mogged so bad. Game Over.\n";
            break;
        }

        if (sanity == 0 || energy == 0) {
            cout << "...\n";
            cout << "Why did you leave me?\n";
            cout << "I don't like you anymore.\n";
            break;
        }

        if (gamble >= 100) {
            breakdownAnimation();
            cout << petName << " has hit rock bottom...\nGame Over.\n";
            break;
        }

        cout << "\nWhat do you want to do?\n";
        cout << "1. Feed some aura\n";
        cout << "2. Let the thing recharge their rizz meter\n";
        cout << "3. Clean the thing cuz it's stinkee\n";
        cout << "4. Wait and Find Out\n";
        cout << "5. Teach the thing how to gamble\n";
        cout << "6. Buy some milk\n";
        cout << "7. Give emotional support\n";
        cout << "8. give your pet emotional damage by telling a dad joke\n";

        if (adminMode) {
            typeText("9. totally not a secret mode\n", 20);
        }

        cout << "Choice: ";
        if (!(cin >> choice)) {
            // handle non-integer entry
            cin.clear();
            string dummy;
            getline(cin, dummy);
            cout << "Invalid choice.\n";
            this_thread::sleep_for(chrono::seconds(1));
            continue;
        }

        switch (choice) {
            case 1: feedPet(); break;
            case 2:
                sleepPet();
                petBlinkingAnimation();
                break;
            case 3: cleanPet(); break;
            case 4: cout << "Time is passing...\n"; break;
            case 5: gamblePet(); break;
            case 6: cout << "The thing waited for you to come back with milk... you never did.\n"; break;
            case 7: emotionalsupport(); break;
            case 8: teachDadJoke(); break;
            case 9:
                if (adminMode) { // admin panel call
                    activateAdminPanel();
                } else {
                    cout << "enngk! INVALID!!.\n";
                }
                break;
            default: cout << "Invalid choice.\n"; break;
        }

        this_thread::sleep_for(chrono::seconds(2));
        decreaseStats();
    }

    return 0;
}

// ------------------- Function Definitions ----------------------

void showStatus() {
    cout << "\n" << petName << "'s Status:\n";
    showPetArt();
    cout << "Hunger: " << hunger << "\n";
    cout << "Energy: " << energy << "\n";
    cout << "Cleanliness: " << cleanliness << "\n";
    cout << "Gambling Addiction: " << gamble << "\n";
    cout << "Sanity: " << sanity << "\n";
    cout << "Money: $" << money << "\n";
}

//bool enableTyping = true; //-----skip the animation for testing or accessibility
void typeText(const string& text, int delayMs) {
    for (char c : text) {
        cout << c << flush; // print immediately
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
}

void feedPet() {
    hunger = min(hunger + 20, 100);
    cout << petName << " ate homemade cookies!\n";
}

void sleepPet() {
    energy = min(energy + 20, 100);
    cout << petName << " is sleeping! Shush!\n";
}

void cleanPet() {
    cleanliness = min(cleanliness + 20, 100);
    cout << petName << " looks shiny!\n";
}

void gamblePet() {
    // LETS GO GAMBLING
    int moneySpent = rand() % 10 + 1;
    money = max(money - moneySpent, 0);
    int outcome = rand() % 100 + 1;

    cout << petName << " went gambling and spent $" << moneySpent << "...\n";

    gamble = min(gamble + moneySpent, 100);

    if (outcome <= 10) {
        cout << "JACKPOT!! " << petName << " won BIG! (+20 energy, +10 sanity)\n";
        energy = min(energy + 20, 100);
        sanity = min(sanity + 10, 100);
    } else if (outcome <= 40) {
        cout << petName << " won a little bit... (+5 sanity)\n";
        sanity = min(sanity + 5, 100);
    } else {
        cout << petName << " lost it all... again. (-10 sanity)\n";
        sanity = max(sanity - 10, 0);
    }

    cout << R"(
   (\_/)  
   ($.$)   must... pull... one more time...
  / >💸
)";
}

void emotionalsupport() {
    sanity = min(sanity + 10, 100);
    cout << "You gave " << petName << " a hug. They feel a little better.\n";
}

void teachDadJoke() {
    vector<string> jokes = {
        "Why don't skeletons fight each other? They don't have the guts.",
        "I only know 25 letters of the alphabet. I don't know y.",
        "I used to be addicted to soap, but I'm clean now.",
        "Why did the scarecrow win an award? Because he was outstanding in his field!",
        "What do you call fake spaghetti? An impasta!",
        "What do you call cheese that isn't yours? Nacho cheese.",
        "Why do melons have weddings? They cantelope.",
        "My dog just ate a $100 bill. I guess he has expensive taste.",
        "Why did the coffee taste like dirt? Because it was ground just a few minutes ago.",
        "What is the best present? Broken drums! You can't beat them.",
        "I have a horse named mayo, and mayo neighs.",
        "What's the best animal in soccer? A score-pion."
    };

    int jokeIndex = rand() % static_cast<int>(jokes.size());

    cout << "\nYou told " << petName << " a dad joke:\n";
    cout << "\"" << jokes[jokeIndex] << "\"\n";

    // Stats impact
    sanity = max(sanity - 5, 0);         // BRAIN ROT
    hunger = min(hunger + 10, 100);      // CASEOH
    energy = min(energy + 5, 100);       // COPIUM

    cout << petName << " is dying inside.\n";
}

void activateAdminPanel() {
    int adminChoice;

    cout << "\n--- ADMIN PANEL ---\n";
    cout << "1. Max all stats\n";
    cout << "2. Infinite money\n";
    cout << "3. Cure gambling addiction\n";
    cout << "4. Trigger secret ending\n";
    cout << "5. Exit admin panel\n";
    cout << "6. tomorrow is another day\n";
    cout << "Choice: ";
    if (!(cin >> adminChoice)) {
        cin.clear();
        string dummy;
        getline(cin, dummy);
        cout << "Invalid admin choice.\n";
        return;
    }

    switch (adminChoice) {
        case 1:
            hunger = energy = cleanliness = sanity = 100;
            cout << "Stats maxed out. You're a perfect pet parent now.\n";
            break;
        case 2:
            money = 9999999;
            cout << "You're rich beyond belief. Capitalism wins again.\n";
            break;
        case 3:
            gamble = 0;
            cout << "Your pet had a gambling factory reset.\n";
            break;
       case 4:
            cout << "\nYou have ascended beyond the game.\n";
            cout << petName << " looks at you with glowing eyes.\n";
            cout << "\"You were never supposed to reach this point...\"\n";
            cout << "\"But now that you have... welcome.\"\n";
            cout << "Opening a secret portal...\n";
            openURL("https://youtu.be/GZCSd8bd8do?si=03pLERxdSB9MqSI6"); // <-- change to your real URL
            cout << "THE END.\n";
            exit(0);
        case 5:
            cout << "Exiting admin panel.\n";
            break;
        case 6: {
            cout << "You sure?. (y/n): ";
            char confirm;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                restartComputer();
            } else {
                cout << "SMART CHOICE. \n";
            }
            break;
        }
        default:
            cout << "That's not a thing. Even for an admin.\n";
            break;
    }
}

void restartComputer() {
#ifdef _WIN32
    //windows
    system("shutdown /r /t 0");
#else
    // On Linux/macOS
    system("sudo reboot");
#endif
}

void showPetArt() {
    cout << "\n";

    if (sanity >= 80) {
        cout << R"(
   (\_/)  
   (•ᴗ•)   I'm feeling awesome!
  / >🍪
)";
    } else if (sanity >= 50) {
        cout << R"(
   (\_/)  
   (•_•)   I'm doing okay...
  / >🍞
)";
    } else if (sanity >= 20) {
        cout << R"(
   (\_/)  
   (o_o)   Uhh... you good, bro?
  / >🧃
)";
    } else {
        cout << R"(
   (\_/)  
   (x_x)   the voices are loud today
  / >🪦
)";
    }

    cout << "\n";
}

void petBlinkingAnimation() {
    for (int i = 0; i < 3; ++i) {
        system(CLEAR_COMMAND);
        cout << R"(
   (\_/)
   (•ᴗ•)   *blink blink*
  / >🍪
)";
        this_thread::sleep_for(chrono::milliseconds(400));

        system(CLEAR_COMMAND);
        cout << R"(
   (\_/)
   (-_-)
  / >🍪
)";
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    system(CLEAR_COMMAND);
    cout << R"(
   (\_/)
   (•ᴗ•)   I'm awake now.
  / >🍪
)";
    this_thread::sleep_for(chrono::milliseconds(600));
}

// depresso expresso ascii
void breakdownAnimation() {
    for (int i = 0; i < 2; ++i) {
        system(CLEAR_COMMAND);
        cout << R"(
   (\_/)
   (ಥ_ಥ)   why... the gambling... it took everything...
  / >💳
)";
        this_thread::sleep_for(chrono::milliseconds(500));

        system(CLEAR_COMMAND);
        cout << R"(
   (\_/)
   (T_T)   it's all gone...
  / >🪦
)";
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    system(CLEAR_COMMAND);
    cout << R"(
   (\_/)
   (x_x)   send help.
  / >🪦
)";
}

void decreaseStats() {
    hunger = max(hunger - 5, 0);
    energy = max(energy - 3, 0);
    cleanliness = max(cleanliness - 4, 0);
    sanity = max(sanity - 1, 0);
    gamble = max(gamble - 5, 0);  // Reduce addiction slowly

    // HOLD UP!
    if (gamble >= 80) {
        int interventionChance = rand() % 100 + 1;
        if (interventionChance <= 20) { // 20% chance per turn
            cout << "\n🚨 WEEWOO WEE WOO ALERT! ALERT! 🚨\n";
            cout << petName << " was caught trying to sell your furniture to fuel its gambling addiction.\n";
            cout << "You staged an intervention.\n";
            gamble = max(gamble - 40, 0);   // becoming a normal pet
            sanity = min(sanity + 15, 100); // becoming sane again
            energy = max(energy - 10, 0);   // Interventions are draining!
            cout << petName << " is slowly learning that they need to rob a bank.\n";
            
        }
    }
}

