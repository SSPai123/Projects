#include <iostream>
#include<stdlib.h>
#include<ctime>
#include<string.h>

using namespace std;

const int MAX_TRIES=5;

int letterFill(char guess,string secretword, string& guessword);
void hangman(string words[]);

int main()
{
    int option; string ch;
    string countries[]={"india","afghanistan","london","china","america","pakistan","australia","switzerland","peru","czech_republic"};
    string rivers[]={"ganga","nile","missouri","brahmaputra","narmada","sindhu","tungabhadra","sharavati","mississipi","godavari"};
    string personalities[]={"gandhiji","nelson_mandela","bill_gates","einstein","plato","edison","armstrong","kalpana_chawla","lakshmibai","mother_theresa"};
    string companies[]={"flipkart","microsoft","google","isro","infosys","robosoft","lamborghini","ferrari","apple","twitter"};

    cout<<"\t\t\t\tWELCOME TO THE GAME HANGMAN\n";
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"Each letter is represented by a star.\nIf there are two words to be guessed then one star have to be replaced by underscore after the first word\n";
    cout<<"You have "<<MAX_TRIES<<" tries to try and guess the word\n";
    cout<<"Enter each letter in lower case only!\n";
    cout<<"-------------------------------------------------------------------------\n";
label:  cout<<"Type 1 to guess name of countries\n";
        cout<<"Type 2 to guess name of rivers\n";
        cout<<"Type 3 to guess name of personalities\n";
        cout<<"Type 4 to guess name of companies\n";
        cin>>option;
        if(option==1)
        {
            hangman(countries);
        }
        else if(option==2)
        {
            hangman(rivers);
        }
        else if(option==3)
        {
            hangman(personalities);
        }
        else if(option==4)
        {
            hangman(companies);
        }
        else
        {
            cout<<"Invalid Entry\n";
        }
    cout<<"Do you want to continue playing?? Type yes or no\n";
    cin>>ch;
    if(ch=="yes")
    {
        goto label;
    }
    else
    {
        cout<<"********************Thanks for Playing, Bye!****************\n";
        exit(0);
    }
    return 0;
}
void hangman(string words[])
{
    string name;
    char letter;
    int wrong_guesses_num=0;
    string word,ch;int p;
    srand(time(NULL));
    int n=rand()%10;
    word=words[n];
    string secret(word.length(),'*');
    while(wrong_guesses_num<MAX_TRIES)
    {
        cout<<"\n"<<secret;
        cout<<"\nGuess a letter\n";
        cin>>letter;
        p=letterFill(letter,word,secret);
        if(p==0)
        {
            cout<<"\nThat Letter Is not there in that word\n";
            wrong_guesses_num++;
        }
        else if(p!=0)
        {
            cout<<"Amazing! You Have Found A Letter!! :-)\n";
                goto label;
        }
        cout<<"You Have "<<MAX_TRIES-wrong_guesses_num<<" guesses left\n";
       label: if(word==secret)
        {
            cout<<word<<endl;
            cout<<"WOW!You Got the word!!\n";
            break;
        }
    }
    if(wrong_guesses_num==MAX_TRIES)
    {
        cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        cout<<"Sorry,You have been HANGED!\n";
        cout<<"The word was "<<word<<endl;
        cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    }
}
int letterFill(char guess,string secretword, string& guessword)
{
    int i;
    int matches=0;
    int len=secretword.length();
    for(i=0;i<len;i++)
    {
        if(guess==guessword[i])
        {
            return 0;
        }
        if(guess==secretword[i])
        {
            guessword[i]=guess;
            matches++;
        }
    }
    return matches;
}
