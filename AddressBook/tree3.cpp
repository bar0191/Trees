#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <limits>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::map;
using std::ostream;
using std::istream;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::max;
using std::ofstream;
using std::ifstream;

class aBook
{
private:
    string zipCode;
    string strtName;
    string city;
    string state;
public:
    aBook() : zipCode(), strtName(), city(), state() {}
    
    string getzipCode() const { return zipCode; }
    void setZipCode(string zip) { zipCode = zip; }
    
    string getStrtName() const { return strtName; }
    void setStrtName(string name) { strtName = name; }
    
    string getCity() const { return city; }
    void setCity(string cityName) { city = cityName; }
    
    string getState() const { return state; }
    void setState(string stateName) { state = stateName; }
    
    //~aBook() {};
    
    friend ostream& operator << (ostream& output, const aBook& obj)
    {
        return output << obj.strtName << '.' << obj.city << ", " << obj.state << obj.zipCode;
    }
    
    friend istream& operator >> (istream& input, aBook& obj)
    {
        return input >> obj.strtName >> obj.city >> obj.state >> obj.zipCode;
    }
    
    aBook& operator = (const aBook& rhs) 
    { 
        this->zipCode = rhs.zipCode; 
        this->strtName = rhs.strtName;
        this->city = rhs.city;
        this->state = rhs.state;
        return* this;
    }
    
    bool operator == (const aBook& rhs) const
    {
        if (this->zipCode != rhs.zipCode) return false;
        if (this->strtName != rhs.strtName) return false;
        if (this->city != rhs.city) return false;
        if (this->state != rhs.city) return false;
        return true;
    }
    
    bool operator < (const aBook& rhs) const
    {
        if (this->zipCode == rhs.zipCode && this->strtName == rhs.strtName && 
            this->city == rhs.city && this->state < rhs.state) return true;
        if (this->zipCode == rhs.zipCode && this->strtName == rhs.strtName && this->city < rhs.city)
            return true;
        if (this->zipCode == rhs.zipCode && this->strtName < rhs.strtName) return true;
        if (this->zipCode < rhs.zipCode) return true;
        
        return false;
    }
};

enum addressBookCmds { addToBook = 1, removeFromBook, printBook, searchBook, reprintMenu, clear, changeData, exitprog };

enum aBookEditCmds { chStName = 1, chCity, chState, chZipCode, exitEdits };

string cmd();
void cmds();
void cmds2();
void clrScreen();
void newLine();
addressBookCmds entryData(map<string, aBook>& Entry, aBook& addressData);
aBookEditCmds changeInfo(map<string, aBook> Entry, aBook& addressData);
void print(map<string, aBook> Entry);
void searchData(map<string, aBook> Entry);
void removeData(map<string, aBook>& Entry);
void saveBook(map<string, aBook> Entry);
void loadBook(map<string, aBook>& Entry, aBook& addressData);

int main()
{
    map<string, aBook> Entry;
    aBook addressData;
    int menuChoice = 0;
    
    cout << "Loading... " << endl;
    
    loadBook(Entry, addressData);
    
    cmds();
    
    do
    {
        cout << "> ";
        cin  >> menuChoice;
        cin.ignore();
        
        switch (menuChoice)
        {
            case addToBook:
                entryData(Entry, addressData);
                break;
            case removeFromBook:
                removeData(Entry);
                break;
            case printBook:
                print(Entry);
                break;
            case searchBook:
                searchData(Entry);
                break;
            case reprintMenu:
                cmds();
                break;
            case clear:
                clrScreen();
                break;
            case changeData:
                changeInfo(Entry, addressData);
                break;
            case exitprog:
                cout << "Saving Address Book... " << endl;
                saveBook(Entry);
                cout << "Goodbye! " << endl;
                Entry.clear();
                break;
            default:
                cout << "*ERROR* invalid command... " << endl;
                newLine();
                break;       
        }
    } while (menuChoice != exitprog);  
   

	return 0;
}

string cmd()
{
	string cmd;				// delcare string for user cmd	

  	cout << endl;			// endline before printing new cmd line
  	cout << "> ";		    // output cmd line
  	getline(cin, cmd);		// get user input   
    
  	return cmd;				// return string input by user
}

void clrScreen()
{
  	cout << "\033[2J\033[1;1H";		// ASCII escape codes to clear screen
}

void newLine()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void cmds()
{
	// print commands
  	cout << endl;
  	cout << "+--------------MAIN MENU-------------+\n"
       	 << "| 1. Add person to Address Book      |\n"
         << "| 2. Remove person from Address Book |\n"
         << "| 3. Print your Address Book         |\n"
         << "| 4. Search for person in Book       |\n"
         << "| 5. Re-Print Menu                   |\n"
	     << "| 6. Clear screen                    |\n"
	     << "| 7. Change someone's information    |\n"
         << "| 8. Exit Menu                       |\n"
         << "+------------------------------------+\n";

}

void cmds2()
{
    cout << endl;
    cout << "+-------------EDITS MENU------------+\n"
         << "| 1. Change street address          |\n"
         << "| 2. Change city                    |\n"
         << "| 3. Change state                   |\n"
         << "| 4. Change zip code                |\n"
         << "| 5. Go back to main menu           |\n"
         << "+-----------------------------------+\n";
}

addressBookCmds entryData(map<string, aBook>& Entry, aBook& addressData)
{
    string strtAddress;
    string name;
    string city;
    string state;
    string zipCode;
    
    cout << "Enter name of the person you would like to add to Address Book: ";
    name = cmd();
    
    cout << "Enter street address: ";
    strtAddress = cmd();
    
    cout << "Enter city: ";
    city = cmd();
    
    cout << "Enter state: ";
    state = cmd();
    
    cout << "Enter zip code: ";
    zipCode = cmd();
    
    addressData.setStrtName(strtAddress);
    addressData.setZipCode(zipCode);
    addressData.setCity(city);
    addressData.setState(state);
    Entry[name] = addressData;  
    
    cout << name << " Has been added to Address Book." << endl;
}

aBookEditCmds changeInfo(map<string, aBook>& Entry, aBook addressData)
{
    string targetName;
    map<string, aBook>::iterator it;
    int choice;
    string newStName;
    string newCity;
    string newState;
    string newZipCode;
    
    if (Entry.empty())
    {
        cout << "ERROR: Address Book is empty... " << endl;
        return exitEdits;
    }
    
    cout << "Enter first and last name of the person you would like to edit: ";
    targetName = cmd();
    
    cout << "Locating " << targetName << "... ";
    it = Entry.find(targetName);
    
    if (it != Entry.end())
    {
        cout << "Found!\n";
        cout << it->second << endl;
        cout << "Please select from the following menu options below to make edits: " << endl;
        cmds2();
        
        do
        {
     
            cout << "> ";
            cin  >> choice;
            cin.ignore();
            
            switch (choice)
            {
                case chStName:
                    cout << "Enter new street name: ";
                    newStName = cmd();
                    addressData.setStrtName(newStName);
                    cout << targetName << "'s street address has been updated to: ";
                    cout << newStName << endl;
                    Entry[targetName] = addressData;      
                    break;
                case chCity:
                    cout << "Enter new city: ";
                    newCity = cmd();
                    addressData.setCity(newCity);
                    cout << targetName << "'s city has been updated to: ";
                    cout << newCity << endl;
                    Entry[targetName] = addressData;
                    break;
                case chState:
                    cout << "Enter new state: ";
                    newState = cmd();
                    addressData.setState(newState);
                    cout << targetName << "'s state has been updated to: ";
                    cout << newState << endl;
                    Entry[targetName] = addressData;
                    break;
                case chZipCode:
                    cout << "Enter new zip code: ";
                    newZipCode = cmd();
                    addressData.setZipCode(newZipCode);
                    cout << targetName << "'s zip code has been updated to: ";
                    cout << newZipCode << endl;
                    Entry[targetName] = addressData;
                    break;
                case exitEdits:
                    cout << "Going back to main menu... " << endl;
                    cmds();
                    break;
                default:
                    cout << "ERROR: Invalid selection... " << endl;
                    newLine();
                    break;        
            }
        } while (choice != exitEdits);
    }
    else
    {
        cout << "\nERROR: " << targetName << " does not exist in Address Book... " << endl;
    }

}

void print(map<string, aBook> Entry)
{
    if (Entry.empty())
    {
        cout << "Address Book is empty... " << endl;
        return;
    }

    for (auto i = Entry.begin(); i != Entry.end(); ++i)
    {
        cout << (*i).first << ":" << (*i).second << endl;
    }
}

void searchData(map<string, aBook> Entry)
{
    string targetName;
    map<string, aBook>::iterator person;
    
    if (Entry.empty())
    {
        cout << "ERROR: Address Book is empty..." << endl;
        return;
    }
    
    cout << "Enter First and last name of the person you would like to search: ";
    targetName = cmd();
    
   cout << "Locating " << targetName << "... ";
   person = Entry.find(targetName);
   
   if (person != Entry.end())
   {
        cout << "Found!\n";
        cout << person->second << endl;
   }
   else
   {
        cout << "\nERROR: " << targetName << " does not exist in Address Book... " << endl;
        return;
   }
   
}

void removeData(map<string, aBook>& Entry)
{
    string targetName;
    map<string, aBook>::iterator it;
    
    if (Entry.empty())
    {
        cout << "ERROR: Address Book is empty..." << endl;
        return;
    }
    
    cout << "Enter First and last name of person you would like to remove: ";
    targetName = cmd();
    
    cout << "Locating " << targetName << "... " << endl;
    it = Entry.find(targetName);
    
    if (it != Entry.end())
    {
        Entry.erase(it);
    }
    else
    {
        cout << "ERROR: " << targetName << " does not exist in Address Book... " << endl;
        return;
    }
   
    cout << "Removed. " << endl;
    
}

void saveBook(map<string, aBook> Entry)
{
    ofstream fout;
    
    fout.open("addressbook.txt");
    
    if (fout.fail())
    {
        cout << "ERROR: File does not exist... " << endl;
        return;
    }
    
    for (auto i = Entry.begin(); i != Entry.end(); ++i)
    {
        fout << (*i).first << ": " << (*i).second << endl;
    }
    
    cout << "Data saved." << endl;
    fout.close();   
}

void loadBook(map<string, aBook>& Entry, aBook& addressData)
{
    ifstream fin;
    string strtAddress;
    string name;
    string city;
    string state;
    string zipCode;
    
    fin.open("addressbook.txt");
    
    if (fin.fail())
    {
        cout << "ERROR: File does not exist... " << endl;
        return;
    }
    
   while (getline(fin, name, ':') && getline(fin, strtAddress, '.') && getline(fin, city, ',') &&   getline(fin, state, ' ') && getline(fin, zipCode))
   {
        addressData.setStrtName(strtAddress);
        addressData.setCity(city);
        addressData.setState(state);
        addressData.setZipCode(zipCode);
        Entry[name] = addressData;
   }
        
}



